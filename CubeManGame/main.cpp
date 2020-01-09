#include <GL/glut.h>
#include "Pacman.h"
#include "Ghost.h"


// Variaveis globais
extern const int CELL_SIZE = 2; // Tamanho da box (centrada na origem) onde as figuras s�o desenhadas.
extern const int TAB_SIZE = 10; // Tamanho (n�mero de casas) do tabuleiro quadrado. TAB_SIZE tem que ser par (facilita o alinhamento).

Pacman pacman = Pacman(1, 1);
Ghost ghost = Ghost();

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Camara
	gluLookAt(0, -5, 1, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	// Redimensiona a mundo para caber na janela.
	glScalef(0.2, 0.2, 0.2);

	pacman.draw();
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

void specialKeyboard(int key, int x, int y) {
	pacman.move(key);
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
	//glutTimerFunc(timeUpdate, update, timeUpdate);
	glutMainLoop();
}