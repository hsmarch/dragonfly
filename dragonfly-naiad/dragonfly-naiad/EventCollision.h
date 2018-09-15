#include "Event.h"
#include "Object.h"
#ifndef __EVENTCOLLISION_H_
#define __EVENTCOLLISION_H_
namespace df
{
	const std::string COLLISION_EVENT = "CollisionEvent";

	class EventCollision : public Event
	{
	public:
		EventCollision();
		EventCollision(Object* p_o1, Object* p_o2, Vector p);
		void setObject1(Object* p_new_o1);
		Object* getObject1() const;
		void setObject2(Object* p_new_o2);
		Object* getObject2() const;
		void setPosition(Vector new_pos);
		Vector getPosition() const;

	private:
		Vector pos;
		Object* p_obj1;
		Object* p_obj2;
	};
}
#endif

