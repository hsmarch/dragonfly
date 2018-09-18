#pragma once

#include <string>

#include "Manager.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

/*
Manages Objects in a game
*/
namespace df {
  const int MAX_ALTITUDE = 5;

  class WorldManager : public Manager {
    public:
      static WorldManager& getInstance();
      int startUp();  // Starts the manager (returns 0 for success, -1 for error)
      void shutDown();  // Stops the manager
      int insertObject(Object* p_o); // Adds an object to the list of objects that get updates
      int removeObject(Object* p_o); // Removes an object from the list of objects that get updates
      ObjectList getAllObjects() const; // Return all object
      ObjectList objectsOfType(std::string type) const;  // Return all objects of a given type
      void update(); // Update, removing marked objects
      ObjectList isCollision(Object *p_o, Vector where); //Returns a list of objects that collide at "where"
      int moveObject(Object* p_o, Vector where);  //Move, unless into solid object, then send event
      int markForDelete(Object *p_o); // Mark an object to be deleted on the next call to update
      void draw(); //Draw all contained objects

    private:
      WorldManager();
      WorldManager(WorldManager const&);
      void operator=(WorldManager const&);

      ObjectList updates;
      ObjectList deletions;
  };
}
