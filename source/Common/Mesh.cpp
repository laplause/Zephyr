#include "Mesh.h"
#include "Common.h"
using namespace RenderCore;

Mesh::Mesh(const std::string& meshName) : mName(meshName), mpVertexBuffer(nullptr), mpIndexBuffer(nullptr)
{
	
}

Mesh::~Mesh()
{
	ZEPHYR_RELEASEOBJECT(mpVertexBuffer);
	ZEPHYR_RELEASEOBJECT(mpIndexBuffer);
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

const ID3D11Buffer* Mesh::GetIndexBuffer() const
{
	return mpIndexBuffer;
}

const unsigned int Mesh::GetIndexCount() const
{
	return mIndexCount;
}