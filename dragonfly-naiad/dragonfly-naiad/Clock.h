#ifndef __CLOCK_H__
#define __CLOCK_H__

class Clock
{
private:
	long int previous_time;

public:
	Clock();
	long int delta(void);
	long int split(void) const;
};

#endif
