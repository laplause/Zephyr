#include "Sprite.h"
#include "ModelManager.h"
#include "EngineState.h"
using namespace Core;
using namespace ZMath;

Sprite::Sprite(int id, const std::string& objectName) : GameObject(id, objectName), mQuad(objectName, this), mPosition(0, 0)
{

}

Sprite::~Sprite()
{

}

void Sprite::Initialize(DirectXRenderer* renderer, const std::string& materialName, Texture* spriteTexture)
{
	const ZMath::Vec2& texSize = spriteTexture->GetTextureDimensions();
	mTextureWidth = texSize.x;
	mTextureHeight = texSize.y;

	mQuad.Initialize(renderer->Direct3DDevice(), renderer->Direct3DDeviceContext());
	ModelManager::GetModelManager()->AddModel(GetName(), &mQuad);
	AttachRenderable(renderer->CreateRenderable(GetName(), materialName, GetHandle()));
}

void Sprite::Update(const Core::GameTime& gameTime)
{
	mQuad.Update(gameTime);
}

void Sprite::SetPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
	mTransform.m03 = x;
	mTransform.m13 = -y;
}

Sprite::SpriteQuad::SpriteQuad(const std::string& meshName, Sprite* parent) : Mesh(meshName), mParent(parent)
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
	left = (float)(-SCREEN_WIDTH / 2) -(float)(mParent->mTextureWidth / 2) + mParent->mPosition.x;
	right = left + mParent->mTextureWidth;
	top = (float)(SCREEN_HEIGHT / 2) + (float)(mParent->mTextureHeight / 2) - mParent->mPosition.y;
	bottom = top - mParent->mTextureHeight;

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

void Sprite::SpriteQuad::Update(const Core::GameTime& gameTime)
{
	float speed = 50.0f;
	float velocity = speed*(float)gameTime.ElapsedGameTime();

	mParent->SetPosition(velocity + mParent->mPosition.x, velocity + mParent->mPosition.y);
}

void Sprite::SpriteQuad::Draw(const Core::GameTime& gameTime, ID3D11DeviceContext* deviceContext)
{
	unsigned int stride = sizeof(Vertex);
	unsigned int offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &mpVertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(mpIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	deviceContext->DrawIndexed(mIndexCount, 0, 0);
}