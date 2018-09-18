#pragma once

#include "Event.h"
#include "Vector.h"

/*
A specialized event that is broadcast when an object leaves the screen
*/
namespace df {
  const std::string MOUSE_EVENT = "df::mouse";

  enum EventMouseAction {
    UNDEFINED_MOUSE_ACTION = -1,
    CLICKED,
    PRESSED,
    MOVED,
  };

  enum EventMouseButton {
    UNDEFINED_MOUSE_BUTTON = -1,
    LEFT,
    RIGHT,
    MIDDLE,
  };

  class EventMouse : public Event {
    public:
      EventMouse();
      void setMouseButton(EventMouseButton new_mouse_button);
      EventMouseButton getMouseButton() const;
      void setMouseAction(EventMouseAction new_action);
      EventMouseAction getMouseAction() const;
      void setMousePosition(Vector new_mouse_xy);
      Vector getMousePosition() const;
    private:
      EventMouseButton mouse_button;
      EventMouseAction mouse_action;
      Vector mouse_xy;
  };
}
