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
	return m_sInstance;
}