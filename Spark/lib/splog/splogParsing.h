#pragma once

/* Uses {+num+} to represent the num-th variable in the coming variable list
 * TODO (not urgent) add "/+{" or "/+}" to make printing string "{0}" possible
 * Commented functions/declarations are in splogDecl.h
 * */

namespace splog {

	/* ---- Converting Possible Types to String ---- */
	std::string spToString(std::string t)
	{
		// uses pass-by-value to prevent infinite recurring
		return t;
	}

	std::string spToString(char const* charArr)
	{
		std::string res(charArr);
		return res;
	}

	/*template<typename T>
	std::string spToString(T& t);
	}*/
	/* --------------------------------------------- */

	/* --- Dispatching --- */
	// case 1
	std::string dispatchLogEvent(std::string str)
	{
		return str;
	}

	// case 2
	//template <typename T, typename... Args>
	//std::string dispatchLogEvent(std::string str, const T& t, const Args&... params)
	//{
	//	dispatchLogEvent(str, 0, t, params...);
	//	return str;
	//}
	/* ----------------- */

}