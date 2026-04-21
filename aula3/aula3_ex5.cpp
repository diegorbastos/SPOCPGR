/*
Exercicio 5: Multiplos Objetos Independentes
Objetivo: Adicione dois quadrados com cores diferentes. Use teclas WASD para mover um, e
IJKL para mover o outro.
Desafio extra: Crie uma funcao generica drawSquare(float x, float y, float r, float g, float b)
para reutilizar codigo.
*/

#include <GL/glut.h>
#include <cstdlib>

float square1X = -0.4f; // Novo: posicao X do primeiro quadrado.
float square1Y = 0.0f; // Novo: posicao Y do primeiro quadrado.
float square2X = 0.4f; // Novo: posicao X do segundo quadrado.
float square2Y = 0.0f; // Novo: posicao Y do segundo quadrado.
float step = 0.1f;

void drawSquare(float x, float y, float r, float g, float b) { // Novo: desenha qualquer quadrado.
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x - 0.1f, y - 0.1f);
        glVertex2f(x + 0.1f, y - 0.1f);
        glVertex2f(x + 0.1f, y + 0.1f);
        glVertex2f(x - 0.1f, y + 0.1f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawSquare(square1X, square1Y, 1.0f, 0.0f, 0.0f); // Novo: primeiro quadrado vermelho.
    drawSquare(square2X, square2Y, 0.0f, 1.0f, 0.0f); // Novo: segundo quadrado verde.
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    switch (key) {
    case 'w':
        if (square1Y + step <= 0.9f) square1Y += step; // Novo: move o primeiro para cima.
        break;
    case 's':
        if (square1Y - step >= -0.9f) square1Y -= step; // Novo: move o primeiro para baixo.
        break;
    case 'a':
        if (square1X - step >= -0.9f) square1X -= step; // Novo: move o primeiro para a esquerda.
        break;
    case 'd':
        if (square1X + step <= 0.9f) square1X += step; // Novo: move o primeiro para a direita.
        break;
    case 'i':
        if (square2Y + step <= 0.9f) square2Y += step; // Novo: move o segundo para cima.
        break;
    case 'k':
        if (square2Y - step >= -0.9f) square2Y -= step; // Novo: move o segundo para baixo.
        break;
    case 'j':
        if (square2X - step >= -0.9f) square2X -= step; // Novo: move o segundo para a esquerda.
        break;
    case 'l':
        if (square2X + step <= 0.9f) square2X += step; // Novo: move o segundo para a direita.
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dois quadrados independentes - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
