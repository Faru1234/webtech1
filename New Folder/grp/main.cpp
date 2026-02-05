#include <GL/glut.h>

#include <math.h>

// Function to draw broken heart shape

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // Red color for love ❤️

    glBegin(GL_POLYGON);

    for (float t = 0; t < 2 * 3.1416; t += 0.01) {

        float x = 16 * pow(sin(t), 3);

        float y = 13 * cos(t) - 5 * cos(2*t) - 2 * cos(3*t) - cos(4*t);

        glVertex2f(x / 20.0, y / 20.0);

    }

    glEnd();

    glFlush();

}

// Function to set up the environment

void init() {

    glClearColor(1.0, 1.0, 1.0, 1.0); // White background

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1); // Coordinate range

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(100, 100);

    glutCreateWindow("LOVE ❤️ - OpenGL GLUT");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
