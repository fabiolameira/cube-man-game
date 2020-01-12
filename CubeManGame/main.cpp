#include <gl/glut.h>
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"


// Constantes globais
extern const int CELL_SIZE = 2; // Tamanho da box (centrada na origem) onde as figuras são desenhadas.
extern const int TAB_SIZE = 12; // Tamanho (número de casas) do tabuleiro quadrado. TAB_SIZE tem que ser par (facilita o alinhamento).

// Variaveis globais
int timeUpdate = 500;


Pacman pacman = Pacman(1, 1);
Ghost ghost = Ghost();
Board board = Board();

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Camara
	gluLookAt(0, -5, 5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	// Redimensiona a mundo para caber na janela.
	glScalef(0.2, 0.2, 0.2);

	pacman.draw();
	board.draw();
	ghost.draw();

	glFlush();

	glutSwapBuffers();
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glFrustum(-2.0, 2.0, -2.0 * (float) h / (float) w, 2.0 * (float) h / (float) w, 3.0, 20.0);
	}
	else {
		glFrustum(-2.0 * (float) w / (float) h, 2.0 * (float) w / (float) h, -2.0, 2.0, 3.0, 20.0);
	}
	glMatrixMode(GL_MODELVIEW);
}

void update(int v) {
	board.draw();
	ghost.randomMove(pacman.x, pacman.y);

	glutPostRedisplay();
	glutTimerFunc(v, update, v);
}

void specialKeyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		if (pacman.y != TAB_SIZE - 1 && board.haveCube(pacman.x, pacman.y + 1)) {
			pacman.y++;
		}
		break;
	case GLUT_KEY_DOWN:
		if (pacman.y != 0 && board.haveCube(pacman.x, pacman.y - 1)) {
			pacman.y--;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (pacman.x != TAB_SIZE - 1 && board.haveCube(pacman.x + 1, pacman.y)) {
			pacman.x++;
		}
		break;
	case GLUT_KEY_LEFT:
		if (pacman.x != 0 && board.haveCube(pacman.x - 1, pacman.y)) {
			pacman.x--;
		}
		break;
	}
	board.toStep(pacman.x, pacman.y);
	if (board.validateVictory())
	{
		exit(0);
	}
	glutPostRedisplay();
}

void myInit() {

}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cube-Man Game");
	myInit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	//glutKeyboardFunc(teclas);
	glutSpecialFunc(specialKeyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glutTimerFunc(timeUpdate, update, timeUpdate);
	glutMainLoop();
}