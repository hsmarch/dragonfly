//
// Dragonfly ObjectListIterator.cpp - Harrison March
//

// Engine Includes
#include "ObjectListIterator.h"

ObjectListIterator::ObjectListIterator()
{
}

ObjectListIterator::ObjectListIterator(const ObjectList* p_l)
{
	p_list = p_l;
	first();
}

void ObjectListIterator::first()
{
	index = 0;
}

void ObjectListIterator::next()
{
	if (index < p_list->getCount())
	{
		index++;
	}
}

bool ObjectListIterator::isDone() const
{
	return (index == p_list->getCount());
}

df::Object* ObjectListIterator::currentObject() const
{
	return p_list->list[index];
}
