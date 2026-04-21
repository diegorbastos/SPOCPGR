/*
Exercício 1: Mover um Círculo com o Teclado
Objetivo: Trocar o quadrado por um círculo e movimentá-lo com as teclas W, A, S, D.
Dica: Use GL_TRIANGLE_FAN e um for para gerar os vértices do círculo.
*/

#include <GL/glut.h>
#include <cstdlib>
#include <cmath> // Novo: permite usar seno e cosseno.

float x = 0.0f;
float y = 0.0f;
float step = 0.1f;
float radius = 0.15f; // Novo: raio do circulo.
int segments = 50; // Novo: quantidade de partes do circulo.

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_TRIANGLE_FAN); // Novo: desenha o circulo usando triangulos.
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.0f); // Novo: centro do circulo.
        for (int i = 0; i <= segments; i++) { // Novo: gera os vertices da borda.
            float angle = 2.0f * 3.14159f * i / segments;
            float vx = radius * cos(angle);
            float vy = radius * sin(angle);
            glVertex2f(vx, vy);
        }
    glEnd();
    glutSwapBuffers();
}
void keyboard(unsigned char key, int xMouse, int yMouse) {
    switch (key) {
    case 'w': y += step; break;
    case 's': y -= step; break;
    case 'a': x -= step; break;
    case 'd': x += step; break;
    case 27: exit(0);
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
    glutCreateWindow("Controle com Teclado - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
