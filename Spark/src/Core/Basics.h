#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPARK_API __declspec(dllexport)
	#else
		#define SPARK_API __declspec(dllimport)
	#endif
#else
	#error Sparks only supports Windows!
#endif

#ifdef SP_ASSERT_ENABLED
	#define SP_CORE_ASSERT(x, ...) \
		if (!(x)) \
		{\
			SP_CORE_LOG_ERROR("Assertion failed: {0}", __VA_ARGS__);\
			__debugbreak();\
		}
	#define SP_ASSERT(x, ...) \
		if (!(x)) \
		{\
			SP_LOG_ERROR("Assertion failed: {0}", __VA_ARGS__); \
			__debugbreak(); \
		}
#else
	#define SP_CORE_ASSERT(x, ...)
	#define SP_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)