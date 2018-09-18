#include "Manager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"

df::Manager::Manager() {
  type = "";
  is_started = false;
}

std::string df::Manager::getType() const {
  return type;
}

bool df::Manager::isStarted() const {
  return is_started;
}

void df::Manager::setType(std::string new_type) {
  type = new_type;
}

df::Manager::~Manager() {}
int df::Manager::startUp() {
  is_started = true;
  return -1;
}
void df::Manager::shutDown() {
  is_started = false;
}

int df::Manager::onEvent(const Event* p_event) const {
  int count = 0;

  auto all_objects = df::WorldManager::getInstance().getAllObjects();
  ObjectListIterator list_iter(&all_objects);
  for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
    list_iter.currentObject()->eventHandler(p_event);
    count++;
  }

  return count;
}
