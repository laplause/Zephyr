#include "DirectXRenderer.h"
#include "Mesh.h"
#include "Triangle.h"
#include "ColorMaterial.h"
#include "TextureMaterial.h"
#include "ModelManager.h"
#include "MaterialManager.h"
#include "GameObjectManager.h"
#include "Texture.h"
#include "XmlParseMaster.h"
#include "XmlParseHelperTexture.h"
#include "TextureData.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "GameClock.h"
#include "InputManager.h"
using namespace RenderCore;

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR comandLine, int showCommand)
{
	Core::GameClock gameClock;
	Core::GameTime gameTime;

	RenderCore::DirectXRenderer dx(instance, L"RenderWindow", L"blah", showCommand);
	dx.Initialize();

	Core::InputManager::CreateInstance(dx);

	TextureData data;
	XmlParseMaster parser(&data);
	XmlParseHelperTexture textureHelper(&parser);

	parser.ParseFromFile("..\\..\\Resources\\TexturesToLoad.xml");
	TextureManager::GetTextureManager()->LoadTexturesFromData(dx.Direct3DDevice());

	Triangle *t = new Triangle("triangle");
	TextureMaterial *tm = new TextureMaterial("texturing");
	ColorMaterial *c = new ColorMaterial("color");

	t->Initialize(dx.Direct3DDevice(), dx.Direct3DDeviceContext());
	tm->Initialize("..\\..\\bin\\Texture.cso", "..\\..\\bin\\TexturePS.cso", &dx);
	c->Initialize("..\\..\\bin\\Color.cso", "..\\..\\bin\\ColorPS.cso", &dx);

	MaterialManager::GetMaterialManager()->AddMaterial("color", c);
	MaterialManager::GetMaterialManager()->AddMaterial("texturing", tm);
	ModelManager::GetModelManager()->AddModel("triangle", t);

	Sprite *s = new Sprite(0, "quad");
	s->Initialize(&dx, "texturing", TextureManager::GetTextureManager()->GetTexture("Jax"));

	GameObjectManager::GetGameObjectManager()->AddGameObject(s->GetHandle(), s);

	//dx.CreateRenderable("triangle", "texturing");

	MSG message;
	ZeroMemory(&message, sizeof(message));

	float speed = 100.0f;
	float velocity = 0;
	Core::InputManager& im = *(Core::InputManager::GetInputManager());

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			gameClock.UpdateGameTime(gameTime);

			velocity = speed*(float)gameTime.ElapsedGameTime();

			im.Update(gameTime);
			
			if (im.IsKeyDown(DIK_S) && im.IsKeyDown(DIK_D))
				s->SetPosition(velocity + s->GetPosition().x, velocity + s->GetPosition().y);
			else if (im.IsKeyDown(DIK_S) || im.IsButtonDown(MouseButtons::MOUSEBUTTONSLEFT))
				s->SetPosition(s->GetPosition().x, velocity + s->GetPosition().y);
			else if (im.IsKeyDown(DIK_D))
				s->SetPosition(velocity + s->GetPosition().x, s->GetPosition().y);
			dx.Update(gameTime);
			dx.Draw(gameTime);
		}
	}

	dx.Shutdown();

	return 0;
}