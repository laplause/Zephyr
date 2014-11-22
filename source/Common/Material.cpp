#include "Material.h"
#include "ZAssert.h"
#include "Common.h"
#include <fstream>
using namespace RenderCore;

Material::Material(const std::string& materialName) : mName(materialName), mpVertexShader(NULL), mpPixelShader(NULL), mpInputLayout(NULL)
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
	unsigned int vsFileSize = 0, psFileSize = 0;
	char* vsData = nullptr;
	char* psData = nullptr;

	shaderFileStream.open(vsFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		vsFileSize = (unsigned int)shaderFileStream.tellg();
		vsData = new char[vsFileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(&vsData[0], vsFileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreateVertexShader(vsData, vsFileSize, NULL, &mpVertexShader);
	}

	shaderFileStream.open(psFileName.c_str(), std::ifstream::in | std::ifstream::binary);
	if (shaderFileStream.good())
	{
		shaderFileStream.seekg(0, std::ios::end);
		psFileSize = (unsigned int)shaderFileStream.tellg();
		psData = new char[psFileSize];
		shaderFileStream.seekg(0, std::ios::beg);
		shaderFileStream.read(&psData[0], psFileSize);
		shaderFileStream.close();

		renderer->Direct3DDevice()->CreatePixelShader(psData, psFileSize, NULL, &mpPixelShader);
	}

	// Create the input layout description
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0  }
	};

	renderer->Direct3DDevice()->CreateInputLayout(ied, 2, vsData, vsFileSize, &mpInputLayout);

	DeleteObjects(vsData);
	DeleteObjects(psData);
}

ID3D11InputLayout* Material::GetInputLayout() const
{
	ZEPHYR_ASSERT(mpInputLayout != nullptr, "The input layout has not been initialized");
	return mpInputLayout;
}