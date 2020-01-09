#include <gl/glut.h>
#include "Pacman.h"
extern const int TAB_SIZE;
extern const int CELL_SIZE;

Pacman::Pacman(int x, int y) {
	this->cube = Cube(1, 1, 0);
	this->x = x;
	this->y = y;
	this->scale = 0.8;
}

void Pacman::translatePosition() {
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, CELL_SIZE / 2);
	glTranslatef(this->x * CELL_SIZE + CELL_SIZE / 2, this->y * CELL_SIZE + CELL_SIZE / 2, 0);
}

void Pacman::draw() {
	glPushMatrix();
	translatePosition();
	glScalef(this->scale, this->scale, 1);
	this->cube.draw();
	glPopMatrix();
}