#ifndef __OBJECTLIST_H__
#define __OBJECTLIST_H__

//Engine Includes
#include "Object.h"
#include "ObjectListIterator.h"


const int MAX_OBJECTS = 5000;
class df::Object;
class ObjectListIterator;

class ObjectList
{
private:
	int count;
	df::Object* list[MAX_OBJECTS];

public:
	friend class ObjectListIterator;

	ObjectList();

	ObjectList operator+(ObjectList list);

	int insert(df::Object* p_o);

	int remove(df::Object* p_o);

	void clear();

	int getCount() const;

	bool isEmpty() const;

	bool isFull() const;
};
#endif
