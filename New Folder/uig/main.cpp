// Memorial Garden Scene (2D) — NO LOOPS FOR OBJECTS (BEGINNER STYLE)
// DEFAULT OPENGL COORDINATE SYSTEM (-1 to 1)
// NO ORTHO, NO RESHAPE

#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// ------------------------------
// Helpers
// ------------------------------
static float clamp01(float v)
{
    if (v < 0.0f) return 0.0f;
    if (v > 1.0f) return 1.0f;
    return v;
}
static void setColor(float r, float g, float b)
{
    glColor3f(clamp01(r), clamp01(g), clamp01(b));
}

// ------------------------------
// SHAPE METHODS
// ------------------------------
static void drawRectangle(float x1, float y1, float x2, float y2,
                          float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

static void drawTriangle(float x1, float y1,
                         float x2, float y2,
                         float x3, float y3,
                         float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

static void drawQuad(float x1, float y1, float x2, float y2,
                     float x3, float y3, float x4, float y4,
                     float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glVertex2f(x4, y4);
    glEnd();
}

static void drawEllipse(float cx, float cy, float rx, float ry,
                        float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= 90; i++)
        {
            float a = 2.0f * 3.1415926f * i / 90.0f;
            glVertex2f(cx + cos(a) * rx,
                       cy + sin(a) * ry);
        }
    glEnd();
}

// ------------------------------
// OBJECT METHODS
// ------------------------------
static void drawTree(float x, float y, float s, float shade)
{
    drawRectangle(x - 0.02f*s, y - 0.12f*s,
                  x + 0.02f*s, y + 0.12f*s,
                  0.34f, 0.22f, 0.14f);

    drawEllipse(x, y + 0.20f*s, 0.22f*s, 0.13f*s,
                0.14f*shade, 0.42f*shade, 0.14f*shade);
}

static void drawGrave(float x, float y, float w, float h)
{
    drawRectangle(x - w*0.5f, y,
                  x + w*0.5f, y + h,
                  0.72f, 0.72f, 0.72f);

    drawRectangle(x - w*0.6f, y - h*0.25f,
                  x + w*0.6f, y,
                  0.48f, 0.48f, 0.48f);
}

// ------------------------------
// SCENE
// ------------------------------
static void drawScene()
{
    // sky
    drawRectangle(-1.0f, 0.2f, 1.0f, 1.0f, 0.85f, 0.92f, 1.0f);

    // grass
    drawRectangle(-1.0f, -1.0f, 1.0f, 0.2f, 0.33f, 0.63f, 0.30f);

    // background trees
    drawTree(-0.8f, 0.2f, 0.7f, 0.9f);
    drawTree(-0.6f, 0.2f, 0.6f, 0.9f);
    drawTree( 0.6f, 0.2f, 0.6f, 0.9f);
    drawTree( 0.8f, 0.2f, 0.7f, 0.9f);

    // hill
    drawEllipse(0.0f, 0.05f, 0.85f, 0.2f, 0.36f, 0.62f, 0.34f);

    // graves
    drawGrave(-0.5f, -0.6f, 0.15f, 0.06f);
    drawGrave(-0.2f, -0.6f, 0.15f, 0.06f);
    drawGrave( 0.1f, -0.6f, 0.15f, 0.06f);
    drawGrave( 0.4f, -0.6f, 0.15f, 0.06f);
}

// ------------------------------
// GLUT
// ------------------------------
static void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawScene();
    glutSwapBuffers();
}

static void keyboard(unsigned char key, int, int)
{
    if (key == 27 || key == 'q' || key == 'Q')
        std::exit(0);
}

static void initGL()
{
    glClearColor(0.93f, 0.96f, 1.0f, 1.0f);
    glDisable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Memorial Garden (Default OpenGL)");

    initGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
