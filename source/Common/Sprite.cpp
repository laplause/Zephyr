#include "Sprite.h"
#include "ModelManager.h"
using namespace Core;
using namespace ZMath;

Sprite::Sprite(const std::string& objectName) : mQuad(objectName), mName(objectName)
{

}

Sprite::~Sprite()
{

}

void Sprite::Initialize(DirectXRenderer* renderer, const std::string& materialName)
{
	mQuad.Initialize(renderer->Direct3DDevice(), renderer->Direct3DDeviceContext());
	ModelManager::GetModelManager()->AddModel(mName, &mQuad);
	mComponentHandles[Component::RENDERABLE] = renderer->CreateRenderable(mName, materialName);
}

void Sprite::Update()
{
	mQuad.Update();
}

Sprite::SpriteQuad::SpriteQuad(const std::string& meshName) : Mesh(meshName)
{

}

Sprite::SpriteQuad::~SpriteQuad()
{

}

void Sprite::SpriteQuad::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	unsigned long* indices;
	Vertex* vertices;
	mIndexCount = 6;

	vertices = new Vertex[4];
	indices = new unsigned long[mIndexCount];

	float left, top, right, bottom;
	left = (float)((1024 / 2)*-1) + 250;
	right = left + (float)200;
	top = (float)(768 / 2) - 50;
	bottom = top - (float)200;

	vertices[0].position = Vec3(left, top, 0.0f);  // top left
	vertices[0].textureCoordinates = Vec2(0, 0);

	vertices[1].position = Vec3(left, bottom, 0.0f); // bottom left
	vertices[1].textureCoordinates = Vec2(0, 1.0f);

	vertices[2].position = Vec3(right, top, 0.0f);   // top right
	vertices[2].textureCoordinates = Vec2(1.0f, 0);

	vertices[3].position = Vec3(right, bottom, 0.0f); // bottom right
	vertices[3].textureCoordinates = Vec2(1.0f, 1.0f);

	indices[0] = 1;
	indices[1] = 0;
	indices[2] = 2;
	indices[3] = 1;
	indices[4] = 2;
	indices[5] = 3;

	// Create a vertex buffer
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
	ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(Vertex)* 4;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;
	
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	device->CreateBuffer(&vertexBufferDesc, &vertexData, &mpVertexBuffer);

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long)* mIndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	device->CreateBuffer(&indexBufferDesc, &indexData, &mpIndexBuffer);

	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;
}

void Sprite::SpriteQuad::Update()
{

}

void Sprite::SpriteQuad::Draw(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride = sizeof(Vertex);
	unsigned int offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &mpVertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(mpIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	deviceContext->DrawIndexed(mIndexCount, 0, 0);
}