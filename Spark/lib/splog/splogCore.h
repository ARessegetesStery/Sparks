#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <ctime>

namespace splog {

	enum LogType
	{
		Trace = 0,
		Info = 1,
		Warning = 2,
		Error = 3,
		Fatal = 4
	};

}