// Railway Station Scene (2D) - Perspective Refined

#include <GL/glut.h>

#include <cmath>

#include <cstdlib>

int WIN_W = 1200;

int WIN_H = 600;

int gSkyMode = 1;   // 1=day, 2=night, 3=afternoon, 4=rain

float gRainT = 0.0f;

// ------------------------------

// Helpers & Shapes

// ------------------------------

float clamp01(float v)

{

    if (v < 0.0f)

    {

        return 0.0f;

    }

    if (v > 1.0f)

    {

        return 1.0f;

    }

    return v;

}

void setColor(float r, float g, float b) {

    glColor3f(r, g, b);

}

void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b) {

    setColor(r, g, b);

    glBegin(GL_QUADS);

        glVertex2f(x1, y1); glVertex2f(x2, y1);

        glVertex2f(x2, y2); glVertex2f(x1, y2);

    glEnd();

}

void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b) {

    setColor(r, g, b);

    glBegin(GL_QUADS);

        glVertex2f(x1, y1); glVertex2f(x2, y2);

        glVertex2f(x3, y3); glVertex2f(x4, y4);

    glEnd();

}

void drawThickLine(float x1, float y1, float x2, float y2, float w, float r, float g, float b) {

    setColor(r, g, b);

    float dx = x2 - x1, dy = y2 - y1;

    float len = std::sqrt(dx*dx + dy*dy);

    if (len < 0.0001f) return;

    float nx = -dy / len * (w / 2.0f), ny = dx / len * (w / 2.0f);

    glBegin(GL_QUADS);

        glVertex2f(x1 - nx, y1 - ny); glVertex2f(x1 + nx, y1 + ny);

        glVertex2f(x2 + nx, y2 + ny); glVertex2f(x2 - nx, y2 - ny);

    glEnd();

}

void drawEllipse(float cx, float cy, float rx, float ry, float r, float g, float b) {

    setColor(r, g, b);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx, cy);

        for (int i = 0; i <= 90; i++) {

            float a = (2.0f * 3.14159f * i) / 90.0f;

            glVertex2f(cx + std::cos(a) * rx, cy + std::sin(a) * ry);

        }

    glEnd();

}

// ------------------------------

// STATION OBJECTS

// ------------------------------

void drawLeftPlatformAndFence() {

    // 1. Gray Tile Area (Far left)

    drawQuad(-1.0f, -1.0f, -0.4f, -1.0f, 0.05f, 0.15f, -1.0f, 0.15f, 0.85f, 0.86f, 0.88f);

    // 2. Yellow Safety Line

    drawQuad(-0.4f, -1.0f, -0.32f, -1.0f, 0.08f, 0.15f, 0.05f, 0.15f, 0.95f, 0.82f, 0.20f);

    // 3. Red Tactile Edge (Near tracks)

    drawQuad(-0.32f, -1.0f, 0.15f, -1.0f, 0.18f, 0.15f, 0.08f, 0.15f, 0.72f, 0.16f, 0.20f);

    // Left Fence (White with blue diamond details)

    drawRectangle(-1.0f, 0.15f, -0.90f, 0.55f, 0.95f, 0.95f, 0.95f);

    // Blue diamond patterns on fence

    for(float y = 0.2f; y < 0.5f; y += 0.1f) {

        drawRectangle(-0.98f, y, -0.92f, y+0.05f, 0.2f, 0.5f, 0.9f);

    }

}

void drawPlatform() {

    // Left side sequence: Gray Tiles -> Yellow Line -> Red Tactile Edge

    // 1. Gray Tile Area

    drawQuad(-1.0f, -1.0f, -0.4f, -1.0f, -0.05f, 0.15f, -1.0f, 0.15f, 0.85f, 0.86f, 0.88f);

    // 2. Yellow Line

    drawQuad(-0.4f, -1.0f, -0.32f, -1.0f, -0.02f, 0.15f, -0.05f, 0.15f, 0.95f, 0.80f, 0.10f);

    // 3. Red Tactile Edge (Closest to tracks)

    drawQuad(-0.32f, -1.0f, 0.15f, -1.0f, 0.12f, 0.15f, -0.02f, 0.15f, 0.80f, 0.25f, 0.25f);

    // Far Left Fence (White with blue diamonds)

    drawRectangle(-1.0f, 0.15f, -0.85f, 0.5f, 0.95f, 0.95f, 0.95f);

    drawEllipse(-0.92f, 0.35f, 0.04f, 0.1f, 0.15f, 0.55f, 0.92f); // Diamond-like detail

}

