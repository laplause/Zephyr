#include "Renderable.h"
#include "ModelManager.h"
#include "MaterialManager.h"
#include "GameObjectManager.h"
#include "Mesh.h"
#include "Material.h"
#include "ZAssert.h"
using namespace RenderCore;

Renderable::Renderable() : Component(), mMaterial(NULL), mMesh(NULL)
{

}

Renderable::~Renderable()
{

}

void Renderable::Initialize(const std::string& meshName, const std::string& materialName)
{
	mMesh = ModelManager::GetModelManager()->GetModel(meshName);
	mMaterial = MaterialManager::GetMaterialManager()->GetMaterial(materialName);
}

void Renderable::Update(const Core::GameTime& gameTime)
{
	ZEPHYR_ASSERT(mMesh != nullptr, "A renderable was initialized with a null mesh");
	mMesh->Update(gameTime);
	mMaterial->Update(gameTime);
}

void Renderable::Draw(const Core::GameTime& gameTime, ID3D11DeviceContext* deviceContext, Camera* camera)
{
	ZEPHYR_ASSERT(mMesh != nullptr, "A renderable was initialized with a null mesh");
	ZEPHYR_ASSERT(mMaterial != nullptr, "A renderable was initialized with a null material");
	mMaterial->SetActiveShader(deviceContext);
	mMaterial->SetShaderBuffers(deviceContext, camera, GameObjectManager::GetGameObjectManager()->GetGameObject(GetObjectHandle())->GetTransform());
	mMesh->Draw(gameTime, deviceContext);
}