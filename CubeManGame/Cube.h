#pragma once
#include <gl/glut.h>

class Cube {
public:
	float color[3];

	float vertices[8][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0},
						 {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
						 {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

	float normals[8][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0},
						{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
						{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

	float colors[8][3] = { {0.0,0.0,0.0}, {1.0,0.0,0.0},
					   {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
					   {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };

	Cube();

	void setColor(float red, float green, float blue);

	Cube(float red, float green, float blue);

	void polygon(int a, int b, int c, int d);

	void lineLoop(int a, int b, int c, int d);

	void draw();
};