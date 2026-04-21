#include <GL/glut.h> // Inclui a biblioteca GLUT/OpenGL.
#include <cstdlib> // Permite usar a funcao exit().
// Posicao do quadrado.
float x = 0.0f; // Guarda a posicao horizontal.
float y = 0.0f; // Guarda a posicao vertical.
float step = 0.1f; // Define o tamanho do movimento.
// Funcao para desenhar a cena.
void display() { // Inicia a funcao de desenho.
    glClear(GL_COLOR_BUFFER_BIT); // Limpa a tela.
    glLoadIdentity(); // Reseta as transformacoes.
    glTranslatef(x, y, 0.0f); // Move o quadrado.
    glBegin(GL_QUADS); // Comeca a desenhar um quadrado.
        glColor3f(1.0f, 0.0f, 0.0f); // Define a cor vermelha.
        glVertex2f(-0.1f, -0.1f); // Define o vertice inferior esquerdo.
        glVertex2f(0.1f, -0.1f); // Define o vertice inferior direito.
        glVertex2f(0.1f, 0.1f); // Define o vertice superior direito.
        glVertex2f(-0.1f, 0.1f); // Define o vertice superior esquerdo.
    glEnd(); // Finaliza o desenho.
    glutSwapBuffers(); // Mostra o buffer desenhado.
} // Fecha a funcao de desenho.
void keyboard(unsigned char key, int xMouse, int yMouse) { // Trata teclas pressionadas.
    switch (key) { // Verifica qual tecla foi pressionada.
    case 'w': y += step; break; // Move para cima.
    case 's': y -= step; break; // Move para baixo.
    case 'a': x -= step; break; // Move para a esquerda.
    case 'd': x += step; break; // Move para a direita.
    case 27: exit(0); // Fecha ao pressionar ESC.
    } // Fecha o switch.
    glutPostRedisplay(); // Solicita redesenho.

} // Fecha a funcao do teclado.
void init() { // Inicia as configuracoes do OpenGL.
    glClearColor(0.0, 0.0, 0.0, 1.0); // Define o fundo preto.
    glMatrixMode(GL_PROJECTION); // Seleciona a matriz de projecao.
    glLoadIdentity(); // Reseta a matriz atual.
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Define a area visivel.
} // Fecha a funcao de inicializacao.
// Funcao principal.
int main(int argc, char** argv) { // Ponto de entrada do programa.
    glutInit(&argc, argv); // Inicializa o GLUT.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Define buffer duplo e cor RGB.
    glutInitWindowSize(500, 500); // Define o tamanho da janela.
    glutCreateWindow("Controle com Teclado - OpenGL"); // Cria a janela.
    init(); // Aplica as configuracoes iniciais.
    glutDisplayFunc(display); // Registra a funcao de desenho.
    glutKeyboardFunc(keyboard); // Registra a funcao do teclado.
    glutMainLoop(); // Inicia o loop principal.
    return 0; // Encerra o programa.
} // Fecha a funcao principal.
