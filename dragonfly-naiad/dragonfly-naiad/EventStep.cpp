#include "EventStep.h"

df::EventStep::EventStep(int init_step_count){
  setType(STEP_EVENT);
  setStepCount(init_step_count);
}

df::EventStep::EventStep() : df::EventStep(0) { }

void df::EventStep::setStepCount(int new_step_count){
  step_count = new_step_count;
}

int df::EventStep::getStepCount() const {
  return step_count;
}
