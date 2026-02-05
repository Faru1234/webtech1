// Memorial Garden Scene (2D) — NO LOOPS FOR OBJECTS (BEGINNER STYLE)

// Everything is drawn by calling simple methods again and again.

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

static void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

{

    setColor(r, g, b);

    glBegin(GL_TRIANGLES);

        glVertex2f(x1, y1);

        glVertex2f(x2, y2);

        glVertex2f(x3, y3);

    glEnd();

}

static void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,

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

            float a = (2.0f * 3.1415926535f * i) / (float)seg;

            float x = cx + std::cos(a) * rx;

            float y = cy + std::sin(a) * ry;

            glVertex2f(x, y);

        }

    glEnd();

}

// ------------------------------

// OBJECT METHODS (still simple)

// ------------------------------

static void drawTree(float x, float y, float s, float shade)

{

    // trunk

    drawRectangle(x - 0.02f*s, y - 0.12f*s, x + 0.02f*s, y + 0.12f*s, 0.34f, 0.22f, 0.14f);

    float r1 = 0.10f * shade;

    float g1 = 0.33f * shade;

    float b1 = 0.12f * shade;

    float r2 = 0.14f * shade;

    float g2 = 0.42f * shade;

    float b2 = 0.14f * shade;

    // canopy blobs (multiple simple calls)

    drawEllipse(x + 0.00f*s, y + 0.20f*s, 0.22f*s, 0.13f*s, r2, g2, b2);

    drawEllipse(x - 0.16f*s, y + 0.18f*s, 0.18f*s, 0.12f*s, r1, g1, b1);

    drawEllipse(x + 0.16f*s, y + 0.18f*s, 0.18f*s, 0.12f*s, r1, g1, b1);

    drawEllipse(x - 0.06f*s, y + 0.28f*s, 0.16f*s, 0.10f*s, r2, g2, b2);

    drawEllipse(x + 0.06f*s, y + 0.28f*s, 0.16f*s, 0.10f*s, r2, g2, b2);

}

static void drawShelter(float x, float y, float scale)

{

    // body

    drawRectangle(x - 0.12f*scale, y - 0.06f*scale, x + 0.12f*scale, y + 0.06f*scale,

                  0.42f, 0.30f, 0.20f);

    // roof

    drawTriangle(x - 0.14f*scale, y + 0.06f*scale,

                 x + 0.14f*scale, y + 0.06f*scale,

                 x + 0.00f*scale, y + 0.14f*scale,

                 0.30f, 0.22f, 0.14f);

}

static void drawGrave(float x, float y, float w, float h)

{

    // slab

    drawRectangle(x - w*0.5f, y, x + w*0.5f, y + h, 0.70f, 0.70f, 0.70f);

    // base shadow

    drawRectangle(x - w*0.58f, y - h*0.20f, x + w*0.58f, y, 0.48f, 0.48f, 0.48f);

    // small grass tuft

    drawEllipse(x + w*0.10f, y - h*0.05f, w*0.34f, h*0.55f, 0.20f, 0.56f, 0.22f);

}

static void drawBush(float x, float y, float rx, float ry)

{

    drawEllipse(x, y, rx, ry, 0.20f, 0.52f, 0.22f);

    drawEllipse(x + rx*0.55f, y - ry*0.10f, rx*0.75f, ry*0.85f, 0.18f, 0.48f, 0.20f);

}

// ------------------------------

// SCENE PARTS (NO LOOPS HERE)

// ------------------------------

static void drawSky()

{

    drawRectangle(-1.2f,  0.25f,  1.2f,  1.2f, 0.80f, 0.89f, 0.98f);

    drawRectangle(-1.2f, -0.05f,  1.2f,  0.25f,0.88f, 0.93f, 0.99f);

    drawRectangle(-1.2f, -0.25f,  1.2f, -0.05f,0.93f, 0.96f, 1.00f);

    // clouds (hard-coded)

    drawEllipse(-0.55f, 0.80f, 0.22f, 0.06f, 0.98f, 0.98f, 0.98f);

    drawEllipse(-0.40f, 0.81f, 0.16f, 0.05f, 0.97f, 0.97f, 0.97f);

    drawEllipse( 0.40f, 0.86f, 0.26f, 0.07f, 0.98f, 0.98f, 0.98f);

    drawEllipse( 0.58f, 0.85f, 0.18f, 0.05f, 0.97f, 0.97f, 0.97f);

}

