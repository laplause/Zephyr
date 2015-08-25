///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	These values control much of how the engine behaves. Some data oriented approach must be     //
//  implemented eventually.                                                                      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "Keyboard.h"
#include "Mouse.h"

namespace Core
{
	class InputManager
	{
	public:
		~InputManager();
		static InputManager* CreateInstance(const RenderCore::Renderer& renderer);
		static InputManager* GetInputManager();

		void Update(const GameTime& gameTime);
		void Shutdown();

		//Keyboard Interface
		bool IsKeyUp(unsigned char key) const;
		bool IsKeyDown(unsigned char key) const;
		bool WasKeyUp(unsigned char key) const;
		bool WasKeyDown(unsigned char key) const;
		bool WasKeyPressedThisFrame(unsigned char key) const;
		bool WasKeyReleasedThisFrame(unsigned char key) const;
		bool IsKeyHeldDown(unsigned char key) const;

		//Mouse Interface
		long X() const;
		long Y() const;
		long Wheel() const;
		bool IsButtonUp(MouseButtons button) const;
		bool IsButtonDown(MouseButtons button) const;
		bool WasButtonUp(MouseButtons button) const;
		bool WasButtonDown(MouseButtons button) const;
		bool WasButtonPressedThisFrame(MouseButtons button) const;
		bool WasButtonReleasedThisFrame(MouseButtons button) const;
		bool IsButtonHeldDown(MouseButtons button) const;

	private:
		InputManager();
		InputManager(const RenderCore::Renderer& renderer);
		InputManager(const InputManager& rhs);
		InputManager& operator=(const InputManager& rhs);

		void Initialize(const RenderCore::Renderer& renderer);

		static InputManager* m_sInstance;
		LPDIRECTINPUT8 mDirectInput;
		Keyboard *mKeyboard;
		Mouse *mMouse;

	};
}
#endif