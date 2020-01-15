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
	bool exist=false;
	while (!exist) {
		this->x = rand() % TAB_SIZE-1;
		this->y = rand() % TAB_SIZE-1;
		exist = board.haveCube(this->x, this->y);
	}
}


bool Ghost::validateLoss(int xPacman, int yPacman) {
	if (this->x==xPacman&& this->y == yPacman){
		return true;
	}else if (this->x == xPacman+1 && this->y == yPacman){
			return true;
	}else if (this->x == xPacman-1 && this->y == yPacman){
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
	if (!validateLoss(xPacman, yPacman)){
		if (this->smart) {
			smartMove(xPacman, yPacman, board);
		}
		else {
			randomMove(board);
		}
	}
	else{
		printf("---==YOU'RE A LOSER==---");
		printf(" ");
		printf(" ");
		exit(0);
	}
}

void Ghost::smartMove(int xPacman, int yPacman, Board board) {
	int xResulting = xPacman-this->x;
	int yResulting = yPacman-this->y;
	bool muve = false;
	int i = 0;
	while (!muve){
		if (abs(xResulting)>= abs(yResulting)){
			if (xResulting>0){
				if (this->x != 0 && board.haveCube(this->x + 1, this->y)) {
					this->x++;
					muve = true;
				}else{
					i++;
					int aux;
					switch (i) {
						case 1:
							aux = xResulting;
							xResulting = yResulting;
							yResulting = aux;
						break;
						case 2:
							muve = true;
							break;
					}
				}
			}
			else {
				if (this->x != TAB_SIZE-1 && board.haveCube(this->x -1, this->y)) {
					this->x--;
					muve = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResulting;
						xResulting = yResulting;
						yResulting = aux;
						break;
					case 2:
						muve = true;
						break;
					}
				}
			}
		}
		else{
			if (yResulting > 0) {
				if (this->y != 0 && board.haveCube(this->x, this->y+1)) {
					this->y++;
					muve = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResulting;
						xResulting = yResulting;
						yResulting = aux;
						break;
					case 2:
						muve = true;
						break;
					}
				}
			}
			else {
				if (this->y != TAB_SIZE-1 && board.haveCube(this->x, this->y-1)) {
					this->y--;
					muve = true;
				}else {
					i++;
					int aux;
					switch (i) {
					case 1:
						aux = xResulting;
						xResulting = yResulting;
						yResulting = aux;
						break;
					case 2:
						muve = true;
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
			this->direction = rand() % (103 - 100 + 1) + 100;
		}
		break;
	case 101:
		if (this->y != TAB_SIZE - 1 && board.haveCube(this->x, this->y + 1)) {
			this->y++;
		}
		else {
			this->direction = rand() % (103 - 100 + 1) + 100;
		}
		break;
	case 102:
		if (this->x != TAB_SIZE - 1 && board.haveCube(this->x + 1, this->y)) {
			this->x++;
		}
		else {
			this->direction = rand() % (103 - 100 + 1) + 100;
		}
		break;
	case 103:
		if (this->y != 0 && board.haveCube(this->x, this->y - 1)) {
			this->y--;
		}else{
			this->direction = rand() % (103 - 100 + 1) + 100;
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