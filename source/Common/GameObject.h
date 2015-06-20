///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr game object it contains an array of component handles. //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include "ZMath.h"

namespace Core
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject(int id);
		virtual ~GameObject();

		bool isEnabled();
		bool isVisible();

		void setEnabled(bool enable);
		void setVisible(bool visible);

	protected:
		bool mEnabled;
		bool mVisible;
		int mHandle;
		unsigned int mComponentHandles[Component::COMPONENT_TYPE_MAX];
		ZMath::Mat4x4 mTransform;
	};
}
#endif
