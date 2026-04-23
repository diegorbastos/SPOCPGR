/*
1- Explorando a Rasterizacao de Linhas Nativa

Objetivo: Usar as primitivas de linha do OpenGL e modificar o estado do
rasterizador para alterar como os pixels são desenhados.
- Crie uma janela básica usando GLUT.
- Dentro da função de desenho (display), utilize a primitiva GL_LINES para
desenhar o contorno de uma nave espacial simples (ou um controle de
videogame) usando apenas retas conectadas.
- Use a função glLineWidth(5.0f); antes do glBegin e observe o que
acontece com a espessura.
- Ative o modo de linha tracejada usando glEnable(GL_LINE_STIPPLE); e
configure o padrão com glLineStipple(1, 0x00FF);. Rode o programa
e veja como o OpenGL "quebra" a rasterização da reta
*/

#include <GL/glut.h>

void drawShipOutline() {
    glColor3f(0.0f, 0.9f, 1.0f);
    glLineWidth(5.0f);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF); // Configura o stipple para tracejar. Stipple = Varios pontos

    glBegin(GL_LINES);
        // Corpo principal.
        glVertex2f(0.0f, 0.65f);
        glVertex2f(-0.22f, 0.15f);

        glVertex2f(-0.22f, 0.15f);
        glVertex2f(-0.42f, -0.45f);

        glVertex2f(-0.42f, -0.45f);
        glVertex2f(-0.14f, -0.28f);

        glVertex2f(-0.14f, -0.28f);
        glVertex2f(0.0f, -0.62f);

        glVertex2f(0.0f, -0.62f);
        glVertex2f(0.14f, -0.28f);

        glVertex2f(0.14f, -0.28f);
        glVertex2f(0.42f, -0.45f);

        glVertex2f(0.42f, -0.45f);
        glVertex2f(0.22f, 0.15f);

        glVertex2f(0.22f, 0.15f);
        glVertex2f(0.0f, 0.65f);

        // Janela da nave.
        glVertex2f(-0.10f, 0.18f);
        glVertex2f(0.10f, 0.18f);

        glVertex2f(0.10f, 0.18f);
        glVertex2f(0.10f, -0.02f);

        glVertex2f(0.10f, -0.02f);
        glVertex2f(-0.10f, -0.02f);

        glVertex2f(-0.10f, -0.02f);
        glVertex2f(-0.10f, 0.18f);

        // Asa esquerda.
        glVertex2f(-0.22f, -0.05f);
        glVertex2f(-0.65f, -0.30f);

        glVertex2f(-0.65f, -0.30f);
        glVertex2f(-0.42f, -0.45f);

        // Asa direita.
        glVertex2f(0.22f, -0.05f);
        glVertex2f(0.65f, -0.30f);

        glVertex2f(0.65f, -0.30f);
        glVertex2f(0.42f, -0.45f);

        // Chamas do motor.
        glVertex2f(-0.10f, -0.45f);
        glVertex2f(-0.18f, -0.78f);

        glVertex2f(-0.18f, -0.78f);
        glVertex2f(0.0f, -0.64f);

        glVertex2f(0.0f, -0.64f);
        glVertex2f(0.18f, -0.78f);

        glVertex2f(0.18f, -0.78f);
        glVertex2f(0.10f, -0.45f);
    glEnd();

    glDisable(GL_LINE_STIPPLE);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    drawShipOutline();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.02f, 0.02f, 0.05f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Aula 5 - Linhas tracejadas - Nave");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
