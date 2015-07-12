///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a manager class that is used to interface with all the models that the engine will   //
//  contain. This manager will be created on engine start up and then it will load models into   //
//  the engine using data from a file.                                                           //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include <vector>
#include <string>

namespace Core
{
	class GameObject;

	class GameObjectManager
	{
	public:
		~GameObjectManager();
		static GameObjectManager* CreateInstance();
		static GameObjectManager* GetGameObjectManager();
		void Shutdown();
		void AddGameObject(const unsigned int index, GameObject* gameObject);
		GameObject* GetGameObject(const unsigned int index);

	private:
		GameObjectManager();
		GameObjectManager(const GameObjectManager& rhs);
		GameObjectManager& operator=(const GameObjectManager& rhs);

		std::vector<GameObject*> mGameObjectTable;
		static GameObjectManager *m_sInstance;
	};
}
#endif