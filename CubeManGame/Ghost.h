#pragma once
#include <gl/glut.h>
#include "Cube.h"
#include "Board.h"

class Ghost {
public:
	Cube cube;
	float x, y;
	float scale;
	bool smart;
	int index=0;
	int direction = rand() % 4 + 100;
	Ghost();
	void draw();
	void randomPosition(Board board);
	void translatePosition();
	bool loseValidator(int xPacman, int yPacman);
	void move(int xPacman, int yPacman, Board board);
	void smartMove(int xPacman, int yPacman, Board board);
	void randomMove(Board board);
};