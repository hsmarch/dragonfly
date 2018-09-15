#ifndef __OBJECT_H__
#define __OBJECT_H__

//System Includes
#include <string>
//Engine Includes
#include "Vector.h"
#include "Event.h"

namespace df
{
	class Object
	{
	private:
		int id;
		std::string type;
		Vector pos;

	public:
		Object();
		virtual ~Object();

		virtual int EventHandler(const Event* p_e);

		void setId(int new_id);
		int getId() const;

		void setType(std::string new_type);
		std::string getType() const;

		void setPosition(Vector new_pos);
		Vector getPosition() const;
	};
}

#endif
