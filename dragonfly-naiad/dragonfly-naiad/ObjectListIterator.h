#ifndef __OBJECTLISTITERATOR_H__
#define __OBJECTLISTITERATOR_H__

//Engine Includes
#include "ObjectList.h"

class df::Object;
class ObjectList;

class ObjectListIterator
{
private:
	ObjectListIterator();
	int index;
	const ObjectList* p_list;

public:
	ObjectListIterator(const ObjectList* p_l);

	void first();
	void next();
	bool isDone() const;

	df::Object* currentObject() const;
};
#endif
