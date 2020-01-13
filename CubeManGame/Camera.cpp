#include <gl/glut.h>
#include "Camera.h"

Camera::Camera() {
	this->x = 0;
	this->y = -5;
	this->z = 7;
	this->lookX = 0.0;
	this->lookY = 0.0;
	this->lookZ = 0.0;
}