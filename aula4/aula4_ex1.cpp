/*
Desenha Casita
*/

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7f, 0.0f);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f(0.3f, -0.1f);
        glVertex2f(0.3f, 0.2f);
        glVertex2f(-0.3f, 0.2f);
    glEnd();
    //glutSwapBuffers();

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(0.3f, 0.2f);
        glVertex2f(0.0f, 0.4f);
    glEnd();
    //glutSwapBuffers();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.2f, -0.1f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(-0.1f, 0.07f);
        glVertex2f(-0.2f, 0.07f);
    glEnd();
    //glutSwapBuffers();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.5f);
        glVertex2f(0.1f, 0.03f);
        glVertex2f(0.2f, 0.03f);
        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.1f, 0.1f);
    glEnd();
    glutSwapBuffers();
}

void init () {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutCreateWindow("Casita");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}