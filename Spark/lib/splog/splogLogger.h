#pragma once

#include "splogCore.h"
#include "splogDecl.h"

namespace splog {

	//template <typename... Args>
	//std::string dispatchLogEvent(Args... params);

	Logger::Logger(std::string name) : m_name(name) {   }

	Logger::~Logger() {  };

	//static std::shared_ptr<Logger> Logger::genLogger(std::string name)
	//{
	//	std::shared_ptr<Logger> ptr(new Logger(name));
	//	return ptr;
	//}

	void Logger::setLogFormat(std::string str)
	{
		m_fmtInfo = str;
	}

}