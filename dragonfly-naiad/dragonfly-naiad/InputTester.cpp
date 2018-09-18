#include "GameManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "EventMouse.h"
#include "Object.h"

//An object the prints when events are received
class InputTestObj : public df::Object {
  public:
    std::string pressed = "No key pressed yet";
    std::string mouse_button = "No mouse button pressed yet";
    std::string mouse_pos = "Mouse not moved yet";

    void draw() {
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 10), "Last key event was:", df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 11), pressed, df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 12), mouse_button, df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 13), mouse_pos, df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 23), "backspace to quit", df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
    }

    int eventHandler(const df::Event* p_e) {
      if(p_e->getType() == "df::keyboard") {
        df::Keyboard::Key key = (dynamic_cast <const df::EventKeyboard*> (p_e))->getKey();
        df::EventKeyboardAction action = (dynamic_cast <const df::EventKeyboard*> (p_e))->getKeyboardAction();

        std::string action_str;
        switch (action) {
          case df::EventKeyboardAction::UNDEFINED_KEYBOARD_ACTION: action_str = "UNDEFINED_KEYBOARD_ACTION"; break;
          case df::EventKeyboardAction::KEY_PRESSED: action_str = "KEY_PRESSED"; break;
          case df::EventKeyboardAction::KEY_RELEASED: action_str = "KEY_RELEASED"; break;
          case df::EventKeyboardAction::KEY_DOWN: action_str = "KEY_DOWN"; break;
        }
        std::string key_str;
        switch (key) {
          case df::Keyboard::Key::UNDEFINED_KEY: key_str = "Key UNDEFINED_KEY"; break;
          case df::Keyboard::Key::SPACE: key_str = "Key SPACE"; break;
          case df::Keyboard::Key::RETURN: key_str = "Key RETURN"; break;
          case df::Keyboard::Key::ESCAPE: key_str = "Key ESCAPE"; break;
          case df::Keyboard::Key::TAB: key_str = "Key TAB"; break;
          case df::Keyboard::Key::LEFTARROW: key_str = "Key LEFTARROW"; break;
          case df::Keyboard::Key::RIGHTARROW: key_str = "Key RIGHTARROW"; break;
          case df::Keyboard::Key::UPARROW: key_str = "Key UPARROW"; break;
          case df::Keyboard::Key::DOWNARROW: key_str = "Key DOWNARROW"; break;
          case df::Keyboard::Key::PAUSE: key_str = "Key PAUSE"; break;
          case df::Keyboard::Key::MINUS: key_str = "Key MINUS"; break;
          case df::Keyboard::Key::PLUS: key_str = "Key PLUS"; break;
          case df::Keyboard::Key::TILDE: key_str = "Key TILDE"; break;
          case df::Keyboard::Key::PERIOD: key_str = "Key PERIOD"; break;
          case df::Keyboard::Key::COMMA: key_str = "Key COMMA"; break;
          case df::Keyboard::Key::SLASH: key_str = "Key SLASH"; break;
          case df::Keyboard::Key::BACKSLASH: key_str = "Key BACKSLASH"; break;
          case df::Keyboard::Key::MULTIPLY: key_str = "Key MULTIPLY"; break;
          case df::Keyboard::Key::QUOTE: key_str = "Key QUOTE"; break;
          case df::Keyboard::Key::SEMICOLON: key_str = "Key SEMICOLON"; break;
          case df::Keyboard::Key::LEFTCONTROL: key_str = "Key LEFTCONTROL"; break;
          case df::Keyboard::Key::RIGHTCONTROL: key_str = "Key RIGHTCONTROL"; break;
          case df::Keyboard::Key::LEFTSHIFT: key_str = "Key LEFTSHIFT"; break;
          case df::Keyboard::Key::RIGHTSHIFT: key_str = "Key RIGHTSHIFT"; break;
          case df::Keyboard::Key::F1: key_str = "Key F1"; break;
          case df::Keyboard::Key::F2: key_str = "Key F2"; break;
          case df::Keyboard::Key::F3: key_str = "Key F3"; break;
          case df::Keyboard::Key::F4: key_str = "Key F4"; break;
          case df::Keyboard::Key::F5: key_str = "Key F5"; break;
          case df::Keyboard::Key::F6: key_str = "Key F6"; break;
          case df::Keyboard::Key::F7: key_str = "Key F7"; break;
          case df::Keyboard::Key::F8: key_str = "Key F8"; break;
          case df::Keyboard::Key::F9: key_str = "Key F9"; break;
          case df::Keyboard::Key::F10: key_str = "Key F10"; break;
          case df::Keyboard::Key::F11: key_str = "Key F11"; break;
          case df::Keyboard::Key::F12: key_str = "Key F12"; break;
          case df::Keyboard::Key::A: key_str = "Key A"; break;
          case df::Keyboard::Key::B: key_str = "Key B"; break;
          case df::Keyboard::Key::C: key_str = "Key C"; break;
          case df::Keyboard::Key::D: key_str = "Key D"; break;
          case df::Keyboard::Key::E: key_str = "Key E"; break;
          case df::Keyboard::Key::F: key_str = "Key F"; break;
          case df::Keyboard::Key::G: key_str = "Key G"; break;
          case df::Keyboard::Key::H: key_str = "Key H"; break;
          case df::Keyboard::Key::I: key_str = "Key I"; break;
          case df::Keyboard::Key::J: key_str = "Key J"; break;
          case df::Keyboard::Key::K: key_str = "Key K"; break;
          case df::Keyboard::Key::L: key_str = "Key L"; break;
          case df::Keyboard::Key::M: key_str = "Key M"; break;
          case df::Keyboard::Key::N: key_str = "Key N"; break;
          case df::Keyboard::Key::O: key_str = "Key O"; break;
          case df::Keyboard::Key::P: key_str = "Key P"; break;
          case df::Keyboard::Key::Q: key_str = "Key Q"; break;
          case df::Keyboard::Key::R: key_str = "Key R"; break;
          case df::Keyboard::Key::S: key_str = "Key S"; break;
          case df::Keyboard::Key::T: key_str = "Key T"; break;
          case df::Keyboard::Key::U: key_str = "Key U"; break;
          case df::Keyboard::Key::V: key_str = "Key V"; break;
          case df::Keyboard::Key::W: key_str = "Key W"; break;
          case df::Keyboard::Key::X: key_str = "Key X"; break;
          case df::Keyboard::Key::Y: key_str = "Key Y"; break;
          case df::Keyboard::Key::Z: key_str = "Key Z"; break;
          case df::Keyboard::Key::NUM1: key_str = "Key NUM1"; break;
          case df::Keyboard::Key::NUM2: key_str = "Key NUM2"; break;
          case df::Keyboard::Key::NUM3: key_str = "Key NUM3"; break;
          case df::Keyboard::Key::NUM4: key_str = "Key NUM4"; break;
          case df::Keyboard::Key::NUM5: key_str = "Key NUM5"; break;
          case df::Keyboard::Key::NUM6: key_str = "Key NUM6"; break;
          case df::Keyboard::Key::NUM7: key_str = "Key NUM7"; break;
          case df::Keyboard::Key::NUM8: key_str = "Key NUM8"; break;
          case df::Keyboard::Key::NUM9: key_str = "Key NUM9"; break;
          case df::Keyboard::Key::NUM0: key_str = "Key NUM0"; break;
          case df::Keyboard::Key::BACKSPACE: df::GameManager::getInstance().setGameOver(true); break;
        }

        pressed = key_str + " was " + action_str;
      }

      if(p_e->getType() == "df::mouse") {
        df::EventMouseButton button = (dynamic_cast <const df::EventMouse*> (p_e))->getMouseButton();
        df::EventMouseAction action = (dynamic_cast <const df::EventMouse*> (p_e))->getMouseAction();
        df::Vector pos = (dynamic_cast <const df::EventMouse*> (p_e))->getMousePosition();

        std::string button_str;
        switch (button) {
          case df::EventMouseButton::UNDEFINED_MOUSE_BUTTON: button_str = "undefined button"; break;
          case df::EventMouseButton::LEFT: button_str = "left button"; break;
          case df::EventMouseButton::RIGHT: button_str = "right button"; break;
          case df::EventMouseButton::MIDDLE: button_str = "middle button"; break;
        }

        std::string action_str;
        switch (action) {
          case df::EventMouseAction::UNDEFINED_MOUSE_ACTION: action_str = "undefined action"; break;
          case df::EventMouseAction::CLICKED: action_str = "clicked"; break;
          case df::EventMouseAction::PRESSED: action_str = "pressed"; break;
          case df::EventMouseAction::MOVED: action_str = "moved"; break;
        }

        if(action == df::EventMouseAction::MOVED) {
          mouse_pos = action_str + " to " + "(" + std::to_string(pos.getX()) + ", " + std::to_string(pos.getY()) + ")";
        } else {
          mouse_button = button_str + " " + action_str;
        }
      }

      return 0;
    }
};
