#include <gl/glut.h>

class Pacman {
public:
	
	int speed;
	double angle; //Anglo de rotacao necessária em x e em y em graus multiplos de 90
	int x, y;
	bool animate;
	float color[3];

	Pacman(int, int);

	void draw();

	void move(); //move the pacman

	void reinit();  //reinitialize everything

};