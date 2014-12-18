#include "ModelManager.h"
using namespace RenderCore;

ModelManager *ModelManager::m_sInstance = nullptr;

ModelManager::ModelManager()
{

}

ModelManager::~ModelManager()
{

}

ModelManager* ModelManager::CreateInstance()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		m_sInstance = new ModelManager();

	return m_sInstance;
}

ModelManager* ModelManager::GetModelManager()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		return CreateInstance();
}

void ModelManager::AddModel(const std::string& modelName, Mesh* mesh)
{
	if (mesh != nullptr)
		meshTable[modelName] = mesh;
}

Mesh* ModelManager::GetModel(const std::string& modelName)
{
	if (meshTable.find(modelName) != meshTable.end() && meshTable.find(modelName)->second != nullptr)
		return meshTable[modelName];
	else
		return nullptr;
}