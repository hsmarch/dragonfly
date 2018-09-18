#include "InputManager.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

df::InputManager::InputManager() {
  setType("InputManager");
}

df::InputManager& df::InputManager::getInstance() {
  static InputManager input_manager;
  return input_manager;
}

int df::InputManager::startUp() {
  if(!df::GraphicsManager::getInstance().isStarted() ||
     !df::WorldManager::getInstance().isStarted()) {
       df::LogManager::getInstance().writeLog("InputManager: One or more dependant managers are not started\n");
       return -1;
  }

  p_window = df::GraphicsManager::getInstance().getWindow();
  p_window->setKeyRepeatEnabled(false);
  Manager::startUp();
  df::LogManager::getInstance().writeLog("IInputManager: nput manager succesfully started\n");
  return 0;
}

void df::InputManager::shutDown() {
  p_window = nullptr;
  Manager::shutDown();
}

df::Keyboard::Key sfmlKeyToDfKey(sf::Keyboard::Key);
void df::InputManager::getInput() {
  sf::Event event;

  while (p_window->pollEvent(event)) {
    if(event.type == sf::Event::KeyPressed) {
      EventKeyboard e;
      e.setKeyboardAction(df::EventKeyboardAction::KEY_PRESSED);
      e.setKey(sfmlKeyToDfKey(event.key.code));
      onEvent(&e);
    }

    if(event.type == sf::Event::KeyReleased) {
      EventKeyboard e;
      e.setKeyboardAction(df::EventKeyboardAction::KEY_RELEASED);
      e.setKey(sfmlKeyToDfKey(event.key.code));
      onEvent(&e);
    }

    if(event.type == sf::Event::MouseMoved) {
      EventMouse e;
      e.setMouseAction(df::EventMouseAction::MOVED);
      e.setMousePosition(Vector(event.mouseMove.x, event.mouseMove.y));
      onEvent(&e);
    }
  }

  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    EventMouse e;
    e.setMouseAction(df::EventMouseAction::PRESSED);
    e.setMouseButton(df::EventMouseButton::LEFT);
    onEvent(&e);
  }
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
    EventMouse e;
    e.setMouseAction(df::EventMouseAction::PRESSED);
    e.setMouseButton(df::EventMouseButton::RIGHT);
    onEvent(&e);
  }
  if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
    EventMouse e;
    e.setMouseAction(df::EventMouseAction::PRESSED);
    e.setMouseButton(df::EventMouseButton::MIDDLE);
    onEvent(&e);
  }
}

