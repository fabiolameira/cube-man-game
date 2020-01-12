#include <gl/glut.h>
#include <time.h>
#include "Ghost.h"
extern const int TAB_SIZE;
extern const int CELL_SIZE;

Ghost::Ghost() {
	srand((int)time(0));//gera uma nova srand  para os valores seren diferentes cada ves que seija otilisada
	if ((rand() % 3) == 1) {
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

void Ghost::randomMove(int xPacman,int yPacman) {
	if (this->smart)
	{

	}
	else {
		this->x += 1;
	}
}
void Ghost::smartMove(int xPacman, int yPacman) {
	int xResulting = xPacman - x;
	int yResulting = xPacman - x;
	


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