static void drawGrass()

{

    drawRectangle(-1.2f, -1.2f, 1.2f, 0.30f, 0.33f, 0.63f, 0.30f);

    drawRectangle(-1.2f,  0.12f, 1.2f, 0.30f, 0.40f, 0.72f, 0.36f);

    // mowing stripes (hard-coded rectangles, no loop)

    drawRectangle(-1.20f, -1.2f, -0.96f, 0.30f, 0.34f, 0.66f, 0.31f);

    drawRectangle(-0.96f, -1.2f, -0.72f, 0.30f, 0.31f, 0.60f, 0.28f);

    drawRectangle(-0.72f, -1.2f, -0.48f, 0.30f, 0.34f, 0.66f, 0.31f);

    drawRectangle(-0.48f, -1.2f, -0.24f, 0.30f, 0.31f, 0.60f, 0.28f);

    drawRectangle(-0.24f, -1.2f,  0.00f, 0.30f, 0.34f, 0.66f, 0.31f);

    drawRectangle( 0.00f, -1.2f,  0.24f, 0.30f, 0.31f, 0.60f, 0.28f);

    drawRectangle( 0.24f, -1.2f,  0.48f, 0.30f, 0.34f, 0.66f, 0.31f);

    drawRectangle( 0.48f, -1.2f,  0.72f, 0.30f, 0.31f, 0.60f, 0.28f);

    drawRectangle( 0.72f, -1.2f,  0.96f, 0.30f, 0.34f, 0.66f, 0.31f);

    drawRectangle( 0.96f, -1.2f,  1.20f, 0.30f, 0.31f, 0.60f, 0.28f);

    // colorful patches

    drawEllipse(-0.70f, -0.10f, 0.22f, 0.07f, 0.28f, 0.58f, 0.28f);

    drawEllipse(-0.40f, -0.25f, 0.26f, 0.09f, 0.26f, 0.55f, 0.26f);

    drawEllipse( 0.05f, -0.05f, 0.28f, 0.08f, 0.27f, 0.57f, 0.27f);

    drawEllipse( 0.55f, -0.30f, 0.30f, 0.10f, 0.25f, 0.54f, 0.24f);

    drawEllipse( 0.75f, -0.55f, 0.34f, 0.12f, 0.24f, 0.52f, 0.23f);

}

static void drawBackForest()

{

    drawRectangle(-1.2f, 0.16f, 1.2f, 0.33f, 0.12f, 0.26f, 0.12f);

    // trees (no loop, just calls)

    float y = 0.18f;

    drawTree(-1.05f, y, 0.80f, 0.95f);

    drawTree(-0.92f, y, 0.65f, 0.93f);

    drawTree(-0.80f, y, 0.62f, 0.92f);

    drawTree(-0.68f, y, 0.70f, 0.94f);

    drawTree(-0.56f, y, 0.60f, 0.91f);

    drawTree(-0.44f, y, 0.66f, 0.93f);

    drawTree(-0.32f, y, 0.58f, 0.90f);

    drawTree(-0.20f, y, 0.64f, 0.92f);

    drawTree(-0.08f, y, 0.60f, 0.91f);

    drawTree( 0.04f, y, 0.68f, 0.93f);

    drawTree( 0.16f, y, 0.62f, 0.92f);

    drawTree( 0.28f, y, 0.66f, 0.93f);

    drawTree( 0.40f, y, 0.58f, 0.90f);

    drawTree( 0.52f, y, 0.70f, 0.94f);

    drawTree( 0.64f, y, 0.62f, 0.92f);

    drawTree( 0.76f, y, 0.66f, 0.93f);

    drawTree( 0.88f, y, 0.62f, 0.92f);

    drawTree( 1.05f, y, 0.80f, 0.95f);

}

