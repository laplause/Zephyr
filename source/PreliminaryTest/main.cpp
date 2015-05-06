#include "DirectXRenderer.h"
#include "Mesh.h"
#include "Triangle.h"
#include "ColorMaterial.h"
#include "TextureMaterial.h"
#include "ModelManager.h"
#include "MaterialManager.h"
#include "Texture.h"
#include "XmlParseMaster.h"
#include "XmlParseHelperTexture.h"
#include "TextureData.h"
#include "TextureManager.h"
using namespace RenderCore;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR comandLine, int showCommand)
{
	RenderCore::DirectXRenderer dx(instance, L"RenderWindow", L"blah", showCommand);
	dx.Initialize();

	TextureData data;
	XmlParseMaster parser(&data);
	XmlParseHelperTexture textureHelper(&parser);

	parser.ParseFromFile("..\\..\\Resources\\TexturesToLoad.xml");
	TextureManager::GetTextureManager()->LoadTexturesFromData(dx.Direct3DDevice());

	Triangle *t = new Triangle("triangle");
	TextureMaterial *tm = new TextureMaterial("texturing");
	//ColorMaterial *c = new ColorMaterial("color");

	t->Initialize(dx.Direct3DDevice(), dx.Direct3DDeviceContext());
	tm->Initialize("..\\..\\bin\\Texture.cso", "..\\..\\bin\\TexturePS.cso", &dx);
	//c->Initialize("..\\..\\bin\\Color.cso", "..\\..\\bin\\ColorPS.cso", &dx);

	//MaterialManager::GetMaterialManager()->AddMaterial("color", c);
	MaterialManager::GetMaterialManager()->AddMaterial("texturing", tm);
	ModelManager::GetModelManager()->AddModel("triangle", t);

	dx.CreateRenderable("triangle", "texturing");

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