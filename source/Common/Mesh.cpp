#include "Mesh.h"
#include "Common.h"
using namespace RenderCore;

Mesh::Mesh(const std::string& meshName) : mName(meshName), mpVertices(NULL)
{
	for (int i = 0; i < VertexAttributes::VERTEXATTRIBUTESSIZE; i++)
	{
		mAttributeExists[i] = false;
	}
}

Mesh::~Mesh()
{
	DeleteObject(mpVertices);
}

void Mesh::Initialize()
{
	
}

void Mesh::CreateVertexBuffers()
{

}

const ID3D11Buffer* Mesh::GetVertexBuffer() const
{
	return mpVertexBuffer;
}