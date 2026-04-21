/*
Exercício 3: Mudar a Cor com Teclas Numéricas
Objetivo: Permitir que o usuário altere a cor do quadrado com as teclas 1, 2, 3.
● 1 → vermelho
● 2 → verde
● 3 → azul
Dica: Crie variáveis float r, g, b e use-as no glColor3f.
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
        glColor3f(r,g,b); // Novo: usa as variaveis de cor.
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
        break; // Novo: vermelho.
    case '2': 
        r = 0.0f; g = 1.0f; b = 0.0f; 
        break; // Novo: verde.
    case '3': 
        r = 0.0f; g = 0.0f; b = 1.0f; 
        break; // Novo: azul.
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
    glutCreateWindow("Quadrado com limite que muda de cor - OpenGL");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
