#pragma once

#ifdef _WIN32

#include <windows.h>

namespace splog {

	extern LogType;

	void spConfigLogColor(LogType type)
	{
		HANDLE hWinConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		switch (type)
		{
		case splog::LogType::Info:       // white
			SetConsoleTextAttribute(hWinConsole, 7);
			break;
		case splog::LogType::Trace:      // green
			SetConsoleTextAttribute(hWinConsole, 2);
			break;
		case splog::LogType::Warning:    // yellow
			SetConsoleTextAttribute(hWinConsole, 6);
			break;
		case splog::LogType::Error:      // red
			SetConsoleTextAttribute(hWinConsole, 4);
			break;
		case splog::LogType::Fatal:      // purple
			SetConsoleTextAttribute(hWinConsole, 5);
			break;
		}
	}

	void spResetLogColor()
	{
		HANDLE hWinConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hWinConsole, 7);
	}

}

#endif