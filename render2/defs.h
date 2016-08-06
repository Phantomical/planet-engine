#pragma once

#include <sstream>
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

inline std::ofstream& _GetDebugStream()
{
	static std::ofstream _OutputFile = std::ofstream("log.txt");
	_OutputFile.sync_with_stdio();
	return _OutputFile;
}

template<typename... Args>
void OutputDebug(const Args&... args)
{
	std::stringstream stream;
	_OutputDebug(stream, args...);

#ifdef LOG_TO_FILE
	static std::ofstream& _OutputFile = std::ofstream("log.txt");
	_OutputFile << stream.str();
#else
	OutputDebugStringA(stream.str().c_str());
#endif
}
