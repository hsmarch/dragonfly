#include "WorldManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "EventOut.h"

df::WorldManager::WorldManager() {
  setType("WorldManager");
}

df::WorldManager& df::WorldManager::getInstance() {
  static WorldManager world_manager;
  return world_manager;
}

int df::WorldManager::startUp() {
  updates.clear();
  deletions.clear();
  Manager::startUp();
  df::LogManager::getInstance().writeLog("WorldManager: WorldManager successfully started\n");
  return 1;
}

void df::WorldManager::shutDown() {
  ObjectList obj_list = updates;
  ObjectListIterator list_iter(&obj_list);
  for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
    delete list_iter.currentObject();
  }

  Manager::shutDown();
}

int df::WorldManager::insertObject(Object* p_o) {
  int success = updates.insert(p_o);
  if(success == -1) {
    df::LogManager::getInstance().writeLog("WorldManager: Failed to add object (id: %d)\n", p_o->getId());
  }
  return success;
}

int df::WorldManager::removeObject(Object* p_o) {
  int success = updates.remove(p_o);
  if(success == -1) {
    df::LogManager::getInstance().writeLog("WorldManager: Failed to remove object (id: %d)\n", p_o->getId());
  }
  return success;
}

df::ObjectList df::WorldManager::getAllObjects() const {
  return updates;
}

df::ObjectList df::WorldManager::objectsOfType(std::string type) const {
  ObjectList result_list;
  ObjectListIterator list_iter(&updates);
  for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
    if(list_iter.currentObject()->getType() == type) {
      result_list.insert(list_iter.currentObject());
    }
  }
  return result_list;
}

void df::WorldManager::update() {
  //Set velocites
  ObjectListIterator updates_list_iter(&updates);
  for(updates_list_iter.first(); !updates_list_iter.isDone(); updates_list_iter.next()) {
    auto p_o = updates_list_iter.currentObject();
    Vector new_pos = p_o->predictPosition();

    if(new_pos.getX() != p_o->getPosition().getX() ||
       new_pos.getY() != p_o->getPosition().getY()) {
      moveObject(p_o, new_pos);
    }
  }

  //Delete everything marked for deletion
  ObjectListIterator del_list_iter(&deletions);
  for(del_list_iter.first(); !del_list_iter.isDone(); del_list_iter.next()) {
    delete del_list_iter.currentObject();
  }
  deletions.clear();
}

bool positionsIntersect(df::Vector p1, df::Vector p2) {
  if(p1.getX() == p2.getX() && p1.getY() == p2.getY()) {
    return true;
  } else {
    return false;
  }
}

df::ObjectList df::WorldManager::isCollision(Object *p_o, Vector where) {
  ObjectList collisionList;
  ObjectListIterator updates_list_iter(&updates);
  for(updates_list_iter.first(); !updates_list_iter.isDone(); updates_list_iter.next()) {
    Object* p_temp_o = updates_list_iter.currentObject();
    if(p_temp_o != p_o) {
      if(positionsIntersect(p_temp_o->getPosition(), where) && p_temp_o->isSolid()) {
        collisionList.insert(p_temp_o);
      }
    }
  }
  return collisionList;
}

int df::WorldManager::moveObject(Object* p_o, Vector where) {
  ObjectList collisionsList = isCollision(p_o, where);

  if(collisionsList.getCount() != 0) {
    bool will_move = true;

    ObjectListIterator coll_iter(&collisionsList);
    for(coll_iter.first(); !coll_iter.isDone(); coll_iter.next()) {
      auto p_temp_o = coll_iter.currentObject();

      EventCollision c(p_o, p_temp_o, where);
      p_o->eventHandler(&c);
      p_temp_o->eventHandler(&c);

      if(p_o->getSolidness() == Solidness::HARD && p_temp_o->getSolidness() == Solidness::HARD) {
        will_move = false;
      }
    }
    if(!will_move) {
      return -1;
    }
  }

  if(where.getX() < 0 || where.getX() > df::GraphicsManager::getInstance().getHorizontal() - 1 ||
     where.getY() < 0 || where.getY() > df::GraphicsManager::getInstance().getVertical() - 1) {
    EventOut o;
    p_o->eventHandler(&o);
  }

  p_o->setPosition(where);
  return 0;
}

void df::WorldManager::draw() {
  ObjectListIterator list_iter(&updates);

  for(int altitude = 0; altitude <= MAX_ALTITUDE; altitude++) {
    for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
      if(list_iter.currentObject()->getAltitude() == altitude) {
        list_iter.currentObject()->draw();
      }
    }
  }
}

int df::WorldManager::markForDelete(Object *p_o) {
  ObjectListIterator list_iter(&deletions);
  for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
    if(list_iter.currentObject() == p_o) {
      return 0;
    }
  }

  int success = deletions.insert(p_o);
  if(success == -1) {
    df::LogManager::getInstance().writeLog("WorldManager: Failed to add object (id: %d) to deletions list\n", p_o->getId());
  }
  return success;
}
