#include "ObjectListIterator.h"

df::ObjectListIterator::ObjectListIterator(const df::ObjectList* p_l) {
  p_list = p_l;
}

void df::ObjectListIterator::first() {
  index = 0;
}

void df::ObjectListIterator::next() {
  if(index < p_list->count) {
    index++;
  }
}

bool df::ObjectListIterator::isDone() const {
  return (index >= p_list->count);
}

df::Object* df::ObjectListIterator::currentObject() const {
  return p_list->p_obj[index];
}
