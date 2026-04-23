/*
2- Preenchimento automático e Interpolação de Cores.
Objetivo: Usar polígonos preenchidos e observar como a GPU interpola cores
nativamente (Gouraud Shading), substituindo a necessidade de um algoritmo de
Flood Fill manual.
- Desenhe um triângulo grande ocupando a maior parte da tela usando a
primitiva GL_TRIANGLES.-
- Para cada vértice (glVertex2f), declare uma cor diferente antes dele
usando glColor3f.
● Vértice 1: Vermelho (1.0, 0.0, 0.0)
● Vértice 2: Verde (0.0, 1.0, 0.0)
● Vértice 3: Azul (0.0, 0.0, 1.0)
- Rode o programa. Observe o gradiente perfeito gerado pelo rasterizador.
- Adicione o comando glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
no início do programa. O que aconteceu com o preenchimento? A tela deve
mostrar apenas as arestas do triângulo, revelando o "esqueleto" do polígono.
*/

#include <GL/glut.h>

void display () {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.5f);
    glEnd();
    glutSwapBuffers();
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
    glutInitWindowSize(700, 700);
    glutCreateWindow("Aula 5 - Triangulo RGB");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}