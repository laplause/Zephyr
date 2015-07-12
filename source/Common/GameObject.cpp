#include "GameObject.h"
using namespace Core;

GameObject::GameObject()
:mEnabled(true), mVisible(true), mHandle(-1), mTransform(ZMath::CreateIdentity4x4())
{
	for (int i = 0; i < Component::COMPONENT_TYPE_MAX; i++)
	{
		mComponentHandles[i] = -1;
	}
}

GameObject::GameObject(int id, const std::string& objectName)
: mEnabled(true), mVisible(true), mHandle(id), mName(objectName), mTransform(ZMath::CreateIdentity4x4())
{
	for (int i = 0; i < Component::COMPONENT_TYPE_MAX; i++)
	{
		mComponentHandles[i] = -1;
	}
}

GameObject::~GameObject()
{

}

bool GameObject::isEnabled()
{
	return mEnabled;
}

bool GameObject::isVisible()
{
	return mVisible;
}

void GameObject::setEnabled(bool enable)
{
	mEnabled = enable;
}

void GameObject::setVisible(bool visible)
{
	mVisible = visible;
}

void GameObject::AttachRenderable(unsigned int handle)
{
	mComponentHandles[Component::RENDERABLE] = (int)handle;
}

const std::string& GameObject::GetName() const
{
	return mName;
}

const int GameObject::GetHandle() const
{
	return mHandle;
}

const ZMath::Mat4x4& GameObject::GetTransform() const
{
	return mTransform;
}