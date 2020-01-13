#pragma once
#include <gl/glut.h>
#include "Cube.h"
#include "Board.h"

class Pacman {
public:
	Cube cube;
	int x, y;
	float scale;

	Pacman(int x, int y);
	void translatePosition();
	void draw();
	void move(int key, Board board);

};