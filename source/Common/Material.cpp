#include "Material.h"
#include "Common.h"
#include <fstream>
using namespace RenderCore;

Material::Material(const std::string& materialName) : mName(materialName), mpVertexShader(NULL), mpPixelShader(NULL), mpInputLayout(NULL),
mpVertexShaderByteCode(nullptr), mpPixelShaderByteCode(nullptr), mVertexShaderFileSize(0), mPixelShaderFileSize(0)
{

}

Material::~Material()
{
	ZEPHYR_RELEASEOBJECT(mpVertexShader);
	ZEPHYR_RELEASEOBJECT(mpPixelShader);
	ZEPHYR_RELEASEOBJECT(mpInputLayout);
}

void Material::Initialize(const std::string& vsFileName, const std::string& psFileName, DirectXRenderer* renderer)
{
	std::ifstream shaderFileStream;

	shaderFileStream.open(vsFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		mVertexShaderFileSize = (unsigned int)shaderFileStream.tellg();
		mpVertexShaderByteCode = new char[mVertexShaderFileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(mpVertexShaderByteCode, mVertexShaderFileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreateVertexShader(mpVertexShaderByteCode, mVertexShaderFileSize, NULL, &mpVertexShader);
	}

	shaderFileStream.open(psFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		mPixelShaderFileSize = (unsigned int)shaderFileStream.tellg();
		mpPixelShaderByteCode = new char[mPixelShaderFileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(mpPixelShaderByteCode, mPixelShaderFileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreatePixelShader(mpPixelShaderByteCode, mPixelShaderFileSize, NULL, &mpPixelShader);
	}
}

void Material::SetActiveShader(ID3D11DeviceContext* deviceContext)
{
	deviceContext->VSSetShader(mpVertexShader, NULL, 0);
	deviceContext->PSSetShader(mpPixelShader, NULL, 0);
}

void Material::SetShaderBuffers(ID3D11DeviceContext* deviceContext, Camera* camera)
{

}