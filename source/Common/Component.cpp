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

void Component::Assign()
{
	mAssigned = true;
}

const unsigned int Component::GetId() const
{
	return mId;
}

void Component::SetId(const unsigned int newId)
{
	mId = newId;
}