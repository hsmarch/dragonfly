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
void testLogManager();
void testManager();
void testClock();
void testObject();
void testObjectList();
void testWorldManager();
void testGameManager();

//Global variables for test cases
df::GameManager &g_mngr = df::GameManager::getInstance();
df::LogManager &l_mngr = df::LogManager::getInstance();
df::Object *testObj = new df::Object();
Vector *test_position = new Vector();
ObjectList *test_list = new ObjectList();
df::Object *testObj2 = new df::Object();

int main(int argc, char *argv[]) {

	l_mngr.writeLog(" - Starting Test Session - \n");
	testLogManager();
	testManager();
	testClock();
	testObject();
	testObjectList();
	testWorldManager();
	testGameManager();
}

void testLogManager()
{
	/*

	Log Manager Tests.

	- Checks if flush is enabled.
	- Checks manager.getType()
	- Checks printing, single and multiple args

	*/
	l_mngr.writeLog("Initializing Log Manager Tests. GM and LM init Success!\n");
	if (l_mngr.do_flush) {
		l_mngr.writeLog("LM Flush enabled. This message should not print.");
	}
	l_mngr.writeLog("%s MultiArg Test %s %d\n", l_mngr.getType().c_str(), "qwerty", 3);
}

void testManager()
{
	/*
	Manager Tests.
	 - Checks if manager can start
	 - Checks default manager type
	 - Shuts down manager
	*/
	l_mngr.writeLog("\n\n - Manager Test Suite -  \n");
	df::Manager *manager = new df::Manager();
	manager->startUp();
	l_mngr.writeLog("Manager getType() Test: %s\n", manager->getType().c_str());
	manager->shutDown();
}

void testClock()
{
	/*
	Clock Tests.
	 - Checks Split and delta methods of clock class.
	 */
	l_mngr.writeLog("\n\n - Clock Test Suite -  \n");
	Clock *test_clock = new Clock();
	Sleep(1);
	long int test_time = test_clock->split();
	l_mngr.writeLog("\tTest: Clock Split %lu\n", test_time);
	Sleep(2);
	test_time = test_clock->delta();
	l_mngr.writeLog("\tTest: Clock Delta  %lu\n", test_time);
}

void testObject()
{
	/*
	Object Tests
	 - Creates an object
	 - Sets params
	 */
	l_mngr.writeLog("\n\n - Object Test Suite - \n");
	
	testObj->setType("Test Object");
	testObj->setId(5);
	test_position->setXY(5, 4);
	testObj->setPosition(*test_position);
	l_mngr.writeLog("\t Object type: %s\n\t Object id: %d\n\t Object position: x=%d, y=%d\n", testObj->getType().c_str(), testObj->getId(), testObj->getPosition().getX(), testObj->getPosition().getY());

}

void testObjectList()
{
	/*
	ObjectList and ObjectListIterator Tests
	 - Checks various object list and iterator features
	 */
	l_mngr.writeLog("\n\n - ObjectList and ObjectListIterator Test Suite - \n");
	l_mngr.writeLog("\tList size: %d\n\tAdding to list\n", test_list->getCount());
	testObj2->setType("Test Object 2");
	test_list->insert(testObj);
	test_list->insert(testObj2);
	for (int i = 0; i < 5001; i++) {
		if (test_list->insert(testObj2) == 1) {
			l_mngr.writeLog("\tObject List Full! Cannot create!\n");
		}
	}
	l_mngr.writeLog("\tAfter insertion: getCount(): %d\tisEmpty(): %d\n", test_list->getCount(), test_list->isEmpty());
	for (int i = 0; i < 4995; i++) {
		test_list->remove(testObj2);
	}
	l_mngr.writeLog("\tAfter deletion: getCount(): %d\tisEmpty(): %d\n", test_list->getCount(), test_list->isEmpty());
	test_list->insert(testObj2);
	test_list->insert(testObj2);
	ObjectListIterator test_li(test_list);
	l_mngr.writeLog("\tPrinting all Objects in List\n");
	for (test_li.first(); !test_li.isDone(); test_li.next()) {
		l_mngr.writeLog("\tObject type: %s, isDone(): %d\n", test_li.currentObject()->getType().c_str(), test_li.isDone());
	}
}

void testWorldManager()
{
	/*
	WorldManager Tests
	 - Creates and checks object lists of world manager before and after step.
	 */
	l_mngr.writeLog("\n\n - WorldManager Test Suite - \n");
	df::WorldManager &world_manager = df::WorldManager::getInstance();
	l_mngr.writeLog("\t%s instance fetched.\n", world_manager.getType().c_str());

	test_list = &world_manager.getAllObjects();
	l_mngr.writeLog("\tWorldManager Object List getCount(): %d, isEmpty: %d\n", test_list->getCount(), test_list->isEmpty());
	world_manager.removeObject(testObj);
	world_manager.markForDelete(testObj2);
	world_manager.update();
	test_list = &world_manager.getAllObjects();
	l_mngr.writeLog("\tWorldManager Object List getCount(): %d, isEmpty: %d\n", test_list->getCount(), test_list->isEmpty());
	l_mngr.setFlush(true);
}

void testGameManager()
{
	/*
	GameManager Tests
	 - Runs GameManager
	 */
	l_mngr.writeLog("\n\n - GameManager Test Suite - \n");
	df::Object *g_test = new df::Object();
	g_mngr.run();
}
