#include <gl/glut.h>
#include <stdlib.h> 
#include <stdio.h>
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

void Ghost::randomPosition(Board board) {
	bool exist = false;
	while (!exist) {
		this->x = rand() % TAB_SIZE;
		this->y = rand() % TAB_SIZE;
		exist = board.haveCube(this->x, this->y);
	}
}


bool Ghost::loseValidator(int xPacman, int yPacman) {
	if (this->x == xPacman && this->y == yPacman){
		return true;
	}else if (this->x == xPacman + 1 && this->y == yPacman){
			return true;
	}else if (this->x == xPacman - 1 && this->y == yPacman){
		return true;
	}else if (this->x == xPacman && this->y == yPacman-1){
		return true;
	}else if (this->x == xPacman && this->y == yPacman-1){
		return true;
	}else{
		return false;
	}
}

void Ghost::move(int xPacman, int yPacman, Board board) {
		if (this->smart) {
			smartMove(xPacman, yPacman, board);
		}
		else {
			randomMove(board);
		}
}

void Ghost::smartMove(int xPacman, int yPacman, Board board) {
	int xResult = xPacman - this->x;
	int yResult = yPacman - this->y;
	bool move = false;
	int i = 0;
	while (!move){
		if (abs(xResult)>= abs(yResult)){
			if (xResult>0){
				if (this->x >= 0 && board.haveCube(this->x + 1, this->y)) {
					this->x++;
					move = true;
				}else{
					i++;
					int aux;
					switch (i) {
						case 1:
							aux = xResult;
							xResult = yResult;
							yResult = aux;
						break;
						case 2:
							move = true;
							break;
					}
				}
			}
			else {
				if (this->x <= TAB_SIZE-1 && board.haveCube(this->x - 1, this->y)) {
					this->x--;
					move = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResult;
						xResult = yResult;
						yResult = aux;
						break;
					case 2:
						move = true;
						break;
					}
				}
			}
		}
		else{
			if (yResult > 0) {
				if (this->y >= 0 && board.haveCube(this->x, this->y + 1)) {
					this->y++;
					move = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResult;
						xResult = yResult;
						yResult = aux;
						break;
					case 2:
						move = true;
						break;
					}
				}
			}
			else {
				if (this->y <= TAB_SIZE-1 && board.haveCube(this->x, this->y - 1)) {
					this->y--;
					move = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResult;
						xResult = yResult;
						yResult = aux;
						break;
					case 2:
						move = true;
						break;
					}
				}
			}
		}
	}
}

void Ghost::randomMove(Board board) {
	switch (this->direction) {
	case 100:
		if (this->x != 0 && board.haveCube(this->x - 1, this->y)) {
			this->x--;
		}
		else {
			this->direction = rand() % 4 + 100;
		}
		break;
	case 101:
		if (this->y != TAB_SIZE - 1 && board.haveCube(this->x, this->y + 1)) {
			this->y++;
		}
		else {
			this->direction = rand() % 4 + 100;
		}
		break;
	case 102:
		if (this->x != TAB_SIZE - 1 && board.haveCube(this->x + 1, this->y)) {
			this->x++;
		}
		else {
			this->direction = rand() % 4 + 100;
		}
		break;
	case 103:
		if (this->y != 0 && board.haveCube(this->x, this->y - 1)) {
			this->y--;
		}else{
			this->direction = rand() % 4 + 100;
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