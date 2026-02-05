#include <GL/glut.h>

#include <cmath>

#include <cstdlib>

// ================= GLOBAL =================

int mode = 0; // 0 Sun, 1 Rain, 2 Snow, 3 Night

float rainY = 1.0f;

// ================= BASIC SHAPES =================

void rect(float x,float y,float w,float h,float r,float g,float b){

    glColor3f(r,g,b);

    glBegin(GL_QUADS);

    glVertex2f(x,y);

    glVertex2f(x+w,y);

    glVertex2f(x+w,y+h);

    glVertex2f(x,y+h);

    glEnd();

}

void circle(float cx,float cy,float r,float R,float G,float B){

    glColor3f(R,G,B);

    glBegin(GL_POLYGON);

    for(float i=0;i<360;i++){

        float rad=i*3.1416/180;

        glVertex2f(cx+cos(rad)*r,cy+sin(rad)*r);

    }

    glEnd();

}

// ================= BACKGROUND =================

void sky(){

    if(mode==0) rect(-1,0,2,1,0.75,0.9,1);       // sunny

    if(mode==1) rect(-1,0,2,1,0.4,0.45,0.5);    // rainy

    if(mode==3) rect(-1,0,2,1,0.05,0.05,0.15);  // night

}

void ground(){

    rect(-1,-1,2,1,0.4,0.7,0.3);

}

// ================= CLOUD =================

void cloud(float x,float y){

    circle(x,y,0.07,1,1,1);

    circle(x+0.08,y+0.03,0.07,1,1,1);

    circle(x+0.16,y,0.07,1,1,1);

}

// ================= WEATHER =================

void sun(){

    circle(0.7,0.75,0.1,1,0.9,0);

}

void moon(){

    circle(0.7,0.75,0.1,1,1,0.8);

    circle(0.73,0.78,0.1,0.05,0.05,0.15);

}

void stars(){

    glColor3f(1,1,1);

    glBegin(GL_POINTS);

    for(int i=0;i<100;i++)

        glVertex2f((rand()%200-100)/100.0,(rand()%100)/100.0);

    glEnd();

}

void rain(){

    glColor3f(0.8,0.8,1);

    glBegin(GL_LINES);

    for(float x=-1;x<=1;x+=0.1){

        glVertex2f(x,rainY);

        glVertex2f(x,rainY-0.1);

    }

    glEnd();

    rainY-=0.02;

    if(rainY<-1) rainY=1;

}

// ================= SCENE OBJECTS =================

void stairs(){

    float y=0.05;

    for(int i=0;i<5;i++){

        rect(-0.3,y,0.6,0.05,0.7,0.1,0.1);

        rect(-0.3,y+0.01,0.6,0.02,1,1,1);

        y-=0.06;

    }

}

void cross(){

    rect(-0.02,0.15,0.04,0.3,1,1,1);

    rect(-0.1,0.3,0.2,0.05,1,1,1);

}

void house(float x){

    rect(x,-0.05,0.18,0.15,0.5,0.25,0.1);

    glColor3f(0.4,0.2,0.1);

    glBegin(GL_TRIANGLES);

    glVertex2f(x-0.02,0.1);

    glVertex2f(x+0.2,0.1);

    glVertex2f(x+0.09,0.2);

    glEnd();

}

void grave(float x,float y){

    rect(x,y,0.06,0.04,1,1,1);

}

// ================= DISPLAY =================

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    sky();

    ground();

    // clouds

    cloud(-0.6,0.7);

    cloud(-0.1,0.75);

    cloud(0.3,0.7);

    if(mode==0) sun();

    if(mode==1) rain();

    if(mode==3){ moon(); stars(); }

    // trees line

    for(float x=-1;x<=1;x+=0.15){

        rect(x,-0.1,0.03,0.2,0.4,0.2,0.1);

        circle(x+0.015,0.15,0.07,0.1,0.4,0.1);

    }

    stairs();

    cross();

    house(-0.45);

    house(0.27);

    // graves (same as image)

    for(float x=-0.7;x<=0.7;x+=0.2){

        grave(x,-0.6);

        grave(x,-0.7);

    }

    glFlush();

}

// ================= INPUT =================

void keyboard(unsigned char key,int,int){

    if(key=='1') mode=0;

    if(key=='2') mode=1;

    if(key=='4') mode=3;

    glutPostRedisplay();

}

// ================= INIT =================

void init(){

    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-1,1,-1,1,-1,1);

}

// ================= MAIN =================

int main(int argc,char** argv){

    glutInit(&argc,argv);

    glutInitWindowSize(900,600);

    glutCreateWindow("Memorial Garden - Weather Scene");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutIdleFunc(display);

    glutMainLoop();

    return 0;

}
