#include <GL/glut.h>
#include <cmath>

// ================= GLOBAL VARIABLES =================
float rainY1 = 1.0f;
float rainY2 = 0.6f;
float rainY3 = 0.2f;

// ================= BASIC SHAPES =================

// Circle using sin & cos
void drawCircle(float cx, float cy, float r, float R, float G, float B)
{
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180.0f;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

// Rectangle
void drawRectangle(float x1, float y1, float x2, float y2,
                   float R, float G, float B)
{
    glColor3f(R, G, B);
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

// Triangle
void drawTriangle(float x1, float y1,
                  float x2, float y2,
                  float x3, float y3,
                  float R, float G, float B)
{
    glColor3f(R, G, B);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

// ================= SCENE OBJECTS =================

void drawSky()
{
    drawRectangle(-1, 0, 1, 1, 0.05f, 0.05f, 0.2f); // night sky
}

void drawGround()
{
    drawRectangle(-1, -1, 1, 0, 0.0f, 0.4f, 0.0f);
}

void drawMoon()
{
    drawCircle(0.7f, 0.7f, 0.12f, 1.0f, 1.0f, 0.8f);
}

void drawHill1()
{
    drawTriangle(-1, 0, -0.4f, 0.5f, 0.2f, 0,
                 0.1f, 0.4f, 0.1f);
}

void drawHill2()
{
    drawTriangle(-0.2f, 0, 0.4f, 0.6f, 1.0f, 0,
                 0.1f, 0.35f, 0.1f);
}

void drawTree1()
{
    drawRectangle(-0.8f, -0.2f, -0.75f, 0.2f, 0.4f, 0.2f, 0.1f);
    drawCircle(-0.78f, 0.25f, 0.12f, 0.0f, 0.6f, 0.0f);
}

void drawTree2()
{
    drawRectangle(0.5f, -0.2f, 0.55f, 0.2f, 0.4f, 0.2f, 0.1f);
    drawCircle(0.53f, 0.25f, 0.12f, 0.0f, 0.6f, 0.0f);
}

// ================= RAIN =================

void drawRain()
{
    glColor3f(0.6f, 0.6f, 1.0f);
    glBegin(GL_LINES);

        glVertex2f(-0.6f, rainY1);
        glVertex2f(-0.6f, rainY1 - 0.1f);

        glVertex2f(0.0f, rainY2);
        glVertex2f(0.0f, rainY2 - 0.1f);

        glVertex2f(0.6f, rainY3);
        glVertex2f(0.6f, rainY3 - 0.1f);

    glEnd();
}

void updateRain(int)
{
    rainY1 -= 0.02f;
    rainY2 -= 0.02f;
    rainY3 -= 0.02f;

    if (rainY1 < -1) rainY1 = 1;
    if (rainY2 < -1) rainY2 = 1;
    if (rainY3 < -1) rainY3 = 1;

    glutPostRedisplay();
    glutTimerFunc(30, updateRain, 0);
}

// ================= DISPLAY =================

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();   // default coordinate system

    drawSky();
    drawMoon();
    drawHill1();
    drawHill2();
    drawGround();
    drawTree1();
    drawTree2();
    drawRain();

    glFlush();
}

// ================= INIT =================

void init()
{
    glClearColor(0, 0, 0, 1);
}

// ================= MAIN =================

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Night Scene with Rain (Default)");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, updateRain, 0);

    glutMainLoop();
    return 0;
}
