#include <time.h>
#include <stdio.h>

#include "Clock.h"

df::Clock::Clock() {
  previous_time = getCurrentTime();
}

long int df::Clock::delta() {
  auto current_time = getCurrentTime();
  if(current_time < 0) return -1;

  auto time_elapsed = current_time - previous_time;
  previous_time = current_time;

  return time_elapsed;
}

long int df::Clock::split() const {
  auto current_time = getCurrentTime();
  if(current_time < 0) return -1;
  return current_time - previous_time;
}

long int df::Clock::getCurrentTime() const {
  struct timespec current_time;
  if(clock_gettime(CLOCK_REALTIME, &current_time) < 0) {
    return -1;
  } else {
    return (current_time.tv_sec * 1000000) + (current_time.tv_nsec / 1000);
  }
}
