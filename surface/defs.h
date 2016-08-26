#pragma once

#undef LOG_TO_FILE

#include <sstream>
#include <iostream>
#ifdef LOG_TO_FILE
#include <iostream>
#include <fstream>
#else
#include <windows.h>
#endif


template<typename Arg, typename... Args>
typename std::enable_if<sizeof...(Args) == 0>::type _OutputDebug(std::stringstream& str, const Arg& arg, const Args&... args)
{
	str << arg;
}
template<typename Arg, typename... Args>
typename std::enable_if<sizeof...(Args) != 0>::type _OutputDebug(std::stringstream& str, const Arg& arg, const Args&... args)
{
	str << arg;
	_OutputDebug(str, args...);
}

#ifdef LOG_TO_FILE
inline std::ostream& _GetDebugStream()
{
	static std::ostream& _OutputFile = std::cout;
	_OutputFile.sync_with_stdio();
	return _OutputFile;
}
#endif

template<typename... Args>
void OutputDebug(const Args&... args)
{
	std::stringstream stream;
	_OutputDebug(stream, args...);

#ifdef LOG_TO_FILE
	static std::ostream& _OutputFile = _GetDebugStream();
	_OutputFile << stream.str();
#else
	OutputDebugStringA(stream.str().c_str());
#endif
}
