#include <GL/glut.h>
#include "Cube.h"

Cube::Cube(double x, double y, bool visible) {
	this->x = x;
	this->y = y;
	this->color[0] = rand() / RAND_MAX; // Red
	this->color[1] = rand() / RAND_MAX; // Green
	this->color[2] = rand() / RAND_MAX; // Blue
}
