#include "Keyboard.h"
#include "ZAssert.h"
using namespace Core;

Keyboard::Keyboard(const RenderCore::Renderer& renderer, LPDIRECTINPUT8 directInput) : 
mDevice(nullptr), mDirectInput(directInput), mRenderer(&renderer)
{
	ZEPHYR_ASSERT(mDirectInput != nullptr, "The directInput pointer used to create the object was created unsuccessfully.");
	ZeroMemory(mCurrentState, sizeof(mCurrentState));
	ZeroMemory(mLastState, sizeof(mLastState));
	Initialize();
}

Keyboard::~Keyboard()
{
	if (mDevice != nullptr)
	{
		mDevice->Unacquire();
		mDevice->Release();
		mDevice = nullptr;
	}
}

const unsigned char* const Keyboard::CurrentState() const
{
	return mCurrentState;
}

const unsigned char* const Keyboard::LastState() const
{
	return mLastState;
}

void Keyboard::Initialize()
{
	mDirectInput->CreateDevice(GUID_SysKeyboard, &mDevice, nullptr);
	ZEPHYR_ASSERT(mDevice != nullptr, "IDIRECTINPUT8::CreateDevice() failed");

	if (FAILED(mDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		ZEPHYR_ASSERT(mDevice == nullptr, "IDirectInputDevice8::SetDataFormat() failed");
	}

	mDevice->SetCooperativeLevel(mRenderer->GetWindow()->GetWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	mDevice->Acquire();
}

void Keyboard::Update(const GameTime& gameTime)
{
	if (mDevice != nullptr)
	{
		memcpy(mLastState, mCurrentState, sizeof(mCurrentState));

		if (FAILED(mDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState)))
		{
			if (SUCCEEDED(mDevice->Acquire()))
			{
				mDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState);
			}
		}
	}
}

bool Keyboard::IsKeyUp(unsigned char key) const
{
	return ((mCurrentState[key] & 0x80) == 0);
}

bool Keyboard::IsKeyDown(unsigned char key) const
{
	return ((mCurrentState[key] & 0x80) != 0);
}

bool Keyboard::WasKeyUp(unsigned char key) const
{
	return ((mLastState[key] & 0x80) == 0);
}

bool Keyboard::WasKeyDown(unsigned char key) const
{
	return ((mLastState[key] & 0x80) != 0);
}

bool Keyboard::WasKeyPressedThisFrame(unsigned char key) const
{
	return (IsKeyDown(key) && WasKeyUp(key));
}

bool Keyboard::WasKeyReleasedThisFrame(unsigned char key) const
{
	return (IsKeyUp(key) && WasKeyDown(key));
}

bool Keyboard::IsKeyHeldDown(unsigned char key) const
{
	return (IsKeyDown(key) && WasKeyDown(key));
}