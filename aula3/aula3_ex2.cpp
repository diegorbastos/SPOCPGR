/*
Exercício 2: Limitar o Movimento dentro da Tela
Objetivo: Modifique o código base para impedir que o quadrado saia da área visível da janela.
Desafio: A área de visualização é de -1.0 a 1.0 em X e Y. Use if para verificar antes de
atualizar x e y.
*/

#include <GL/glut.h>
#include <cstdlib>

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int xMouse, int yMouse) {
    switch (key) {
    case 'w':
        if (y + step <= 0.9f) y += step; // Novo: impede sair por cima.
        break;
    case 's':
        if (y - step >= -0.9f) y -= step; // Novo: impede sair por baixo.
        break;
    case 'a':
        if (x - step >= -0.9f) x -= step; // Novo: impede sair pela esquerda.
        break;
    case 'd':
        if (x + step <= 0.9f) x += step; // Novo: impede sair pela direita.
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
    glutCreateWindow("Quadrado com limite - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
