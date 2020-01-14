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

	Ghost();

	void draw();
	void translatePosition();
	bool validateLoss(int xPacman, int yPacman);
	void move(int xPacman, int yPacman, Board board);
	void smartMove(int xPacman, int yPacman, Board board);
	void randomMove(Board board);
};