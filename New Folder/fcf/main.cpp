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

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(4.5f, 1.75f);
        glVertex2f(4.25f, 2.25f);
        glVertex2f(4.5f, 2.75f);
        glVertex2f(4.75f, 2.25f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(5.0f, 1.0f);
        glVertex2f(4.75f, 1.5f);
        glVertex2f(5.0f, 2.0f);
        glVertex2f(5.25f, 1.5f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.7f, 0.0f);
        glVertex2f(5.50f, 1.75f);
        glVertex2f(5.25f, 2.25f);
        glVertex2f(5.5f, 2.75f);
        glVertex2f(5.75f, 2.25f);
    glEnd();

    glBegin(GL_QUADS);                 //Morocco flag
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 6.0f);
        glVertex2f(1.0f, 11.0f);
        glVertex2f(9.0f, 11.0f);
        glVertex2f(9.0f, 6.0f);
    glEnd();

    glBegin(GL_LINE_STRIP);                 //Morocco flag
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(4.25f, 8.0f);
        glVertex2f(4.75f, 9.75f);
        glVertex2f(5.25f, 8.0f);
        glVertex2f(4.0f, 9.25f);
        glVertex2f(5.5f, 9.25f);
        glVertex2f(4.25f, 8.0f);
    glEnd();


    glBegin(GL_QUADS);                 //Vietnam flag
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(12.0f, 0.5f);
        glVertex2f(12.0f, 5.0f);
        glVertex2f(20.0f, 5.0f);
        glVertex2f(20.0f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(15.5f, 2.0f);
        glVertex2f(16.0f, 3.5f);
        glVertex2f(16.5f, 2.0f);
        glVertex2f(16.0f, 2.5f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(15.25f, 3.0f);
        glVertex2f(16.75f, 3.0f);
        glVertex2f(16.0f, 2.5f);
    glEnd();

    glBegin(GL_QUADS);            //4TH FLAG SWEDEN
        glColor3f(0.000f, 0.322f, 0.576f);
        glVertex2f(12.0f, 6.0f);
        glVertex2f(12.0f, 11.0f);
        glVertex2f(21.0f, 11.0f);
        glVertex2f(21.0f, 6.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(14.5f, 11.0f);
        glVertex2f(15.25f, 11.0f);
        glVertex2f(15.25f, 6.0f);
        glVertex2f(14.5f, 6.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(12.0f, 9.25f);
        glVertex2f(21.0f, 9.25f);
        glVertex2f(21.0f, 8.50f);
        glVertex2f(12.0f, 8.50f);
    glEnd();


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Project");

    gluOrtho2D(0, 23, 0, 12);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
