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
int pontuation = 0;
bool paused = false;
bool keyPress = false;

//Camera rotation
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
		int x = pacman.x;
		int y = pacman.y;
		if (matrix[x][y]){
			position = false;
		}
		if (matrix[x+1][y]){
			position = false;
		}
		if (matrix[x-1][y]){
			position = false;
		}
		if (matrix[x][y+1]){
			position = false;
		}
		if (matrix[x][y-1]) {
			position = false;
		}
	}
}

void restartGame() {
	if (paused) paused = !paused;
	pontuation = 0;
	board = Board();
	pacman = Pacman();
	ghosts = new Ghost[numberOffGhosts];
	myInit();
}

void youWin() {

	paused = !paused;
	pacman.cube.color[0] = 0;
	pacman.cube.color[1] = 1;
	pacman.cube.color[2] = 0;

	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].cube.color[0] = 0;
		ghosts[i].cube.color[1] = 1;
		ghosts[i].cube.color[2] = 0;
	}

	printf("         ---==YOU'RE A WINNER==---\n");
	printf("Congratulations! You have made: (%i) points :)\n", (int)pontuation);
}

void youLose() {

	paused = !paused;
	pacman.cube.color[0] = 1;
	pacman.cube.color[1] = 0;
	pacman.cube.color[2] = 0;

	for (int i = 0; i < numberOffGhosts; i++) {
		ghosts[i].cube.color[0] = 1;
		ghosts[i].cube.color[1] = 0;
		ghosts[i].cube.color[2] = 0;
	}

	printf("      ---==YOU'RE A LOSER==---\n");
	printf("Game Over! You have made: (%i) points :)\n", (int)pontuation);
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
		youWin();
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
			if (!ghosts[i].loseValidator(pacman.x, pacman.y)) {
				ghosts[i].move(pacman.x, pacman.y, board);
			}
			else {
				youLose();
			}
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

void updatePacman(int v) {
	pacman.move(board);
	pacman.draw();
	if (pacman.index==9){
		pacman.index=0;
		pacman.x = round(pacman.x);
		pacman.y = round(pacman.y);
		board.toStep(pacman.x, pacman.y);
		keyPress = false;
	}else {
		pacman.index++;
		glutTimerFunc(10, updatePacman, 10);
	}
	glutPostRedisplay();
}


void specialKeyboard(int key, int x, int y) {
	if (!paused && !keyPress) {
		keyPress = true;
		pacman.direction = key;
		pacman.index=0;
		glutTimerFunc(10, updatePacman, 10);
		board.toStep(pacman.x, pacman.y);
		pontuation++;
		for (int i = 0; i < numberOffGhosts; i++) {
			if (pacman.loseValidator(ghosts[i].x, ghosts[i].y)) {
				youLose();
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