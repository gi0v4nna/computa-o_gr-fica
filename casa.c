#include <GL/glut.h>
#include <stdlib.h>
#include <GL/glu.h>

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    // triangulo -> teto da casa
    glBegin(GL_TRIANGLES);
    {
        glColor3b(0, 1, 0);
        glVertex2f(3, 0); //topo
        glVertex2f(1, 3); //- base - esquerd
        glVertex2f(5, 3); //- base - dir
    }
    glEnd();

    // quadrilatero -> teto da casa
    glBegin(GL_QUADS);
    {
        glColor3b(0, 0, 1); //cor do quadrilatero
        glVertex2f(3, 0);//a partir do topo
        glVertex2f(5, 3);//esq (-base - final do triang)
        glVertex2f(12, 3);//dir (- base - final do teto)
        glVertex2f(9, 0); //dir (cima)
    }
    glEnd();

    //quadrado vermelho
    glBegin(GL_QUADS);
    {
        glColor3b(1, 0, 0); 
        glVertex2f(1, 3);//topo esq 
        glVertex2f(5, 3);//topo dir
        glVertex2f(5, 8);//base dir
        glVertex2f(1, 8);//base esq
    }
    glEnd();

    //quadrado rosa (porta)
    glBegin(GL_QUADS);
    {
        glColor3b(1, 0, 1);
        glVertex2f(2, 6); //topo esq
        glVertex2f(4, 6); //topo dir
        glVertex2f(4, 10); //base dir
        glVertex2f(2, 10); //base esq
    }
    glEnd();

    //quadrado azul (trinco)
    glBegin(GL_QUADS);
    {
        glColor3b(0, 0.5, 1);
        glVertex2f(2.3, 8);
        glVertex2f(2.5,8);
        glVertex2f(2.5, 8.2);
        glVertex2f(2.3, 8.2);
    }
    glEnd();


    //quad azul marinho
    glBegin(GL_QUADS);
    {
        glColor3b(0, 0.25, 0.51);
        glVertex2f(5, 3);
        glVertex2f(12, 3);
        glVertex2f(12, 8);
        glVertex2f(5 ,8);

    }
    glEnd();

    //janela esq
    glBegin(GL_QUADS);
    {
        glColor3b(0, 0.51, 0.51);
        glVertex2f(5.5, 3.5);
        glVertex2f(7.5, 3.5);
        glVertex2f(7.5, 9.5);
        glVertex2f(5.5, 9.5);
    }

    // tapete azul
    glBegin(GL_QUADS);

    glVertex2f(1, 1); // origem
    glVertex2f(3, 3); // porta (vertice esquerd)
    glVertex2f(5, 3); // porta (vertice dir)
    glVertex2f(4, 1); // end
    glEnd();


}