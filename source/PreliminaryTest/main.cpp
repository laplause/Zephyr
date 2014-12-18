#include "DirectXRenderer.h"
#include "Mesh.h"
#include "Triangle.h"
#include "ColorMaterial.h"
#include "ModelManager.h"
#include "MaterialManager.h"
using namespace RenderCore;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR comandLine, int showCommand)
{
	RenderCore::DirectXRenderer dx(instance, L"RenderWindow", L"blah", showCommand);
	dx.Initialize();

	Triangle *t = new Triangle("triangle");
	ColorMaterial *c = new ColorMaterial("color");

	t->Initialize(dx.Direct3DDevice(), dx.Direct3DDeviceContext());
	c->Initialize("C:\\Chris Shit\\Programming Projects\\c++ Projects\\zephyr\\bin\\Color.cso", "C:\\Chris Shit\\Programming Projects\\c++ Projects\\zephyr\\bin\\ColorPS.cso", &dx);

	MaterialManager::GetMaterialManager()->AddMaterial("color", c);
	ModelManager::GetModelManager()->AddModel("triangle", t);

	dx.CreateRenderable("triangle", "color");

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