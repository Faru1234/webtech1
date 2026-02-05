// Memorial Garden Scene (2D) — NO LOOPS FOR OBJECTS (BEGINNER STYLE)

// Default projection (NO glOrtho)

// Compile (Linux): g++ main.cpp -lGL -lGLU -lglut -o scene

// Compile (Windows/CodeBlocks): link freeglut, opengl32, glu32

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

static void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b)

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

static void drawQuad(float x1, float y1,

                     float x2, float y2,

                     float x3, float y3,

                     float x4, float y4,

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

static void drawEllipse(float cx, float cy, float rx, float ry, float r, float g, float b)

{

    setColor(r, g, b);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx, cy);

        int seg = 90;

        for (int i = 0; i <= seg; i++)

        {

            float a = (2.0f * 3.1415926535f * i) / seg;

            glVertex2f(cx + cos(a) * rx, cy + sin(a) * ry);

        }

    glEnd();

}

// ------------------------------

// OBJECT METHODS

// ------------------------------

static void drawTree(float x, float y, float s, float shade)

{

    drawRectangle(x - 0.02f*s, y - 0.12f*s, x + 0.02f*s, y + 0.12f*s,

                  0.34f, 0.22f, 0.14f);

    drawEllipse(x, y + 0.20f*s, 0.22f*s, 0.13f*s, 0.14f*shade, 0.42f*shade, 0.14f*shade);

    drawEllipse(x - 0.16f*s, y + 0.18f*s, 0.18f*s, 0.12f*s, 0.10f*shade, 0.33f*shade, 0.12f*shade);

    drawEllipse(x + 0.16f*s, y + 0.18f*s, 0.18f*s, 0.12f*s, 0.10f*shade, 0.33f*shade, 0.12f*shade);

}

static void drawShelter(float x, float y, float s)

{

    drawRectangle(x - 0.12f*s, y - 0.06f*s, x + 0.12f*s, y + 0.06f*s,

                  0.42f, 0.30f, 0.20f);

    drawTriangle(x - 0.14f*s, y + 0.06f*s,

                 x + 0.14f*s, y + 0.06f*s,

                 x,            y + 0.14f*s,

                 0.30f, 0.22f, 0.14f);

}

static void drawGrave(float x, float y, float w, float h)

{

    drawRectangle(x - w*0.5f, y, x + w*0.5f, y + h, 0.7f, 0.7f, 0.7f);

    drawRectangle(x - w*0.6f, y - h*0.2f, x + w*0.6f, y, 0.5f, 0.5f, 0.5f);

}

static void drawBush(float x, float y, float rx, float ry)

{

    drawEllipse(x, y, rx, ry, 0.2f, 0.5f, 0.2f);

    drawEllipse(x + rx*0.5f, y, rx*0.7f, ry*0.8f, 0.18f, 0.48f, 0.2f);

}

// ------------------------------

// SCENE

// ------------------------------

static void drawScene()

{

    // Sky

    drawRectangle(-1.2f, 0.25f, 1.2f, 1.2f, 0.8f, 0.9f, 1.0f);

    // Grass

    drawRectangle(-1.2f, -1.2f, 1.2f, 0.3f, 0.3f, 0.6f, 0.3f);

    // Forest

    drawTree(-0.8f, 0.15f, 0.8f, 0.9f);

    drawTree(-0.5f, 0.15f, 0.7f, 0.9f);

    drawTree( 0.5f, 0.15f, 0.7f, 0.9f);

    drawTree( 0.8f, 0.15f, 0.8f, 0.9f);

    // Shelters

    drawShelter(-0.35f, 0.1f, 0.9f);

    drawShelter( 0.35f, 0.1f, 0.9f);

    // Cross

    drawRectangle(-0.01f, 0.1f, 0.01f, 0.3f, 0.95f, 0.95f, 0.95f);

    drawRectangle(-0.05f, 0.2f, 0.05f, 0.22f, 0.95f, 0.95f, 0.95f);

    // Graves

    drawGrave(-0.4f, -0.6f, 0.12f, 0.05f);

    drawGrave( 0.0f, -0.6f, 0.12f, 0.05f);

    drawGrave( 0.4f, -0.6f, 0.12f, 0.05f);

    drawBush(-0.9f, -0.7f, 0.2f, 0.08f);

    drawBush( 0.9f, -0.7f, 0.2f, 0.08f);

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

// ✅ DEFAULT reshape (NO glOrtho)

static void reshape(int w, int h)

{

    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();   // default projection

    glMatrixMode(GL_MODELVIEW);

}

static void keyboard(unsigned char key, int, int)

{

    if (key == 27 || key == 'q' || key == 'Q')

        exit(0);

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

    glutInitWindowSize(1100, 700);

    glutCreateWindow("Memorial Garden Scene (Default Projection)");

    initGL();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}

