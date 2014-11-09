#include "Material.h"
#include "Common.h"
using namespace RenderCore;

Material::Material(const std::string& materialName) : mName(materialName), mpVertexShader(NULL), mpPixelShader(NULL), mpInputLayout(NULL)
{

}

Material::~Material()
{
	DeleteObject(mpVertexShader);
	DeleteObject(mpPixelShader);
	DeleteObject(mpInputLayout);
}

void Material::Initialize(const std::string& vsFileName, const std::string& psFileName)
{

}