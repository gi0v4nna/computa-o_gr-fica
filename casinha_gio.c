#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

void display(void)
{
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Define a cor de fundo da cena (cor
                                        // usada para limpar o buffer de cor)
  glClear(GL_COLOR_BUFFER_BIT);         // Inicializa o buffer de cores antes de ele
                                        // ser alterado

  glMatrixMode(GL_MODELVIEW); // Informa que as operações seguintes serão
                              // executadas na matrix modelview
  glLoadIdentity();           // Carrega a matriz identidade

  glPointSize(10); // Define quantos pixels representarão um vértice na tela

  // triangulo -> teto da casa
  glColor3f(0, 0.51, 0.25);
  glBegin(GL_TRIANGLES);
  {
    glVertex2f(-0.3, -0.3); // base - esq
    glVertex2f(0.3, -0.3);  // base - dir
    glVertex2f(0.0, 0.3);   // topo
  }
  glEnd();

  // quadrilatero -> teto da casa
  glColor3f(0, 0.51, 1.02); // cor do quadrilatero
  glBegin(GL_QUADS);
  {
    glVertex2f(0.3, -0.3); // base inf esq (começa na base dir)
    glVertex2f(1, -0.3);   // base inf dir
    glVertex2f(0.7, 0.3);  // dir superior
    glVertex2f(0.0, 0.3);  // dir (cima)
  }
  glEnd();

  // quadrado vermelho
  glColor3f(1.02, 0, 0);
  glBegin(GL_QUADS);
  {
    glVertex2f(-0.3, -0.7); // base inf esq
    glVertex2f(0.3, -0.7);  // base inf dir
    glVertex2f(0.3, -0.3);  // dir superior (igual base tri)
    glVertex2f(-0.3, -0.3); // esq superior
  }
  glEnd();

  // quadrado roxo (porta)
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  {
    glVertex2f(-0.2, -0.7);  // base inf esq
    glVertex2f(0.2, -0.7);  // base inf dir
    glVertex2f(0.2, -0.5); // dir sup
    glVertex2f(-0.2, -0.5); // esq sup
  }
  glEnd();

  // quadrado azul (trinco)
  glColor3f(0, 0.5, 1);
  glBegin(GL_QUADS);
  {    
    glVertex2f(2.3, 8);
    glVertex2f(2.5, 8);
    glVertex2f(2.5, 8.2);
    glVertex2f(2.3, 8.2);
  }
  glEnd();

  // quad azul marinho
  glColor3f(0, 0.25, 0.51);
  glBegin(GL_QUADS);
  {
    glVertex2f(0.3, -0.7);//base inf esq
    glVertex2f(1, -0.7);//base inf dir
    glVertex2f(1, -0.3);//dir sup
    glVertex2f(0.3, -0.3);//esq sup
  }
  glEnd();

  // janela esq
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  {    
    glVertex2f(0.4, -0.4);//base inf esq
    glVertex2f(0.6, -0.4);//base inf dir
    glVertex2f(0.6, -0.5);//dir sup
    glVertex2f(0.4, -0.5);//esq sup
  }
  glEnd();

  glColor3f(0, 1, 0.5);
  glBegin(GL_LINES);{
    glVertex2f(0.4, -0.45);
    glVertex2f(0.6, -0.45);
  }
  glEnd();

  glColor3f(0, 1, 0.5);
  glBegin(GL_LINES);{
    glVertex2f(0.5, -0.4);
    glVertex2f(0.5, -0.5);
  }
  glEnd();

  // janela dir
  glColor3f(0, 1, 1);
  glBegin(GL_QUADS);
  {    
    glVertex2f(0.75, -0.4);//base inf esq
    glVertex2f(0.95, -0.4);//base inf dir
    glVertex2f(0.95, -0.5);//dir sup
    glVertex2f(0.75, -0.5);//esq sup
  }
  glEnd();

  glColor3f(0, 1, 0.5);
  glBegin(GL_LINES);{
    glVertex2f(0.75, -0.45);
    glVertex2f(0.95, -0.45);
  }
  glEnd();

  glColor3f(0, 1, 0.5);
  glBegin(GL_LINES);{
    glVertex2f(0.85, -0.4);
    glVertex2f(0.85, -0.5);
  }
  glEnd();

  // tapete
  glBegin(GL_QUADS);
  {
  glVertex2f(-1, -1); // inf esq
  glVertex2f(-0.3, -1); // inf dir
  glVertex2f(0.2, -0.7); // sup dir
  glVertex2f(-0.2, -0.7); // sup esq
  }
  glEnd();

  glFlush(); // Informa que as operações devem ser processadas imediatamente e
             // exibidas na tela
}

/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h)
{
  if (h == 0)
    h = 1;

  printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:
    exit(0);
    break;
  case 32:
    glClearColor(1.0f, 1.0f, 1.0f,
                 1.0f); // Define a cor de fundo da cena (cor usada para
                        // limpar o buffer de cor)
    break;
  default:
    printf("Código tecla: %i. Mouse em (%i,%i)\n", key, x, y);
    break;
  }
  glutPostRedisplay(); // Informa que a janela atual deve ser redesenhada
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv); // Inicializa a OpenGL
  glutInitDisplayMode(
      GLUT_SINGLE |
      GLUT_RGB);                // Configura os modos de exibição (mais detalhes no futuro)
  glutInitWindowSize(600, 500); // Define o tamanho da janela em pixels
  glutInitWindowPosition(0, 0); // Define a posição inicial da janela
  glutCreateWindow(
      "Little house"); // Cria a janela especificando seu título
  glutDisplayFunc(
      display);               // Especifica a função de rendering (exibe a cena no loop)
  glutReshapeFunc(resize);    // Especifica função a ser executada quando a janela
                              // é redimensionada
  glutKeyboardFunc(keyboard); // Especifica função a ser executada quando uma
                              // tecla é pressionada

  glutMainLoop(); // Executa o loop de renderização
  return 0;
}
