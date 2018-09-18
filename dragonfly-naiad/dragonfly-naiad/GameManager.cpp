#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Clock.h"
#include "EventStep.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

df::GameManager::GameManager() {
  setType("GameManager");
  game_over = false;
  loop_count = 0;
  frame_time = FRAME_TIME_DEFAULT;
}

df::GameManager::~GameManager() {
  if(isStarted()) {
    shutDown();
  }
}

df::GameManager& df::GameManager::getInstance() {
  static GameManager game_manager;
  return game_manager;
}

int df::GameManager::startUp() {
  game_over = false;
  loop_count = 0;

  auto log_success = df::LogManager::getInstance().startUp();
  df::LogManager::getInstance().setFlush(true); //We want flushing (at least right now)

  auto graphics_success = df::GraphicsManager::getInstance().startUp();
  auto world_success = df::WorldManager::getInstance().startUp();
  auto input_success = df::InputManager::getInstance().startUp();
  Manager::startUp();

  if(log_success >= 0 && world_success >= 0 && graphics_success >= 0 && input_success >= 0) {
    return 0;
    df::LogManager::getInstance().writeLog("GameManager: GameManager (and all other managers) successfully started\n");
  } else {
    df::LogManager::getInstance().writeLog("GameManager: One or more managers failed to start\n");
    return -1;
  }
}

void df::GameManager::shutDown() {
  df::LogManager::getInstance().shutDown();
  df::WorldManager::getInstance().shutDown();
  setGameOver(true);

  Manager::shutDown();
}

void df::GameManager::run() {
  Clock clock;
  while(!game_over) {
    clock.delta();

    // Get input
    InputManager::getInstance().getInput();

    // Update world state
    EventStep s(loop_count);
    onEvent(&s);
    WorldManager::getInstance().update();

    // Draw to back buffer
    WorldManager::getInstance().draw();

    // Swap buffers
    GraphicsManager::getInstance().swapBuffers();

    loop_count++;

    auto loop_time = clock.split();
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = ((frame_time * 1000) - loop_time) * 1000; //1000 msec in a nsec
    nanosleep(&sleep_time, nullptr);
  }
}

void df::GameManager::setGameOver(bool new_game_over) {
  game_over = new_game_over;
}

bool df::GameManager::getGameOver() const {
  return game_over;
}

int df::GameManager::getFrameTime() const {
  return frame_time;
}
