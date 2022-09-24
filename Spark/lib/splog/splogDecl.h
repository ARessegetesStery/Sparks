#pragma once

#include "splogCore.h"

/* This files includes all the declarations for splog
 * Include this in all header files potentially will use splog
 * For the implementation, please include splog.h
 * */

namespace splog {

	class Logger
	{
	public:
		Logger(std::string name);
		~Logger();

		/* --- Setting up Logging types --- */
		template <typename... Args>
		void info(Args... params);

		template <typename... Args>
		void trace(Args... params);

		template <typename... Args>
		void warning(Args... params);

		template <typename... Args>
		void error(Args... params);

		template <typename... Args>
		void fatal(Args... params);
		/* -------------------------------- */

		//static std::shared_ptr<Logger> genLogger(std::string name);

		static std::shared_ptr<Logger> Logger::genLogger(std::string name)
		{
			std::shared_ptr<Logger> ptr(new Logger(name));
			return ptr;
		}

		void setLogFormat(std::string str);

		// Following are not for users

	private:
		std::string m_name;
		std::string m_fmtInfo;

		void spConfigLogFormat(LogType type, std::string& str, std::string& fmt);

		template <typename... Args>
		void genLog(LogType type, Args... params);

	};

	std::string spToString(std::string t);

	std::string spToString(char const* charArr);

	template<typename T>
	std::string spToString(T& t);

	std::string dispatchLogEvent(std::string str);

	template <typename T, typename... Args>
	std::string dispatchLogEvent(std::string str, const T& t, const Args&... params);

	template <typename T>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t);

	template <typename T, typename... Args>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t, const Args&... params);

	/* --- Setting up Logging types --- */
	template <typename... Args>
	void Logger::info(Args... params)
	{
		genLog(splog::LogType::Info, params...);
	}

	template <typename... Args>
	void Logger::trace(Args... params)
	{
		genLog(splog::LogType::Trace, params...);
	}

	template <typename... Args>
	void Logger::warning(Args... params)
	{
		genLog(splog::LogType::Warning, params...);
	}

	template <typename... Args>
	void Logger::error(Args... params)
	{
		genLog(splog::LogType::Error, params...);
	}

	template <typename... Args>
	void Logger::fatal(Args... params)
	{
		genLog(splog::LogType::Fatal, params...);
	}
	/* -------------------------------- */

	template <typename... Args>
	void Logger::genLog(LogType type, Args... params)
	{
		std::string strWParams = dispatchLogEvent(params...);
		spConfigLogFormat(type, strWParams, m_fmtInfo);
	}

	template <typename T, typename... Args>
	std::string dispatchLogEvent(std::string str, const T& t, const Args&... params)
	{
		dispatchLogEvent(str, 0, t, params...);
		return str;
	}

	template <typename T>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t)
	{
		std::string varSign = "{" + spToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
		{
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
			return;
		}
		str.replace(index, 3, spToString(t));
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spToString(t));
			else
				break;
		}
		dispatchLogEvent(str);
	}

	/* NOTE:
	 * multiple definition of function template will not cause LNK2005
	 * but multiple definition of non-template function will cause such linking error
	 * therefore here follows the implementation of the function templates
	 * */ 
	template <typename T, typename... Args>
	void dispatchLogEvent(std::string& str, int paramCnt, const T& t, const Args&... params)
	{
		std::string varSign = "{" + spToString(paramCnt) + "}";
		size_t index = str.find(varSign);
		if (index == std::string::npos)
		{
			dispatchLogEvent("[SYNTAX ERROR: FEWER MACHING PARAM] ORIGINAL: " + str);
			return;
		}
		str.replace(index, 3, spToString(t));
		while (true)
		{
			index = str.find(varSign, index + 1);
			if (index != std::string::npos)
				str.replace(index, 3, spToString(t));
			else
				break;
		}
		dispatchLogEvent(str, paramCnt + 1, params...);
	}

	template<typename T>
	std::string spToString(T& t)
	{
		const size_t code = typeid(t).hash_code();
		if (typeid(T).hash_code() == typeid(std::string).hash_code())
		{
			return spToString(t);
		}
		if (code == typeid(int).hash_code() || code == typeid(long long int).hash_code() ||
			code == typeid(unsigned int).hash_code() || code == typeid(unsigned long long int).hash_code() ||
			code == typeid(float).hash_code() || code == typeid(double).hash_code() ||
			code == typeid(long double).hash_code())
		{
			return std::to_string(t);
		}
		else if (strncmp(typeid(t).name(), "char const [", 12) == 0)
		{
			return spToString(t);
		}
		//else if (code == typeid(char).hash_code())
		//{
		//	std::string res(1, t);
		//	return res;
		//}
		else
		{
			return "_NOT_SUPPORTED_TYPE";
		}
	}
}