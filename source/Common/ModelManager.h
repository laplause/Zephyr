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

namespace RenderCore
{
	class ModelManager
	{
	public:
		~ModelManager();
		static ModelManager* CreateInstance();
		static ModelManager* GetModelManager();
		void Shutdown();

	private:
		// Hide the constructor since this is a singleton.
		ModelManager();

		static ModelManager *m_sInstance;
	};
}
#endif