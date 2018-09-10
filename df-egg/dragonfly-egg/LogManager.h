#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

//System Includes
#include <stdio.h>

//Engine Includes
#include "Manager.h"

namespace df{
	const std::string LOGFILE_NAME = "DF_TEST.log";

	class LogManager : public df::Manager {

	private:
		LogManager();
		LogManager(LogManager const&);
		void operator = (LogManager const&);

		FILE *p_f;

	public:
		~LogManager();
		static LogManager &getInstance();
		int startUp();
		void shutDown();
		void setFlush(bool do_flush = true);
		int writeLog(const char *fmt, ...) const;
		bool do_flush;
	};
}

#endif