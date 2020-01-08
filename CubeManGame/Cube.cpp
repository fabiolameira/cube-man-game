#include <gl/glut.h>
#include "Cube.h"

Cube::Cube(double x, double y, bool visible, float red, float green, float blue) {
	this->x = x;
	this->y = y;
	this->visible = visible;
	this->color[0] = red;
	this->color[1] = green;
	this->color[2] = blue;
}
