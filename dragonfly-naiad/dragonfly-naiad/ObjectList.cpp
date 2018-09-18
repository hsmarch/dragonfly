#include "ObjectList.h"

df::ObjectList::ObjectList() {
  count = 0;
  for(int i = 0; i < MAX_OBJECTS; i++) {
    p_obj[i] = nullptr;
  }
}

int df::ObjectList::insert(Object* p_o) {
  if(count >= MAX_OBJECTS) {
    return -1;
  }
  p_obj[count] = p_o;
  count++;
  return 0;
}

int df::ObjectList::remove(Object* p_o) {
  bool obj_removed = false;
  for(int i = 0; i < MAX_OBJECTS; i++) {
    //First phase, find the object, decrement count
    if(!obj_removed && p_obj[i] == p_o) {
      count--;
      i--;
      obj_removed = true;
    }
    //Second phase, shift everything over
    else {
      if(i + 1 < MAX_OBJECTS) {
        p_obj[i] = p_obj[i + 1];
      } else {
        p_obj[i] = nullptr;
      }
    }
  }

  if(obj_removed) {
    return 0;
  } else {
    return -1;
  }
}

void df::ObjectList::clear() {
  for(int i = 0; i < MAX_OBJECTS; i++) {
    p_obj[i] = nullptr;
  }
  count = 0;
}

int df::ObjectList::getCount() const {
  return count;
}

bool df::ObjectList::isEmpty() const {
  return count == 0;
}

bool df::ObjectList::isFull() const {
  return count == MAX_OBJECTS;
}
