#include "GraphicsTester.cpp"
#include "InputTester.cpp"

//Forward declaration for project2-1 tests
void testClock();
void testEvents();
void testObjectList();
void testObjectListIterator();
void testGameManager();
void testWorldManager();
void testLogManager();

//Velocity tests
void testVelocity();
void testCollision();
void testCollisionEvents();

int main() {

  //Run graphics tests
  printf("\n##################################\n");
  printf(  "#          Graphics Test         #\n");
  printf(  "##################################\n\n");

  df::GameManager::getInstance().startUp();
  new Test1Obj;
  new HighAltObj; //Intentionally add in a weird order so they don't happen to draw in the right order
  new LowAltObj;
  new MedAltObj;
  df::GameManager::getInstance().run();
  df::GameManager::getInstance().shutDown();

  //Run input tests
  printf("\n##################################\n");
  printf(  "#           Input Test           #\n");
  printf(  "##################################\n\n");
  df::GameManager::getInstance().startUp();
  new InputTestObj;
  df::GameManager::getInstance().run();
  df::GameManager::getInstance().shutDown();

  //Run velocity tests
  printf("\n##################################\n");
  printf(  "#    Velocity/Collision Tests    #\n");
  printf(  "##################################\n\n");
  testVelocity();
  testCollision();
  testCollisionEvents();

  //Run project2-1 tests
  printf("\n##################################\n");
  printf(  "#        Project 2-A Tests       #\n");
  printf(  "##################################\n\n");
  testClock();
  testEvents();
  testObjectList();
  testObjectListIterator();
  testGameManager();
  testWorldManager();
  testLogManager();
}
