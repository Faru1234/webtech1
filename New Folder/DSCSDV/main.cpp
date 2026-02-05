#include <GL/glut.h>
#include <cmath>
void filledCircle(float cx, float cy, float r) {

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
        for(int i = 0; i <= 100; i++){
        float theta = 2.0f * M_PI * float(i) / 100.0f;
        glVertex2f(cx + r * cos(theta), cy + r * sin(theta));

    }
        glEnd();
        {


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.9, 0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i <= 100; i++){
        float theta = 2*M_PI*i/100;
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


    glColor3f(0.8,0.8,0.8); filledCircle(-0.5,0.50,0.32);
    glColor3f(1.0,1.0,1.0); filledCircle(-0.5,0.50,0.22);
    glColor3f(0.2,0.3,0.7); filledCircle(-0.5,0.50,0.12);
    glColor3f(0.0,0.0,0.0); filledCircle(-0.5,0.50,0.07);

    glColor3f(0.8,0.8,0.8); filledCircle(0.5,0.50,0.32);
    glColor3f(1.0,1.0,1.0); filledCircle(0.5,0.50,0.22);
    glColor3f(0.2,0.3,0.7); filledCircle(0.5,0.50,0.12);
    glColor3f(0.0,0.0,0.0); filledCircle(0.5,0.50,0.07);


    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_STRIP);
    for(int i=0;i<=50;i++){
        float t = -M_PI + (M_PI*i/50.0);
        glVertex2f(0.3*cos(t), -0.3 + 0.2*sin(t));
    }
    glEnd();

    glColor3f(0.0,0.0,0.0);
    filledCircle(-1.15,-0.20,0.15);
    filledCircle( 1.15,-0.20,0.15);

    filledCircle(-0.40,-1.35,0.20);
    filledCircle( 0.40,-1.35,0.20);

    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 4x4 coordinate world → (-2 to +2)
    gluOrtho2D(-2.0,2.0,-2.0,2.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Single Minion (4x4 Size)");
    glClearColor(0.95,0.95,0.95,1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}


