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
#define DeleteObject(object) if((object) != NULL) {delete object; object = NULL;}
#define DeleteObjects(objects) if((objects) != NULL) {delete[] objects; objects = NULL;}
#define ReleaseObject(object) if((object) != NULL) {object->Release(); object = NULL;}

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