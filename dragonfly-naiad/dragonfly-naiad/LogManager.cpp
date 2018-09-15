//
// Dragonfly LogManager.cpp - Harrison March
//

//Engine Includes
#include "LogManager.h"

//System Includes
#include <stdarg.h>


df::LogManager::LogManager()
{
	do_flush = false;
	p_f = nullptr;
	setType("LogManager");
}

df::LogManager::~LogManager()
{
}

int df::LogManager::writeLog(const char* fmt, ...) const
{
	va_list args;
	va_start(args, fmt);
	vfprintf(p_f, fmt, args);
	va_end(args);
	if (do_flush)
	{
		fflush(p_f);
	}
	return 0;
}

df::LogManager& df::LogManager::getInstance()
{
	static LogManager l_mInstance;
	return l_mInstance;
}
#pragma warning (disable : 4996)
int df::LogManager::startUp()
{
	Manager::startUp();
	p_f = fopen(LOGFILE_NAME.c_str(), "w");
	return 0;
}

void df::LogManager::shutDown()
{
	fclose(p_f);
	Manager::shutDown();
}

void df::LogManager::setFlush(bool do_flush)
{
	this->do_flush = do_flush;
}
