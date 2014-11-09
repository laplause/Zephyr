///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a Model class for holding a vector of meshes that makes up a model.                  //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

namespace RenderCore
{
	class Mesh;

	class Model
	{
	public:
		Model(const std::string& name);
		~Model();

		void LoadModel(const std::string& modelFileName);

	private:
		void CreateMesh();

		std::vector<Mesh*> mMeshes;
		std::string mName;
	};
}
#endif