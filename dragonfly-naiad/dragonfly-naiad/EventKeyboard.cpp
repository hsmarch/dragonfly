#include "EventKeyboard.h"

df::EventKeyboard::EventKeyboard() {
  setType(KEYBOARD_EVENT);
  key_val = df::Keyboard::UNDEFINED_KEY;
  keyboard_action = df::EventKeyboardAction::UNDEFINED_KEYBOARD_ACTION;
}

void df::EventKeyboard::setKey(df::Keyboard::Key new_key) {
  key_val = new_key;
}

df::Keyboard::Key df::EventKeyboard::getKey() const {
  return key_val;
}

void df::EventKeyboard::setKeyboardAction(df::EventKeyboardAction new_action) {
  keyboard_action = new_action;
}

df::EventKeyboardAction df::EventKeyboard::getKeyboardAction() const {
  return keyboard_action;
}
