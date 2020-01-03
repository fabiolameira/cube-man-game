#include <GL/glut.h>

// Variaveis globais
constexpr auto CELL_SIZE = 2.0; // Tamanho da box (centrada na origem) onde as figuras são desenhadas.
constexpr auto TAB_SIZE = 10; // Tamanho (número de casas) do tabuleiro quadrado. TAB_SIZE tem que ser par (facilita o alinhamento).
int numberOfCubes = 5;

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0},
						 {1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
						 {1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

GLfloat normals[][3] = { {-1.0,-1.0,-1.0}, {1.0,-1.0,-1.0},
						{1.0,1.0,-1.0}, {-1.0,1.0,-1.0}, {-1.0,-1.0,1.0},
						{1.0,-1.0,1.0}, {1.0,1.0,1.0}, {-1.0,1.0,1.0} };

GLfloat colors[][3] = { {0.0,0.0,0.0}, {1.0,0.0,0.0},
					   {1.0,1.0,0.0}, {0.0,1.0,0.0}, {0.0,0.0,1.0},
					   {1.0,0.0,1.0}, {1.0,1.0,1.0}, {0.0,1.0,1.0} };

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
	float scale;
	float color[3];
	float matrix[16]; // Matriz de rotação que define a posição actual do cubo.

public:
	Cube() {
		this->position = MyVector(rand() % TAB_SIZE, rand() % TAB_SIZE);
		this->rotation = MyVector();
		this->scale = 0.8;
		this->color[0] = rand() / RAND_MAX; // Red
		this->color[1] = rand() / RAND_MAX; // Green
		this->color[2] = rand() / RAND_MAX; // Blue
		drawCube();
	}

	MyVector getPosition() {
		return position;
	}

	void setPosition(MyVector position) {
		this->position = position;
	}

	MyVector getRotation() {
		return rotation;
	}

	void setRotation(MyVector rotation) {
		this->rotation = rotation;
	}

	void drawCube() {
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glGetFloatv(GL_MODELVIEW_MATRIX, this->matrix);
		glPopMatrix();
	}

	void selectCube() {
		this->scale *= 1.1;
	}

	void unselectCube() {
		this->scale /= 1.1;
	}

	void deleteCube() 	{
		free(this);
	}

};

Cube cube;
Cube* cubesArray = (Cube*)malloc(sizeof(Cube) * numberOfCubes);

void polygon(int a, int b, int c, int d) {
	glBegin(GL_POLYGON);
	glNormal3fv(normals[a]);
	glVertex3fv(vertices[a]);
	glNormal3fv(normals[b]);
	glVertex3fv(vertices[b]);
	glNormal3fv(normals[c]);
	glVertex3fv(vertices[c]);
	glNormal3fv(normals[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void lineloop(int a, int b, int c, int d) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube() {
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);

	lineloop(0, 3, 2, 1);
	lineloop(2, 3, 7, 6);
	lineloop(0, 4, 7, 3);
	lineloop(1, 2, 6, 5);
	lineloop(4, 5, 6, 7);
	lineloop(0, 1, 5, 4);
}

void drawMap() {
	glPushMatrix();

	// Centrar o tabuleiro no eixo XY e colocar o topo do tabuleiro no eixo dos Z (Z = 0).
	glTranslatef(-(TAB_SIZE * CELL_SIZE) / 2, -(TAB_SIZE * CELL_SIZE) / 2, -CELL_SIZE / 2);

	for (int i = 0; i < TAB_SIZE; i++)
		for (int j = 0; j < TAB_SIZE; j++) {
			glPushMatrix();
			glTranslatef(j * CELL_SIZE + CELL_SIZE / 2, i * CELL_SIZE + CELL_SIZE / 2, 0);
			glScalef(0.90, 0.90, 0.90);
			glColor3f(1.0, 0.0, 0.0);
			colorcube();  // Este cubo tem que ser desenhado dentro do CELL_SIZE.
						  // É o que acontece porque o cubo tem o tamanho do CELL_SIZE.
			glPopMatrix();
		}

	glPopMatrix();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Camara
	gluLookAt(0, -5, 1, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	// Redimensiona a mundo para caber na janela.
	glScalef(0.2, 0.2, 0.2);

	// Desenha o tabuleiro e os cubos.
	drawMap();
	//for (int i = 0; i < numberOfCubes; i++)
	//	desenhaCubo(aCubos[i]);

	glFlush();

	glutSwapBuffers();
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glFrustum(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
			2.0 * (GLfloat)h / (GLfloat)w, 3.0, 20.0);
	else
		glFrustum(-2.0 * (GLfloat)w / (GLfloat)h,
			2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, 3.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void myInit() {
	// Para que as linhas sejam bem desenhadas à volta dos cubos
	glPolygonOffset(1.0, 1.0);
	glEnable(GL_POLYGON_OFFSET_FILL);

	// Cria cubos em posições aleatórias.
	for (int i = 0; i < numberOfCubes; i++) {
		cubesArray[i] = Cube();
	}
	cube = cubesArray[0];
	cube.selectCube();
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
	//glutSpecialFunc(teclasEspeciais);
	glEnable(GL_DEPTH_TEST); /* Enable hidden--surface--removal */
	//glutTimerFunc(timeUpdate, update, timeUpdate);
	glutMainLoop();
}