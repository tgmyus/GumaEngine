#pragma once

#ifdef GUMA_PLATFORM_WINDOWS
	#ifdef GUMA_BUILD_DLL
		#define GUMA_API __declspec(dllexport)
	#else
		#define GUMA_API __declspec(dllimport)
	#endif
#endif
