///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is the base class for the Zephyr component it contains an Id and an assigned bool.      //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPONENT_H
#define COMPONENT_H

namespace Core
{
	//Abstract base class that defines a zephyr component.
	class Component
	{
	public:
		Component();
		virtual ~Component();

		const bool IsAssigned() const;
		const unsigned int GetId() const;

		virtual void Initialize() = 0;

	protected:
		unsigned int mId;
		bool mAssigned;
	};
}
#endif