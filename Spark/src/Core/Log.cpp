#include "sppch.h"

#include "Log.h"
#include "lib/splog/splog.h"

namespace Spark {

	std::shared_ptr<splog::Logger> Log::s_CoreLogger;
	std::shared_ptr<splog::Logger> Log::s_AppLogger;

	void Log::Init()
	{
		s_CoreLogger = splog::Logger::genLogger("Spark");
		s_AppLogger = splog::Logger::genLogger("Sparkle");

		s_CoreLogger->setLogFormat("[||TIME||]||CSTR|| ||NAME||: ||LMSG|| ||CEND||");
		s_AppLogger->setLogFormat("[||TIME||]||CSTR|| ||NAME||: ||LMSG|| ||CEND||");
	}

}
