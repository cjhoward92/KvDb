#pragma once

#include <string>

#ifdef KVDBINTERPRETER_EXPORTS
#define KVDBINTERPRETER_API __declspec(dllexport)
#else
#define KVDBINTERPRETER_API __declspec(dllimport)
#endif

class KvInterpreter
{
public:
	KvInterpreter();
	~KvInterpreter();

	void Parse(std::string const& input);

private:
	std::string _input;
};