#pragma once


#ifdef LEM_PLATFORM_WINDOWS
	#ifdef LEM_BUILD_DLL
		#define LEMON_API __declspec(dllexport)
	#else
		#define LEMON_API __declspec(dllimport)
	#endif
#else
	#error Lemon only supports Windows!
#endif
