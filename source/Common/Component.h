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
		static enum ComponentType
		{
			RENDERABLE = 0,
			COMPONENT_TYPE_MAX
		};

		Component();
		virtual ~Component();

		const bool IsAssigned() const;
		void Assign(const ComponentType componentType);

		const unsigned int GetId() const;
		void SetId(const unsigned int newId);

		const ComponentType GetType() const;

	protected:
		unsigned int mId;
		ComponentType mType;
		bool mAssigned;
	};
}
#endif