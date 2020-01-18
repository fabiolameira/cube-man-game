#include <gl/glut.h>
#include <math.h>
#include "Camera.h"

Camera::Camera() {
	this->x = 0;
	this->y = -5;
	this->z = 1;
	this->lookX = 0.0;
	this->lookY = 0.0;
	this->lookZ = 0.0;
	this->distance = 6;
}

void Camera::move(float phi, float theta) {
	this->x = this->lookX + this->distance * cos(phi) * sin(theta);
	this->y = this->lookY + this->distance * sin(phi) * sin(theta);
	this->z = this->lookZ + this->distance * cos(theta);

	gluLookAt(this->x, this->y, this->z, this->lookX, this->lookY, this->lookZ, 0, 1, 1);
}

void Camera::zoom(int button) { 
	float min = 6;
	float max = 12;

	switch (button) {
		case 3:
			if (this->distance < max) {
				this->distance += 0.05;
			}
			break;
		case 4:
			if (this->distance > min) {
				this->distance -= 0.05;
			}
			break;
	}

}