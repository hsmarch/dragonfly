#pragma once

#include <stdio.h>

# include "Manager.h"

/*
A manager that handles writing logs to a file
*/
namespace df {
  const std::string LOGFILE_NAME = "dragonfly-log.txt";

  class LogManager : public Manager {
    public:
      ~LogManager();
      static LogManager& getInstance();
      int startUp(); // Starts the manager (returns 0 for success, -1 for error)
      void shutDown(); // Stops the manager
      void setFlush(bool do_flush=true); // Sets whether or not the log should be flushed every write
      int writeLog(const char* fmt, ...) const; // Writes a message to log, arguments like printf (returns 0 for success, -1 for error)

    private:
      LogManager();
      LogManager(LogManager const&);
      void operator=(LogManager const&);
      bool do_flush;
      FILE *p_f;
  };
}
