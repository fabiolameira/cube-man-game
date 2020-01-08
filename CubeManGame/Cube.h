#include <gl/glut.h>

class Cube {
public:
	double x, y;
	float color[3];
	bool visible;

	Cube(double, double, bool);

};