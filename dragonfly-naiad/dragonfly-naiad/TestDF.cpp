//
// Dragonfly Naiad Test Suite 
// TestDF.cpp - Harrison March
//
// Engine includes.
#include "LogManager.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

// System Includes
#include <Windows.h>

int main(int argc, char * argv[]);
void test_log_manager();
void test_clock();
void test_object();
void test_object_list();
void test_world_manager();
void test_game_manager();

//Global variables for test cases
df::GameManager &game_manager = df::GameManager::getInstance();
df::LogManager &log_manager = df::LogManager::getInstance();
df::Object *test_obj = new df::Object();
Vector *test_position = new Vector();
ObjectList *test_list = new ObjectList();
df::Object *test_obj2 = new df::Object();

int main(int argc, char *argv[]) {
	test_log_manager();
	test_clock();
	test_object();
	test_object_list();
	test_world_manager();
	test_game_manager();
}
/**
 *Log Manager Tests.
 *- Checks if flush is enabled
 *- Checks manager.getType(
 *- Checks printing, single and multiple args
 */
void test_log_manager()
{
	log_manager.writeLog(" - Starting Test Session - \n");
	log_manager.writeLog("Initializing Log Manager Tests. GM and LM init Success!\n");
	if (log_manager.do_flush) {
		log_manager.writeLog("LM Flush enabled. This message should not print.");
	}
	log_manager.writeLog("%s MultiArg Test %s %d\n", log_manager.getType().c_str(), "qwerty", 3);
}


void test_clock()
{
	/*
	Clock Tests.
	 - Checks Split and delta methods of clock class.
	 */
	log_manager.writeLog("\n\n - Clock Test Suite -  \n");
	Clock *test_clock = new Clock();
	Sleep(1);
	long int test_time = test_clock->split();
	log_manager.writeLog("\tTest: Clock Split %lu\n", test_time);
	Sleep(2);
	test_time = test_clock->delta();
	log_manager.writeLog("\tTest: Clock Delta  %lu\n", test_time);
}

void test_object()
{
	/*
	Object Tests
	 - Creates an object
	 - Sets params
	 */
	log_manager.writeLog("\n\n - Object Test Suite - \n");
	
	test_obj->setType("Test Object");
	test_obj->setId(5);
	test_position->setXY(5, 4);
	test_obj->setPosition(*test_position);
	log_manager.writeLog("\t Object type: %s\n\t Object id: %d\n\t Object position: x=%d, y=%d\n", test_obj->getType().c_str(), test_obj->getId(), test_obj->getPosition().getX(), test_obj->getPosition().getY());

}

void test_object_list()
{
	/*
	ObjectList and ObjectListIterator Tests
	 - Checks various object list and iterator features
	 */
	log_manager.writeLog("\n\n - ObjectList and ObjectListIterator Test Suite - \n");
	log_manager.writeLog("\tList size: %d\n\tAdding to list\n", test_list->getCount());
	test_obj2->setType("Test Object 2");
	test_list->insert(test_obj);
	test_list->insert(test_obj2);
	for (int i = 0; i < 5001; i++) {
		if (test_list->insert(test_obj2) == 1) {
			log_manager.writeLog("\tObject List Full! Cannot create!\n");
		}
	}
	log_manager.writeLog("\tAfter insertion: getCount(): %d\tisEmpty(): %d\n", test_list->getCount(), test_list->isEmpty());
	for (int i = 0; i < 4995; i++) {
		test_list->remove(test_obj2);
	}
	log_manager.writeLog("\tAfter deletion: getCount(): %d\tisEmpty(): %d\n", test_list->getCount(), test_list->isEmpty());
	test_list->insert(test_obj2);
	test_list->insert(test_obj2);
	ObjectListIterator test_li(test_list);
	log_manager.writeLog("\tPrinting all Objects in List\n");
	for (test_li.first(); !test_li.isDone(); test_li.next()) {
		log_manager.writeLog("\tObject type: %s, isDone(): %d\n", test_li.currentObject()->getType().c_str(), test_li.isDone());
	}
}

void test_world_manager()
{
	/*
	WorldManager Tests
	 - Creates and checks object lists of world manager before and after step.
	 */
	log_manager.writeLog("\n\n - WorldManager Test Suite - \n");
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	log_manager.writeLog("\t%s instance fetched.\n", world_manager.getType().c_str());

	test_list = &world_manager.getAllObjects();
	log_manager.writeLog("\tWorldManager Object List getCount(): %d, isEmpty: %d\n", test_list->getCount(), test_list->isEmpty());
	world_manager.removeObject(test_obj);
	world_manager.markForDelete(test_obj2);
	world_manager.update();
	test_list = &world_manager.getAllObjects();
	log_manager.writeLog("\tWorldManager Object List getCount(): %d, isEmpty: %d\n", test_list->getCount(), test_list->isEmpty());
	log_manager.setFlush(true);
}

void test_game_manager()
{
	/*
	GameManager Tests
	 - Runs GameManager
	 */
	log_manager.writeLog("\n\n - GameManager Test Suite - \n");
	df::Object *g_test = new df::Object();
	game_manager.run();
}
