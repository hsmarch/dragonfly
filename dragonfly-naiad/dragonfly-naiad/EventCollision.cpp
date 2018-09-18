#include "EventCollision.h"
#include "Object.h"
#include "Vector.h"


df::EventCollision::EventCollision(df::Object* p_o1, df::Object* p_o2, Vector p) {
  p_obj1 = p_o1;
  p_obj2 = p_o2;
  pos = p;
}

df::EventCollision::EventCollision(): df::EventCollision::EventCollision(nullptr, nullptr, df::Vector()) {}

void df::EventCollision::setObject1(df::Object* p_new_o1) {
  p_obj1 = p_new_o1;
}

df::Object* df::EventCollision::getObject1() const {
  return p_obj1;
}

void df::EventCollision::setObject2(df::Object* p_new_o2) {
  p_obj2 = p_new_o2;
}

df::Object* df::EventCollision::getObject2() const {
  return p_obj2;
}

void df::EventCollision::setPosition(df::Vector new_pos) {
  pos = new_pos;
}

df::Vector df::EventCollision::getPosition() const {
  return pos;
}
