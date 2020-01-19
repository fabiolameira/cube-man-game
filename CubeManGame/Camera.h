#pragma once
#include <gl/glut.h>

class Camera {
public:
	float x, y, z;
	float lookX, lookY, lookZ;
	float distance;

	Camera();

	void move(float phi, float theta);

	void zoom(int button);
};