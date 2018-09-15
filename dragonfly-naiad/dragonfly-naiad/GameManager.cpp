//
// Dragonfly GameManager.cpp - Harrison March
//

//Engine Includes
#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "EventStep.h"

//System Includes
#include <Windows.h>
#include <stdarg.h>

df::GameManager::GameManager()
{
	setType("GameManager");
	game_over = true;
	frame_time = FRAME_TIME_DEFAULT;
	step_count = 0;
	this->startUp();
}

df::GameManager& df::GameManager::getInstance()
{
	static GameManager g_mInstance;
	return g_mInstance;
}

int df::GameManager::startUp()
{
	Manager::startUp();
	LogManager& l_mngr = LogManager::getInstance();
	l_mngr.startUp();
	WorldManager& w_mngr = WorldManager::getInstance();
	w_mngr.startUp();
	return 0;
}

void df::GameManager::shutDown()
{
	setGameOver(true);
	LogManager& l_mngr = LogManager::getInstance();
	l_mngr.shutDown();
	WorldManager& w_mngr = WorldManager::getInstance();
	w_mngr.shutDown();

	Manager::shutDown();
}

void df::GameManager::run()
{
	Clock* clock = new Clock();
	long int loop_time;
	long int intended_sleep_time;
	long int actual_sleep_time;
	long int adjust_time = 0;
	LogManager& l_mngr = LogManager::getInstance();
	do
	{
		l_mngr.writeLog("Game Tick!\n");
		clock->delta();
		WorldManager& w_mngr = WorldManager::getInstance();
		w_mngr.update();
		EventStep* s = new EventStep(step_count);
		ObjectListIterator li(&w_mngr.getAllObjects());
		for (li.first(); !li.isDone(); li.next())
		{
			li.currentObject()->EventHandler(s);
		}
		step_count++;
		loop_time = clock->split();
		intended_sleep_time = FRAME_TIME_DEFAULT - loop_time - adjust_time;
		Sleep(intended_sleep_time);
		actual_sleep_time = clock->split();
		adjust_time = actual_sleep_time - intended_sleep_time;
	}
	while (!game_over);
	l_mngr.writeLog("Game Shut Down.");
	shutDown();
}

void df::GameManager::setGameOver(bool new_game_over)
{
	game_over = new_game_over;
}

bool df::GameManager::getGameOver() const
{
	return game_over;
}

int df::GameManager::getFrameTime() const
{
	return frame_time;
}
