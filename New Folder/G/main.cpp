#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

// Fixed window
int WIN_W = 1200;
int WIN_H = 600;
float FIXED_ASPECT = (float)WIN_W / (float)WIN_H; // 1100/700
int gSkyMode = 1;   // 1=day, 2=night, 3=afternoon, 4=rain
float gRainT = 0.0f;
// Helpers
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

void setColor(float r, float g, float b)
{
    glColor3f(clamp01(r), clamp01(g), clamp01(b));
}
// SHAPE METHODS
void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
{
    setColor(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,
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

void drawEllipse(float cx, float cy, float rx, float ry, float r, float g, float b)
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

// OBJECT METHODS (still simple)
void drawTree(float x, float y, float s, float shade)
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
void drawShelter(float x, float y, float scale)
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

void drawGrave(float x, float y, float w, float h)
{
    // slab
    drawRectangle(x - w*0.5f, y, x + w*0.5f, y + h, 0.70f, 0.70f, 0.70f);

    // base shadow
    drawRectangle(x - w*0.58f, y - h*0.20f, x + w*0.58f, y, 0.48f, 0.48f, 0.48f);

    // small grass tuft
    drawEllipse(x + w*0.10f, y - h*0.05f, w*0.34f, h*0.55f, 0.20f, 0.56f, 0.22f);
}

void drawBush(float x, float y, float rx, float ry)
{
    drawEllipse(x, y, rx, ry, 0.20f, 0.52f, 0.22f);
    drawEllipse(x + rx*0.55f, y - ry*0.10f, rx*0.75f, ry*0.85f, 0.18f, 0.48f, 0.20f);
}

// SCENE PARTS (NO LOOPS HERE)

void drawGrass()
{
    drawRectangle(-1.0f, -1.0f, 1.0f, 0.30f, 0.33f, 0.63f, 0.30f);
    drawRectangle(-1.0f,  0.12f, 1.0f, 0.30f, 0.40f, 0.72f, 0.36f);

    // mowing stripes (recomputed to exactly fill [-1,1] with 10 stripes)
    drawRectangle(-1.00f, -1.0f, -0.80f, 0.30f, 0.34f, 0.66f, 0.31f);
    drawRectangle(-0.80f, -1.0f, -0.60f, 0.30f, 0.31f, 0.60f, 0.28f);
    drawRectangle(-0.60f, -1.0f, -0.40f, 0.30f, 0.34f, 0.66f, 0.31f);
    drawRectangle(-0.40f, -1.0f, -0.20f, 0.30f, 0.31f, 0.60f, 0.28f);
    drawRectangle(-0.20f, -1.0f,  0.00f, 0.30f, 0.34f, 0.66f, 0.31f);
    drawRectangle( 0.00f, -1.0f,  0.20f, 0.30f, 0.31f, 0.60f, 0.28f);
    drawRectangle( 0.20f, -1.0f,  0.40f, 0.30f, 0.34f, 0.66f, 0.31f);
    drawRectangle( 0.40f, -1.0f,  0.60f, 0.30f, 0.31f, 0.60f, 0.28f);
    drawRectangle( 0.60f, -1.0f,  0.80f, 0.30f, 0.34f, 0.66f, 0.31f);
    drawRectangle( 0.80f, -1.0f,  1.00f, 0.30f, 0.31f, 0.60f, 0.28f);

    // colorful patches
    drawEllipse(-0.70f, -0.10f, 0.22f, 0.07f, 0.28f, 0.58f, 0.28f);
    drawEllipse(-0.40f, -0.25f, 0.26f, 0.09f, 0.26f, 0.55f, 0.26f);
    drawEllipse( 0.05f, -0.05f, 0.28f, 0.08f, 0.27f, 0.57f, 0.27f);
    drawEllipse( 0.55f, -0.30f, 0.30f, 0.10f, 0.25f, 0.54f, 0.24f);
    drawEllipse( 0.75f, -0.55f, 0.34f, 0.12f, 0.24f, 0.52f, 0.23f);
}

void drawBackForest()
{
    drawRectangle(-1.0f, 0.16f, 1.0f, 0.33f, 0.12f, 0.26f, 0.12f);

    float y = 0.18f;
    // edge trees nudged inside [-1,1] (visually same)
    drawTree(-1.00f, y, 0.80f, 0.95f);
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
    drawTree( 1.00f, y, 0.80f, 0.95f);
}

// --- remaining scene parts are unchanged ---
void drawHillAndBeds()
{
    drawEllipse(0.00f, 0.10f, 0.85f, 0.18f, 0.36f, 0.62f, 0.34f);

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

    drawEllipse(-0.26f, 0.02f, 0.26f, 0.06f, 0.62f, 0.16f, 0.18f);
    drawEllipse( 0.26f, 0.02f, 0.26f, 0.06f, 0.62f, 0.16f, 0.18f);

    drawEllipse(-0.58f, 0.01f, 0.28f, 0.06f, 0.28f, 0.56f, 0.28f);
    drawEllipse( 0.58f, 0.01f, 0.28f, 0.06f, 0.28f, 0.56f, 0.28f);
}

void drawStairsAndCross()
{
    drawQuad(-0.38f, -0.02f,  0.38f, -0.02f,  0.34f, -0.004f, -0.34f, -0.004f, 0.83f, 0.83f, 0.83f);
    drawQuad(-0.355f, 0.01f,  0.355f, 0.01f,  0.315f, 0.026f, -0.315f, 0.026f, 0.81f, 0.81f, 0.81f);
    drawQuad(-0.33f,  0.04f,  0.33f,  0.04f,  0.295f, 0.056f, -0.295f, 0.056f, 0.79f, 0.79f, 0.79f);
    drawQuad(-0.305f, 0.07f,  0.305f, 0.07f,  0.275f, 0.086f, -0.275f, 0.086f, 0.77f, 0.77f, 0.77f);
    drawQuad(-0.28f,  0.10f,  0.28f,  0.10f,  0.255f, 0.116f, -0.255f, 0.116f, 0.75f, 0.75f, 0.75f);
    drawQuad(-0.255f, 0.13f,  0.255f, 0.13f,  0.235f, 0.146f, -0.235f, 0.146f, 0.73f, 0.73f, 0.73f);

    drawRectangle(-0.07f, 0.10f, 0.07f, 0.14f, 0.92f, 0.92f, 0.92f);

    drawRectangle(-0.012f, 0.14f, 0.012f, 0.30f, 0.96f, 0.96f, 0.96f);
    drawRectangle(-0.055f, 0.22f, 0.055f, 0.24f, 0.96f, 0.96f, 0.96f);

    drawEllipse(0.00f, 0.10f, 0.08f, 0.02f, 0.65f, 0.65f, 0.65f);
}

void drawGraves()
{
    drawGrave(-0.72f, -0.78f, 0.13f, 0.055f);
    drawGrave(-0.50f, -0.78f, 0.13f, 0.055f);
    drawGrave(-0.28f, -0.78f, 0.13f, 0.055f);
    drawGrave(-0.06f, -0.78f, 0.13f, 0.055f);
    drawGrave( 0.16f, -0.78f, 0.13f, 0.055f);
    drawGrave( 0.38f, -0.78f, 0.13f, 0.055f);
    drawGrave( 0.60f, -0.78f, 0.13f, 0.055f);

    drawGrave(-0.66f, -0.62f, 0.11f, 0.048f);
    drawGrave(-0.46f, -0.62f, 0.11f, 0.048f);
    drawGrave(-0.26f, -0.62f, 0.11f, 0.048f);
    drawGrave(-0.06f, -0.62f, 0.11f, 0.048f);
    drawGrave( 0.14f, -0.62f, 0.11f, 0.048f);
    drawGrave( 0.34f, -0.62f, 0.11f, 0.048f);
    drawGrave( 0.54f, -0.62f, 0.11f, 0.048f);

    drawGrave(-0.58f, -0.46f, 0.095f, 0.042f);
    drawGrave(-0.40f, -0.46f, 0.095f, 0.042f);
    drawGrave(-0.22f, -0.46f, 0.095f, 0.042f);
    drawGrave(-0.04f, -0.46f, 0.095f, 0.042f);
    drawGrave( 0.14f, -0.46f, 0.095f, 0.042f);
    drawGrave( 0.32f, -0.46f, 0.095f, 0.042f);
    drawGrave( 0.50f, -0.46f, 0.095f, 0.042f);

    drawGrave(-0.52f, -0.32f, 0.082f, 0.036f);
    drawGrave(-0.36f, -0.32f, 0.082f, 0.036f);
    drawGrave(-0.20f, -0.32f, 0.082f, 0.036f);
    drawGrave(-0.04f, -0.32f, 0.082f, 0.036f);
    drawGrave( 0.12f, -0.32f, 0.082f, 0.036f);
    drawGrave( 0.28f, -0.32f, 0.082f, 0.036f);
    drawGrave( 0.44f, -0.32f, 0.082f, 0.036f);

    drawGrave(-0.44f, -0.20f, 0.070f, 0.030f);
    drawGrave(-0.30f, -0.20f, 0.070f, 0.030f);
    drawGrave(-0.16f, -0.20f, 0.070f, 0.030f);
    drawGrave(-0.02f, -0.20f, 0.070f, 0.030f);
    drawGrave( 0.12f, -0.20f, 0.070f, 0.030f);
    drawGrave( 0.26f, -0.20f, 0.070f, 0.030f);
    drawGrave( 0.40f, -0.20f, 0.070f, 0.030f);

    drawBush(-0.88f, -0.70f, 0.20f, 0.08f);
    drawBush( 0.86f, -0.66f, 0.24f, 0.09f);

    drawBush(-0.55f, -0.20f, 0.12f, 0.05f);
    drawBush( 0.62f, -0.32f, 0.14f, 0.06f);
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
    glColor4f(0.85f, 0.92f, 1.00f, 0.65f);

    float speed = 1.2f;     // falling speed
    float dropLen = 0.06f;  // small drop length

    glBegin(GL_LINES);

        int cols = 170;  // density (more = more rain)
        for (int i = 0; i < cols; i++)
        {
            float x = -1.0f + (2.0f * i) / (float)cols;

            float phase = i * 0.17f;
            float y0 = 1.05f - std::fmod(gRainT * speed + phase, 2.15f);
            float slant = 0.008f + 0.008f * std::sin(i * 0.35f);

            glVertex2f(x, y0);
            glVertex2f(x + slant, y0 - dropLen);

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
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ✅ Draw sky WITHOUT scaling => bigger sky + sun visible
    drawSky(gSkyMode);


    // ✅ Draw everything else EXACTLY SAME as before
    glPushMatrix();
        //glScalef(1.0f, FIXED_ASPECT, 1.0f);

        drawGrass();
        drawBackForest();
        drawHillAndBeds();

        drawShelter(-0.36f, 0.12f, 0.85f);
        drawShelter( 0.36f, 0.12f, 0.85f);

        drawStairsAndCross();
        drawGraves();
    glPopMatrix();
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

    glutSwapBuffers();
}
void keyboard(unsigned char key, int, int)
{
    if (key == 27 || key == 'q' || key == 'Q')
    {
        std::exit(0);
    }
    if (key == 'd' || key == 'D')
    {
        gSkyMode = 1;
    }
    if (key == 'n' || key == 'N')
    {
        gSkyMode = 2;
    }
    if (key == 'a' || key == 'A')
    {
        gSkyMode = 3;
    }
    if (key == 'r' || key == 'R')
    {
        gSkyMode = 4;
    }

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

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIN_W, WIN_H);
    glutCreateWindow("Memorial Garden Scene (2D) - No Loops Style");

    initGL();
    glutDisplayFunc(display);
    // NO reshape callback now
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}
