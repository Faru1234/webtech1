#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

float sunX = 100;
float hillShift = 0;

/* Circle */
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++) {
        float a = i * PI / 180;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

/* Smooth Hill */
void drawHill(float x, float y, float r) {
    drawCircle(x, y, r);
    drawCircle(x + r * 0.8, y, r * 0.7);
    drawCircle(x - r * 0.8, y, r * 0.7);
}

/* Tree */
void drawTree(float x, float y) {
    // trunk
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(x - 5, y);
        glVertex2f(x + 5, y);
        glVertex2f(x + 5, y + 30);
        glVertex2f(x - 5, y + 30);
    glEnd();

    // leaves
    glColor3f(0.0f, 0.6f, 0.2f);
    drawCircle(x, y + 45, 18);
    drawCircle(x - 12, y + 40, 15);
    drawCircle(x + 12, y + 40, 15);
}

/* Display */
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    /* Sky Gradient */
    glBegin(GL_POLYGON);
        glColor3f(0.55f, 0.85f, 1.0f);
        glVertex2f(0, 300);
        glVertex2f(800, 300);

        glColor3f(0.35f, 0.65f, 1.0f);
        glVertex2f(800, 600);
        glVertex2f(0, 600);
    glEnd();

    /* Sun Animation */
    glColor3f(1.0f, 0.9f, 0.2f);
    drawCircle(sunX, 520, 35);

    /* Far Hills */
    glColor3f(0.6f, 0.8f, 0.6f);
    drawHill(200 + hillShift * 0.3, 320, 150);
    drawHill(500 + hillShift * 0.3, 330, 170);

    /* Mid Hills */
    glColor3f(0.3f, 0.65f, 0.3f);
    drawHill(150 + hillShift * 0.6, 270, 200);
    drawHill(450 + hillShift * 0.6, 270, 220);

    /* Near Hills */
    glColor3f(0.1f, 0.5f, 0.25f);
    drawHill(250 + hillShift, 220, 260);
    drawHill(600 + hillShift, 220, 300);

    /* Ground (NO black part) */
    glColor3f(0.25f, 0.7f, 0.3f);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(800, 0);
        glVertex2f(800, 220);
        glVertex2f(0, 220);
    glEnd();

    /* Trees Left */
    drawTree(60, 190);
    drawTree(100, 190);
    drawTree(140, 190);

    /* Trees Right */
    drawTree(660, 190);
    drawTree(700, 190);
    drawTree(740, 190);

    glFlush();
}

/* Animation */
void update(int value) {
    sunX += 0.5;
    hillShift -= 0.2;

    if (sunX > 850) sunX = -50;
    if (hillShift < -200) hillShift = 0;

    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 800, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Realistic Animated Moynamoti Hills");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
