#pragma once

#include "ObjectList.h"
#include "Object.h"

/*
A simplified interface for accessing an ObjectList
*/
namespace df {
  class ObjectListIterator {
    public:
      ObjectListIterator(const ObjectList* p_l); // ctor, needs an ObjectList
      void first(); // Go to the first object
      void next(); // Go to the next object
      bool isDone() const; // Check if the iterator is currently on the last item
      Object* currentObject() const; // Return the object pointer the iterator is currently on

    private:
      ObjectListIterator();
      int index;
      const ObjectList* p_list;
  };
}
