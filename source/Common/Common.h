///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	Common macros and functions that are used system wide in the Zephyr engine				     //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMMON_H
#define COMMON_H

#include "EngineState.h"

namespace Zephyr
{
#define ZEPHYR_DELETEOBJECT(object) if((object) != nullptr) {delete object; object = nullptr;}
#define ZEPHYR_DELETEOBJECTS(objects) if((objects) != nullptr) {delete[] objects; objects = nullptr;}
#define ZEPHYR_RELEASEOBJECT(object) if((object) != nullptr) {object->Release(); object = nullptr;}

#if defined WINDOWS
#define MULTI_LINE_MACRO_BEGIN do{
#define MULTI_LINE_MACRO_END \
	__pragma(warning(push)) \
	__pragma(warning(disable:4127)) \
    } while (0) \
	__pragma(warning(pop))
#endif
}

#endif