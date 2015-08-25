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
#include <string>

namespace Core
{
	class GameObject
	{
	public:
		GameObject();
		explicit GameObject(int id, const std::string& objectName);
		virtual ~GameObject();

		bool isEnabled();
		bool isVisible();

		void setEnabled(bool enable);
		void setVisible(bool visible);

		const std::string& GetName() const;
		const int GetHandle() const;
		const ZMath::Mat4x4& GetTransform() const;

		void AttachRenderable(unsigned int handle);

	protected:
		ZMath::Mat4x4 mTransform;
		int mComponentHandles[Component::COMPONENT_TYPE_MAX];

	private:
		bool mEnabled;
		bool mVisible;
		int mHandle;
		std::string mName;
	};
}
#endif
