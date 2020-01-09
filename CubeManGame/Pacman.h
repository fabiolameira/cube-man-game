#include <gl/glut.h>
#include "Cube.h"

class Pacman {
public:

	Cube cube;
	int x, y;
	float scale;

	Pacman(int x, int y);

	void translatePosition();

	void draw();

};