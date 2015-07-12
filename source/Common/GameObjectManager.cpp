#include "GameObjectManager.h"
using namespace Core;

GameObjectManager *GameObjectManager::m_sInstance = nullptr;

GameObjectManager::GameObjectManager() : mGameObjectTable(20)
{

}

GameObjectManager::~GameObjectManager()
{

}

GameObjectManager* GameObjectManager::CreateInstance()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		m_sInstance = new GameObjectManager();

	return m_sInstance;
}

GameObjectManager* GameObjectManager::GetGameObjectManager()
{
	if (m_sInstance != nullptr)
		return m_sInstance;
	else
		return CreateInstance();
}

void GameObjectManager::AddGameObject(const unsigned int index, GameObject* gameObject)
{
	if (gameObject != nullptr)
		mGameObjectTable[index] = gameObject;
}

GameObject* GameObjectManager::GetGameObject(const unsigned int index)
{
	if (mGameObjectTable[index] != nullptr)
		return mGameObjectTable[index];
	else
		return nullptr;
}