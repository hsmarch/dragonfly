//
// Dragonfly EventStep.cpp - Harrison March
//

//Engine Includes
#include "EventStep.h"

int step_count;

df::EventStep::EventStep()
{
	setType(STEP_EVENT);
	step_count = 0;
}

df::EventStep::EventStep(int init_step_count)
{
	setType(STEP_EVENT);
	step_count = init_step_count;
}

void df::EventStep::setStepCount(int new_step_count)
{
	step_count = new_step_count;
}

int df::EventStep::getStepCount() const
{
	return step_count;
}
