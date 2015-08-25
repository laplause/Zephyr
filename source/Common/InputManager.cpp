#include "InputManager.h"
#include "ZAssert.h"
#include "Common.h"
using namespace Core;

InputManager* InputManager::m_sInstance = nullptr;

InputManager::InputManager(const RenderCore::Renderer& renderer) : mDirectInput(nullptr), mKeyboard(nullptr), mMouse(nullptr)
{
	DirectInput8Create(renderer.GetWindow()->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&mDirectInput, nullptr);
	Initialize(renderer);
}

InputManager::~InputManager()
{
	
}

void InputManager::Initialize(const RenderCore::Renderer& renderer)
{
	mKeyboard = new Keyboard(renderer, mDirectInput);
	mMouse = new Mouse(renderer, mDirectInput);
}

InputManager* InputManager::CreateInstance(const RenderCore::Renderer& renderer)
{
	if (m_sInstance != nullptr)
	{
		return m_sInstance;
	}
	else
	{
		m_sInstance = new InputManager(renderer);
	}

	return m_sInstance;
}

InputManager* InputManager::GetInputManager()
{
	ZEPHYR_ASSERT(m_sInstance != nullptr, "The InputManager is null. CreatInstance must be explicitly called for this singleton.");
	return m_sInstance;
}

void InputManager::Update(const GameTime& gameTime)
{
	mKeyboard->Update(gameTime);
	mMouse->Update(gameTime);
}

void InputManager::Shutdown()
{

}

bool InputManager::IsKeyUp(unsigned char key) const
{
	return mKeyboard->IsKeyUp(key);
}

bool InputManager::IsKeyDown(unsigned char key) const
{
	return mKeyboard->IsKeyDown(key);
}

bool InputManager::WasKeyUp(unsigned char key) const
{
	return mKeyboard->WasKeyUp(key);
}

bool InputManager::WasKeyDown(unsigned char key) const
{
	return mKeyboard->WasKeyDown(key);
}

bool InputManager::WasKeyPressedThisFrame(unsigned char key) const
{
	return mKeyboard->WasKeyPressedThisFrame(key);
}

bool InputManager::WasKeyReleasedThisFrame(unsigned char key) const
{
	return mKeyboard->WasKeyReleasedThisFrame(key);
}

bool InputManager::IsKeyHeldDown(unsigned char key) const
{
	return mKeyboard->IsKeyHeldDown(key);
}

long InputManager::X() const
{
	return mMouse->X();
}

long InputManager::Y() const
{
	return mMouse->Y();
}

long InputManager::Wheel() const
{
	return mMouse->Wheel();
}

bool InputManager::IsButtonUp(MouseButtons button) const
{
	return mMouse->IsButtonUp(button);
}

bool InputManager::IsButtonDown(MouseButtons button) const
{
	return mMouse->IsButtonDown(button);
}

bool InputManager::WasButtonUp(MouseButtons button) const
{
	return mMouse->WasButtonUp(button);
}

bool InputManager::WasButtonDown(MouseButtons button) const
{
	return mMouse->WasButtonDown(button);
}

bool InputManager::WasButtonPressedThisFrame(MouseButtons button) const
{
	return mMouse->WasButtonPressedThisFrame(button);
}

bool InputManager::WasButtonReleasedThisFrame(MouseButtons button) const
{
	return mMouse->WasButtonReleasedThisFrame(button);
}

bool InputManager::IsButtonHeldDown(MouseButtons button) const
{
	return mMouse->IsButtonHeldDown(button);
}