void drawLeftShelter() {

    // Support Pillar (The blue "Y" structure)

    drawRectangle(-0.70f, 0.15f, -0.66f, 0.55f, 0.12f, 0.35f, 0.75f);

    // Y-arms

    glLineWidth(5);

    glBegin(GL_LINES);

    setColor(0.12f, 0.35f, 0.75f);

    glVertex2f(-0.68f, 0.55f); glVertex2f(-0.85f, 0.70f);

    glVertex2f(-0.68f, 0.55f); glVertex2f(-0.50f, 0.70f);

    glEnd();

    // Main Canopy (Perspective)

    drawQuad(-1.0f, 0.85f, -0.20f, 0.85f, -0.25f, 0.70f, -1.0f, 0.70f, 0.10f, 0.35f, 0.80f);

}


void drawLampPost(float x, float yBottom, float h) {

    // Pole

    drawRectangle(x - 0.005f, yBottom, x + 0.005f, yBottom + h, 0.3f, 0.3f, 0.3f);

    // Angled Arm

    glBegin(GL_LINES);

    glVertex2f(x, yBottom + h); glVertex2f(x - 0.04f, yBottom + h + 0.02f);

    glEnd();

    // Lamp Head

    drawRectangle(x - 0.05f, yBottom + h + 0.01f, x - 0.03f, yBottom + h + 0.03f, 0.2f, 0.2f, 0.2f);

}

void drawRightStation() {

    // Distant building/shelter on the right

    drawRectangle(0.65f, 0.15f, 1.0f, 0.40f, 0.10f, 0.35f, 0.75f);

    // Boundary line between tracks and right buildings

    drawRectangle(0.18f, 0.15f, 1.0f, 0.16f, 0.2f, 0.2f, 0.2f);

    // Lamp posts along the right side

    drawLampPost(0.60f, 0.16f, 0.35f);

    drawLampPost(0.80f, 0.16f, 0.50f);

    drawLampPost(0.95f, 0.16f, 0.65f);

}

void drawTracks() {

    // Ground Gravel

    drawRectangle(0.15f, -1.0f, 1.0f, 0.15f, 0.5f, 0.48f, 0.45f);

    // Rails fanning out

    glLineWidth(3);

    glBegin(GL_LINES);

    setColor(0.2f, 0.2f, 0.2f);

    // Track 1

    glVertex2f(0.35f, -1.0f); glVertex2f(0.20f, 0.15f);

    glVertex2f(0.55f, -1.0f); glVertex2f(0.25f, 0.15f);

    // Track 2

    glVertex2f(0.80f, -1.0f); glVertex2f(0.35f, 0.15f);

    glVertex2f(1.05f, -1.0f); glVertex2f(0.40f, 0.15f);

    glEnd();

}

void drawSun()

{

    float cx = -0.78f;

    float cy = 0.85f;

    // glow

    drawEllipse(cx, cy, 0.14f, 0.14f, 1.00f, 0.96f, 0.72f);

    // main sun

    drawEllipse(cx, cy, 0.09f, 0.09f, 1.00f, 0.88f, 0.20f);

    // highlight

    drawEllipse(cx + 0.03f, cy + 0.03f, 0.03f, 0.03f, 1.00f, 0.98f, 0.90f);

}

// ------------------------------

// SKY EFFECTS

// ------------------------------

void drawHalfMoon(float cx, float cy, float r)

{

    // bright disk

    drawEllipse(cx, cy, r, r, 0.98f, 0.98f, 0.92f);

    // dark disk shifted to create "half moon"

    drawEllipse(cx + r*0.55f, cy, r, r, 0.07f, 0.09f, 0.16f);

}

void drawStars()

{

    // hard-coded stars (no loop)

    drawEllipse(-0.85f, 0.90f, 0.01f, 0.01f, 1,1,1);

    drawEllipse(-0.60f, 0.92f, 0.008f,0.008f,1,1,1);

    drawEllipse(-0.30f, 0.88f, 0.009f,0.009f,1,1,1);

    drawEllipse( 0.10f, 0.93f, 0.008f,0.008f,1,1,1);

    drawEllipse( 0.35f, 0.89f, 0.010f,0.010f,1,1,1);

    drawEllipse( 0.65f, 0.92f, 0.008f,0.008f,1,1,1);

    drawEllipse(-0.75f, 0.78f, 0.007f,0.007f,1,1,1);

    drawEllipse(-0.45f, 0.74f, 0.009f,0.009f,1,1,1);

    drawEllipse(-0.10f, 0.77f, 0.008f,0.008f,1,1,1);

    drawEllipse( 0.25f, 0.75f, 0.007f,0.007f,1,1,1);

    drawEllipse( 0.55f, 0.78f, 0.009f,0.009f,1,1,1);

    drawEllipse( 0.85f, 0.76f, 0.007f,0.007f,1,1,1);

}

