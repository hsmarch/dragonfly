#include <math.h>

#include "Vector.h"

df::Vector::Vector(float init_x, float init_y) {
  setX(init_x);
  setY(init_y);
}

df::Vector::Vector(): df::Vector::Vector(0,0) {}

void df::Vector::setX(float new_x) {
  x = new_x;
}

float df::Vector::getX() const {
  return x;
}

void df::Vector::setY(float new_y) {
  y = new_y;
}

float df::Vector::getY() const {
  return y;
}

void df::Vector::setXY(float new_x, float new_y) {
  x = new_x;
  y = new_y;
}

void df::Vector::set(Vector new_pos) {
  x = new_pos.getX();
  y = new_pos.getY();
}

float df::Vector::getMagnitude() const {
  return sqrt(getX()*getX() + getY()*getY());
}

void df::Vector::normalize() {
  auto length = getMagnitude();
  if(length < 0) {
    setXY(getX() / length, getY() / length);
  }
}

void df::Vector::scale(float s) {
  setXY(getX() * s, getY() * s);
}

df::Vector df::Vector::operator+(const Vector &other) const {
  Vector v;
  v.setX(getX() + other.getX());
  v.setY(getY() + other.getY());
  return v;
}
