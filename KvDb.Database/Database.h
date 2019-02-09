#pragma once

#include <string>

#ifdef KVDBDATABASE_EXPORTS
#define KVDBEXPORT __declspec(dllexport)
#else
#define KVDBEXPORT __declspec(dllimport)
#endif

class KVDBEXPORT Database
{
public:
	Database(const char *path);
	~Database();

private:
	std::string *_path;
};