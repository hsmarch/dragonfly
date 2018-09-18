#include <stdio.h>
#include <unistd.h>

#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Clock.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "EventStep.h"

//An object the prints when events are received
class StepTestObj : public df::Object {
  public:
    bool should_print;
    StepTestObj(bool print) {
      should_print = print;
    }
    virtual int eventHandler(const df::Event* p_e) {
      if(p_e->getType() == "df::step") {
        int step = (dynamic_cast <const df::EventStep*> (p_e))->getStepCount();

        if(should_print) {
          printf("Received step event (step #%d)\n", step);
        }

        //Stop on step 10
        if(step == 29) {
          df::GameManager::getInstance().setGameOver(true);
        }
      }
      return 0;
    }
};

void testClock() {
  printf("Testing Clock\n");

  //Test for general accuracy
  printf("Sleeping 1 second: ");
  df::Clock c;
  sleep(1);
  auto after_one_sec = c.delta();
  printf("took %ld, expected about 1000000\n", after_one_sec);

  //Test that split doesn't save
  sleep(1);
  auto first_split = c.split();
  sleep(1);
  auto second_split = c.split();
  printf("Test that split doesn't save: first - %ld, second - %ld\n", first_split, second_split);

  printf("Clock Tests Complete\n\n");
}

void testGameManager() {
  printf("Testing GameManager\n");

  printf("GameManager should start all managers\n");
  df::GameManager::getInstance().startUp();
  printf("GameManager started: %s\n", df::GameManager::getInstance().isStarted() ? "true" : "false");
  printf("WorldManager started: %s\n", df::WorldManager::getInstance().isStarted() ? "true" : "false");
  printf("LogManager started: %s\n\n", df::LogManager::getInstance().isStarted() ? "true" : "false");

  df::Clock c;
  printf("GameManger should run 30 steps, then stop at about 30 fps\n");
  new StepTestObj(false);
  df::GameManager::getInstance().run();
  auto time_for_30_frames = c.delta();
  printf("Took %ld microseconds, expected about 1000000\n\n", time_for_30_frames);

  printf("GameManager should shut down all managers\n");
  df::GameManager::getInstance().shutDown();
  printf("GameManager stopped: %s\n", df::GameManager::getInstance().isStarted() ? "false" : "true");
  printf("WorldManager stopped: %s\n", df::WorldManager::getInstance().isStarted() ? "false" : "true");
  printf("LogManager stopped: %s\n\n", df::LogManager::getInstance().isStarted() ? "false" : "true");

  printf("GameManager Tests Complete\n\n");
}

void testEvents() {
  printf("Testing Events (Covers Event, StepEvent, and eventHandler())\n");

  printf("Test object should receive 30 steps, then stop the GameManger\n");
  new StepTestObj(true);
  df::GameManager::getInstance().run();

  printf("Event Testing Complete\n\n");
}

void testObjectList() {
  printf("Testing ObjectList\n");

  df::ObjectList list;
  printf("Test adding two Objects to an ObjectList\n");
  list.insert(new df::Object());
  list.insert(new df::Object());
  printf("List size: %d\n\n", list.getCount());

  printf("Test adding more than the max count\n");
  for(int i = 0; i < df::MAX_OBJECTS + 5; i++) {
    list.insert(new df::Object());
  }
  printf("List size (expects %d) : %d\n\n", df::MAX_OBJECTS, list.getCount());

  printf("Test clearing an ObjectList\n");
  list.clear();
  printf("List size: %d\n\n", list.getCount());

  printf("Test adding two objects, and removing the first one\n");
  df::Object* obj1 = new df::Object();
  list.insert(obj1);
  list.insert(new df::Object());
  list.remove(obj1);
  printf("List size: %d\n\n", list.getCount());

  list.clear(); //We know clear works now, so its safe to use here

  printf("Test adding two objects, and removing the second one\n");
  df::Object* obj2 = new df::Object();
  list.insert(new df::Object());
  list.insert(obj2);
  list.remove(obj2);
  printf("List size: %d\n\n", list.getCount());

  list.clear(); //We know clear works now, so its safe to use here

  printf("Test filling the list, then removing the first object, then adding another (tests shifting)\n");
  list.insert(obj1);
  for(int i = 1; i < df::MAX_OBJECTS; i++) {
    list.insert(new df::Object());
  }
  list.insert(new df::Object());
  printf("List size (expects %d) : %d\n\n", df::MAX_OBJECTS, list.getCount());

  printf("Event ObjectList\n\n");
}

void testObjectListIterator() {
  printf("Testing ObjectListIterator\n");

  printf("Add three items, iterate through the list, and ensure all items are visited\n");
  df::Object* obj1 = new df::Object();
  df::Object* obj2 = new df::Object();
  df::Object* obj3 = new df::Object();
  df::ObjectList list;
  list.insert(obj1);
  list.insert(obj2);
  list.insert(obj3);
  df::ObjectListIterator list_iter(&list);
  for(list_iter.first(); !list_iter.isDone(); list_iter.next()) {
    printf("Visited obj at %p\n", list_iter.currentObject());
  }
  printf("Expected: All addresses are different\n\n");

  printf("ObjectListIterator Testing Complete\n\n");
}

void testWorldManager() {
  printf("Testing WorldManager\n");

  df::GameManager::getInstance().startUp();
  df::WorldManager& wm = df::WorldManager::getInstance();

  printf("Add two Objects (different types) Both should appear in getAllObjects()\n");
  df::Object* obj1 = new df::Object();
  obj1->setType("type1");
  df::Object* obj2 = new df::Object();
  obj2->setType("type2");
  printf("Count: %d (expected 2)\n\n", wm.getAllObjects().getCount());

  printf("Only one should should appear in objectsOfType(\"type1\")\n");
  printf("Count: %d (expected 1)\n\n", wm.objectsOfType("type1").getCount());

  printf("Remove one Object. only one should appear in getAllObjects()\n");
  wm.removeObject(obj1);
  printf("Count: %d (expected 1)\n\n", wm.getAllObjects().getCount());

  printf("Mark the last object for deletion and update. none appear in getAllObjects()\n");
  wm.markForDelete(obj2);
  wm.update();
  printf("Count: %d (expected 0)\n\n", wm.getAllObjects().getCount());

  df::GameManager::getInstance().shutDown();

  printf("WorldManager Testing Complete\n\n");
}

void testLogManager() {
  printf("Testing LogManager (ALL TESTS HERE MUST BE MANUALLY CHECKED IN \'dragonfly-log.txt\'!)\n");

  printf("Starting logger\n");
  df::LogManager& logger = df::LogManager::getInstance();
  printf("Startup value: %d\n\n", logger.startUp());

  printf("Logging \'test message\' in \'dragonfly-log.txt\'\n\n");
  logger.writeLog("test message\n");

  printf("Logging \'test 123456\' in \'dragonfly-log.txt\' to test ints\n\n");
  logger.writeLog("test %d\n", 123456);

  printf("Logging many test messages with flushing off\n\n");
  for(int i = 0; i < 100; i++) {
    logger.writeLog("flushing off log test %d\n", i + 1);
  }

  printf("Logging many test messages with flushing off\n\n");
  logger.setFlush(true);
  for(int i = 0; i < 100; i++) {
    logger.writeLog("flushing on log test %d\n", i + 1);
  }

  printf("LogManager Testing Complete\n\n");
}
