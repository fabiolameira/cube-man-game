#include <GL/glut.h>
#include "Pacman.h"

Pacman::Pacman(int x, int y) {
	this->x = x;
	this->y = y;
	this->angle = 90;
	this->speed = 0.1;
	this->animate = false;
	this->color[0] = rand() / RAND_MAX; // Red
	this->color[1] = rand() / RAND_MAX; // Green
	this->color[2] = rand() / RAND_MAX; // Blue

}

void Pacman::draw() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glPopMatrix();
}