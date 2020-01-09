#pragma once
#include <gl/glut.h>
#include "Cube.h"

class Ghost {
public:

	Cube cube;
	int x, y;
	float scale;
	bool smart;

	Ghost();

	void translatePosition();

	void draw();

};