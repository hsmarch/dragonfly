#pragma once

#include "Event.h"

/*
A specialized event that is broadcast at each step of the game loop
*/
namespace df {
  const std::string STEP_EVENT = "df::step";
  class EventStep : public Event {
    public:
      EventStep(); // ctor, default to step count of 0
      EventStep(int init_step_count); // ctor, with step count
      void setStepCount(int new_step_count); // update the step count
      int getStepCount() const; // return the step count

    private:
      int step_count;
  };
}
