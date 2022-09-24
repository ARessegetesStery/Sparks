#pragma once

#include "Core/Basics.h"

#include "lib/splog/splogDecl.h"

namespace Spark {

	class SPARK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<splog::Logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<splog::Logger>& getAppLogger() { return s_AppLogger; }

	private:
		static std::shared_ptr<splog::Logger> s_CoreLogger;
		static std::shared_ptr<splog::Logger> s_AppLogger;

	};

}

#define SP_CORE_LOG_INFO(...)    ::Spark::Log::getCoreLogger()->info(__VA_ARGS__);
#define SP_CORE_LOG_TRACE(...)   ::Spark::Log::getCoreLogger()->trace(__VA_ARGS__);
#define SP_CORE_LOG_WARNING(...) ::Spark::Log::getCoreLogger()->warning(__VA_ARGS__);
#define SP_CORE_LOG_ERROR(...)   ::Spark::Log::getCoreLogger()->error(__VA_ARGS__);
#define SP_CORE_LOG_FATAL(...)   ::Spark::Log::getCoreLogger()->fatal(__VA_ARGS__);

#define SP_LOG_INFO(...)         ::Spark::Log::getAppLogger()->info(__VA_ARGS__);
#define SP_LOG_TRACE(...)        ::Spark::Log::getAppLogger()->trace(__VA_ARGS__);
#define SP_LOG_WARNING(...)      ::Spark::Log::getAppLogger()->warning(__VA_ARGS__);
#define SP_LOG_ERROR(...)        ::Spark::Log::getAppLogger()->error(__VA_ARGS__);
#define SP_LOG_FATAL(...)        ::Spark::Log::getAppLogger()->fatal(__VA_ARGS__);

