#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Camera.h"

// Constantes globais
extern const int CELL_SIZE = 2; // Tamanho da box (centrada na origem) onde as figuras são desenhadas.
extern const int TAB_SIZE = 12; // Tamanho (número de casas) do tabuleiro quadrado. TAB_SIZE tem que ser par (facilita o alinhamento).

// Variaveis globais
int timeUpdate = 500;
int numberOffGhosts = 5;

//Camera rotatian
int oldX, oldY;
bool rotate = false;
float theta = 0, phi = 0;

Board board = Board();
Camera camera = Camera();
Pacman pacman = Pacman();
Ghost* ghosts = new Ghost[numberOffGhosts];

void myInit() {
	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].randomPosition(board);
	}
	//pacman.randomPosition(board);
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Camara
	camera.move(phi, theta);

	// Redimensiona a mundo para caber na janela.
	glScalef(0.2, 0.2, 0.2);

	pacman.draw();
	board.draw();

	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].draw();
	}

	board.toStep(pacman.x, pacman.y);
	if (board.victoryValidator()) {
		printf("---==YOU'RE A WINNER==---");
		printf(" ");
		printf(" ");
		exit(0);
	}

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

	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].move(pacman.x, pacman.y, board);
	}

	glutPostRedisplay();
	glutTimerFunc(v, update, v);
}

void mouseClick(int button, int state, int x, int y) {
	rotate = false;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		oldX = x;
		oldY = y;
		rotate = true;
	}
}

void mouseMove(int x, int y) {
	if (rotate) {
		theta += (x - oldX) * 0.002f;
		phi += (y - oldY) * 0.002f;
	}
	oldX = x;
	oldY = y;
	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y) {
	pacman.move(key, board);
	glutPostRedisplay();
}

void main(int argc, char** argv) {
	myInit();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Cube-Man Game");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);
	glutSpecialFunc(specialKeyboard);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	glutTimerFunc(timeUpdate, update, timeUpdate);
	glutMainLoop();
}