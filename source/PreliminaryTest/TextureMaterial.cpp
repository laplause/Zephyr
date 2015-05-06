#include "TextureMaterial.h"
#include "Common.h"
#include "TextureManager.h"

TextureMaterial::TextureMaterial(const std::string& materialName) : Material(materialName), mpMatrixBuffer(nullptr), mpSamplerState(nullptr)
{

}

TextureMaterial::~TextureMaterial()
{
	ZEPHYR_RELEASEOBJECT(mpMatrixBuffer);
	ZEPHYR_RELEASEOBJECT(mpSamplerState);
}

void TextureMaterial::Initialize(const std::string& vsFileName, const std::string& psFileName, RenderCore::DirectXRenderer* renderer)
{
	Material::Initialize(vsFileName, psFileName, renderer);

	unsigned int numElements = 0;

	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	numElements = sizeof(ied) / sizeof(ied[0]);
	renderer->Direct3DDevice()->CreateInputLayout(ied, numElements, mpVertexShaderByteCode, mVertexShaderFileSize, &mpInputLayout);
	ZEPHYR_DELETEOBJECTS(mpVertexShaderByteCode);
	ZEPHYR_DELETEOBJECTS(mpPixelShaderByteCode);

	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBuffer);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	renderer->Direct3DDevice()->CreateBuffer(&matrixBufferDesc, nullptr, &mpMatrixBuffer);

	D3D11_SAMPLER_DESC samplerDesc;
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	renderer->Direct3DDevice()->CreateSamplerState(&samplerDesc, &mpSamplerState);

	mTexture = RenderCore::TextureManager::GetTextureManager()->GetTexture("Jax")->GetTextureResource();
}

void TextureMaterial::SetActiveShader(ID3D11DeviceContext* deviceContext)
{
	Material::SetActiveShader(deviceContext);
	deviceContext->IASetInputLayout(mpInputLayout);
}

void TextureMaterial::SetShaderBuffers(ID3D11DeviceContext* deviceContext, RenderCore::PerspectiveCamera* camera)
{
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBuffer* matrixData;
	unsigned int bufferNumber;

	deviceContext->Map(mpMatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	matrixData = (MatrixBuffer*)mappedResource.pData;

	matrixData->world = ZMath::CreateIdentity4x4();
	matrixData->view = camera->ViewMatrix();
	matrixData->projection = camera->ProjectionMatrix();

	deviceContext->Unmap(mpMatrixBuffer, 0);

	bufferNumber = 0;

	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &mpMatrixBuffer);

	deviceContext->PSSetShaderResources(0, 1, &mTexture);
}