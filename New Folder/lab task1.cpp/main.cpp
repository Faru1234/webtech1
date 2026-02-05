#include <windows.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  //Background color RGB
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(1.0f, 0.5f);
        glVertex2f(2.5f, 0.5f);
        glVertex2f(2.5f, 5.0f);
        glVertex2f(1.0f, 5.0f);
    glEnd();

     glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(2.5f, 0.5f);
        glVertex2f(2.5f, 5.0f);
        glVertex2f(7.5f, 5.0f);
        glVertex2f(7.5f, 0.5f);
    glEnd();




     glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(7.5f, 0.5f);
        glVertex2f(7.5f, 5.0f);
        glVertex2f(9.0f, 5.0f);
        glVertex2f(9.0f, 0.5f);
    glEnd();









    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Project");

    gluOrtho2D(0, 19, 0, 11);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
