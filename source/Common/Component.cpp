#include "Component.h"
using namespace Core;

Component::Component() : mId(0), mAssigned(false)
{

}

Component::~Component()
{

}

const bool Component::IsAssigned() const
{
	return mAssigned;
}

void Component::Assign(const ComponentType componentType)
{
	mAssigned = true;
	mType = componentType;
}

const unsigned int Component::GetId() const
{
	return mId;
}

void Component::SetId(const unsigned int newId)
{
	mId = newId;
}

const Component::ComponentType Component::GetType() const
{
	return mType;
}

const int Component::GetObjectHandle() const
{
	return mObjectHandle;
}

void Component::AssignObjectHandle(const int objectHandle)
{
	mObjectHandle = objectHandle;
}