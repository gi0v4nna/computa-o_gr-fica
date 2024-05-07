#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

int ombro = 0, cotovelo = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    { // ombro
        glPushMatrix();
        {
            glTranslatef(-0.5, 0, 0); //esquerda
            glRotatef(ombro, 0, 0, 1);
            glTranslatef(0.5, 0, 0);//volta pro centro
            glColor3f(0.5, 0.0, 0.0);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);

            glPushMatrix();
            {
                glTranslatef(1.0, 0.0, 0.0);
                glRotatef(cotovelo, 0, 0, 1);
                glColor3f(0.0, 0.0, 0.5);
                glutWireCube(1.0);
            }
            glPopMatrix();
        }
        glPopMatrix();

        // cotovelo
    }

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION); // define projeção

    glLoadIdentity();                               // matriz identidade
    gluPerspective(75.0, w / (h * 1.0), 1.0, 20.0); // angulo, aspecto, perto, longe
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);           // posX, posY, posZ, centerX, centerY,centerZ, upX, upY, upZ

    glMatrixMode(GL_MODELVIEW); // Define as transformações sobre os objetos
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        ombro = (ombro + 5) % 360;
        glutPostRedisplay();
        break;
    case 'd':
        ombro = (ombro - 5) % 360;
        glutPostRedisplay();
        break;
    case 's':
        cotovelo = (cotovelo + 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        cotovelo = (cotovelo - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return 0;
}