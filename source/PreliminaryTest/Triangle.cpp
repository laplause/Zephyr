#include "Triangle.h"

Triangle::Triangle(const std::string& meshName) : Mesh(meshName), mpVetices(nullptr)
{

}

Triangle::~Triangle()
{
	
}

void Triangle::Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	mpVetices = new Vertex[3];

	mpVetices[0].position.x = 0.0f;
	mpVetices[0].position.y = 0.5f;
	mpVetices[0].position.z = 0.0f;

	mpVetices[0].color.r = 1.0f;
	mpVetices[0].color.g = 0.0f;
	mpVetices[0].color.b = 0.0f;
	mpVetices[0].color.a = 1.0f;

	mpVetices[1].position.x = 0.45f;
	mpVetices[1].position.y = -0.5f;
	mpVetices[1].position.z = 0.0f;

	mpVetices[1].color.r = 0.0f;
	mpVetices[1].color.g = 1.0f;
	mpVetices[1].color.b = 0.0f;
	mpVetices[1].color.a = 1.0f;

	mpVetices[2].position.x = -0.45f;
	mpVetices[2].position.y = -0.5f;
	mpVetices[2].position.z = 0.0f;

	mpVetices[2].color.r = 0.0f;
	mpVetices[2].color.g = 0.0f;
	mpVetices[2].color.b = 1.0f;
	mpVetices[2].color.a = 1.0f;

	// Create a vertex buffer
	D3D11_BUFFER_DESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(bufferDesc));

	bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	bufferDesc.ByteWidth = sizeof(Vertex)* 3;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

	device->CreateBuffer(&bufferDesc, nullptr, &mpVertexBuffer);

	// Copy the vertices into the buffer.
	D3D11_MAPPED_SUBRESOURCE ms;
	deviceContext->Map(mpVertexBuffer, NULL, D3D11_MAP_WRITE_DISCARD, NULL, &ms);
	memcpy(ms.pData, mpVetices, sizeof(mpVetices));
	deviceContext->Unmap(mpVertexBuffer, NULL);
}

void Triangle::Update()
{

}

void Triangle::Draw(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride = sizeof(Vertex);
	unsigned int offset = 0;
	deviceContext->IASetVertexBuffers(0, 1, &mpVertexBuffer, &stride, &offset);

	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	deviceContext->Draw(3, 0);
}