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
		void Assign();
		const unsigned int GetId() const;
		void SetId(const unsigned int newId);

	protected:
		unsigned int mId;
		bool mAssigned;
	};
}
#endif