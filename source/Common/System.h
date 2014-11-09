///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	This is a base System that contains the methods that all systems in the zephyr engine use.   //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SYSTEM_H
#define SYSTEM_H

namespace Core
{
	//Abstract base class that defines a zephyr system.
	class System
	{
	public:
		System();
		virtual ~System();

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
	};
}
#endif