//Monster switch to convert between SFML and DF key types
df::Keyboard::Key sfmlKeyToDfKey(sf::Keyboard::Key e) {
  switch(e) {
    case sf::Keyboard::Key::Space:
      return df::Keyboard::Key::SPACE;
    case sf::Keyboard::Key::Return:
      return df::Keyboard::Key::RETURN;
    case sf::Keyboard::Key::Escape:
      return df::Keyboard::Key::ESCAPE;
    case sf::Keyboard::Key::Tab:
      return df::Keyboard::Key::TAB;
    case sf::Keyboard::Key::Left:
      return df::Keyboard::Key::LEFTARROW;
    case sf::Keyboard::Key::Right:
      return df::Keyboard::Key::RIGHTARROW;
    case sf::Keyboard::Key::Up:
      return df::Keyboard::Key::UPARROW;
    case sf::Keyboard::Key::Down:
      return df::Keyboard::Key::DOWNARROW;
    case sf::Keyboard::Key::Pause:
      return df::Keyboard::Key::PAUSE;
    case sf::Keyboard::Key::Dash:
      return df::Keyboard::Key::MINUS;
    case sf::Keyboard::Key::Equal:
      return df::Keyboard::Key::PLUS;
    case sf::Keyboard::Key::Tilde:
      return df::Keyboard::Key::TILDE;
    case sf::Keyboard::Key::Period:
      return df::Keyboard::Key::PERIOD;
    case sf::Keyboard::Key::Comma:
      return df::Keyboard::Key::COMMA;
    case sf::Keyboard::Key::Slash:
      return df::Keyboard::Key::SLASH;
    case sf::Keyboard::Key::BackSlash:
      return df::Keyboard::Key::BACKSLASH;
    case sf::Keyboard::Key::Multiply:
      return df::Keyboard::Key::MULTIPLY;
    case sf::Keyboard::Key::Quote:
      return df::Keyboard::Key::QUOTE;
    case sf::Keyboard::Key::SemiColon:
      return df::Keyboard::Key::SEMICOLON;
    case sf::Keyboard::Key::LControl:
      return df::Keyboard::Key::LEFTCONTROL;
    case sf::Keyboard::Key::RControl:
      return df::Keyboard::Key::RIGHTCONTROL;
    case sf::Keyboard::Key::LShift:
      return df::Keyboard::Key::LEFTSHIFT;
    case sf::Keyboard::Key::RShift:
      return df::Keyboard::Key::RIGHTSHIFT;
    case sf::Keyboard::Key::F1:
      return df::Keyboard::Key::F1;
    case sf::Keyboard::Key::F2:
      return df::Keyboard::Key::F2;
    case sf::Keyboard::Key::F3:
      return df::Keyboard::Key::F3;
    case sf::Keyboard::Key::F4:
      return df::Keyboard::Key::F4;
    case sf::Keyboard::Key::F5:
      return df::Keyboard::Key::F5;
    case sf::Keyboard::Key::F6:
      return df::Keyboard::Key::F6;
    case sf::Keyboard::Key::F7:
      return df::Keyboard::Key::F7;
    case sf::Keyboard::Key::F8:
      return df::Keyboard::Key::F8;
    case sf::Keyboard::Key::F9:
      return df::Keyboard::Key::F9;
    case sf::Keyboard::Key::F10:
      return df::Keyboard::Key::F10;
    case sf::Keyboard::Key::F11:
      return df::Keyboard::Key::F11;
    case sf::Keyboard::Key::F12:
      return df::Keyboard::Key::F12;
    case sf::Keyboard::Key::A:
      return df::Keyboard::Key::A;
    case sf::Keyboard::Key::B:
      return df::Keyboard::Key::B;
    case sf::Keyboard::Key::C:
      return df::Keyboard::Key::C;
    case sf::Keyboard::Key::D:
      return df::Keyboard::Key::D;
    case sf::Keyboard::Key::E:
      return df::Keyboard::Key::E;
    case sf::Keyboard::Key::F:
      return df::Keyboard::Key::F;
    case sf::Keyboard::Key::G:
      return df::Keyboard::Key::G;
    case sf::Keyboard::Key::H:
      return df::Keyboard::Key::H;
    case sf::Keyboard::Key::I:
      return df::Keyboard::Key::I;
    case sf::Keyboard::Key::J:
      return df::Keyboard::Key::J;
    case sf::Keyboard::Key::K:
      return df::Keyboard::Key::K;
    case sf::Keyboard::Key::L:
      return df::Keyboard::Key::L;
    case sf::Keyboard::Key::M:
      return df::Keyboard::Key::M;
    case sf::Keyboard::Key::N:
      return df::Keyboard::Key::N;
    case sf::Keyboard::Key::O:
      return df::Keyboard::Key::O;
    case sf::Keyboard::Key::P:
      return df::Keyboard::Key::P;
    case sf::Keyboard::Key::Q:
      return df::Keyboard::Key::Q;
    case sf::Keyboard::Key::R:
      return df::Keyboard::Key::R;
    case sf::Keyboard::Key::S:
      return df::Keyboard::Key::S;
    case sf::Keyboard::Key::T:
      return df::Keyboard::Key::T;
    case sf::Keyboard::Key::U:
      return df::Keyboard::Key::U;
    case sf::Keyboard::Key::V:
      return df::Keyboard::Key::V;
    case sf::Keyboard::Key::W:
      return df::Keyboard::Key::W;
    case sf::Keyboard::Key::X:
      return df::Keyboard::Key::X;
    case sf::Keyboard::Key::Y:
      return df::Keyboard::Key::Y;
    case sf::Keyboard::Key::Z:
      return df::Keyboard::Key::Z;
    case sf::Keyboard::Key::Num1:
      return df::Keyboard::Key::NUM1;
    case sf::Keyboard::Key::Num2:
      return df::Keyboard::Key::NUM2;
    case sf::Keyboard::Key::Num3:
      return df::Keyboard::Key::NUM3;
    case sf::Keyboard::Key::Num4:
      return df::Keyboard::Key::NUM4;
    case sf::Keyboard::Key::Num5:
      return df::Keyboard::Key::NUM5;
    case sf::Keyboard::Key::Num6:
      return df::Keyboard::Key::NUM6;
    case sf::Keyboard::Key::Num7:
      return df::Keyboard::Key::NUM7;
    case sf::Keyboard::Key::Num8:
      return df::Keyboard::Key::NUM8;
    case sf::Keyboard::Key::Num9:
      return df::Keyboard::Key::NUM9;
    case sf::Keyboard::Key::Num0:
      return df::Keyboard::Key::NUM0;
    case sf::Keyboard::Key::BackSpace:
      return df::Keyboard::Key::BACKSPACE;
    default:
      return df::Keyboard::Key::UNDEFINED_KEY;
  }
}
