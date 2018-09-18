#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"

df::Object::Object() {
  static int current_id = 0;
  id = current_id++;
  type = "undefined";
  altitude = MAX_ALTITUDE / 2;
  solidness = Solidness::HARD;

  df::WorldManager::getInstance().insertObject(this);
}

df::Object::~Object() {
  df::WorldManager::getInstance().removeObject(this);
}

void df::Object::setId(int new_id) {
  id = new_id;
}

int df::Object::getId() const {
  return id;
}

void df::Object::setType(std::string new_type) {
  type = new_type;
}

std::string df::Object::getType() const {
  return type;
}

void df::Object::setPosition(Vector new_pos) {
  position = new_pos;
}

void df::Object::setPosition(float x, float y) {
  position = Vector(x, y);
}

df::Vector df::Object::getPosition() const {
  return position;
}

void df::Object::setAltitude(int new_altitude) {
  if(new_altitude >= 0 && new_altitude <= MAX_ALTITUDE) {
    altitude = new_altitude;
  }
}

int df::Object::getAltitude() const {
  return altitude;
}

void df::Object::setSpeed(float new_speed) {
  speed = new_speed;
}

float df::Object::getSpeed() const {
  return speed;
}

void df::Object::setDirection(Vector new_direction) {
  direction = new_direction;
}

df::Vector df::Object::getDirection() const {
  return direction;
}

df::Vector df::Object::getVelocity() const {
  df::Vector v = getDirection();
  v.scale(getSpeed());
  return v;
}

void df::Object::setVelocity(df::Vector new_velocity) {
  df::Vector v = new_velocity;
  v.normalize();
  direction.set(v);
  speed = new_velocity.getMagnitude();
}

df::Vector df::Object::predictPosition() {
  return position + getVelocity();
}

int df::Object::eventHandler(const Event* p_e) {
  return -1;
}

void df::Object::draw() {}

bool df::Object::isSolid() const {
  return getSolidness() == Solidness::HARD || getSolidness() == Solidness::SOFT;
}

int df::Object::setSolidness(df::Solidness new_solid) {
  df::ObjectList collisionsList = df::WorldManager::getInstance().isCollision(this, getPosition());

  if(collisionsList.getCount() != 0) {
    ObjectListIterator coll_iter(&collisionsList);
    for(coll_iter.first(); !coll_iter.isDone(); coll_iter.next()) {
      auto p_temp_o = coll_iter.currentObject();
      if(getSolidness() == Solidness::HARD && p_temp_o->getSolidness() == Solidness::HARD) {
        return -1;
      }
    }
  }

  solidness = new_solid;
  return 0;
}

df::Solidness df::Object::getSolidness() const {
  return solidness;
}
