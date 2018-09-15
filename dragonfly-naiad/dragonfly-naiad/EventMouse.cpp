//
// Dragonfly EventMouse.cpp - Harrison March
//
#include "EventMouse.h"

df::EventMouse::EventMouse()
{
	setType(MOUSE_EVENT);
	mouse_action = UNDEFINED_MOUSE_ACTION;
	mouse_button = UNDEFINED_MOUSE_BUTTON;
	mouse_xy = Vector(-1, -1);
}

void df::EventMouse::setMouseButton(EventMouseButton new_mouse_button)
{
	mouse_button = new_mouse_button;
}

df::EventMouseButton df::EventMouse::getMouseButton() const
{
	return mouse_button;
}

void df::EventMouse::setMouseAction(EventMouseAction new_action)
{
	mouse_action = new_action;
}

df::EventMouseAction df::EventMouse::getMouseAction() const
{
	return mouse_action;
}

void df::EventMouse::setMousePosition(Vector new_mouse_xy)
{
	mouse_xy = new_mouse_xy;
}

df::Vector df::EventMouse::getMousePosition() const
{
	return mouse_xy;
}
