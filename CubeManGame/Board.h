#pragma once
#include <gl/glut.h>
#include "Cube.h"
extern const int TAB_SIZE;
extern const int CELL_SIZE;
class Board : public Cube {
public:
    bool matrix[10][10];
	Cube cube;
	Board();
	bool haveCube(int x, int y);
	void map();
	void draw();


};
