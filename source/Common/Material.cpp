#include "Material.h"
#include "ZAssert.h"
#include "Common.h"
#include <fstream>
using namespace RenderCore;

Material::Material(const std::string& materialName) : mName(materialName), mpVertexShader(NULL), mpPixelShader(NULL), mpInputLayout(NULL),
mpVertexShaderBlob(nullptr), mpPixelShaderBlob(nullptr)
{

}

Material::~Material()
{
	ReleaseObject(mpVertexShader);
	ReleaseObject(mpPixelShader);
	ReleaseObject(mpInputLayout);
}

void Material::Initialize(const std::string& vsFileName, const std::string& psFileName, DirectXRenderer* renderer)
{
	std::ifstream shaderFileStream;
	mpVertexShaderBlob = new ShaderBlob();
	mpPixelShaderBlob = new ShaderBlob();

	shaderFileStream.open(vsFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		mpVertexShaderBlob->fileSize = (unsigned int)shaderFileStream.tellg();
		mpVertexShaderBlob->shaderData = new char[mpVertexShaderBlob->fileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(&(mpVertexShaderBlob->shaderData[0]), mpVertexShaderBlob->fileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreateVertexShader(mpVertexShaderBlob->shaderData, mpVertexShaderBlob->fileSize, NULL, &mpVertexShader);
	}

	shaderFileStream.open(psFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		mpPixelShaderBlob->fileSize = (unsigned int)shaderFileStream.tellg();
		mpPixelShaderBlob->shaderData = new char[mpPixelShaderBlob->fileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(&mpPixelShaderBlob->shaderData[0], mpPixelShaderBlob->fileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreatePixelShader(mpPixelShaderBlob->shaderData, mpPixelShaderBlob->fileSize, NULL, &mpPixelShader);
	}
}

ID3D11InputLayout* Material::GetInputLayout() const
{
	ZEPHYR_ASSERT(mpInputLayout != nullptr, "The input layout has not been initialized");
	return mpInputLayout;
}

Material::ShaderBlob::ShaderBlob() : shaderData(nullptr), fileSize(0)
{

}

Material::ShaderBlob::~ShaderBlob()
{
	DeleteObjects(shaderData);
}