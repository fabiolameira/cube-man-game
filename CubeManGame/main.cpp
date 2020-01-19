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
bool paused = false;

//Camera rotatian
int oldX, oldY;
bool rotate = false;
float theta = 1, phi = -1.57;

Board board = Board();
Camera camera = Camera();
Pacman pacman = Pacman();
Ghost* ghosts = new Ghost[numberOffGhosts];

void myInit() {
	bool matrix[TAB_SIZE][TAB_SIZE];
	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			matrix[x][y] = false;
		}
	}
	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].randomPosition(board);
		matrix[ghosts[i].x][ghosts[i].y]=true;
	}
	bool position=false;
	while (!position) {
		pacman.randomPosition(board);
		position = true;
		if (matrix[pacman.x][pacman.y]){
			position = false;
		}
		if (matrix[pacman.x+1][pacman.y]){
			position = false;
		}
		if (matrix[pacman.x-1][pacman.y]){
			position = false;
		}
		if (matrix[pacman.x][pacman.y+1]){
			position = false;
		}
		if (matrix[pacman.x][pacman.y-1]) {
			position = false;
		}
	}
}

void restartGame() {
	if (paused) paused = !paused;
	board = Board();
	myInit();
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

	if (!paused) {
		for (int i = 0; i < numberOffGhosts; i++) {
			ghosts[i].move(pacman.x, pacman.y, board);
		}

		glutPostRedisplay();
	}
	glutTimerFunc(v, update, v);
}

void mouseClick(int button, int state, int x, int y) {
	rotate = false;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		oldX = x;
		oldY = y;
		rotate = true;
	}

	if (button == 3 || button == 4) {
		camera.zoom(button);
		glutPostRedisplay();
	}
}

void mouseMove(int x, int y) {
	if (rotate) {
		phi += (x - oldX) * 0.002f;
		theta += (y - oldY) * 0.002f;
	}
	oldX = x;
	oldY = y;
	glutPostRedisplay();
}

void specialKeyboard(int key, int x, int y) {
	if (!paused) {
		pacman.move(key, board);
		glutPostRedisplay();
		for (int i = 0; i < numberOffGhosts; i++) {
			if (pacman.loseValidator(ghosts[i].x, ghosts[i].y)) {
				printf("---==YOU'RE A LOSER==---");
				printf(" ");
				printf(" ");
				exit(0);

			}
		}
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;
	case 'p':
	case 'P':
		paused = !paused;
		break;
	case 'r':
	case 'R':
		restartGame();
		break;
	}
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
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glEnable(GL_DEPTH_TEST);
	glutTimerFunc(timeUpdate, update, timeUpdate);
	glutMainLoop();
}