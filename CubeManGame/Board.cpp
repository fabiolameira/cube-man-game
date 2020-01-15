#include <gl/glut.h>
#include <time.h>
#include "Board.h"
extern const int TAB_SIZE;
extern const int CELL_SIZE;

Board::Board() {
	this->cube = Cube(1, 0, 0);
	map();
}

bool Board::haveCube(int x, int y) {
	if ((x >= 0 && x < TAB_SIZE) && (y >= 0 && y < TAB_SIZE)) {
		return this->matrix[x][y];
	}
	else {
		return false;
	}
}

void Board::map() {
	int idMap;
	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			this->matrix[x][y] = true;
		}
    }
	srand((int)time(0));
	idMap = rand() % 4;
	switch (idMap) {
	//switch (4) {
	case 1: 
		this->matrix[0][1] = false;
		this->matrix[0][6] = false;
		this->matrix[0][10] = false;
		this->matrix[1][3] = false;
		this->matrix[1][4] = false;
		this->matrix[1][6] = false;
		this->matrix[1][8] = false;
		this->matrix[2][2] = false;
		this->matrix[2][3] = false;
		this->matrix[2][4] = false;
		this->matrix[2][6] = false;
		this->matrix[2][8] = false;
		this->matrix[2][9] = false;
		this->matrix[2][10] = false;
		this->matrix[3][0] = false;
		this->matrix[3][2] = false;
		this->matrix[3][9] = false;
		this->matrix[3][10] = false;
		this->matrix[3][11] = false;
		this->matrix[4][2] = false;
		this->matrix[4][4] = false;
		this->matrix[4][6] = false;
		this->matrix[4][7] = false;
		this->matrix[5][1] = false;
		this->matrix[5][2] = false;
		this->matrix[5][4] = false;
		this->matrix[5][9] = false;
		this->matrix[5][10] = false;
		this->matrix[6][1] = false;
		this->matrix[6][2] = false;
		this->matrix[6][7] = false;
		this->matrix[6][9] = false;
		this->matrix[6][10] = false;
		this->matrix[7][4] = false;
		this->matrix[7][5] = false;
		this->matrix[7][7] = false;
		this->matrix[7][9] = false;
		this->matrix[8][0] = false;
		this->matrix[8][1] = false;
		this->matrix[8][2] = false;
		this->matrix[8][9] = false;
		this->matrix[8][11] = false;
		this->matrix[9][1] = false;
		this->matrix[9][2] = false;
		this->matrix[9][3] = false;
		this->matrix[9][5] = false;
		this->matrix[9][7] = false;
		this->matrix[9][8] = false;
		this->matrix[9][9] = false;
		this->matrix[10][3] = false;
		this->matrix[10][5] = false;
		this->matrix[10][7] = false;
		this->matrix[10][8] = false;
		this->matrix[11][1] = false;
		this->matrix[11][5] = false;
		this->matrix[11][10] = false;
		break;
	case 2: 
		this->matrix[3][3] = false;
		this->matrix[3][4] = false;
		this->matrix[4][3] = false;
		this->matrix[4][4] = false;
		break;
	case 3:
		this->matrix[0][5] = false;
		this->matrix[0][6] = false;
		this->matrix[1][1] = false;
		this->matrix[1][2] = false;
		this->matrix[1][3] = false;
		this->matrix[1][5] = false;
		this->matrix[1][6] = false;
		this->matrix[1][8] = false;
		this->matrix[1][9] = false;
        this->matrix[1][10] = false;
		this->matrix[2][1] = false;
		this->matrix[2][2] = false;
		this->matrix[2][9] = false;
		this->matrix[2][10] = false;
		this->matrix[3][1] = false;
		this->matrix[3][10] = false;
		this->matrix[3][4] = false;
		this->matrix[3][7] = false;
		this->matrix[4][3] = false;
		this->matrix[4][8] = false;
		this->matrix[5][0] = false;
		this->matrix[5][1] = false;
		this->matrix[5][10] = false;
		this->matrix[5][11] = false;
		this->matrix[6][0] = false;
		this->matrix[6][1] = false;
		this->matrix[6][10] = false;
		this->matrix[6][11] = false;
		this->matrix[8][1] = false;
		this->matrix[8][10] = false;
		this->matrix[8][4] = false;
		this->matrix[8][7] = false;
		this->matrix[7][3] = false;
		this->matrix[7][8] = false;
		this->matrix[9][1] = false;
		this->matrix[9][2] = false;
		this->matrix[9][9] = false;
		this->matrix[9][10] = false;
		this->matrix[10][1] = false;
		this->matrix[10][2] = false;
		this->matrix[10][3] = false;
		this->matrix[10][8] = false;
		this->matrix[10][9] = false;
		this->matrix[10][10] = false;
		this->matrix[10][6] = false;
		this->matrix[10][5] = false;
		this->matrix[11][6] = false;
		this->matrix[11][5] = false;
		break;
	case 4:
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
		this->matrix[1][11] = false;
		this->matrix[1][0] = false;
		this->matrix[2][9] = false;
		this->matrix[2][8] = false;
		this->matrix[2][0] = false;
		this->matrix[3][9] = false;
		this->matrix[3][8] = false;
		this->matrix[3][5] = false;
		this->matrix[3][4] = false;
		this->matrix[3][3] = false;
		this->matrix[3][2] = false;
		this->matrix[3][1] = false;
		this->matrix[3][0] = false;
		this->matrix[4][11] = false;
		this->matrix[4][5] = false;
		this->matrix[4][3] = false;
		this->matrix[5][11] = false;
		this->matrix[5][10] = false;
		this->matrix[5][5] = false;
		this->matrix[6][2] = false;
		this->matrix[7][2] = false;
		this->matrix[7][3] = false;
		this->matrix[8][11] = false;
		this->matrix[8][10] = false;
		this->matrix[8][9] = false;
		this->matrix[8][8] = false;
		this->matrix[8][2] = false;
		this->matrix[9][8] = false;
		this->matrix[9][5] = false;
		this->matrix[9][4] = false;
		this->matrix[10][1] = false;
		this->matrix[10][5] = false;
		this->matrix[10][4] = false;
		this->matrix[10][11] = false;
		this->matrix[11][1] = false;
		this->matrix[11][2] = false;
		this->matrix[11][11] = false;
		this->matrix[11][10] = false;
		break;

	}
	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			this->matrixStep[x][y] = !this->matrix[x][y];
		}
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
				glTranslatef(x * CELL_SIZE + CELL_SIZE / 2, y * CELL_SIZE + CELL_SIZE / 2, 1);
				glScalef(0.90, 0.90, 0.20);
				glColor3f(1.0, 0.0, 0.0);
				if (this->matrixStep[x][y]) {
					cube.setColor(0, 1, 0);
				}
				else {
					cube.setColor(1, 0, 0);
				}
				cube.draw();
				glPopMatrix();
			}
		}
	}

	glPopMatrix();
}

void Board::toStep(int x, int y) {
	this->matrixStep[x][y] = true;
}

bool Board::victoryValidator() {
	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			if (!matrixStep[x][y]) {
				return false;
			}			
		}
	}
	return true;
}