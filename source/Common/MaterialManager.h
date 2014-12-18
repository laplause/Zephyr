///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a manager class that is used to interface with all the models that the engine will   //
//  contain. This manager will be created on engine start up and then it will load models into   //
//  the engine using data from a file.                                                           //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include <map>
#include <string>

namespace RenderCore
{
	class Material;

	class MaterialManager
	{
	public:
		~MaterialManager();
		static MaterialManager* CreateInstance();
		static MaterialManager* GetMaterialManager();
		void Shutdown();
		void AddMaterial(const std::string& materialName, Material* material);
		Material* GetMaterial(const std::string& materialName);

	private:
		MaterialManager();
		MaterialManager(const MaterialManager& rhs);
		MaterialManager& operator=(const MaterialManager& rhs);

		std::map<std::string, Material*> materialTable;
		static MaterialManager *m_sInstance;
	};
}
#endif