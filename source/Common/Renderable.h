///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a base class that defines a renderable. A renderable is a component that can be      //
//  referenced by an entity and is held and used by the renderer so that entities can be drawn.  //
//  entities that do not have a reference to a renderable will be invisible. Renderables contain //
//  a model and a material which should be set to an existing model and material contained in    //
//  their respective managers.                                                                   //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Component.h"
#include <string>

namespace RenderCore
{
	class Material;
	class Mesh;

	class Renderable : public Core::Component
	{
	public:
		Renderable();
		virtual ~Renderable();

		virtual void Initialize(const std::string& meshName, const std::string& materialName);

	protected:
		Material* mMaterial;
		Mesh* mMesh;
	};
}
#endif