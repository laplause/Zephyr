///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the cross platform object that creates a window and it's interface					 //
//																	                             //
//	Majority of implementation inspired by Paul Varcholik's book Real time						 //
//	3D rendering with DirectX and HLSL	                                                         //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SYSTEMWINDOW_H
#define SYSTEMWINDOW_H

#include <string>
#include "EngineState.h"

#if WINDOWS
#include <Windows.h>
#endif

namespace RenderCore
{
	class SystemWindow
	{
	public:
#if WINDOWS
		SystemWindow(HINSTANCE instance, const std::wstring& windowClass, const std::wstring& windowTitle, int showCommand);
#endif
		~SystemWindow();
		void Initialize();
		void Shutdown();

	private:
		SystemWindow(const SystemWindow& rhs);
		SystemWindow& operator=(const SystemWindow& rhs);

#if WINDOWS
		POINT CenterWindow(unsigned int windowWidth, unsigned int windowHeight);
		static LRESULT WINAPI WndProc(HWND windowHandle, unsigned int message, WPARAM wParam, LPARAM lParam);

		HINSTANCE mInstance;
		std::wstring mWindowClass;
		std::wstring mWindowTitle;
		int mShowCommand;
		HWND mWindowHandle;
		WNDCLASSEX mWindow;
		DEVMODE dmScreenSettings;
#endif
		unsigned int mScreenWidth;
		unsigned int mScreeHeight;
	};
}
#endif