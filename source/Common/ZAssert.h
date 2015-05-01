///////////////////////////////////////////////////////////////////////////////////////////////////
//	Author: Christopher Sosa																	 //
//																								 //
//	Custom assert macros and functions for handling errors.				                         //
//  Inspiration from Jason Gregory's Game Engine Architecture and                                //
//  http://cnicholson.net/2009/02/stupid-c-tricks-adventures-in-assert/                          //
//                                                                                               //
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef ZASSERT_H
#define ZASSERT_H

#include "Common.h"
#include <string>
#include <windows.h>

namespace ZAssert
{
	static inline void ReportFailure(const char* condition, const char* fileName, int line, const char* msg);

#if defined WINDOWS
#define ZEPHYR_HALT() __debugbreak();
#endif

#ifdef ASSERTS_ENABLED
#define ZEPHYR_ASSERT(condition, message) \
	MULTI_LINE_MACRO_BEGIN \
		if (!(condition)) \
		{ \
		ZAssert::ReportFailure(#condition, __FILE__, __LINE__, message); \
			ZEPHYR_HALT(); \
		} \
	MULTI_LINE_MACRO_END
#else
#define ZEPHYR_ASSERT(condition) \
	do { (void)sizeof(condition); } while(0)
#endif

	static inline void ReportFailure(const char* condition, const char* fileName, int line, const char* msg)
	{
		char errorMessage[1024] = {0};
		char lineNumber[6] = { 0 };
		_itoa_s(line, lineNumber, sizeof(lineNumber), 10);
		memcpy(errorMessage, fileName, sizeof(errorMessage));
		strcat_s(errorMessage, sizeof(errorMessage), "\n");
		strcat_s(errorMessage, sizeof(errorMessage), "line: ");
		strcat_s(errorMessage, sizeof(errorMessage), lineNumber);
		strcat_s(errorMessage, sizeof(errorMessage), "\n");
		strcat_s(errorMessage, sizeof(errorMessage), msg);
		MessageBox(NULL, errorMessage, condition, MB_OK);
	}
}
#endif