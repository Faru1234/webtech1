/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>


#include <GL/glut.h>
#include <cmath>

void filledCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);     glVertex2f(cx, cy);     for(int i = 0; i <= 100; i++){
        float theta = 2.0f * M_PI * float(i) / 100.0f;         glVertex2f(cx + r * cos(theta), cy + r * sin(theta));
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.9, 0.0);     glBegin(GL_POLYGON);
    for(int i = 0; i <= 100; i++){         float theta = 2*M_PI*i/100;
        glVertex2f(0.0 + 1.0*cos(theta), 0.0 + 1.4*sin(theta));
    }
    glEnd();

    glColor3f(0.0, 0.3, 0.7);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0,0.1);
    glVertex2f( 1.0,0.1);
    glVertex2f( 1.0,-1.2);
    glVertex2f(-1.0,-1.2);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-0.4,-0.2);
    glVertex2f( 0.4,-0.2);
    glVertex2f( 0.4,-0.6);
    glVertex2f(-0.4,-0.6);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.3);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.7,0.1);
    glVertex2f(-1.0,0.1);

    glVertex2f(1.0,0.3);
    glVertex2f(0.7,0.3);
    glVertex2f(0.7,0.1);
    glVertex2f(1.0,0.1);
    glEnd();


    glColor3f(0.15,0.15,0.15);
       glBegin(GL_QUADS);

    glVertex2f(-1.4,0.35);

    glVertex2f( 1.4,0.35);
      glVertex2f( 1.4,0.15);
          glVertex2f(-1.4,0.15);
               glEnd();

}
