#include "MaterialManager.h"
using namespace RenderCore;

MaterialManager *MaterialManager::m_sInstance = nullptr;

MaterialManager::MaterialManager()
{

}

MaterialManager::~MaterialManager()
{

}

MaterialManager* MaterialManager::CreateInstance()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		m_sInstance = new MaterialManager();

	return m_sInstance;
}

MaterialManager* MaterialManager::GetMaterialManager()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		return CreateInstance();
}

void MaterialManager::AddMaterial(const std::string& materialName, Material* material)
{
	if (material != nullptr)
		materialTable[materialName] = material;
}

Material* MaterialManager::GetMaterial(const std::string& materialName)
{
	if (materialTable.find(materialName) != materialTable.end())
		return materialTable[materialName];
	else
		return nullptr;
}