void drawRainClouds()

{

    // dark clouds (hard-coded blobs)

    drawEllipse(-0.70f, 0.88f, 0.30f, 0.10f, 0.30f, 0.30f, 0.34f);

    drawEllipse(-0.45f, 0.90f, 0.28f, 0.09f, 0.28f, 0.28f, 0.32f);

    drawEllipse(-0.20f, 0.88f, 0.32f, 0.11f, 0.30f, 0.30f, 0.34f);

    drawEllipse( 0.20f, 0.90f, 0.34f, 0.11f, 0.30f, 0.30f, 0.34f);

    drawEllipse( 0.50f, 0.88f, 0.30f, 0.10f, 0.28f, 0.28f, 0.32f);

    drawEllipse( 0.80f, 0.90f, 0.34f, 0.11f, 0.30f, 0.30f, 0.34f);

}

static void drawRainDrops()

{

    // soft rain look

    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLineWidth(1.0f);

    // use alpha color (directly here)

    glColor4f(0.85f, 0.92f, 1.00f, 0.65f);

    float speed = 1.2f;     // falling speed

    float dropLen = 0.06f;  // small drop length

    glBegin(GL_LINES);

        int cols = 170;  // density (more = more rain)

        for (int i = 0; i < cols; i++)

        {

            float x = -1.0f + (2.0f * i) / (float)cols;

            // small variation per column (so it doesn't look like grid)

            float phase = i * 0.17f;

            // y goes from top -> bottom and wraps (respawns at top)

            float y0 = 1.05f - std::fmod(gRainT * speed + phase, 2.15f);

            // slight wind (tiny slant, NOT huge)

            float slant = 0.008f + 0.008f * std::sin(i * 0.35f);

            // draw a short line segment = raindrop

            glVertex2f(x, y0);

            glVertex2f(x + slant, y0 - dropLen);

            // second layer to increase density (offset)

            float y1 = 1.05f - std::fmod(gRainT * speed * 1.10f + phase + 0.8f, 2.15f);

            glVertex2f(x + 0.012f, y1);

            glVertex2f(x + 0.012f + slant, y1 - dropLen * 0.85f);

        }

    glEnd();

    glDisable(GL_BLEND);

}

void drawSunsetSun()

{

    float cx = 0.72f;

    float cy = 0.55f;

    // glow

    drawEllipse(cx, cy, 0.16f, 0.16f, 1.00f, 0.70f, 0.20f);

    // sun

    drawEllipse(cx, cy, 0.10f, 0.10f, 1.00f, 0.45f, 0.10f);

}

void drawSky(int gSkyMode)

