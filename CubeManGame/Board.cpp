#include <gl/glut.h>
#include "Board.h"
#include <time.h>
extern const int TAB_SIZE;
extern const int CELL_SIZE;

Board::Board() {
	this->cube = Cube(1, 0, 0);
	map();
}

bool Board::haveCube(int x, int y) {
	return this->matrix[x][y];
}

void Board::map() {
	int idMap;
	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			this->matrix[x][y] = true;
		}
    }
	srand((int)time(0));
	idMap = rand() % 5;
	//switch (idMap) {
	switch (1) {
	case 1: 
		break;
	case 2: 
		break;
	case 3:
		break;
	case 4:
		//0
		this->matrix[0][10] = false;
		this->matrix[0][11] = false;
		this->matrix[0][8] = false;
		this->matrix[0][7] = false;
		this->matrix[0][5] = false;
		this->matrix[0][4] = false;
		this->matrix[0][3] = false;
		this->matrix[0][2] = false;
		this->matrix[0][1] = false;
		this->matrix[0][0] = false;
		//1
		this->matrix[1][11] = false;
		this->matrix[1][0] = false;
		//2
		this->matrix[2][9] = false;
		this->matrix[2][8] = false;
		this->matrix[2][0] = false;

		//3
		this->matrix[3][9] = false;
		this->matrix[3][8] = false;
		this->matrix[3][5] = false;
		this->matrix[3][4] = false;
		this->matrix[3][3] = false;
		this->matrix[3][2] = false;
		this->matrix[3][1] = false;
		this->matrix[3][0] = false;
		//4
		this->matrix[4][11] = false;
		this->matrix[4][5] = false;
		this->matrix[4][3] = false;
		//5
		this->matrix[5][11] = false;
		this->matrix[5][10] = false;
		this->matrix[5][5] = false;
		//6
		this->matrix[6][2] = false;
		//7
		this->matrix[7][2] = false;
		this->matrix[7][3] = false;
		//8
		this->matrix[8][11] = false;
		this->matrix[8][10] = false;
		this->matrix[8][9] = false;
		this->matrix[8][8] = false;
		this->matrix[8][2] = false;
		//10
		this->matrix[9][8] = false;
		this->matrix[9][5] = false;
		this->matrix[9][4] = false;
		//11
		this->matrix[10][1] = false;
		this->matrix[10][5] = false;
		this->matrix[10][4] = false;
		this->matrix[10][11] = false;
		//12
		this->matrix[11][1] = false;
		this->matrix[11][2] = false;
		this->matrix[11][11] = false;
		this->matrix[11][10] = false;
		break;
	}
}

void Board::draw() {
	glPushMatrix();
	// Centrar o tabuleiro no eixo XY e colocar o topo do tabuleiro no eixo dos Z (Z = 0).
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, -CELL_SIZE / 2);

	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			if (haveCube(x, y)) {
				glPushMatrix();
				glTranslatef(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, 0);
				glScalef(0.90, 0.90, 0.90);
				glColor3f(1.0, 0.0, 0.0);
				cube.draw();
				glPopMatrix();
			}
		}
	}

	glPopMatrix();
}