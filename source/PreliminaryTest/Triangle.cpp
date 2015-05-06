#include "Triangle.h"

Triangle::Triangle(const std::string& meshName) : Mesh(meshName)
{

}

Triangle::~Triangle()
{
	
}

void Triangle::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	unsigned long* indices;
	Vertex* vertices;
	mIndexCount = 3;

	vertices = new Vertex[3];
	indices = new unsigned long[mIndexCount];

	vertices[0].position = ZMath::Vec3(-1.0f, -1.0f, 0);
	vertices[0].textureCoordinates = ZMath::Vec2(0.0f, 1.0f);

	vertices[1].position = ZMath::Vec3(0, 1.0f, 0);
	vertices[1].textureCoordinates = ZMath::Vec2(0.5f, 0);

	vertices[2].position = ZMath::Vec3(1.0f, -1.0f, 0);
	vertices[2].textureCoordinates = ZMath::Vec2(1.0f, 1.0f);

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	// Create a vertex buffer
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
	ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(Vertex)* 3;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	device->CreateBuffer(&vertexBufferDesc, &vertexData, &mpVertexBuffer);

	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * mIndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	device->CreateBuffer(&indexBufferDesc, &indexData, &mpIndexBuffer);

	delete [] vertices;
	vertices = 0;

	delete [] indices;
	indices = 0;
}

void Triangle::Update()
{

}

void Triangle::Draw(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride = sizeof(Vertex);
	unsigned int offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &mpVertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(mpIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	deviceContext->DrawIndexed(mIndexCount, 0, 0);
}