#include "Renderable.h"
#include "ModelManager.h"
#include "Mesh.h"
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
}

void Renderable::Update()
{
	mMesh->Update();
}

void Renderable::Draw(ID3D11DeviceContext* deviceContext)
{
	mMesh->Draw(deviceContext);
}