{

    if (gSkyMode == 1)

    {

        // day sky (your current)

        drawRectangle(-1.0f,  0.35f,  1.0f,  1.0f, 0.78f, 0.89f, 0.98f);

        drawRectangle(-1.0f,  0.10f,  1.0f,  0.35f,0.86f, 0.93f, 0.99f);

        drawRectangle(-1.0f, -0.25f,  1.0f,  0.10f,0.93f, 0.96f, 1.00f);

        drawSun();

        // clouds

        drawEllipse(-0.55f, 0.80f, 0.22f, 0.06f, 0.98f, 0.98f, 0.98f);

        drawEllipse(-0.40f, 0.81f, 0.16f, 0.05f, 0.97f, 0.97f, 0.97f);

        drawEllipse( 0.40f, 0.86f, 0.26f, 0.07f, 0.98f, 0.98f, 0.98f);

        drawEllipse( 0.58f, 0.85f, 0.18f, 0.05f, 0.97f, 0.97f, 0.97f);

    }

    else if (gSkyMode == 2)

    {

        // night gradient

        drawRectangle(-1.0f,  0.35f,  1.0f,  1.0f, 0.05f, 0.07f, 0.16f);

        drawRectangle(-1.0f,  0.10f,  1.0f,  0.35f,0.06f, 0.08f, 0.20f);

        drawRectangle(-1.0f, -0.25f,  1.0f,  0.10f,0.08f, 0.10f, 0.24f);

        drawStars();

        drawHalfMoon(0.75f, 0.85f, 0.10f); // half moon (right side)

    }

    else if (gSkyMode == 3)

    {

        // sunset / afternoon orange sky

        drawRectangle(-1.0f,  0.35f,  1.0f,  1.0f, 0.98f, 0.62f, 0.30f);

        drawRectangle(-1.0f,  0.10f,  1.0f,  0.35f,0.98f, 0.72f, 0.45f);

        drawRectangle(-1.0f, -0.25f,  1.0f,  0.10f,0.95f, 0.82f, 0.60f);

        drawSunsetSun();

        // warm clouds

        drawEllipse(-0.55f, 0.82f, 0.24f, 0.07f, 1.00f, 0.86f, 0.70f);

        drawEllipse(-0.35f, 0.83f, 0.18f, 0.06f, 1.00f, 0.83f, 0.65f);

        drawEllipse( 0.30f, 0.86f, 0.26f, 0.07f, 1.00f, 0.85f, 0.68f);

        drawEllipse( 0.50f, 0.85f, 0.18f, 0.06f, 1.00f, 0.82f, 0.62f);

    }

    else if (gSkyMode == 4)// SKY_RAIN

    {

        // rainy sky (no sun)

        drawRectangle(-1.0f,  0.35f,  1.0f,  1.0f, 0.55f, 0.60f, 0.68f);

        drawRectangle(-1.0f,  0.10f,  1.0f,  0.35f,0.62f, 0.66f, 0.74f);

        drawRectangle(-1.0f, -0.25f,  1.0f,  0.10f,0.70f, 0.72f, 0.78f);

        drawRainClouds();

    }

}

void drawScreenTint(float r, float g, float b, float a)

{

    glEnable(GL_BLEND);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(clamp01(r), clamp01(g), clamp01(b), clamp01(a));

    glBegin(GL_QUADS);

        glVertex2f(-1.0f, -1.0f);

        glVertex2f( 1.0f, -1.0f);

        glVertex2f( 1.0f,  1.0f);

        glVertex2f(-1.0f,  1.0f);

    glEnd();

    glDisable(GL_BLEND);

}


void initGL()

{

    glClearColor(0.93f, 0.96f, 1.00f, 1.0f);

    glDisable(GL_DEPTH_TEST);

    // Fixed viewport + fixed projection [-1..1] (classic)

    glViewport(0, 0, WIN_W, WIN_H);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluLookAt(

    0, 0, 1,    // eye (camera position)

    0, 0, 0,    // center (look at)

    0, 1, 0     // up direction

);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}

// ------------------------------

// GLUT CALLBACKS

// ------------------------------

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    drawSky(gSkyMode);

    drawRectangle(-1.0f, 0.12f, 1.0f, 0.18f, 0.75f, 0.75f, 0.78f); // Horizon band

    drawTracks();

    drawLeftPlatformAndFence();

    drawLeftShelter();

    drawRightStation();

    // Right Side Lamp Posts following perspective

    if (gSkyMode == 2)

    {

        drawScreenTint(0.0f, 0.0f, 0.0f, 0.22f);

    } // night darker

    if (gSkyMode == 4)

    {

        drawScreenTint(0.0f, 0.0f, 0.0f, 0.12f); // rain slightly darker

    }

    if (gSkyMode == 4)

    {

        drawRainDrops(); // rain animation on top

    }

        glEnd();


    glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {

    if (key == 'd' || key == 'D') gSkyMode = 1;

    if (key == 'n' || key == 'N') gSkyMode = 2;

    if (key == 'a' || key == 'A') gSkyMode = 3;

    if (key == 'r' || key == 'R') gSkyMode = 4;

    glutPostRedisplay();

}

void timer(int)

{

    if (gSkyMode == 4)

    {

        gRainT += 0.08f;          // speed

        if (gRainT > 1000.0f)

        {

            gRainT = 0.0f;

        }

        glutPostRedisplay();

    }

    glutTimerFunc(16, timer, 0); // ~60 FPS

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WIN_W, WIN_H);

    glutCreateWindow("Railway Station - Refined Scene");

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutTimerFunc(16, timer, 0);

    glutMainLoop();

    return 0;

}
