#include "GameObject.h"
using namespace Core;

GameObject::GameObject()
:mEnabled(true), mVisible(true), mHandle(-1), mTransform(ZMath::CreateIdentity4x4())
{
	mComponentHandles[Component::COMPONENT_TYPE_MAX] = { 0 };
}

GameObject::GameObject(int id)
: mEnabled(true), mVisible(true), mHandle(id), mTransform(ZMath::CreateIdentity4x4())
{
	mComponentHandles[Component::COMPONENT_TYPE_MAX] = { 0 };
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