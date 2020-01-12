#include <gl/glut.h>
#include "Cube.h"

Cube::Cube() {
	this->color[0] = 1;
	this->color[1] = 0;
	this->color[2] = 0;
}

Cube::Cube(float red, float green, float blue) {
	this->color[0] = red;
	this->color[1] = green;
	this->color[2] = blue;
}
void Cube::setColor(float red, float green, float blue){
this->color[0] = red;
this->color[1] = green;
this->color[2] = blue;
}

void Cube::polygon(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
	glNormal3fv(this->normals[a]);
	glVertex3fv(this->vertices[a]);
	glNormal3fv(this->normals[b]);
	glVertex3fv(this->vertices[b]);
	glNormal3fv(this->normals[c]);
	glVertex3fv(this->vertices[c]);
	glNormal3fv(this->normals[d]);
	glVertex3fv(this->vertices[d]);
	glEnd();
}

void Cube::lineLoop(int a, int b, int c, int d) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(this->vertices[a]);
	glVertex3fv(this->vertices[b]);
	glVertex3fv(this->vertices[c]);
	glVertex3fv(this->vertices[d]);
	glEnd();
}

void Cube::draw() {
	glColor3fv(this->color);
	this->polygon(0, 3, 2, 1);
	this->polygon(2, 3, 7, 6);
	this->polygon(0, 4, 7, 3);
	this->polygon(1, 2, 6, 5);
	this->polygon(4, 5, 6, 7);
	this->polygon(0, 1, 5, 4);

	this->lineLoop(0, 3, 2, 1);
	this->lineLoop(2, 3, 7, 6);
	this->lineLoop(0, 4, 7, 3);
	this->lineLoop(1, 2, 6, 5);
	this->lineLoop(4, 5, 6, 7);
	this->lineLoop(0, 1, 5, 4);
}