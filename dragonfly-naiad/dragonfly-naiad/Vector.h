#ifndef __Vector_H__
#define __Vector_H__

class Vector
{
private:
	int x;
	int y;

public:
	Vector(int init_x, int init_y);
	Vector();

	void setX(int new_x);
	int getX() const;
	void setY(int new_y);
	int getY() const;

	void setXY(int new_x, int new_y);
};

#endif
