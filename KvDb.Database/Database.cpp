// KvDb.Database.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Database.h"

Database::Database(const char *path)
{
	_path = new std::string(path);
}

Database::~Database()
{
	delete _path;
}
