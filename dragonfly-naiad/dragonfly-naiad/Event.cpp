#include "Event.h"

df::Event::Event() {
  event_type = UNDEFINED_EVENT;
}

df::Event::~Event() {}

void df::Event::setType(std::string new_event_type) {
  event_type = new_event_type;
}

std::string df::Event::getType() const {
  return event_type;
}
