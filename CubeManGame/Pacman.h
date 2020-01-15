#pragma once
#include <gl/glut.h>
#include "Cube.h"
#include "Board.h"

class Pacman {
public:
	Cube cube;
	int x, y;
	float scale;

	Pacman();
	void randomPosition(Board board);
	void translatePosition();
	void draw();
	void move(int key, Board board);

};