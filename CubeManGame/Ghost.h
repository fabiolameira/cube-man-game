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

	void draw();
	void translatePosition();
	void randomMove(int xPacman, int yPacman);
	void smartMove(int xPacman,int yPacman);
};