static void drawHillAndBeds()

{

    // hill (small)

    drawEllipse(0.00f, 0.10f, 0.85f, 0.18f, 0.36f, 0.62f, 0.34f);

    // hedge dots (no loop, hard-coded)

    drawEllipse(-0.80f, 0.06f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.72f, 0.07f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.64f, 0.08f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.56f, 0.085f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.48f, 0.09f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.40f, 0.09f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.32f, 0.085f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.24f, 0.08f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.16f, 0.07f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse(-0.08f, 0.065f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.00f, 0.06f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.08f, 0.065f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.16f, 0.07f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.24f, 0.08f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.32f, 0.085f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.40f, 0.09f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.48f, 0.09f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.56f, 0.085f,0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.64f, 0.08f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.72f, 0.07f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    drawEllipse( 0.80f, 0.06f, 0.05f, 0.03f, 0.22f, 0.50f, 0.22f);

    // flower beds

    drawEllipse(-0.26f, 0.02f, 0.26f, 0.06f, 0.62f, 0.16f, 0.18f);

    drawEllipse( 0.26f, 0.02f, 0.26f, 0.06f, 0.62f, 0.16f, 0.18f);

    // side green beds

    drawEllipse(-0.58f, 0.01f, 0.28f, 0.06f, 0.28f, 0.56f, 0.28f);

    drawEllipse( 0.58f, 0.01f, 0.28f, 0.06f, 0.28f, 0.56f, 0.28f);

}

static void drawStairsAndCross()

{

    // stairs (still simple, but hard-coded steps)

    drawQuad(-0.38f, -0.02f,  0.38f, -0.02f,  0.34f, -0.004f, -0.34f, -0.004f, 0.83f, 0.83f, 0.83f);

    drawQuad(-0.355f, 0.01f,  0.355f, 0.01f,  0.315f, 0.026f, -0.315f, 0.026f, 0.81f, 0.81f, 0.81f);

    drawQuad(-0.33f,  0.04f,  0.33f,  0.04f,  0.295f, 0.056f, -0.295f, 0.056f, 0.79f, 0.79f, 0.79f);

    drawQuad(-0.305f, 0.07f,  0.305f, 0.07f,  0.275f, 0.086f, -0.275f, 0.086f, 0.77f, 0.77f, 0.77f);

    drawQuad(-0.28f,  0.10f,  0.28f,  0.10f,  0.255f, 0.116f, -0.255f, 0.116f, 0.75f, 0.75f, 0.75f);

    drawQuad(-0.255f, 0.13f,  0.255f, 0.13f,  0.235f, 0.146f, -0.235f, 0.146f, 0.73f, 0.73f, 0.73f);

    // pedestal

    drawRectangle(-0.07f, 0.10f, 0.07f, 0.14f, 0.92f, 0.92f, 0.92f);

    // cross

    drawRectangle(-0.012f, 0.14f, 0.012f, 0.30f, 0.96f, 0.96f, 0.96f);

    drawRectangle(-0.055f, 0.22f, 0.055f, 0.24f, 0.96f, 0.96f, 0.96f);

    // shadow

    drawEllipse(0.00f, 0.10f, 0.08f, 0.02f, 0.65f, 0.65f, 0.65f);

}

static void drawGraves()

{

    // 5 rows (hard-coded graves, no loop)

    // Row 1 (bottom biggest)

    drawGrave(-0.72f, -0.78f, 0.13f, 0.055f);

    drawGrave(-0.50f, -0.78f, 0.13f, 0.055f);

    drawGrave(-0.28f, -0.78f, 0.13f, 0.055f);

    drawGrave(-0.06f, -0.78f, 0.13f, 0.055f);

    drawGrave( 0.16f, -0.78f, 0.13f, 0.055f);

    drawGrave( 0.38f, -0.78f, 0.13f, 0.055f);

    drawGrave( 0.60f, -0.78f, 0.13f, 0.055f);

    // Row 2

    drawGrave(-0.66f, -0.62f, 0.11f, 0.048f);

    drawGrave(-0.46f, -0.62f, 0.11f, 0.048f);

    drawGrave(-0.26f, -0.62f, 0.11f, 0.048f);

    drawGrave(-0.06f, -0.62f, 0.11f, 0.048f);

    drawGrave( 0.14f, -0.62f, 0.11f, 0.048f);

    drawGrave( 0.34f, -0.62f, 0.11f, 0.048f);

    drawGrave( 0.54f, -0.62f, 0.11f, 0.048f);

    // Row 3

    drawGrave(-0.58f, -0.46f, 0.095f, 0.042f);

    drawGrave(-0.40f, -0.46f, 0.095f, 0.042f);

    drawGrave(-0.22f, -0.46f, 0.095f, 0.042f);

    drawGrave(-0.04f, -0.46f, 0.095f, 0.042f);

    drawGrave( 0.14f, -0.46f, 0.095f, 0.042f);

    drawGrave( 0.32f, -0.46f, 0.095f, 0.042f);

    drawGrave( 0.50f, -0.46f, 0.095f, 0.042f);

    // Row 4

    drawGrave(-0.52f, -0.32f, 0.082f, 0.036f);

    drawGrave(-0.36f, -0.32f, 0.082f, 0.036f);

    drawGrave(-0.20f, -0.32f, 0.082f, 0.036f);

    drawGrave(-0.04f, -0.32f, 0.082f, 0.036f);

    drawGrave( 0.12f, -0.32f, 0.082f, 0.036f);

    drawGrave( 0.28f, -0.32f, 0.082f, 0.036f);

    drawGrave( 0.44f, -0.32f, 0.082f, 0.036f);

    // Row 5 (near hill smaller)

    drawGrave(-0.44f, -0.20f, 0.070f, 0.030f);

    drawGrave(-0.30f, -0.20f, 0.070f, 0.030f);

    drawGrave(-0.16f, -0.20f, 0.070f, 0.030f);

    drawGrave(-0.02f, -0.20f, 0.070f, 0.030f);

    drawGrave( 0.12f, -0.20f, 0.070f, 0.030f);

    drawGrave( 0.26f, -0.20f, 0.070f, 0.030f);

    drawGrave( 0.40f, -0.20f, 0.070f, 0.030f);

    // bushes like photo corners

    drawBush(-0.88f, -0.70f, 0.20f, 0.08f);

    drawBush( 0.86f, -0.66f, 0.24f, 0.09f);

    drawBush(-0.55f, -0.20f, 0.12f, 0.05f);

    drawBush( 0.62f, -0.32f, 0.14f, 0.06f);

}

static void drawScene()

{

    drawSky();

    drawGrass();

    drawBackForest();

    drawHillAndBeds();

    // shelters

    drawShelter(-0.36f, 0.12f, 0.85f);

    drawShelter( 0.36f, 0.12f, 0.85f);

    // stairs + cross

    drawStairsAndCross();

    // graves + bushes

    drawGraves();

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

// Simple reshape (easy)

static void reshape(int w, int h)

{

    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    float aspect = (float)w / (float)h;

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    if (aspect >= 1.0f)

    {

        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, -1.0, 1.0);

    }

    else

    {

        glOrtho(-aspect, aspect, -1.0, 1.0, -1.0, 1.0);

    }

}

static void keyboard(unsigned char key, int, int)

{

    if (key == 27 || key == 'q' || key == 'Q')

    {

        std::exit(0);

    }

    glutPostRedisplay();

}

static void initGL()

{

    glClearColor(0.93f, 0.96f, 1.00f, 1.0f);

    glDisable(GL_DEPTH_TEST);

}

int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1100, 700);

    glutCreateWindow("Memorial Garden Scene (2D) - No Loops Style");

    initGL();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;

}
