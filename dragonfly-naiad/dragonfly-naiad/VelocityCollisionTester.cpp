#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "Object.h"
#include "Vector.h"
#include "EventCollision.h"
#include "EventOut.h"

void testVelocity() {
  df::LogManager::getInstance().startUp();
  df::WorldManager::getInstance().startUp();

  auto obj1 = new df::Object;
  obj1->setVelocity(df::Vector(1, 0));
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Update from (0,0) with x velocity 1. Expected: (1, 0) Received: (%f, %f)\n",
         obj1->getPosition().getX(), obj1->getPosition().getY());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setVelocity(df::Vector(0, 1));
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Update from (0,0) with y velocity 1. Expected: (0, 1) Received: (%f, %f)\n",
         obj1->getPosition().getX(), obj1->getPosition().getY());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setVelocity(df::Vector(-1, 0));
  obj1->setPosition(df::Vector(1, 0));
  df::WorldManager::getInstance().update();
  printf("Update from (1,0) with x velocity -1. Expected: (0, 0) Received: (%f, %f)\n",
         obj1->getPosition().getX(), obj1->getPosition().getY());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setVelocity(df::Vector(1, 1));
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Update from (0,0) with x and y velocity 1. Expected: (sqrt(2), sqrt(2)) Received: (%f, %f)\n",
         obj1->getPosition().getX(), obj1->getPosition().getY());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setVelocity(df::Vector(1, 0));
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  df::WorldManager::getInstance().update();
  df::WorldManager::getInstance().update();
  printf("3 updates from (0,0) with x velocity 1. Expected: (3, 0) Received: (%f, %f)\n",
         obj1->getPosition().getX(), obj1->getPosition().getY());
  df::WorldManager::getInstance().removeObject(obj1);

  df::LogManager::getInstance().shutDown();
  df::WorldManager::getInstance().shutDown();
}

void testCollision() {
  df::LogManager::getInstance().startUp();
  df::WorldManager::getInstance().startUp();

  auto obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Object at (0,0), check collision with (1,1). Expected: 0 Received: %d\n",
         df::WorldManager::getInstance().isCollision(obj1, df::Vector(1,1)).getCount());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Object at (0,0), check collision with own space. Expected: 0 Received: %d\n",
         df::WorldManager::getInstance().isCollision(obj1, df::Vector(0,0)).getCount());
  df::WorldManager::getInstance().removeObject(obj1);

  obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  auto obj2 = new df::Object;
  obj2->setPosition(df::Vector(1, 1));
  df::WorldManager::getInstance().update();
  printf("Objects at (0,0) and (1, 1), check collision from first at (1, 1). Expected: 1 Received: %d\n",
         df::WorldManager::getInstance().isCollision(obj1, df::Vector(1,1)).getCount());
  df::WorldManager::getInstance().removeObject(obj1);
  df::WorldManager::getInstance().removeObject(obj2);

  obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  obj2 = new df::Object;
  obj2->setPosition(df::Vector(1, 1));
  obj2->setSolidness(df::Solidness::SOFT);
  df::WorldManager::getInstance().update();
  printf("Objects at (0,0) and (1, 1), with the second SOFT. Check collision from first at (1, 1). Expected: 1 Received: %d\n",
         df::WorldManager::getInstance().isCollision(obj1, df::Vector(1,1)).getCount());
  df::WorldManager::getInstance().removeObject(obj1);
  df::WorldManager::getInstance().removeObject(obj2);

  obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  obj2 = new df::Object;
  obj2->setPosition(df::Vector(1, 1));
  obj2->setSolidness(df::Solidness::SPECTRAL);
  df::WorldManager::getInstance().update();
  printf("Objects at (0,0) and (1, 1), with the second SPECTRAL. Check collision from first at (1, 1). Expected: 0 Received: %d\n",
         df::WorldManager::getInstance().isCollision(obj1, df::Vector(1,1)).getCount());
  df::WorldManager::getInstance().removeObject(obj1);
  df::WorldManager::getInstance().removeObject(obj2);

  obj1 = new df::Object;
  obj1->setPosition(df::Vector(0, 0));
  obj2 = new df::Object;
  obj2->setSolidness(df::Solidness::SPECTRAL);
  obj2->setPosition(df::Vector(0, 0));
  df::WorldManager::getInstance().update();
  printf("Set an object to hard in an occupied space. Should return error code. Expected: -1 Received: %d\n",
         obj2->setSolidness(df::Solidness::HARD));
  df::WorldManager::getInstance().removeObject(obj1);
  df::WorldManager::getInstance().removeObject(obj2);

  df::LogManager::getInstance().shutDown();
  df::WorldManager::getInstance().shutDown();
}

//An object the prints when collision and out of bounds events are recieved
class StepTestObj : public df::Object {
  public:
    int eventHandler(const df::Event* p_e) {
      if(p_e->getType() == "df::collision") {
        auto e = (dynamic_cast <const df::EventCollision*> (p_e));
        printf("Received collision event between id#%d and id#%d\n", e->getObject1()->getId(), e->getObject2()->getId());
      }

      if(p_e->getType() == "df::out") {
        printf("Received out event\n");
      }
      return 0;
    }
};

void testCollisionEvents() {
  df::GameManager::getInstance().startUp();

  auto obj1 = new StepTestObj;
  obj1->setPosition(df::Vector(0, 0));
  obj1->setVelocity(df::Vector(1, 0));
  auto obj2 = new StepTestObj;
  obj2->setPosition(df::Vector(1, 0));
  df::WorldManager::getInstance().update();
  printf("Objects at (0,0) and (1, 0), with first moving into second. Expected: two events received: \n");
  df::WorldManager::getInstance().removeObject(obj1);
  df::WorldManager::getInstance().removeObject(obj2);

  obj1 = new StepTestObj;
  obj1->setPosition(df::Vector(0, 0));
  obj1->setVelocity(df::Vector(99999, 0));
  df::WorldManager::getInstance().update();
  printf("Object moving with x velocity 99999 Expected: one events received: \n");
  df::WorldManager::getInstance().removeObject(obj1);

  df::GameManager::getInstance().shutDown();
}
