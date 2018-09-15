#ifndef __EVENT_H__
#define __EVENT_H__

//System Includes
#include <string>

namespace df
{
	const std::string UNDEFINED_EVENT = "UndefinedEvent";

	class Event
	{
	private:
		std::string event_type;

	public:

		Event();

		virtual ~Event();

		void setType(std::string new_type);

		std::string getType() const;
	};
}

#endif
