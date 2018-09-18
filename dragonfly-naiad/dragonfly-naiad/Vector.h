#pragma once

/*
A pair of floats with various convenience methods
*/
namespace df {
  class Vector {
    public:
      Vector();
      Vector(float init_x, float init_y);
      void setX(float new_x);
      float getX() const;
      void setY(float new_y);
      float getY() const;
      void setXY(float new_x, float new_y);
      void set(Vector new_pos);
      float getMagnitude() const;
      void normalize();
      void scale(float s);
      Vector operator+(const Vector &other) const;

    private:
      float x;
      float y;
  };
}
