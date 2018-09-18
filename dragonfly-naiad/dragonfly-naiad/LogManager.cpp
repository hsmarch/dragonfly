#include <stdarg.h>

#include "LogManager.h"

df::LogManager::LogManager() {
  setType("LogManager");
}

df::LogManager::~LogManager() {
  if(isStarted()) {
    shutDown();
  }
}

df::LogManager& df::LogManager::getInstance() {
  static LogManager log_manager;
  return log_manager;
}

int df::LogManager::startUp() {
  if(isStarted()) {
    std::fprintf(stderr, "Already logging!\n");
    return -1;
  }

  p_f = fopen(LOGFILE_NAME.c_str(), "w+");
  if(p_f == nullptr) {
    std::fprintf(stderr, "Cannot open logfile!\n");
    return -1;
  }

  Manager::startUp();
  writeLog("LogManager: LogManager successfully started\n");
  return 0;
}

void df::LogManager::shutDown() {
  if(p_f != nullptr) {
    fflush(p_f);
    fclose(p_f);
  }
  Manager::shutDown();
}

void df::LogManager::setFlush(bool do_flush) {
  LogManager::do_flush = do_flush;
}

int df::LogManager::writeLog(const char* fmt, ...) const {
  int success = 0;

  va_list args;
  va_start(args, fmt);
  success = vfprintf(p_f, fmt, args);
  va_end(args);

  if(do_flush && success >= 0) {
    success = fflush(p_f);
  }

  return success;
}
