#ifndef __EVENTSTEP_H__
#define __EVENTSTEP_H__

//Engine Includes
#include "Event.h"

namespace df
{
	const std::string STEP_EVENT = "df::stepEvent";

	class EventStep : public Event
	{
	private:
		int step_count;

	public:
		EventStep();

		EventStep(int init_step_count);

		void setStepCount(int new_step_count);

		int getStepCount() const;
	};
}
#endif
