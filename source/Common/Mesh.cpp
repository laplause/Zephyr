#include "Mesh.h"
#include "Common.h"
using namespace RenderCore;

Mesh::Mesh(const std::string& meshName) : mName(meshName), mpVertexBuffer(nullptr)
{
	
}

Mesh::~Mesh()
{
	
}

void Mesh::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	
}

void Mesh::Draw(ID3D11DeviceContext* deviceContext)
{

}

void Mesh::Update()
{

}

void Mesh::CreateVertexBuffers()
{

}

const ID3D11Buffer* Mesh::GetVertexBuffer() const
{
	return mpVertexBuffer;
}