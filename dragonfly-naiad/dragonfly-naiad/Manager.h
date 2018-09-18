#pragma once

#include <string.h>

#include "Event.h"

/*
A generalized manager. Most should be singletons
*/
namespace df {
  class Manager {
    public:
      Manager();
      virtual ~Manager();
      std::string getType() const; // Returns the manager type
      virtual int startUp(); // Starts the manager (returns 0 for success, -1 for error)
      virtual void shutDown(); // Stops the manager
      bool isStarted() const; // Returns whether or not the manager is started
      int onEvent(const Event* p_event) const; //Does thing when an event is fired.

    protected:
      void setType(std::string type);

    private:
      std::string type;
      bool is_started;
  };
}
