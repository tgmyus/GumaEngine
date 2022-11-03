#pragma once

#ifdef GUMA_PLATFORM_WINDOWS
	#ifdef GUMA_BUILD_DLL
		#define GUMA_API __declspec(dllexport)
	#else
		#define GUMA_API __declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)

#include "Precompiled.h"

namespace Guma
{
	template<typename T, typename ... Args>
	constexpr std::unique_ptr<T> MakeUnique(Args&& ... InArgs)
	{
		return std::make_unique<T>(std::forward<Args>(InArgs)...);
	}
}
