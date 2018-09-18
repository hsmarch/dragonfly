#include "GameManager.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "Vector.h"
#include "Color.h"
#include "Object.h"

//An object the prints when events are received
class Test1Obj : public df::Object {
  public:
    void draw() {
      //Test corners
      df::GraphicsManager::getInstance().drawCh(df::Vector(0 ,  0), 'X', df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(79,  0), 'X', df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(0 , 23), 'X', df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(79, 23), 'X', df::COLOR_DEFAULT);

      //Write out a hello world to be cute
      df::GraphicsManager::getInstance().drawCh(df::Vector(2 , 0), 'H', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(3 , 0), 'E', df::YELLOW);
      df::GraphicsManager::getInstance().drawCh(df::Vector(4 , 0), 'L', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(5 , 0), 'L', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(6 , 0), 'O', df::CYAN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(7 , 0), ' ', df::WHITE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(8 , 0), 'W', df::MAGENTA);
      df::GraphicsManager::getInstance().drawCh(df::Vector(9 , 0), 'O', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(10 ,0), 'R', df::YELLOW);
      df::GraphicsManager::getInstance().drawCh(df::Vector(11, 0), 'L', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(12, 0), 'D', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(13, 0), '!', df::CYAN);

      df::GraphicsManager::getInstance().drawString(df::Vector(30, 20), "left justify", df::LEFT_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(30, 21), "center justify", df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(30, 22), "right justify", df::RIGHT_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawString(df::Vector(39, 23), "esc to quit", df::CENTER_JUSTIFIED, df::COLOR_DEFAULT);
    }

    //Quit on esc
    int eventHandler(const df::Event* p_e) {
      if(p_e->getType() == "df::keyboard") {
        if((dynamic_cast <const df::EventKeyboard*> (p_e))->getKey() == df::Keyboard::Key::ESCAPE) {
          df::GameManager::getInstance().setGameOver(true);
        }
      }
      return 0;
    }
};

class LowAltObj : public df::Object {
  public:
    LowAltObj() {
      setAltitude(0);
    }
    void draw() {
      df::GraphicsManager::getInstance().drawString(df::Vector(19, 5), "low altitude (red)", df::RIGHT_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(15, 5), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(15, 6), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(15, 7), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(15, 8), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 5), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 6), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 7), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 8), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 5), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 6), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 7), '#', df::RED);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 8), '#', df::RED);
    }
};
class MedAltObj : public df::Object {
  public:
    MedAltObj() {
      setAltitude(df::MAX_ALTITUDE / 2);
    }
    void draw() {
      df::GraphicsManager::getInstance().drawString(df::Vector(20, 6), "medium altitude (green)", df::RIGHT_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 6), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 7), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 8), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(16, 9), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 6), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 7), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 8), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 9), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18, 6), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18, 7), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18, 8), '#', df::GREEN);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18, 9), '#', df::GREEN);
    }
};
class HighAltObj : public df::Object {
  public:
    HighAltObj() {
      setAltitude(df::MAX_ALTITUDE);
    }
    void draw() {
      df::GraphicsManager::getInstance().drawString(df::Vector(21, 7), "high altitude (blue)", df::RIGHT_JUSTIFIED, df::COLOR_DEFAULT);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17,  7), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17,  8), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17,  9), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(17, 10), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18,  7), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18,  8), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18,  9), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(18, 10), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(19,  7), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(19,  8), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(19,  9), '#', df::BLUE);
      df::GraphicsManager::getInstance().drawCh(df::Vector(19, 10), '#', df::BLUE);
    }
};
