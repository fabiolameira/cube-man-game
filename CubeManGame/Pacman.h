#pragma once
#include <gl/glut.h>
#include "Cube.h"
#include "Board.h"

class Pacman {
public:
	Cube cube;
	float x, y;
	float scale;
	int index;
	int direction;

	Pacman();
	void randomPosition(Board board);
	bool loseValidator(int xGhosts, int yGhosts);
	void translatePosition();
	void draw();
	void move(Board board);

};