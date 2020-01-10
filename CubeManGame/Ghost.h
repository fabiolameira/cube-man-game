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

	void randomMove();

	void translatePosition();

	void draw();

};