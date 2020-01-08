#include <gl/glut.h>

class Cube {
public:
	double x, y;
	float color[3];
	bool visible;

	Cube();

	Cube(double x, double y, bool visible, float red, float green, float);

};