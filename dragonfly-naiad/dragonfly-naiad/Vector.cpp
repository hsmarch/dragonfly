//
// Dragonfly Vector.cpp - Harrison March
//

//Engine Includes
#include "Vector.h"

Vector::Vector(int init_x, int init_y)
{
	x = init_x;
	y = init_y;
}

Vector::Vector()
{
	x = 0;
	y = 0;
}

void Vector::setX(int new_x)
{
	x = new_x;
}

int Vector::getX() const
{
	return x;
}

void Vector::setY(int new_y)
{
	y = new_y;
}

int Vector::getY() const
{
	return y;
}

void Vector::setXY(int new_x, int new_y)
{
	x = new_x;
	y = new_y;
}
