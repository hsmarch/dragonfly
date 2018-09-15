//
// Dragonfly ObjectList.cpp - Harrison March
//

//Engine Includes
#include "ObjectList.h"

ObjectList::ObjectList()
{
	count = 0;
}

ObjectList ObjectList::operator+(ObjectList list)
{
	ObjectList big_list = *this;
	ObjectListIterator li(&list);
	for (li.first(); !li.isDone(); li.next())
	{
		df::Object* p_o = li.currentObject();
		big_list.insert(p_o);
	}
	return big_list;
}

int ObjectList::insert(df::Object* p_o)
{
	if (count == MAX_OBJECTS)
	{
		return 1;
	}
	list[count] = p_o;
	count++;
	return 0;
}

int ObjectList::remove(df::Object* p_o)
{
	for (int i = 0; i < count; i++)
	{
		if (list[i] == p_o)
		{
			for (int j = i; j < count - 1; j++)
			{
				list[j] = list[j + 1];
			}
			count--;
			return 0;
		}
	}
	return 1;
}

void ObjectList::clear()
{
	count = 0;
}

int ObjectList::getCount() const
{
	return count;
}

bool ObjectList::isEmpty() const
{
	return (count==0);zx 
}

bool ObjectList::isFull() const
{
	bool is_full = (count == MAX_OBJECTS);
		return is_full;
}
