///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a manager class that is used to interface with all the models that the engine will   //
//  contain. This manager will be created on engine start up and then it will load models into   //
//  the engine using data from a file.                                                           //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <map>
#include <string>

namespace RenderCore
{
	class Mesh;

	class ModelManager
	{
	public:
		~ModelManager();
		static ModelManager* CreateInstance();
		static ModelManager* GetModelManager();
		void Shutdown();
		void AddModel(const std::string& modelName, Mesh* mesh);
		Mesh* GetModel(const std::string& modelName);

	private:
		// Hide the constructors since this is a singleton.
		ModelManager();
		ModelManager(const ModelManager& rhs);
		ModelManager& operator=(const ModelManager& rhs);

		std::map<std::string, Mesh*> meshTable;
		static ModelManager *m_sInstance;
	};
}
#endif