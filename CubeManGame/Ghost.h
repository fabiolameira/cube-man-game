#pragma once
#include <gl/glut.h>
#include "Cube.h"
#include "Board.h"

class Ghost {
public:
	Cube cube;
	int x, y;
	float scale;
	bool smart;
	int direction = rand() % (103 - 100 + 1) + 100;
	Ghost();
	void draw();
	void randomPosition(Board board);
	void translatePosition();
	bool validateLoss(int xPacman, int yPacman);
	void move(int xPacman, int yPacman, Board board);
	void smartMove(int xPacman, int yPacman, Board board);
	void randomMove(Board board);
};