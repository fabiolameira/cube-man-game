#include <GL/glut.h>

// Tamanho da box (centrada na origem) onde as figuras são desenhadas.
constexpr auto TAB_SIZE = 10;
// Tamanho (número de casas) do tabuleiro quadrado. TAB_SIZE tem que ser par (facilita o alinhamento).
constexpr auto TAB_SIZE = 10;

class MyVector {
public:
	float x;
	float y;

	MyVector() {
		this->x = 0;
		this->y = 0;
	}

	MyVector(float x, float y) {
		this->x = x;
		this->y = y;
	}

};

class Cube {
private:

	MyVector position; // Posição do cubo nas casas do tabuleiro.
	MyVector rotation; // Rotação necessária em x e em y em graus multiplos de 90.
	float color[3];

};