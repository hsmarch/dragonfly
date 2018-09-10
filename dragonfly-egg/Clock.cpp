//
// Dragonfly Clock.cpp - Harrison March
//

//Engine Includes
#include "Clock.h"
#include <Windows.h>

//System Includes
#include <ctime>
#include <cstdio>

long int previous_time;

Clock::Clock() {
	SYSTEMTIME init_time;
	GetSystemTime(&init_time);
	previous_time = (init_time.wMinute * 60 * 1000)
		+ (init_time.wSecond * 1000)
		+ (init_time.wMilliseconds);
}

long int Clock::delta(void) {
	SYSTEMTIME init_time;
	GetSystemTime(&init_time);
	long int current_time = (init_time.wMinute * 60 * 1000)
						+ (init_time.wSecond * 1000)
						+ (init_time.wMilliseconds);
	long int return_time = current_time - previous_time;
	previous_time = current_time;
	return return_time;
}

long int Clock::split(void) const {
	SYSTEMTIME init_time;
	GetSystemTime(&init_time);
	long int current_time = (init_time.wMinute * 60 * 1000)
		+ (init_time.wSecond * 1000)
		+ (init_time.wMilliseconds);
	long int return_time = current_time - previous_time;
	return return_time;
}