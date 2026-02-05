#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float _move = 0.0f;
float _moveCar2 = 0.0f;
bool isDay=true;
int activeScene = 1;

void update(int value){
    _move+=.02f;
    if(_move>19.0)
    {
        _move=-7.0;  //reset from this value
    }

    _moveCar2 -= 0.02f;
    if (_moveCar2 < -19.0) {
        _moveCar2 = 6.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);


}



void circle(float radius, float xc, float yc, float r, float g, float b)  //circle function
{

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}


void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'D' || key == 'd') {
        isDay = true; // Set day mode
    }
    if (key == 'N' || key == 'n') {
        isDay = false; // Set night mode

    }
    if (key == '2') {
        activeScene = 2;  // Switch to second scene
    }
    if (key == '1') {
        activeScene = 1;  // Switch to first scene
    }
    if(key == '3') {
        activeScene = 3; //switch to 3rd scene
    }

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if(activeScene==1) {

    if (isDay) {
        glClearColor(0.53f, 0.81f, 0.92f, 1.0f); // Day background (sky color)
    } else {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f); // Night background (dark sky)
    }

    glLineWidth(7.5);


	glBegin(GL_QUADS);                    //Road pitch
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(19.0f, 0.0f);
	glVertex2f(19.0f, 3.0f);
	glVertex2f(0.0f, 3.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(1.0f, 1.25f);
	glVertex2f(2.0f, 1.25f);
	glVertex2f(2.25f, 1.5f);
	glVertex2f(1.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 2
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(3.0f, 1.25f);
	glVertex2f(4.0f, 1.25f);
	glVertex2f(4.25f, 1.5f);
	glVertex2f(3.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 3
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(5.0f, 1.25f);
	glVertex2f(6.0f, 1.25f);
	glVertex2f(6.25f, 1.5f);
	glVertex2f(5.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 4
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(7.0f, 1.25f);
	glVertex2f(8.0f, 1.25f);
	glVertex2f(8.25f, 1.5f);
	glVertex2f(7.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 5
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(9.0f, 1.25f);
	glVertex2f(10.0f, 1.25f);
	glVertex2f(10.25f, 1.5f);
	glVertex2f(9.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 6
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(11.0f, 1.25f);
	glVertex2f(12.0f, 1.25f);
	glVertex2f(12.25f, 1.5f);
	glVertex2f(11.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 7
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(13.0f, 1.25f);
	glVertex2f(14.0f, 1.25f);
	glVertex2f(14.25f, 1.5f);
	glVertex2f(13.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 8
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(15.0f, 1.25f);
	glVertex2f(16.0f, 1.25f);
	glVertex2f(16.25f, 1.5f);
	glVertex2f(15.25f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Road Divider 9
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(17.0f, 1.25f);
	glVertex2f(18.0f, 1.25f);
	glVertex2f(18.25f, 1.5f);
	glVertex2f(17.25f, 1.5f);
	glEnd();


	glBegin(GL_QUADS);                    //Ground
	glColor3f(0.710f, 0.396f, 0.114f);
	glVertex2f(0.0f, 3.0f);
	glVertex2f(0.0f, 3.25f);
	glVertex2f(19.0f, 3.25f);
	glVertex2f(19.0f, 3.0f);
	glEnd();


	glBegin(GL_QUADS);                    //Tall Building start
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(5.0f, 3.25f);
	glVertex2f(5.0f, 4.25f);
	glVertex2f(8.25f, 4.25f);
	glVertex2f(8.25f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(5.5f, 4.25f);
	glVertex2f(8.25f, 4.25f);
	glVertex2f(8.25f, 5.0f);
	glVertex2f(5.5f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(5.5f, 5.0f);
	glVertex2f(5.5, 6.0f);
	glVertex2f(7.75f, 6.0f);
	glVertex2f(7.75f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(6.0f, 6.0f);
	glVertex2f(7.75, 6.0f);
	glVertex2f(7.75f, 7.0f);
	glVertex2f(6.0f, 7.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(6.0f, 7.0f);
	glVertex2f(7.25, 7.0f);
	glVertex2f(7.25f, 8.0f);
	glVertex2f(6.0f, 8.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(6.5f, 8.0f);
	glVertex2f(7.25, 8.0f);
	glVertex2f(7.25f, 8.75f);
	glVertex2f(6.5f, 8.75f);
	glEnd();

	glBegin(GL_LINE_STRIP);                    //Tall Building End
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(7.20, 8.75f);
	glVertex2f(7.20f, 9.50f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building 3d view
	glColor3f(0.14f, 0.35f, 0.55f);
	glVertex2f(5.0f, 4.25f);
	glVertex2f(4.75, 4.0f);
	glVertex2f(4.75f, 3.25f);
	glVertex2f(5.0f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building 3d view
	glColor3f(0.14f, 0.35f, 0.55f);
	glVertex2f(5.25f, 4.25f);
	glVertex2f(5.5f, 4.25f);
	glVertex2f(5.5f, 6.0f);
	glVertex2f(5.25f, 5.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building 3d view
	glColor3f(0.14f, 0.35f, 0.55f);
	glVertex2f(6.0f, 8.0f);
	glVertex2f(5.75f, 7.75f);
	glVertex2f(5.75f, 6.0f);
	glVertex2f(6.0f, 6.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building 3d view
	glColor3f(0.14f, 0.35f, 0.55f);
	glVertex2f(6.5f, 8.75f);
	glVertex2f(6.25f, 8.5f);
	glVertex2f(6.25f, 8.0f);
	glVertex2f(6.5f, 8.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(5.25f, 3.5f);
	glVertex2f(5.5f, 3.5);
	glVertex2f(5.5f, 4.0f);
	glVertex2f(5.25f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(5.75f, 3.5f);
	glVertex2f(6.0f, 3.5);
	glVertex2f(6.0f, 4.0f);
	glVertex2f(5.75f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.25f, 3.5f);
	glVertex2f(6.5f, 3.5);
	glVertex2f(6.5f, 4.0f);
	glVertex2f(6.25f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 3.5f);
	glVertex2f(7.0f, 3.5f);
	glVertex2f(7.0f, 4.0f);
	glVertex2f(6.75f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.25f, 3.5f);
	glVertex2f(7.5f, 3.5f);
	glVertex2f(7.5f, 4.0f);
	glVertex2f(7.25f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.75f, 3.5f);
	glVertex2f(8.0f, 3.5f);
	glVertex2f(8.0f, 4.0f);
	glVertex2f(7.75f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.75f, 4.25f);
	glVertex2f(8.0f, 4.25f);
	glVertex2f(8.0f, 4.75f);
	glVertex2f(7.75f, 4.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.25f, 4.25f);
	glVertex2f(7.5f, 4.25f);
	glVertex2f(7.5f, 4.75f);
	glVertex2f(7.25f, 4.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 4.25f);
	glVertex2f(7.0f, 4.25f);
	glVertex2f(7.0f, 4.75f);
	glVertex2f(6.75f, 4.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.25f, 4.25f);
	glVertex2f(6.5f, 4.25f);
	glVertex2f(6.5f, 4.75f);
	glVertex2f(6.25f, 4.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(5.75f, 4.25f);
	glVertex2f(6.0f, 4.25f);
	glVertex2f(6.0f, 4.75f);
	glVertex2f(5.75f, 4.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(5.75f, 5.25f);
	glVertex2f(6.0f, 5.25f);
	glVertex2f(6.0f, 5.75f);
	glVertex2f(5.75f, 5.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.25f, 5.25f);
	glVertex2f(6.5f, 5.25f);
	glVertex2f(6.5f, 5.75f);
	glVertex2f(6.25f, 5.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 5.25f);
	glVertex2f(7.0f, 5.25f);
	glVertex2f(7.0f, 5.75f);
	glVertex2f(6.75f, 5.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.25f, 5.25f);
	glVertex2f(7.5f, 5.25f);
	glVertex2f(7.5f, 5.75f);
	glVertex2f(7.25f, 5.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(7.25f, 6.25f);
	glVertex2f(7.5f, 6.25f);
	glVertex2f(7.5f, 6.75f);
	glVertex2f(7.25f, 6.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 6.25f);
	glVertex2f(7.0f, 6.25f);
	glVertex2f(7.0f, 6.75f);
	glVertex2f(6.75f, 6.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.25f, 6.25f);
	glVertex2f(6.5f, 6.25f);
	glVertex2f(6.5f, 6.75f);
	glVertex2f(6.25f, 6.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.25f, 7.25f);
	glVertex2f(6.5f, 7.25f);
	glVertex2f(6.5f, 7.75f);
	glVertex2f(6.25f, 7.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 7.25f);
	glVertex2f(7.0f, 7.25f);
	glVertex2f(7.0f, 7.75f);
	glVertex2f(6.75f, 7.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Tall Building Window End
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(6.75f, 8.0f);
	glVertex2f(7.0f, 8.0f);
	glVertex2f(7.0f, 8.5f);
	glVertex2f(6.75f, 8.5f);
	glEnd();


	glBegin(GL_POLYGON);                    //Mountain
	glColor3f(0.0f, 0.6f, 0.0f);
	glVertex2f(8.25f, 3.25f);
	glVertex2f(8.25f, 4.25f);
	glVertex2f(11.0f, 5.25);
	glVertex2f(12.5f, 6.75f);
	glVertex2f(14.5f, 8.0f);
	glVertex2f(18.25f, 6.0f);
	glVertex2f(19.0f, 4.75f);
	glVertex2f(19.0f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building
	glColor3f(1.0f, 0.65f, 0.0f);
	glVertex2f(0.75f, 3.25f);
	glVertex2f(0.75f, 5.5);
	glVertex2f(4.75f, 5.5f);
	glVertex2f(4.75f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building 3d view
	glColor3f(1.0f, 0.55f, 0.0f);
	glVertex2f(0.75f, 5.5f);
	glVertex2f(0.5f, 5.25);
	glVertex2f(0.5f, 3.25f);
	glVertex2f(0.75f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window start
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 3.5f);
	glVertex2f(1.5f, 3.5);
	glVertex2f(1.5f, 4.0f);
	glVertex2f(1.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.0f, 3.5f);
	glVertex2f(2.5f, 3.5);
	glVertex2f(2.5f, 4.0f);
	glVertex2f(2.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(3.0f, 3.5f);
	glVertex2f(3.5f, 3.5);
	glVertex2f(3.5f, 4.0f);
	glVertex2f(3.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 3.5f);
	glVertex2f(4.5f, 3.5);
	glVertex2f(4.5f, 4.0f);
	glVertex2f(4.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, 4.5f);
	glVertex2f(1.5f, 4.5);
	glVertex2f(1.5f, 5.0f);
	glVertex2f(1.0f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.0f, 4.5f);
	glVertex2f(2.5f, 4.5);
	glVertex2f(2.5f, 5.0f);
	glVertex2f(2.0f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(3.0f, 4.5f);
	glVertex2f(3.5f, 4.5);
	glVertex2f(3.5f, 5.0f);
	glVertex2f(3.0f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Medium Building Window End
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 4.5f);
	glVertex2f(4.5f, 4.5);
	glVertex2f(4.5f, 5.0f);
	glVertex2f(4.0f, 5.0f);
	glEnd();


	glBegin(GL_QUADS);                    //Hall Building start
	glColor3f(1.0f, 0.65f, 0.0f);
	glVertex2f(8.5f, 3.25f);
	glVertex2f(8.5f, 5.25);
	glVertex2f(14.5f, 5.25f);
	glVertex2f(14.5f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building door
	glColor3f(0.55f, 0.27f, 0.07f);
	glVertex2f(10.5f, 3.25f);
	glVertex2f(12.5f, 3.25);
	glVertex2f(12.5f, 4.5f);
	glVertex2f(10.5f, 4.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building door
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex2f(11.0f, 3.25f);
	glVertex2f(12.0f, 3.25);
	glVertex2f(12.0f, 4.0f);
	glVertex2f(11.0f, 4.0f);
	glEnd();

	glBegin(GL_TRIANGLES);                    //Hall Building door
	glColor3f(0.55f, 0.27f, 0.07f);
	glVertex2f(10.25f, 4.5f);
	glVertex2f(12.75f, 4.5);
	glVertex2f(11.5f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building roof
	glColor3f(0.55f, 0.27f, 0.07f);
	glVertex2f(8.25f, 5.25f);
	glVertex2f(14.75f, 5.25);
	glVertex2f(14.75f, 5.5f);
	glVertex2f(8.25f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building roof
	glColor3f(1.0f, 0.65f, 0.0f);
	glVertex2f(9.5f, 5.5f);
	glVertex2f(13.5f, 5.5);
	glVertex2f(13.5f, 6.0f);
	glVertex2f(9.5f, 6.0f);
	glEnd();

	glBegin(GL_TRIANGLES);                    //Hall Building roof
	glColor3f(0.55f, 0.27f, 0.07f);
	glVertex2f(9.25f, 6.0f);
	glVertex2f(13.75f, 6.0);
	glVertex2f(11.5f, 6.75f);
	glEnd();

	circle(0.2f, 11.5, 5.75, 1, 1, 1);

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(8.75f, 3.5f);
	glVertex2f(9.25f, 3.5);
	glVertex2f(9.25f, 4.0f);
	glVertex2f(8.75f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(9.5f, 3.5f);
	glVertex2f(10.0f, 3.5);
	glVertex2f(10.0f, 4.0f);
	glVertex2f(9.5f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.0f, 3.5f);
	glVertex2f(13.5f, 3.5);
	glVertex2f(13.5f, 4.0f);
	glVertex2f(13.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.75f, 3.5f);
	glVertex2f(14.25f, 3.5);
	glVertex2f(14.25f, 4.0f);
	glVertex2f(13.75f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(8.75f, 4.5f);
	glVertex2f(9.25f, 4.5);
	glVertex2f(9.25f, 5.0f);
	glVertex2f(8.75f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(9.5f, 4.5f);
	glVertex2f(10.0f, 4.5);
	glVertex2f(10.0f, 5.0f);
	glVertex2f(9.5f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.0f, 4.5f);
	glVertex2f(13.5f, 4.5);
	glVertex2f(13.5f, 5.0f);
	glVertex2f(13.0f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Hall Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.75f, 4.5f);
	glVertex2f(14.25f, 4.5);
	glVertex2f(14.25f, 5.0f);
	glVertex2f(13.75f, 5.0f);
	glEnd();


    if (isDay) {
        circle(0.8f, 10, 9, 1, 0.84f, 0); // Sun during day
    }


    if (!isDay) {
        circle(0.8f, 10, 9, 0.9f, 0.9f, 0.9f); // Moon during night
    }

    glBegin(GL_QUADS);                    //Traffic Light
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(17.75f, 4.0f);
	glVertex2f(18.25f, 4.0);
	glVertex2f(18.25f, 5.5f);
	glVertex2f(17.75f, 5.5f);
	glEnd();

	glBegin(GL_LINE_STRIP);                    //Traffic Light stand
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(18.0f, 3.25f);
	glVertex2f(18.0f, 4.0);
	glEnd();

	circle(0.15,18,4.25,0,1,0); //Green light
	circle(0.15,18,4.75,1,1,0); //Yellow light
	circle(0.15,18,5.25,1,0,0); //Red light

	glBegin(GL_QUADS);                    //Tree trunk
	glColor3f(0.55f, 0.27f, 0.07f);
	glVertex2f(15.75f, 3.25f);
	glVertex2f(16.25f, 3.25f);
	glVertex2f(16.25f, 5.0f);
	glVertex2f(15.75f, 5.0f);
	glEnd();

    circle(1,16,5.5,0,1,0);  //Tree leaves
    circle(0.7,16.75,5,0,1,0);
    circle(0.7,15.25,5,0,1,0);




    glPushMatrix();        // Save current transformation
    glTranslatef(_move, 0.0f, 0.0f); // Move car horizontally  (x,y,z)

    glBegin(GL_QUADS);             //Red car start
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.25f, 0.5f);
    glVertex2f(4.0f, 0.5f);
    glVertex2f(4.0f, 1.0f);
    glVertex2f(0.25f, 1.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.68f, 0.85f, 0.90f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(3.25f, 1.0f);
    glVertex2f(2.75f, 1.5f);
    glVertex2f(1.5f, 1.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(3.75f, 0.75f);
    glVertex2f(4.0f, 0.75f);
    glVertex2f(4.0f, 1.0f);
    glVertex2f(3.75f, 1.0f);
    glEnd();

    circle(0.25,3.25,0.5,0.5,0.5,0.5);  //Wheels
    circle(0.25,0.75,0.5,0.5,0.5,0.5);  //Wheels

    glLineWidth(4.5);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, 1.5f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(_moveCar2, 0.0f, 0.0f);  //2nd car


    glBegin(GL_POLYGON); // Blue car
    glColor3f(0.5f, 0.0f, 0.5f);
    glVertex2f(15.0f, 1.75f);
    glVertex2f(18.5f, 1.75f);
    glVertex2f(18.5f, 3.0f);
    glVertex2f(15.5f, 3.0f);
    glVertex2f(15.0f, 2.5f);
    glEnd();

    circle(0.25,15.5,1.75,0.5,0.5,0.5);  //Wheels
    circle(0.25,17.75,1.75,0.5,0.5,0.5);  //Wheels

    glBegin(GL_TRIANGLES);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(15.0f, 2.5f);
    glVertex2f(15.5f, 2.5f);
    glVertex2f(15.5f, 3.0f);
    glEnd();

    glBegin(GL_QUADS);             //door start
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(16.0f, 1.75f);
    glVertex2f(16.25f, 1.75f);
    glVertex2f(16.25f, 2.25f);
    glVertex2f(16.0f, 2.25f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(16.50f, 2.25f);
    glVertex2f(16.75f, 2.25f);
    glVertex2f(16.75f, 2.5f);
    glVertex2f(16.5f, 2.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(17.0f, 2.25f);
    glVertex2f(17.25f, 2.25f);
    glVertex2f(17.25f, 2.5f);
    glVertex2f(17.0f, 2.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);
    glVertex2f(17.5f, 2.25f);
    glVertex2f(17.75f, 2.25f);
    glVertex2f(17.75f, 2.5f);
    glVertex2f(17.5f, 2.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.92f);   //door end
    glVertex2f(18.0f, 2.25f);
    glVertex2f(18.25f, 2.25f);
    glVertex2f(18.25f, 2.5f);
    glVertex2f(18.0f, 2.5f);
    glEnd();


    glPopMatrix();


    }



    else if(activeScene==2)    //2nd scenary
    {

        if (isDay) {
        glClearColor(0.527f, 0.527f, 0.527f, 1.0f);
        }
      else {
        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

        }

    glBegin(GL_QUADS);                    //Road sideway
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(19.0f, 0.0f);
	glVertex2f(19.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Road
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 1.0f);
	glVertex2f(19.0f, 1.0f);
	glVertex2f(19.0f, 3.25f);
	glVertex2f(0.0f, 3.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider start
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.75f, 2.0f);
	glVertex2f(2.0f, 2.0f);
	glVertex2f(2.25f, 2.25f);
	glVertex2f(1.0f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(3.0f, 2.0f);
	glVertex2f(4.0f, 2.0f);
	glVertex2f(4.25f, 2.25f);
	glVertex2f(3.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(5.0f, 2.0f);
	glVertex2f(6.0f, 2.0f);
	glVertex2f(6.25f, 2.25f);
	glVertex2f(5.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(7.0f, 2.0f);
	glVertex2f(8.0f, 2.0f);
	glVertex2f(8.25f, 2.25f);
	glVertex2f(7.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(9.0f, 2.0f);
	glVertex2f(10.0f, 2.0f);
	glVertex2f(10.25f, 2.25f);
	glVertex2f(9.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(13.0f, 2.0f);
	glVertex2f(14.0f, 2.0f);
	glVertex2f(14.25f, 2.25f);
	glVertex2f(13.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(15.0f, 2.0f);
	glVertex2f(16.0f, 2.0f);
	glVertex2f(16.25f, 2.25f);
	glVertex2f(15.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Road divider end
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(17.0f, 2.0f);
	glVertex2f(18.0f, 2.0f);
	glVertex2f(18.25f, 2.25f);
	glVertex2f(17.25f, 2.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Zebra crossing
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10.5f, 1.25f);
	glVertex2f(11.5f, 1.25f);
	glVertex2f(11.5f, 1.5f);
	glVertex2f(10.5f, 1.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Zebra crossing
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10.5f, 1.75f);
	glVertex2f(11.5f, 1.75f);
	glVertex2f(11.5f, 2.0f);
	glVertex2f(10.5f, 2.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Zebra crossing
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10.5f, 2.25f);
	glVertex2f(11.5f, 2.25f);
	glVertex2f(11.5f, 2.5f);
	glVertex2f(10.5f, 2.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Zebra crossing end
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10.5f, 2.75f);
	glVertex2f(11.5f, 2.75f);
	glVertex2f(11.5f, 3.0f);
	glVertex2f(10.5f, 3.0f);
	glEnd();



	glBegin(GL_QUADS);                    //Road sideway
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex2f(0.0f, 3.0f);
	glVertex2f(19.0f, 3.0f);
	glVertex2f(19.0f, 3.75f);
	glVertex2f(0.0f, 3.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Rail track
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 3.75f);
	glVertex2f(19.0f, 3.75f);
	glVertex2f(19.0f, 4.0f);
	glVertex2f(0.0f, 4.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Rail track
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 4.25f);
	glVertex2f(19.0f, 4.25f);
	glVertex2f(19.0f, 4.5f);
	glVertex2f(0.0f, 4.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Rail track
	glColor3f(0.7f, 0.4f, 0.2f);
	glVertex2f(0.0f, 4.0f);
	glVertex2f(19.0f, 4.0f);
	glVertex2f(19.0f, 4.25f);
	glVertex2f(0.0f, 4.25f);
	glEnd();


    glPushMatrix();        // Save current transformation
    glTranslatef(_move, 0.0f, 0.0f); // Move Train horizontally

    glBegin(GL_POLYGON);                    //Train
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(5.75f, 4.25f);
	glVertex2f(8.25f, 4.25f);
	glVertex2f(8.25f, 4.75f);
	glVertex2f(7.5f, 5.25f);
	glVertex2f(5.75f, 5.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Train
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(3.25f, 4.25f);
	glVertex2f(5.5f, 4.25f);
	glVertex2f(5.5f, 5.25f);
	glVertex2f(3.25f, 5.25f);
	glEnd();

	glBegin(GL_QUADS);                    //Train
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(0.75f, 4.25f);
	glVertex2f(3.0f, 4.25f);
	glVertex2f(3.0f, 5.25f);
	glVertex2f(0.75f, 5.25f);
	glEnd();

    circle(0.25,7.5,4.25,0.1, 0.2, 0.0); //Train wheels
    circle(0.25,6.25,4.25,0.1, 0.2, 0.0); //Train wheels
    circle(0.25,5,4.25,0.1, 0.2, 0.0); //Train wheels
    circle(0.25,3.75,4.25,0.1, 0.2, 0.0); //Train wheels
    circle(0.25,2.5,4.25,0.1, 0.2, 0.0); //Train wheels
    circle(0.25,1.25,4.25,0.1, 0.2, 0.0); //Train wheels

    glBegin(GL_TRIANGLES);         //Train glass
	glColor3f(0.5f, 0.7f, 1.0f);
	glVertex2f(7.5f, 4.75f);
	glVertex2f(8.25f, 4.75f);
	glVertex2f(7.5f, 5.25f);
	glEnd();

	glBegin(GL_QUADS);         //Train glass
	glColor3f(0.5f, 0.7f, 1.0f);
	glVertex2f(3.5f, 4.75f);
	glVertex2f(5.0f, 4.75f);
	glVertex2f(5.0f, 5.0f);
	glVertex2f(3.5f, 5.0f);
	glEnd();

	glBegin(GL_QUADS);         //Train glass
	glColor3f(0.5f, 0.7f, 1.0f);
	glVertex2f(1.0f, 4.75f);
	glVertex2f(2.5f, 4.75f);
	glVertex2f(2.5f, 5.0f);
	glVertex2f(1.0f, 5.0f);
	glEnd();

    glPopMatrix();


	glBegin(GL_QUADS);                    //Building
	glColor3f(0.14f, 0.42f, 0.55f);
	glVertex2f(2.0f, 3.75f);
	glVertex2f(5.0f, 3.75f);
	glVertex2f(5.0f, 9.0f);
	glVertex2f(2.0f, 9.0f);
	glEnd();

	glBegin(GL_QUADS);                    //Building 3d view
	glColor3f(0.14f, 0.35f, 0.55f);
	glVertex2f(1.75f, 3.75f);
	glVertex2f(2.0f, 3.75f);
	glVertex2f(2.0f, 9.0f);
	glVertex2f(1.75f, 8.75f);
	glEnd();

	glBegin(GL_QUADS);                    //Building door
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(3.25f, 3.75f);
	glVertex2f(3.75f, 3.75f);
	glVertex2f(3.75f, 4.5f);
	glVertex2f(3.25f, 4.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.25f, 5.0f);
	glVertex2f(3.0f, 5.0f);
	glVertex2f(3.0f, 5.5f);
	glVertex2f(2.25f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.25f, 6.0f);
	glVertex2f(3.0f, 6.0f);
	glVertex2f(3.0f, 6.5f);
	glVertex2f(2.25f, 6.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.25f, 7.0f);
	glVertex2f(3.0f, 7.0f);
	glVertex2f(3.0f, 7.5f);
	glVertex2f(2.25f, 7.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(2.25f, 8.0f);
	glVertex2f(3.0f, 8.0f);
	glVertex2f(3.0f, 8.5f);
	glVertex2f(2.25f, 8.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 5.0f);
	glVertex2f(4.75f, 5.0f);
	glVertex2f(4.75f, 5.5f);
	glVertex2f(4.0f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 6.0f);
	glVertex2f(4.75f, 6.0f);
	glVertex2f(4.75f, 6.5f);
	glVertex2f(4.0f, 6.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 7.0f);
	glVertex2f(4.75f, 7.0f);
	glVertex2f(4.75f, 7.5f);
	glVertex2f(4.0f, 7.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Building window end
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(4.0f, 8.0f);
	glVertex2f(4.75f, 8.0f);
	glVertex2f(4.75f, 8.5f);
	glVertex2f(4.0f, 8.5f);
	glEnd();

	glBegin(GL_QUADS);                    //Tree branch
	glColor3f(0.6f, 0.3f, 0.1f);
	glVertex2f(8.5f, 3.5f);
	glVertex2f(9.0f, 3.5f);
	glVertex2f(9.0f, 6.75f);
	glVertex2f(8.5f, 6.75f);
	glEnd();

	circle(1.75,8.75,8,0,1,0); //Tree leaves
	circle(1.0,10,7,0,1,0); //Tree leaves
	circle(1.0,7.5,7,0,1,0); //Tree leaves

	circle(0.5,8,9.5,1,1,1); //Tree Snow
	circle(0.5,8.5,9.5,1,1,1); //Tree snow
	circle(0.5,9,9.75,1,1,1); //Tree snow
	circle(0.5,9.25,9.5,1,1,1); //Tree snow

	glBegin(GL_QUADS);               //Building
	glColor3f(1.0f, 0.6f, 0.0f);
	glVertex2f(13.0f, 3.75f);
	glVertex2f(16.0f, 3.75f);
	glVertex2f(16.0f, 8.0f);
	glVertex2f(13.0f, 8.0f);
	glEnd();

	glBegin(GL_QUADS);               //Building 3d view
	glColor3f(0.9f, 0.5f, 0.0f);
	glVertex2f(12.75f, 3.75f);
	glVertex2f(13.0f, 3.75f);
	glVertex2f(13.0f, 8.0f);
	glVertex2f(12.75f, 7.75f);
	glEnd();

	glBegin(GL_QUADS);               //Building Door
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(14.25f, 3.75f);
	glVertex2f(14.75f, 3.75f);
	glVertex2f(14.75f, 4.5f);
	glVertex2f(14.25f, 4.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.25f, 5.0f);
	glVertex2f(14.0f, 5.0f);
	glVertex2f(14.0f, 5.5f);
	glVertex2f(13.25f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.25f, 5.0f);
	glVertex2f(14.0f, 5.0f);
	glVertex2f(14.0f, 5.5f);
	glVertex2f(13.25f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.25f, 6.0f);
	glVertex2f(14.0f, 6.0f);
	glVertex2f(14.0f, 6.5f);
	glVertex2f(13.25f, 6.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(13.25f, 7.0f);
	glVertex2f(14.0f, 7.0f);
	glVertex2f(14.0f, 7.5f);
	glVertex2f(13.25f, 7.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(15.0f, 5.0f);
	glVertex2f(15.75f, 5.0f);
	glVertex2f(15.75f, 5.5f);
	glVertex2f(15.0f, 5.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(15.0f, 6.0f);
	glVertex2f(15.75f, 6.0f);
	glVertex2f(15.75f, 6.5f);
	glVertex2f(15.0f, 6.5f);
	glEnd();

	glBegin(GL_QUADS);               //Building window
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(15.0f, 7.0f);
	glVertex2f(15.75f, 7.0f);
	glVertex2f(15.75f, 7.5f);
	glVertex2f(15.0f, 7.5f);
	glEnd();

	circle(0.25,15.75,8,1,1,1); //snow
	circle(0.25,15.5,8.25,1,1,1); //snow
	circle(0.25,15.25,8,1,1,1); //snow
	circle(0.25,15,8,1,1,1); //snow



	glPushMatrix();
    glTranslatef(_moveCar2, 0.0f, 0.0f);  //Car

    glBegin(GL_QUADS);       //car body design
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(14.5f, 1.5f);
    glVertex2f(18.75f, 1.5f);
    glVertex2f(18.75f, 2.25f);
    glVertex2f(14.5f, 2.25f);
    glEnd();

    glBegin(GL_QUADS);       //car window
    glColor3f(0.5f, 0.7f, 1.0f);
    glVertex2f(15.5f, 2.25f);
    glVertex2f(18.0f, 2.25f);
    glVertex2f(17.5f, 2.75f);
    glVertex2f(16.0f, 2.75f);
    glEnd();

    circle(0.40, 15.25, 1.5, 0.1, 0.2, 0.0);  //Wheel
    circle(0.40, 18, 1.5, 0.1, 0.2, 0.0);  //Wheel

    glBegin(GL_LINE_STRIP);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(16.75f, 2.75f);
    glVertex2f(16.75, 1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);   //car headlight
    glVertex2f(14.5, 2.0f);
    glVertex2f(14.75, 2.0f);
    glVertex2f(14.75, 2.25f);
    glVertex2f(14.5, 2.25f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);   //car light beam
    glVertex2f(14.5, 2.15f);
    glVertex2f(11.75, 1.25f);
    glVertex2f(13.5, 1.25f);
    glEnd();

    glPopMatrix();

    glBegin(GL_QUADS);                    //Traffic Light
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(11.75f, 1.25f);
	glVertex2f(12.25f, 1.25f);
	glVertex2f(12.25f, 2.75f);
	glVertex2f(11.75f, 2.75f);
	glEnd();

	glBegin(GL_LINE_STRIP);                    //Traffic Light stand
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(12.0f, 0.5f);
	glVertex2f(12.0f, 1.25f);
	glEnd();

	circle(0.15,12,1.5,0,1,0); //Green light
	circle(0.15,12,2,1,1,0); //Yellow light
	circle(0.15,12,2.5,1,0,0); //Red light


	glPushMatrix();
    glTranslatef(0.0f, _moveCar2, 0.0f);

    circle(0.05,1.0,1.0,1.0,1.0,1.0);
    circle(0.05,2.0,3.0,1.0,1.0,1.0);
    circle(0.05,3.0,5.0,1.0,1.0,1.0);
    circle(0.05,4.0,7.0,1.0,1.0,1.0);
    circle(0.05,5.0,2.0,1.0,1.0,1.0);
    circle(0.05,6.0,13.0,1.0,1.0,1.0);
    circle(0.05,7.0,11.0,1.0,1.0,1.0);
    circle(0.05,8.0,6.0,1.0,1.0,1.0);
    circle(0.05,9.0,8.0,1.0,1.0,1.0);
    circle(0.05,12.0,10.0,1.0,1.0,1.0);
    circle(0.05,14.0,20.0,1.0,1.0,1.0);
    circle(0.05,18.0,18.0,1.0,1.0,1.0);
    circle(0.05,17.0,22.0,1.0,1.0,1.0);
    circle(0.05,13.0,2.0,1.0,1.0,1.0);
    circle(0.05,10.0,6.0,1.0,1.0,1.0);
    circle(0.05,13.0,8.0,1.0,1.0,1.0);
    circle(0.05,12.0,3.0,1.0,1.0,1.0);
    circle(0.05,11.0,19.0,1.0,1.0,1.0);


    glPopMatrix();

    }


    else {             //Scenery 3

    glClearColor(0.94f, 0.87f, 0.73f, 1.0f); // sand color
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(7.5);

    //sky

    if(isDay) {
    glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.98f);
    glVertex2f(0.0f, 7.0f);
    glVertex2f(0.0f, 12.0f);
    glVertex2f(19.0f, 12.0f);
    glVertex2f(19.0f, 7.0f);
    glEnd();
    }

    if(!isDay) {
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.1f, 0.3f); // Dark blue
    glVertex2f(0.0f, 7.0f);
    glVertex2f(0.0f, 12.0f);
    glVertex2f(19.0f, 12.0f);
    glVertex2f(19.0f, 7.0f);
    glEnd();


    }



    if (isDay) {
        circle(0.7, 13.0, 8.5, 1.0, 1.0, 0.0); // Sun during day
    }


    if (!isDay) {
        circle(0.7f, 13, 8.5, 0.9f, 0.9f, 0.9f); // Moon during night
    }




    // cloud
    if(isDay) {                               //if day
        circle(0.9, 7.0, 10.5, 1.0, 1.0, 1.0);
        circle(0.7, 6.4, 10.5, 1.0, 1.0, 1.0);
        circle(0.7, 7.6, 10.5, 1.0, 1.0, 1.0);
        circle(0.6, 6.7, 10.0, 1.0, 1.0, 1.0);
        circle(0.6, 7.3, 10.0, 1.0, 1.0, 1.0);
        circle(0.5, 7.0, 11.0, 1.0, 1.0, 1.0);
    }

    if(!isDay) {      //if night
        circle(0.9, 7.0, 10.5, 0.6, 0.6, 0.6);
        circle(0.7, 6.4, 10.5, 0.6, 0.6, 0.6);
        circle(0.7, 7.6, 10.5, 0.6, 0.6, 0.6);
        circle(0.6, 6.7, 10.0, 0.6, 0.6, 0.6);
        circle(0.6, 7.3, 10.0, 0.6, 0.6, 0.6);
        circle(0.5, 7.0, 11.0, 0.6, 0.6, 0.6);

    }




    //hill
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.60f, 0.0f);
    glVertex2f(0.0f, 7.0f);
    glVertex2f(0.0f, 7.5f);
    glVertex2f(0.5f, 8.25f);
    glVertex2f(1.25f, 7.0f);
    glEnd();

    //hill 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex2f(0.75f, 7.0f);
    glVertex2f(1.5f, 7.75f);
    glVertex2f(2.0f, 7.0f);
    glEnd();

    //hill 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.85f, 0.0f);
    glVertex2f(2.0f, 7.0f);
    glVertex2f(2.25f, 8.25f);
    glVertex2f(2.5f, 7.0f);
    glEnd();

    //hill 4
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex2f(2.5f, 7.0f);
    glVertex2f(2.75f, 8.0f);
    glVertex2f(3.0f, 7.0f);
    glEnd();

    //hill 5
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex2f(3.75f, 7.0f);
    glVertex2f(5.0f, 8.0f);
    glVertex2f(6.0f, 7.25f);
    glVertex2f(6.25f, 7.0f);
    glEnd();

    //tree 1
    glBegin(GL_QUADS);
    glColor3f(0.70f, 0.5f, 0.0f);
    glVertex2f(8.75f, 7.0f);
    glVertex2f(8.75f, 8.50f);
    glVertex2f(9.0f, 8.50f);
    glVertex2f(9.0f, 7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(8.25f, 8.5f);
    glVertex2f(9.0f, 9.25f);
    glVertex2f(9.5f, 8.5f);
    glEnd();

    //tree 2
    glBegin(GL_QUADS);
    glColor3f(0.70f, 0.5f, 0.0f);
    glVertex2f(9.5f, 7.0f);
    glVertex2f(9.5f, 8.0f);
    glVertex2f(9.75f, 8.0f);
    glVertex2f(9.75f, 7.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex2f(9.0f, 8.0f);
    glVertex2f(9.65f, 8.75f);
    glVertex2f(10.25f, 8.0f);
    glEnd();

    //hill 6
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.65f, 0.0f);
    glVertex2f(6.25f, 7.0f);
    glVertex2f(6.0f, 7.25f);
    glVertex2f(7.5f, 8.25f);
    glVertex2f(8.25f, 7.0f);
    glEnd();

    //hill 7
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.65f, 0.0f);
    glVertex2f(10.0f, 7.0f);
    glVertex2f(12.0f, 8.0f);
    glVertex2f(14.50f, 7.0f);
    glEnd();

    //hill 9
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.75f, 0.0f);
    glVertex2f(13.75f, 7.0f);
    glVertex2f(14.25f, 8.0f);
    glVertex2f(15.0f, 8.25f);
    glVertex2f(17.25f, 7.0f);
    glEnd();

    //hill 8
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.85f, 0.0f);
    glVertex2f(11.5f, 7.0f);
    glVertex2f(12.25f, 7.5f);
    glVertex2f(11.5f, 7.0f);
    glVertex2f(13.0f, 8.25f);
    glVertex2f(13.25f, 8.5f);
    glVertex2f(14.25f, 7.0f);
    glEnd();

    //hill 9
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.65f, 0.0f);
    glVertex2f(16.75f, 7.0f);
    glVertex2f(18.5f, 8.5f);
    glVertex2f(19.0f, 8.25f);
    glVertex2f(19.0f, 7.0f);
    glEnd();

    //vally-grass
    circle(.45, 8.75, 6.8, 0, .4, 0);
    circle(.35, 9.2, 6.8, 0, .6, 0);
    circle(.55, 9.8, 6.8, 0, .5, 0);
    circle(.55, 8.25, 6.8, 0, .5, 0);


    //road 1
    glBegin(GL_POLYGON);
    glColor3f(0.50f, 1.0f, 0.0f);
    glVertex2f(0.0f, 7.0f);
    glVertex2f(19.0f, 7.0f);
    glVertex2f(19.0f, 6.25f);
    glVertex2f(0.0f, 6.5f);
    glEnd();

    //road 2
    glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.8f, 0.0f);
    glVertex2f(0.0f, 6.5f);
    glVertex2f(19.0f, 6.25f);
    glVertex2f(19.0f, 6.0f);
    glVertex2f(0.0f, 6.25f);
    glEnd();

    //ground 1
    glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.8f, 0.0f);
    glVertex2f(19.0f, 5.25f);
    glVertex2f(14.5f, 5.5f);
    glVertex2f(11.5f, 4.75f);
    glVertex2f(16.0f, 3.75f);
    glVertex2f(19.0f, 4.0f);
    glEnd();

    //ground 2
    glBegin(GL_POLYGON);
    glColor3f(0.50f, 0.8f, 0.0f);
    glVertex2f(0.0f, 5.5f);
    glVertex2f(10.0f, 5.25f);
    glVertex2f(8.0f, 4.25f);
    glVertex2f(11.50f, 3.5f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    //khor
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.8f, 0.0f);
    glVertex2f(4.75f, 3.75f);
    glVertex2f(5.25f, 5.25f);
    glVertex2f(5.75f, 5.75f);
    glVertex2f(6.250f, 5.25f);
    glVertex2f(6.75f, 4.5f);
    glVertex2f(7.25f, 3.75f);
    glEnd();

    //house 1- left
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.3f, 0.0f);
    glVertex2f(3.0f, 4.75f);
    glVertex2f(3.5f, 5.5f);
    glVertex2f(3.75f, 5.5f);
    glVertex2f(3.25f, 4.75f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.8f, 0.8f);
    glVertex2f(3.25f, 4.0f);
    glVertex2f(3.25f, 4.75f);
    glVertex2f(3.75f, 5.5f);
    glVertex2f(4.25f, 4.75f);
    glVertex2f(4.25f, 3.75f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(4.25f, 3.75f);
    glVertex2f(4.25f, 4.75f);
    glVertex2f(5.75f, 4.75f);
    glVertex2f(5.75f, 3.75f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(4.25f, 4.75f);
    glVertex2f(3.5f, 5.5f);
    glVertex2f(5.25f, 5.5f);
    glVertex2f(6.0f, 4.75f);
    glEnd();

    //door-house-1-left
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(4.75f, 3.75f);
    glVertex2f(4.75f, 4.5f);
    glVertex2f(5.5f, 4.5f);
    glVertex2f(5.5f, 3.75f);
    glEnd();

    //window-house 1 left
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(3.5f, 4.5f);
    glVertex2f(4.0f, 4.45f);
    glVertex2f(4.0f, 4.20f);
    glVertex2f(3.5f, 4.30f);
    glEnd();

    //tree left
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(2.25f, 3.75f);
    glVertex2f(2.25f, 6.25f);
    glVertex2f(3.0f, 6.25f);
    glVertex2f(3.0f, 3.75f);
    glEnd();

    //leaf - tree left
    circle(.75, 2.6, 6.6, 0, .4, 0);
    circle(.35, 2.6, 6.8, 0, .6, 0);
    circle(.75, 2.6, 7.1, 0, .6, 0);
    circle(.85, 3.2, 6.6, 0, .6, 0);
    circle(.85, 2.0, 6.6, 0, .6, 0);
    circle(.55, 1.4, 6.8, 0, .6, 0);
    circle(.55, 3.8, 6.8, 0, .6, 0);



    //tree right
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(14.5f, 5.0f);
    glVertex2f(14.5f, 7.25f);
    glVertex2f(15.25f, 7.25f);
    glVertex2f(15.25f, 5.0f);
    glEnd();

    //leaf - tree right
    circle(.75, 14.9, 7.35, 0, .4, 0);
    circle(.75, 15.8, 7.35, 0, .4, 0);
    circle(.75, 14.0, 7.35, 0, .4, 0);
    circle(.55, 14.5, 7.85, 0, .4, 0);
    circle(.55, 15.4, 7.85, 0, .4, 0);
    circle(.65, 14.9, 8.15, 0, .4, 0);

    //house left
    glBegin(GL_POLYGON);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2f(16.0f, 4.85f);
    glVertex2f(16.0f, 6.75f);
    glVertex2f(19.0f, 6.75f);
    glVertex2f(19.0f, 4.85f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(15.5f, 6.25f);
    glVertex2f(16.5f, 7.25f);
    glVertex2f(19.0f, 7.25f);
    glVertex2f(19.0f, 6.25f);
    glEnd();

    //door-house- right
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(18.0f, 4.85f);
    glVertex2f(18.0f, 6.0f);
    glVertex2f(19.0f, 6.0f);
    glVertex2f(19.0f, 4.85f);
    glEnd();

    //window house right
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.6f, 0.5f);
    glVertex2f(16.25f, 5.25f);
    glVertex2f(16.25f, 5.75f);
    glVertex2f(17.75f, 5.75f);
    glVertex2f(17.75f, 5.25f);
    glEnd();


    //river side
    glBegin(GL_POLYGON);
    glColor3f(0.8f, 0.5f, 0.0f);
    glVertex2f(0.0f, 0.75f);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(19.0f, 3.0f);
    glVertex2f(19.0f, 2.75f);
    glEnd();

    //river
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.75f, 0.85f);
    glVertex2f(0.0f, 0.75f);
    glVertex2f(19.0f, 2.75f);
    glVertex2f(19.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glPushMatrix();        //boat moving
    glTranslatef(_move, 0.0f, 0.0f);


    glBegin(GL_QUADS);    //boat start
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(2.0f, 0.75f);
    glVertex2f(2.5f, 0.25f);
    glVertex2f(4.0f, 0.25f);
    glVertex2f(4.5f, 0.75f);
    glEnd();

    glBegin(GL_TRIANGLES);    //boat
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(4.0f, 0.75f);
    glVertex2f(4.5f, 0.75f);
    glVertex2f(4.75f, 1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);    //boat body end
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(2.0f, 0.75f);
    glVertex2f(2.5f, 0.75f);
    glVertex2f(1.75f, 1.0f);
    glEnd();

    glBegin(GL_QUADS);    //boat
    glColor3f(0.55f, 0.27f, 0.07f);
    glVertex2f(2.5f, 0.75f);
    glVertex2f(4.0f, 0.75f);
    glVertex2f(4.0f, 1.25f);
    glVertex2f(2.5f, 1.25f);
    glEnd();



    glBegin(GL_QUADS);             //pal flag
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(3.85f, 2.5f);
    glVertex2f(3.85f, 1.5f);
    glVertex2f(3.35f, 1.5f);
    glVertex2f(3.35f, 2.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(2.65f, 2.5f);
    glVertex2f(2.65f, 1.5f);
    glVertex2f(3.15f, 1.5f);
    glVertex2f(3.15f, 2.5f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINE_STRIP);    //boat pal stick
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(3.25f, 1.25f);
    glVertex2f(3.25f, 2.75f);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINE_STRIP);    //boat pal stick
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(2.5f, 2.5f);
    glVertex2f(4.0f, 2.5f);
    glEnd();

    glPopMatrix();



    }

    glFlush();

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	cout<<"Select a View"<<endl;
	cout<<"1. Press '1' for City view : Day= 'd' , Night= 'n'"<<endl;
	cout<<"2. Press '2' for Winter view : Day= 'd' , Night= 'n'"<<endl;
	cout<<"3. Press '3' for Spring season view: Day= 'd' , Night= 'n' "<<endl;


	glutInitWindowSize(800, 800);
	glutCreateWindow("Project");
	gluOrtho2D(0,19,0,11);
	glutDisplayFunc(display);
	glutTimerFunc(10, update, 0);
	glutKeyboardFunc(handleKeypress); // Register keypress function
	glutMainLoop();


	return 0;
}
