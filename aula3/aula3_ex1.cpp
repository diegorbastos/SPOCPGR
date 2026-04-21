/*
1- Controle de um Quadrado com Teclado e Clique do Mouse
Objetivo:
-Criar um programa em C++ com OpenGL onde:
-Um quadrado se move pela tela com as teclas W, A, S, D.
-Ao clicar com o botão esquerdo do mouse, o quadrado muda de cor para vermelho.
-Ao clicar com o botão direito do mouse, o quadrado volta à cor original (azul).
-Utilize GLUT_LEFT_BUTTON e GLUT_RIGHT_BUTTON e glutPostRedisplay();

2- Comente as funções keyboard() e mouse() explicando o que cada linha faz.

3- Adapte o código para que:
-O quadrado aumente de tamanho com a tecla +.
-Diminua com a tecla -.

4- Faça com que o clique do botão do meio reinicie a posição do quadrado para (0,0)
*/

#include <GL/glut.h>
#include <cstdlib>

float x = 0.0f;
float y = 0.0f;
float r = 0.0f;
float g = 0.0f;
float b = 1.0f;
float step = 0.1f;
float size = 0.1f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    glBegin(GL_QUADS);
        glColor3f(r, g, b);
        glVertex2f(-size, -size);
        glVertex2f(size, -size);
        glVertex2f(size, size);
        glVertex2f(-size, size);
    glEnd();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int, int) {
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
    case '+':
        size += 0.1f;
        break;
    case '-':
        if (size > 0.05f) size -= 0.1f;
        break;
     
    case 27:
        exit(0);
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int, int) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            r = 1.0f; g = 0.0f; b = 0.0f;
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            r = 0.0f; g = 0.0f; b = 1.0f;
        }
        else if (button == GLUT_MIDDLE_BUTTON) {
            x = 0.0f; y = 0.0f;
        }
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
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
