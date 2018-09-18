#pragma once

#include "Object.h"

/*
An object list provides a simple interface for a list of objects
*/
namespace df {
  const int MAX_OBJECTS = 5000;
  class ObjectListIterator; //Forward declartion to avoid cycle

  class ObjectList {
    public:
      friend class ObjectListIterator;
      ObjectList();
      int insert(Object* p_o); // Add an item to the end of the list (returns 0 for success, -1 for error)
      int remove(Object* p_o); // Remove a given item from the list (returns 0 for success, -1 for error)
      void clear(); // Remove all objects from the list
      int getCount() const; // Return the number of objects currently in the list
      bool isEmpty() const; // Return whether or not the list is empty
      bool isFull() const; // Return whether or not the list is full

    private:
      int count;
      Object* p_obj[MAX_OBJECTS];
  };
}
