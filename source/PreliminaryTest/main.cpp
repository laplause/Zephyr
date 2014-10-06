#include "SystemWindow.h"
using namespace RenderCore;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR comandLine, int showCommand)
{
	SystemWindow l(instance, L"RenderWindow", L"blah", showCommand);
	l.Initialize();

	int a = 0;
	MSG message;
	ZeroMemory(&message, sizeof(message));

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			a++;
		}
	}

	l.Shutdown();

	return 0;
}