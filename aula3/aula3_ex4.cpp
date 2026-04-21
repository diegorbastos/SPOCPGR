/*
Exercício 4: Mover com Setas do Teclado
Objetivo: Use a função glutSpecialFunc() para controlar o quadrado com as setas do
teclado.
Dica: A função recebe GLUT_KEY_LEFT, GLUT_KEY_RIGHT, GLUT_KEY_UP, GLUT_KEY_DOWN
*/

#include <GL/glut.h>
#include <cstdlib>

float x = 0.0f;
float y = 0.0f;
float r = 0.0f; 
float g = 0.0f;
float b = 0.0f;
float step = 0.1f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(r,g,b);
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
        if (y + step <= 0.9f) y += step;
        break;
    case 's':
        if (y - step >= -0.9f) y -= step;
        break;
    case 'a':
        if (x - step >= -0.9f) x -= step;
        break;
    case 'd':
        if (x + step <= 0.9f) x += step;
        break;
    case '1': 
        r = 1.0f; g = 0.0f; b = 0.0f; 
        break;
    case '2': 
        r = 0.0f; g = 1.0f; b = 0.0f; 
        break;
    case '3': 
        r = 0.0f; g = 0.0f; b = 1.0f; 
        break;
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

void specialKeys(int key, int xMouse, int yMouse) { // Novo: trata as setas do teclado.
    switch (key) { // Novo: verifica qual seta foi pressionada.
    case GLUT_KEY_UP:
        if (y + step <= 0.9f) y += step; // Novo: move para cima com a seta.
        break;
    case GLUT_KEY_DOWN:
        if (y - step >= -0.9f) y -= step; // Novo: move para baixo com a seta.
        break;
    case GLUT_KEY_LEFT:
        if (x - step >= -0.9f) x -= step; // Novo: move para a esquerda com a seta.
        break;
    case GLUT_KEY_RIGHT:
        if (x + step <= 0.9f) x += step; // Novo: move para a direita com a seta.
        break;
    }
    glutPostRedisplay(); // Novo: redesenha apos mover com as setas.
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
    glutCreateWindow("Quadrado anda com seta - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys); // Novo: registra a funcao das setas.
    glutMainLoop();
    return 0;
}
