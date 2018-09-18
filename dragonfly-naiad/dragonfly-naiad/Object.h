#pragma once

#include <string.h>

#include "Vector.h"
#include "Event.h"

/*
A general game object. Has a position, type, and id. Can receive events
*/
namespace df {
  enum Solidness {
    HARD,
    SOFT,
    SPECTRAL,
  };

  class Object {
    public:
      Object();
      virtual ~Object();
      void setId(int new_id);
      int getId() const;
      void setType(std::string new_type);
      std::string getType() const;
      void setPosition(Vector new_pos);
      void setPosition(float x, float y);
      Vector getPosition() const;
      void setAltitude(int new_altitude);
      int getAltitude() const;
      void setSpeed(float new_speed);
      float getSpeed() const;
      void setDirection(Vector new_direction);
      Vector getDirection() const;
      Vector getVelocity() const;
      void setVelocity(Vector new_velocity);
      Vector predictPosition();
      virtual int eventHandler(const Event* p_e); //Handle an event
      virtual void draw(); //Draw self
      bool isSolid() const;
      int setSolidness(Solidness new_solid); //Sets solidness, returns 0 if ok, -1 if inconsisent.
      Solidness getSolidness() const;

    private:
      int id;
      std::string type;
      Vector position;
      int altitude;
      Vector direction;
      float speed;
      Solidness solidness;
  };
}
