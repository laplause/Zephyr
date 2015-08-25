#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Renderer.h"
#include "GameTime.h"
#include <dinput.h>

namespace Core
{
	class Keyboard
	{
	public:
		Keyboard(const RenderCore::Renderer& renderer, LPDIRECTINPUT8 directInput);
		~Keyboard();

		const unsigned char* const CurrentState() const;
		const unsigned char* const LastState() const;

		void Update(const GameTime& gameTime);

		bool IsKeyUp(unsigned char key) const;
		bool IsKeyDown(unsigned char key) const;
		bool WasKeyUp(unsigned char key) const;
		bool WasKeyDown(unsigned char key) const;
		bool WasKeyPressedThisFrame(unsigned char key) const;
		bool WasKeyReleasedThisFrame(unsigned char key) const;
		bool IsKeyHeldDown(unsigned char key) const;

	private:
		Keyboard(const Keyboard& rhs);
		void Initialize();

		static const int KeyCount = 256;

		const RenderCore::Renderer* mRenderer;
		LPDIRECTINPUT8 mDirectInput;
		LPDIRECTINPUTDEVICE8 mDevice;
		unsigned char mCurrentState[KeyCount];
		unsigned char mLastState[KeyCount];
	};
}

#endif