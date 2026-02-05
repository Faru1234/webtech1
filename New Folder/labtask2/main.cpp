#include <windows.h>

#include <GL/glut.h>

#include <iostream>

#include <cmath>

using namespace std;

#define MAX_POINTS 2000

int px[MAX_POINTS];

int py[MAX_POINTS];

int pointCount = 0;

int choice;   // which algorithm user selected

int x1_, y1_, x2_, y2_, r;

// =========================

//     DDA LINE ALGORITHM

// =========================

void ddaLine(int x1, int y1, int x2, int y2){

    int dx = x2 - x1;

    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / (float)steps;

    float yinc = dy / (float)steps;

    float x = x1;

    float y = y1;

    for(int i=0; i<=steps; i++){

        px[pointCount] = round(x);

        py[pointCount] = round(y);

        pointCount++;

        x += xinc;

        y += yinc;

    }

}

// =========================

//  MIDPOINT LINE ALGORITHM

// =========================

void midpointLine(int x1, int y1, int x2, int y2){

    int dx = x2 - x1;

    int dy = y2 - y1;

    int d = 2*dy - dx;

    int de = 2*dy;

    int dne = 2*(dy - dx);

    int x = x1;

    int y = y1;

    px[pointCount] = x;

    py[pointCount] = y;

    pointCount++;

    while(x < x2){

        if(d < 0){

            d += de;

            x++;

        }else{

            d += dne;

            x++;

            y++;

        }

        px[pointCount] = x;

        py[pointCount] = y;

        pointCount++;

    }

}

// =========================

// MIDPOINT CIRCLE ALGORITHM

// =========================

void midpointCircle(int xc, int yc, int r){

    int x = 0;

    int y = r;

    int d = 1 - r;

    while(x <= y){

        // Plot 8 symmetric points

        px[pointCount] = xc + x;  py[pointCount++] = yc + y;

        px[pointCount] = xc - x;  py[pointCount++] = yc + y;

        px[pointCount] = xc + x;  py[pointCount++] = yc - y;

        px[pointCount] = xc - x;  py[pointCount++] = yc - y;

        px[pointCount] = xc + y;  py[pointCount++] = yc + x;

        px[pointCount] = xc - y;  py[pointCount++] = yc + x;

        px[pointCount] = xc + y;  py[pointCount++] = yc - x;

        px[pointCount] = xc - y;  py[pointCount++] = yc - x;

        if(d < 0){

            d += 2*x + 3;

        } else {

            d += 2*(x - y) + 5;

            y--;

        }

        x++;

    }

}

// =========================

//      DISPLAY FUNCTION

// =========================

void display(){

    glClearColor(1.0f,1.0f,1.0f,0.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(4);

    glBegin(GL_POINTS);

    glColor3f(0,0,0);

    // draw stored points

    for(int i=0; i<pointCount; i++){

        float X = px[i] / 100.0f;

        float Y = py[i] / 100.0f;

        glVertex2f(X, Y);

    }

    glEnd();

    glFlush();

}


int main(int argc, char** argv){

    cout << "Choose Drawing Algorithm:\n";

    cout << "1. Midpoint Line\n";

    cout << "2. DDA Line\n";

    cout << "3. Midpoint Circle\n";

    cout << "Enter choice: ";

    cin >> choice;

    if(choice == 1 || choice == 2){

        cout << "Enter x1: "; cin >> x1_;

        cout << "Enter y1: "; cin >> y1_;

        cout << "Enter x2: "; cin >> x2_;

        cout << "Enter y2: "; cin >> y2_;

    }

    else if(choice == 3){

        cout << "Enter center x: "; cin >> x1_;

        cout << "Enter center y: "; cin >> y1_;

        cout << "Enter radius: "; cin >> r;

    }

    // generate points

    if(choice == 1)

        midpointLine(x1_, y1_, x2_, y2_);

    else if(choice == 2)

        ddaLine(x1_, y1_, x2_, y2_);

    else if(choice == 3)

        midpointCircle(x1_, y1_, r);

    else{

        cout << "Invalid choice!";

        return 0;

    }

    // OpenGL setup

    glutInit(&argc, argv);

    glutInitWindowSize(640, 480);

    glutCreateWindow("Drawing Algorithms");

    gluOrtho2D(-10,10,-10,10);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}



