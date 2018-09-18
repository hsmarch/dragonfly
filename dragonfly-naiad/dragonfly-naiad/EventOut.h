#pragma once

#include "Event.h"

/*
A specialized event that is broadcast when an object leaves the screen
*/
namespace df {
  const std::string OUT_EVENT = "df::out";
  class EventOut : public Event {
    public:
      EventOut();
  };
}
