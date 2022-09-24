#pragma once

#ifdef _WIN32
	#include "Platform/Windows/splogWindowsConfig.h"
#elif __unix__

#elif __APPLE__

#elif __linux__

#endif

#include "splogLogger.h"

namespace splog {

	void Logger::spConfigLogFormat(LogType type, std::string& str, std::string& fmt)
	{
		size_t ind;
		std::string res;
		res = m_fmtInfo;
		ind = res.find("||NAME||");
		res.replace(ind, 8, m_name);
		ind = res.find("||LMSG||");
		res.replace(ind, 8, str);
		time_t current_time;
		struct tm* local_time;
		current_time = time(NULL);
		local_time = localtime(&current_time);
		std::string timeStr;
		std::string tHourStr = std::to_string(local_time->tm_hour);
		std::string tMinStr = std::to_string(local_time->tm_min);
		std::string tSecStr = std::to_string(local_time->tm_sec);
		if (local_time->tm_hour < 10)
			tHourStr = "0" + tHourStr;
		if (local_time->tm_min < 10)
			tMinStr = "0" + tMinStr;
		if (local_time->tm_sec < 10)
			tSecStr = "0" + tSecStr;
		timeStr = tHourStr + ":" + tMinStr + ":" + tSecStr;
		ind = res.find("||TIME||");
		res.replace(ind, 8, timeStr);
		size_t colorStart = res.find("||CSTR||");
		res.replace(colorStart, 8, "");
		size_t colorEnd = res.find("||CEND||");
		res.replace(colorEnd, 8, "");

		std::cout << res.substr(0, colorStart);
		spConfigLogColor(type);
		std::cout << res.substr(colorStart, colorEnd - colorStart);
		spResetLogColor();
		std::cout << res.substr(colorEnd) << std::endl;
	}

}