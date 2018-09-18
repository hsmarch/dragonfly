#pragma once

#include <string>

/*
The event class defines a type event that objects can respond to
*/
namespace df {
  const std::string UNDEFINED_EVENT = "df::undefined";
  class Event {
      public:
        Event(); // ctor, sets type to UNDEFINED_EVENT type
        virtual ~Event(); // default implementation does nothing
        void setType(std::string new_event_type); // Set the event type
        std::string getType() const; // Return the event type

      private:
        std::string event_type;
  };
}
