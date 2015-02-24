#include "Renderable.h"
#include "ModelManager.h"
#include "MaterialManager.h"
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

void Renderable::Update()
{
	ZEPHYR_ASSERT(mMesh != nullptr, "A renderable was initialized with a null mesh");
	mMesh->Update();
}

void Renderable::Draw(ID3D11DeviceContext* deviceContext, PerspectiveCamera* camera)
{
	ZEPHYR_ASSERT(mMesh != nullptr, "A renderable was initialized with a null mesh");
	ZEPHYR_ASSERT(mMaterial != nullptr, "A renderable was initialized with a null material");
	mMaterial->SetActiveShader(deviceContext);
	mMaterial->SetShaderBuffers(deviceContext, camera);
	mMesh->Draw(deviceContext);
}