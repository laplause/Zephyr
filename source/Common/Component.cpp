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

const unsigned int Component::GetId() const
{
	return mId;
}