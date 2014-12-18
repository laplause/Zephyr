#include "ColorMaterial.h"
#include "Common.h"

ColorMaterial::ColorMaterial(const std::string& materialName) : Material(materialName), mpMatrixBuffer(nullptr)
{

}

ColorMaterial::~ColorMaterial()
{

}

void ColorMaterial::Initialize(const std::string& vsFileName, const std::string& psFileName, RenderCore::DirectXRenderer* renderer)
{
	Material::Initialize(vsFileName, psFileName, renderer);

	unsigned int numElements = 0;

	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	numElements = sizeof(ied) / sizeof(ied[0]);
	renderer->Direct3DDevice()->CreateInputLayout(ied, numElements, mpVertexShaderByteCode, mVertexShaderFileSize, &mpInputLayout);
	DeleteObjects(mpVertexShaderByteCode);
	DeleteObjects(mpPixelShaderByteCode);

	D3D11_BUFFER_DESC matrixBufferDesc;
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBuffer);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	renderer->Direct3DDevice()->CreateBuffer(&matrixBufferDesc, NULL, &mpMatrixBuffer);
}

void ColorMaterial::SetActiveShader(ID3D11DeviceContext* deviceContext)
{
	Material::SetActiveShader(deviceContext);
	deviceContext->IASetInputLayout(mpInputLayout);
}

void ColorMaterial::SetShaderBuffers(ID3D11DeviceContext* deviceContext, RenderCore::Camera* camera)
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
}