#include <GL/glut.h>
#include "Board.h"
extern const int TAB_SIZE;
extern const int CELL_SIZE;

Board::Board() {
	this->cube = Cube(1, 0, 0);

	map();

}
bool Board::haveCube(int x, int y) {
	return this->matrix[x][y];
}

void Board::map()
{
	for (int x = 0; x < TAB_SIZE; x++){
		for (int y = 0; y < TAB_SIZE; y++) {
			this->matrix[x][y] = true;
		}
    }
	this->matrix[1][4] = false;
	this->matrix[1][5] = false;
	this->matrix[1][6] = false;
	this->matrix[2][4] = false;
	this->matrix[3][5] = false;
	this->matrix[3][6] = false;
	this->matrix[4][4] = false;
	this->matrix[4][5] = false;
	this->matrix[4][6] = false;

}
void Board::draw() {
	glPushMatrix();
	// Centrar o tabuleiro no eixo XY e colocar o topo do tabuleiro no eixo dos Z (Z = 0).
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, -CELL_SIZE / 2);

	for (int x = 0; x < TAB_SIZE; x++) {
		for (int y = 0; y < TAB_SIZE; y++) {
			if (haveCube(x, y))
			{
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