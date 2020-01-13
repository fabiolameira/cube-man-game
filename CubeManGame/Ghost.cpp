#include <gl/glut.h>
#include "Ghost.h"

extern const int TAB_SIZE;
extern const int CELL_SIZE;

Ghost::Ghost() {
	int randomNumber = rand() % 2;
	if (randomNumber == 1) {
		this->cube = Cube(1, 0, 1);
		this->smart = true;
	}
	else {
		this->cube = Cube(0, 0, 1);
		this->smart = false;
	}
	this->x = TAB_SIZE / 2;
	this->y = TAB_SIZE / 2;
	this->scale = 0.8;
}

void Ghost::move(int xPacman, int yPacman, Board board) {
	if (this->smart) {
		this->smartMove(xPacman, yPacman);
	}
	else {
		this->randomMove(board);
	}
}

void Ghost::smartMove(int xPacman, int yPacman) {
	int xResulting = xPacman - x;
	int yResulting = xPacman - x;
}

void Ghost::randomMove(Board board) {
	int direction = rand() % (103 - 100 + 1) + 100; //100-Left; 101-Up; 102-Rigth; 103-Down
	switch (direction) {
	case 100:
		if (this->x != 0 && board.haveCube(this->x - 1, this->y)) {
			this->x--;
		}
		break;
	case 101:
		if (this->y != TAB_SIZE - 1 && board.haveCube(this->x, this->y + 1)) {
			this->y++;
		}
		break;
	case 102:
		if (this->x != TAB_SIZE - 1 && board.haveCube(this->x + 1, this->y)) {
			this->x++;
		}
		break;
	case 103:
		if (this->y != 0 && board.haveCube(this->x, this->y - 1)) {
			this->y--;
		}
		break;
	}
}

void Ghost::translatePosition() {
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, CELL_SIZE / 2);
	glTranslatef(this->x * CELL_SIZE + CELL_SIZE / 2, this->y * CELL_SIZE + CELL_SIZE / 2, 0);
}

void Ghost::draw() {
	glPushMatrix();
	translatePosition();
	glScalef(this->scale, this->scale, 1);
	this->cube.draw();
	glPopMatrix();
}