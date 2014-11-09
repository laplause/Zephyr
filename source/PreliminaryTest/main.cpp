#include "DirectXRenderer.h"
#include "Mesh.h"
using namespace RenderCore;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR comandLine, int showCommand)
{
	DirectXRenderer dx(instance, L"RenderWindow", L"blah", showCommand);

	dx.Initialize();

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
			dx.Update();
			dx.Draw();
		}
	}

	dx.Shutdown();

	return 0;
}