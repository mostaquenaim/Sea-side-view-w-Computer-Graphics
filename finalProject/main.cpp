#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include<Windows.h>
#include<MMSystem.h>
using namespace std;

float x,y,i;
int x2,y2;
///sky
int skyStatus=0;
///srot
GLfloat srotPosition=0.0f;
GLfloat srotSpeed=2.0f;
///sun
float SetPosition=0.0f;
float RisePosition=0.0f;
float sunspeed=0.5f;
bool flagSun=true;
///clouds
float cloudPosition=0.0f;
///light
int lightstatus=0;
///ship
float shipPositon=-650.0f;
float shipDown=-10;
float shipspeed=5.0f;
int shipMove=1;
///moon
float moonPosition=0.0f;
///bird
float birdsStatus=0.0f;
///snow
int winter=0;
float Position3=0.0f;
///rain
int rainstatus=0;
///boat
float _run=0.0f;
//float _run=0.0f;
///helicopter
float _run2=0.0f;
///boat
float boatMove=0.0f;
float boatMove2=-100;
///shark
float sharkPosition=-200;
int sharkStatus=0;

void drawTriangle(GLint x0, GLint y0, GLint x1, GLint y1, GLint x2, GLint y2)
{   glBegin(GL_TRIANGLES);
    glVertex2f(x0,y0);glVertex2f(x1,y1);glVertex2f(x2,y2);
    glEnd();
}

void DrawCircle(float cx, float cy, float r, int num_segments) {

	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get current angle

		float x = r * cosf(theta);//calculate x
		float y = r * sinf(theta);//calculate y

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	    //glFlush();
}
///////////////////////////// birds

void update(int value){
   // sndPlaySound("E:\\CG\\finalProjectDone\\Stoomboot.wav",SND_ASYNC);
    ///shark
    if(sharkStatus==1)
    sharkPosition+=srotSpeed+2;
    ///boat
    if(rainstatus==1) {
            if(boatMove>400 && boatMove<450) rainstatus=1;

        else {

                boatMove+=3*srotSpeed;

    }
    if(boatMove2>480 && boatMove2<570) rainstatus=1;
    else boatMove2+=3*srotSpeed;
    }
    else {
    if(skyStatus==0)
    {
        boatMove2+=srotSpeed;
        boatMove+=srotSpeed;
    }
    else if(skyStatus==1)
    {
        if(boatMove>400 && boatMove<450) skyStatus=1;
       else boatMove+=2*srotSpeed;

       if(boatMove2>480 && boatMove2<570) skyStatus=1;
       else boatMove2+=2*srotSpeed;
    }
    else
        {
            boatMove=400;
            boatMove2=480;
    }
    }
    if(boatMove>640) boatMove=0;
    if(boatMove2>740) boatMove2=0;

    ///srot
    srotPosition+=srotSpeed;
    if(srotPosition > 200)
        srotPosition=0.0;

    ///sun
    if(flagSun)
    SetPosition-=sunspeed;
    else if(skyStatus==2)
        moonPosition-=sunspeed;
    else
        RisePosition+=sunspeed;

    if(SetPosition<-300){
        flagSun=false;
        skyStatus=2;
        SetPosition=20;
    }
    if(moonPosition < -400 )
        skyStatus=0;
    if(RisePosition>500){
        flagSun=true;
        RisePosition=0.0;
    }
    ///clouds
    cloudPosition+=srotSpeed;
    if(cloudPosition>200)
        cloudPosition=0.0;

    ///ship
    if(shipMove==1){
    shipPositon+=shipspeed;
    if(shipPositon>1000)
        shipPositon=-650;
    }

    else if(shipMove==2){
        shipPositon-=shipspeed;
        if(shipPositon<-1000)
            shipPositon=20;
    }

    ///Shondha
    if(SetPosition < -220 )
        skyStatus=1;
    //else skyStatus=0;

	///moon
	if(SetPosition < -300 && moonPosition > -400)
        skyStatus=2; ///night
    else if(moonPosition<-400){
        RisePosition=250;
        moonPosition=0;
        SetPosition=50;
    }
    ///snow
    if(Position3<-300)
    {
        Position3=+30.0f;
    }
    if(Position3>300)
       {
           Position3=3;
       }
      Position3 -= srotSpeed;

    glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
void stars(){
    if(skyStatus==2){
    //glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (240, 240, 240);
glPointSize(3.0);
glBegin(GL_POINTS);
glVertex2i(100, 300);
glVertex2i(150, 350);
glVertex2i(200, 300);
glVertex2i(100, 400);
glVertex2i(150, 380);
glVertex2i(200, 400);
glVertex2i(300, 300);
glVertex2i(350, 350);
glVertex2i(400, 300);
glVertex2i(300, 400);
glVertex2i(350, 380);
glVertex2i(400, 400);
glVertex2i(500, 300);
glVertex2i(550, 350);
glVertex2i(600, 300);
glVertex2i(500, 400);
glVertex2i(550, 380);
glVertex2i(600, 400);
glEnd();
    }
//glFlush ();
}

void boat(){

       //if(skyStatus!=2){
                ////////////////////////////////noukar body
                glPushMatrix();
       glTranslatef(boatMove,0,0);
    glColor3ub (132, 112 ,255);
    glBegin(GL_QUADS);
    glVertex2f(20, 220);
    glVertex2f(60, 220);
    glVertex2f(70, 230);
    glVertex2f(10, 230);
    glEnd();
    //////////////

    ///////////////////////////////noukar soi
    glColor3ub (0 ,206, 209);
    glBegin(GL_POLYGON);
    glVertex2f(27, 230);
    glVertex2f(57, 230);
    glVertex2f(57, 240);
    glVertex2f(27, 240);
    glEnd();
    //glFlush();
    ////////////////////////////////pal er chera kapor
    glColor3ub (139 ,131, 120);
    glBegin(GL_TRIANGLES);
    glVertex2f(57, 230);
    glVertex2f(90, 280);
    glVertex2f(50, 290);
    glEnd();
        ///////////////////////////noukar pal
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2f(57, 230);
    glVertex2f(73, 290);
    glEnd();
    glPopMatrix();

    ///2nd boat
    glPushMatrix();
       glTranslatef(boatMove2,0,0);
    glColor3ub (132, 112 ,255);
    glBegin(GL_QUADS);
    glVertex2f(20, 220);
    glVertex2f(60, 220);
    glVertex2f(70, 230);
    glVertex2f(10, 230);
    glEnd();
    //////////////

    ///////////////////////////////noukar soi
    glColor3ub (0 ,206, 209);
    glBegin(GL_POLYGON);
    glVertex2f(27, 230);
    glVertex2f(57, 230);
    glVertex2f(57, 240);
    glVertex2f(27, 240);
    glEnd();
    //glFlush();
    ////////////////////////////////pal er chera kapor
    glColor3ub (47, 79, 79);
    glBegin(GL_TRIANGLES);
    glVertex2f(57, 230);
    glVertex2f(90, 280);
    glVertex2f(50, 290);
    glEnd();
        ///////////////////////////noukar pal
    glColor3ub (206, 175, 109);
    glBegin(GL_LINES);
    glVertex2f(57, 230);
    glVertex2f(73, 290);
    glEnd();
    glPopMatrix();

       //}
}



void snow(){
  if(winter ==1){
    glPushMatrix();
    glTranslatef(0.0f,Position3, 0.0f);

    glColor3ub(255, 255, 255);
    DrawCircle(400, 480, 1, 2000);
	DrawCircle(500, 490, .5, 2000);
	DrawCircle(600, 480, 1, 2000);
   glColor3ub(255, 255, 255);
	DrawCircle(420, 480, 1, 2000);
	DrawCircle(440, 480, .5, 2000);
	DrawCircle(460, 500, 1, 2000);
glColor3ub(255, 255, 255);
	DrawCircle(480, 490, 1, 2000);
	DrawCircle(500, 480, .5, 2000);
	DrawCircle(520, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(570, 500, .5, 2000);
	DrawCircle(580, 480, 1, 2000);
	DrawCircle(590, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(100, 480, .8, 2000);
	DrawCircle(120, 490, .5, 2000);
	DrawCircle(140, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(160, 480, .5, 2000);
	DrawCircle(180, 480, .5, 2000);
	DrawCircle(200, 490, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(220, 490, 1, 2000);
	DrawCircle(240, 480, .5, 2000);
	DrawCircle(260, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(280, 500, .5, 2000);
	DrawCircle(300, 480, .5, 2000);
	DrawCircle(320, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(340, 480, .5, 2000);
	DrawCircle(360, 490, .5, 2000);
	DrawCircle(380, 480, 1, 2000);

    glTranslatef(0.0f,Position3, 0.0f);

   glColor3ub(255, 255, 255);
    DrawCircle(10, 600, 1, 2000);
	DrawCircle(30, 681, .5, 2000);
	DrawCircle(90, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(10, 500, .8, 2000);
	DrawCircle(30, 690, .5, 2000);
	DrawCircle(50, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(70, 600, .5, 2000);
	DrawCircle(90, 681, .5, 2000);
	DrawCircle(21, 690, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(610, 600, 1, 2000);
	DrawCircle(630, 681, .5, 2000);
	DrawCircle(690, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(610, 500, .8, 2000);
	DrawCircle(630, 690, .5, 2000);
	DrawCircle(650, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(670, 600, .5, 2000);
	DrawCircle(690, 681, .5, 2000);
	DrawCircle(621, 690, 1, 2000);
    glColor3ub(28, 40, 51);
    DrawCircle(410, 480, .5, 2000);
	DrawCircle(510, 490, .5, 2000);
	DrawCircle(610, 480, 1, 2000);
    glColor3ub(255, 255, 255);
	DrawCircle(410, 480, .5, 2000);
	DrawCircle(430, 490, .5, 2000);
	DrawCircle(450, 480, 1, 2000);
	glColor3ub(255, 255, 255);
	DrawCircle(470, 480, .5, 2000);
	DrawCircle(490, 480, .5, 2000);
	DrawCircle(530, 490, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(570, 500, .5, 2000);
	DrawCircle(580, 480, 1, 2000);
	DrawCircle(590, 490, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(110, 500, .8, 2000);
	DrawCircle(130, 490, .5, 2000);
	DrawCircle(150, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(170, 480, .5, 2000);
	DrawCircle(190, 490, .5, 2000);
	DrawCircle(210, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(230, 500, .5, 2000);
	DrawCircle(250, 490, .5, 2000);
	DrawCircle(270, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(290, 500, .5, 2000);
	DrawCircle(310, 490, .5, 2000);
	DrawCircle(330, 480, .5, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(350, 500, .5, 2000);
	DrawCircle(370, 480, .5, 2000);
	DrawCircle(390, 490, .5, 2000);

    glTranslatef(Position3,Position3, 0.0f);

   glColor3ub(255, 255, 255);
    DrawCircle(10, 600, 1, 2000);
	DrawCircle(30, 681, .5, 2000);
	DrawCircle(90, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(10, 500, .8, 2000);
	DrawCircle(30, 690, .5, 2000);
	DrawCircle(50, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(70, 600, .5, 2000);
	DrawCircle(90, 681, .5, 2000);
	DrawCircle(21, 690, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(610, 600, 1, 2000);
	DrawCircle(630, 681, .5, 2000);
	DrawCircle(690, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(610, 500, .8, 2000);
	DrawCircle(630, 690, .5, 2000);
	DrawCircle(650, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(670, 600, .5, 2000);
	DrawCircle(690, 681, .5, 2000);
	DrawCircle(621, 690, 1, 2000);
    glColor3ub(255, 255, 255);
    DrawCircle(400, 500, .7, 2000);
	DrawCircle(500, 490, .5, 2000);
	DrawCircle(600, 480, .7, 2000);
glColor3ub(255, 255, 255);
	DrawCircle(420, 500, .7, 2000);
	DrawCircle(440, 490, .7, 2000);
	DrawCircle(460, 480, .7, 2000);
	glColor3ub(255, 255, 255);
	DrawCircle(480, 500, .5, 2000);
	DrawCircle(500, 490, .5, 2000);
	DrawCircle(520, 480, .5, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(570, 500, .7, 2000);
	DrawCircle(580, 490, .7, 2000);
	DrawCircle(590, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(100, 500, .8, 2000);
	DrawCircle(120, 490, .8, 2000);
	DrawCircle(140, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(160, 500, .7, 2000);
	DrawCircle(180, 490, .7, 2000);
	DrawCircle(200, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(220, 500, 1, 2000);
	DrawCircle(240, 490, .5, 2000);
	DrawCircle(260, 480, .5, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(280, 500, 1, 2000);
	DrawCircle(300, 490, .5, 2000);
	DrawCircle(320, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(340, 500, .5, 2000);
	DrawCircle(360, 490, 1, 2000);
	DrawCircle(380, 480, .5, 2000);
    glColor3ub(255, 255, 255);
    DrawCircle(410, 500, 1, 2000);
	DrawCircle(510, 490, .7, 2000);
	DrawCircle(610, 480, .6, 2000);
   glColor3ub(255, 255, 255);
	DrawCircle(410, 480, .7, 2000);
	DrawCircle(430, 490, .6, 2000);
	DrawCircle(450, 500, .5, 2000);
	glColor3ub(255, 255, 255);
	DrawCircle(470, 500, 1, 2000);
	DrawCircle(490, 490, .5, 2000);
	DrawCircle(530, 489, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(570, 500, 1, 2000);
	DrawCircle(580, 481, .7, 2000);
	DrawCircle(590, 491, .8, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(110, 500, .8, 2000);
	DrawCircle(130, 490, .5, 2000);
	DrawCircle(150, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(170, 500, 1, 2000);
	DrawCircle(190, 481, .5, 2000);
	DrawCircle(210, 490, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(230, 500, .5, 2000);
	DrawCircle(250, 498, .7, 2000);
	DrawCircle(270, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(290, 500, .5, 2000);
	DrawCircle(310, 490, .7, 2000);
	DrawCircle(330, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(350, 500, .5, 2000);
	DrawCircle(370, 490, 1, 2000);
	DrawCircle(390, 480, .7, 2000);
   glColor3ub(255, 255, 255);
    DrawCircle(400, 500, 1, 2000);
	DrawCircle(500, 490, .5, 2000);
	DrawCircle(600, 480, .7, 2000);
glColor3ub(255, 255, 255);
	DrawCircle(420, 500, 1, 2000);
	DrawCircle(440, 490, 1, 2000);
	DrawCircle(460, 480, 1, 2000);
glColor3ub(255, 255, 255);
	DrawCircle(480, 500, .7, 2000);
	DrawCircle(500, 490, 1, 2000);
	DrawCircle(520, 480, .7, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(570, 500, 1, 2000);
	DrawCircle(580, 490, .5, 2000);
	DrawCircle(590, 480, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(100, 500, .8, 2000);
	DrawCircle(120, 490, .5, 2000);
	DrawCircle(140, 480, .8, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(160, 500, .7, 2000);
	DrawCircle(180, 490, 1, 2000);
	DrawCircle(200, 480, 1, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(220, 500, 1, 2000);
	DrawCircle(240, 490, .5, 2000);
	DrawCircle(260, 480, 1, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(280, 500, 1, 2000);
	DrawCircle(300, 490, .5, 2000);
	DrawCircle(320, 480, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(340, 500, .5, 2000);
	DrawCircle(360, 490, .7, 2000);
	DrawCircle(380, 480, 1, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(410, 500, 1, 2000);
	DrawCircle(510, 490, .7, 2000);
	DrawCircle(610, 480, 1, 2000);
   glColor3ub(255, 255, 255);
	DrawCircle(410, 480, 1, 2000);
	DrawCircle(430, 490, .7, 2000);
	DrawCircle(450, 500, 1, 2000);
	glColor3ub(255, 255, 255);
	DrawCircle(470, 600, 1, 2000);
	DrawCircle(490, 690, .5, 2000);
	DrawCircle(530, 689, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(570, 600, 1, 2000);
	DrawCircle(580, 681, .5, 2000);
	DrawCircle(590, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(110, 500, .8, 2000);
	DrawCircle(130, 690, .5, 2000);
	DrawCircle(150, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(170, 600, .5, 2000);
	DrawCircle(190, 681, .5, 2000);
	DrawCircle(210, 690, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(230, 600, 1, 2000);
	DrawCircle(250, 698, .7, 2000);
	DrawCircle(270, 680, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(290, 600, 1, 2000);
	DrawCircle(310, 690, .5, 2000);
	DrawCircle(330, 680, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(350, 600, 1, 2000);
	DrawCircle(370, 690, .7, 2000);
	DrawCircle(390, 680, 1, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(10, 600, 1, 2000);
	DrawCircle(30, 681, .5, 2000);
	DrawCircle(90, 691, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(10, 500, .8, 2000);
	DrawCircle(30, 690, .5, 2000);
	DrawCircle(50, 680, .8, 2000);
	glColor3ub(255, 255, 255);
    DrawCircle(70, 600, .5, 2000);
	DrawCircle(90, 681, .5, 2000);
	DrawCircle(21, 690, 1, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(610, 600, 1, 2000);
	DrawCircle(630, 681, .5, 2000);
	DrawCircle(690, 691, .8, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(610, 500, .8, 2000);
	DrawCircle(630, 690, .5, 2000);
    DrawCircle(650, 680, .8, 2000);
glColor3ub(255, 255, 255);
    DrawCircle(670, 600, .5, 2000);
	DrawCircle(690, 681, .5, 2000);
	DrawCircle(621, 690, 1, 2000);

    glPopMatrix();

    }
}
void sky(){
    if(skyStatus==0){
    glColor3ub (135 ,206, 255);
    glBegin(GL_QUADS);
    glVertex2f(0, 480);
    glVertex2f(0, 255);
    glVertex2f(640, 255);
    glVertex2f(640, 480);
    glEnd();
        //glFlush();
    }
    else if(skyStatus==1){
        //glColor3ub (240 ,128, 128);
        glColor3ub (253, 96, 81);
        glBegin(GL_QUADS);
        glVertex2f(0, 480);
        glVertex2f(0, 255);
        glVertex2f(640, 255);
        glVertex2f(640, 480);
        glEnd();
            //glFlush();
    }
    else if(skyStatus==2){
        glColor3ub (0,0,0);
        glBegin(GL_QUADS);
        glVertex2f(0, 480);
        glVertex2f(0, 255);
        glVertex2f(640, 255);
        glVertex2f(640, 480);
        glEnd();
    }
}
void daywater(){
    if(rainstatus==0){
    //glColor3ub (169, 242, 242);
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glBegin(GL_LINES);
    glVertex2f(200, 220);
    glVertex2f(220, 220);

    glVertex2f(210, 230);
    glVertex2f(220, 230);

    glVertex2f(300, 220);
    glVertex2f(320, 220);


    glVertex2f(100, 240);
    glVertex2f(120, 240);

    glVertex2f(150, 180);
    glVertex2f(150, 180);

    glVertex2f(0, 190);
    glVertex2f(10, 190);

    glVertex2f(0, 200);
    glVertex2f(10, 200);

    glVertex2f(30, 185);
    glVertex2f(40, 185);

    glVertex2f(100, 250);
    glVertex2f(125, 250);

    glVertex2f(150,240);
    glVertex2f(165,240);

    glVertex2f(90,200);
    glVertex2f(100,200);



    glVertex2f(270,235);
    glVertex2f(275,235);

    glVertex2f(260,35);
    glVertex2f(275,35);

    glVertex2f(260,35);
    glVertex2f(275,35);

    glVertex2f(250,45);
    glVertex2f(275,45);

    glVertex2f(250,55);
    glVertex2f(265,55);

     glVertex2f(270,235);
    glVertex2f(275,235);

    glVertex2f(260,35);
    glVertex2f(275,35);

    glVertex2f(280,85);
    glVertex2f(305,85);

    glVertex2f(250,65);
    glVertex2f(275,65);

    glVertex2f(80,45);
    glVertex2f(100,45);

    glVertex2f(50,40);
    glVertex2f(70,40);

    glVertex2f(30,45);
    glVertex2f(45,45);

    glVertex2f(10,40);
    glVertex2f(40,40);

    glVertex2f(30,145);
    glVertex2f(45,145);

    glVertex2f(170,190);
    glVertex2f(190,190);

    glVertex2f(105,90);
    glVertex2f(120,90);

    glVertex2f(80,145);
    glVertex2f(95,145);

    glVertex2f(305,90);
    glVertex2f(320,90);

    glVertex2f(380,145);
    glVertex2f(395,145);

    glVertex2f(505,40);
    glVertex2f(520,40);

    glVertex2f(570,25);
    glVertex2f(595,25);

    glVertex2f(50,130);
    glVertex2f(80,130);

    glVertex2f(250,65);
    glVertex2f(275,65);

    glVertex2f(240,25);
    glVertex2f(265,25);

    glVertex2f(350,55);
    glVertex2f(375,55);

    glVertex2f(340,25);
    glVertex2f(365,25);


    glEnd();
    }
   }
void shark(){
    glPushMatrix();
    glTranslatef(sharkPosition,0.0f, 0.0f);
    //glColor3ub  (0, 89, 117);
    //DrawCircle(130,50,50,2000);
    glColor3ub  (0, 109, 117);
    glBegin(GL_POLYGON);
    glVertex2f(100, 50);
    glVertex2f(150, 50);
    glVertex2f(160, 80);
    glEnd();

    glColor3ub  (90,188,216);
    glBegin(GL_LINES);
    glVertex2f(85, 55);
    glVertex2f(95, 55);

    glVertex2f(175, 55);
    glVertex2f(185, 55);

    glVertex2f(165, 65);
    glVertex2f(175, 65);

    glVertex2f(170, 75);
    glVertex2f(180, 75);

    glVertex2f(170, 40);
    glVertex2f(180, 40);

    glVertex2f(110, 40);
    glVertex2f(130, 40);

    glVertex2f(135, 40);
    glVertex2f(165, 40);

    glVertex2f(100, 60);
    glVertex2f(110, 60);

    glVertex2f(105, 70);
    glVertex2f(125, 70);

    glVertex2f(120, 80);
    glVertex2f(130, 80);

    glVertex2f(110, 90);
    glVertex2f(130, 90);

    glVertex2f(140, 90);
    glVertex2f(160, 90);

    glVertex2f(170, 90);
    glVertex2f(190, 90);

    glVertex2f(90, 40);
    glVertex2f(100, 40);
    glEnd();
    glPopMatrix();
}

void rain()
{

    if(rainstatus==1){


    glColor3d(0,1,0);
    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
    x2=rand(),y2=rand();
    x2%=1000; y2%=1000;

        glBegin(GL_LINES);
        glColor3ub(220, 220 ,220);
        glVertex2d(x2,y2);
        glVertex2d(x2+5,y2+5);
        glEnd();
    }

    for(int i=1;i<=1000;i+=5){
  x2=rand(),y2=rand();
       x2%=1000; y2%=1000;

        glBegin(GL_LINES);
        glColor3ub(220, 220 ,220);
        glVertex2d(x2,y2);
        glVertex2d(x2+5,y2+5);
        glEnd();

    }
    }

}

void moon(){
    glColor3ub (255 ,255 ,255);
    glPushMatrix();
    glTranslatef(0.0, moonPosition,0.0);
    DrawCircle(100,505,25,2000);
    glPopMatrix();
        //glFlush();
}
void lightHouse(){
    if(lightstatus==0)
    {


        glColor3ub (255 ,228 ,181);
        glBegin(GL_POLYGON);
        glVertex2f(450+50, 220-50);
        glVertex2f(530+50, 220-50);
        glVertex2f(530+50, 225-50);
        glVertex2f(450+50, 225-50);
        glEnd();
        ////white one 1st
        //glColor3ub (255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(454+50, 225-50);
        glVertex2f(526+50, 225-50);
        glVertex2f(522+50, 250-50);
        glVertex2f(458+50, 250-50);
        glEnd();
        //////////red 2nd
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(458+50, 250-50);
        glVertex2f(522+50, 250-50);
        glVertex2f(517+50, 285-50);
        glVertex2f(463+50, 285-50);
        glEnd();
        //////////white 3rd
        //glColor3ub (255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(463+50, 285-50);
        glVertex2f(517+50, 285-50);
        glVertex2f(512+50, 320-50);
        glVertex2f(468+50, 320-50);
        glEnd();

        ///////////red 4th
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(468+50, 320-50);
        glVertex2f(512+50, 320-50);
        glVertex2f(509+50, 340-50);
        glVertex2f(471+50, 340-50);
        glEnd();
        //////////////white relling
        glColor3ub (255, 0,0);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(519+50, 340-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();


        ////////red 5th
        glColor3ub (255 ,228 ,181);
        glBegin(GL_POLYGON);
        glVertex2f(471+50, 345-50);
        glVertex2f(509+50, 345-50);
        glVertex2f(506+50, 370-50);
        glVertex2f(474+50, 370-50);
        glEnd();
        /////////red
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(465+50, 370-50);
        glVertex2f(515+50, 370-50);
        glVertex2f(515+50, 375-50);
        glVertex2f(465+50, 375-50);
        glEnd();
        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(463+50, 340-50);
        glVertex2f(463+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(463+50, 340-50);
        glVertex2f(463+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(471+50, 340-50);
        glVertex2f(473+50, 340-50);
        glVertex2f(473+50, 360-50);
        glVertex2f(471+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(481+50, 340-50);
        glVertex2f(483+50, 340-50);
        glVertex2f(483+50, 360-50);
        glVertex2f(481+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(491+50, 340-50);
        glVertex2f(493+50, 340-50);
        glVertex2f(493+50, 360-50);
        glVertex2f(491+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(500+50, 340-50);
        glVertex2f(502+50, 340-50);
        glVertex2f(502+50, 360-50);
        glVertex2f(500+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(509+50, 340-50);
        glVertex2f(511+50, 340-50);
        glVertex2f(511+50, 360-50);
        glVertex2f(509+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(517+50, 340-50);
        glVertex2f(519+50, 340-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(517+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 360-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(519+50, 362-50);
        glVertex2f(461+50, 362-50);
        glEnd();

        /////////chad
    glLineWidth(3.0);

        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(470.0f+50, 375.0f-50);
        glVertex2f(470.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(480.0f+50, 375.0f-50);
        glVertex2f(480.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(490.0f+50, 375.0f-50);
        glVertex2f(490.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(500.0f+50, 375.0f-50);
        glVertex2f(500.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(510.0f+50, 375.0f-50);
        glVertex2f(510.0f+50, 395.0f-50);    // x, y
        glEnd();
        /////////chowni
        glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(465+50, 395-50);
        glVertex2f(515+50, 395-50);
        glVertex2f(515+50, 400-50);
        glVertex2f(465+50, 400-50);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub (255, 0, 0); // Red

        glVertex2f(466.0f+50, 400.0f-50);    // x, y
        glVertex2f(514.0f+50, 400.0f-50);
        glVertex2f(490.0f+50,  420.0f-50);

        glEnd();


        ///////door
        glColor3ub (102, 51, 0);
        glBegin(GL_POLYGON);
        glVertex2f(482+50, 225-50);
        glVertex2f(498+50, 225-50);
        glVertex2f(498+50, 245-50);
        glVertex2f(482+50, 245-50);
        glEnd();
        ///////////light
         glColor3ub (28, 28, 28);
       glBegin(GL_POLYGON);
        glVertex2f(485+50, 375-50);
        glVertex2f(495+50, 375-50);
        glVertex2f(495+50, 380-50);
        glVertex2f(485+50, 380-50);
        glEnd();
glColor3ub (233, 211, 164);
        DrawCircle(490+50, 386-50, 6, 6000);
        glEnd();
    }

    else if(lightstatus==1)
    {
         glColor3ub (242, 248, 191);
       glBegin(GL_POLYGON);
        glVertex2f(465+50, 375-50);
        glVertex2f(515+50, 375-50);
        glVertex2f(515+50, 395-50);
        glVertex2f(465+50, 395-50);
        glEnd();



        //light spread

          glColor3ub (243, 248, 197);
       glBegin(GL_POLYGON);
        glVertex2f(0, 350-50);
        glVertex2f(465+50, 375-50);
        glVertex2f(465+50, 395-50);
        glVertex2f(0, 430-50);
        glEnd();


          glColor3ub (243, 248, 197);
       glBegin(GL_POLYGON);
        glVertex2f(515+50, 375-50);
        glVertex2f(640, 367-50);
        glVertex2f(640, 410-50);
        glVertex2f(515+50, 395-50);
        glEnd();


        glColor3ub (192, 192, 192);
        glBegin(GL_POLYGON);
        glVertex2f(450+50, 220-50);
        glVertex2f(530+50, 220-50);
        glVertex2f(530+50, 225-50);
        glVertex2f(450+50, 225-50);
        glEnd();

        glColor3ub (255 ,228 ,181);
        glBegin(GL_POLYGON);
        glVertex2f(450+50, 220-50);
        glVertex2f(530+50, 220-50);
        glVertex2f(530+50, 225-50);
        glVertex2f(450+50, 225-50);
        glEnd();
        ////white one 1st
        //glColor3ub (255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(454+50, 225-50);
        glVertex2f(526+50, 225-50);
        glVertex2f(522+50, 250-50);
        glVertex2f(458+50, 250-50);
        glEnd();
        //////////red 2nd
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(458+50, 250-50);
        glVertex2f(522+50, 250-50);
        glVertex2f(517+50, 285-50);
        glVertex2f(463+50, 285-50);
        glEnd();
        //////////white 3rd
        //glColor3ub (255, 255, 255);
        glBegin(GL_POLYGON);
        glVertex2f(463+50, 285-50);
        glVertex2f(517+50, 285-50);
        glVertex2f(512+50, 320-50);
        glVertex2f(468+50, 320-50);
        glEnd();

        ///////////red 4th
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(468+50, 320-50);
        glVertex2f(512+50, 320-50);
        glVertex2f(509+50, 340-50);
        glVertex2f(471+50, 340-50);
        glEnd();
        //////////////white relling
        glColor3ub (255, 0,0);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(519+50, 340-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();


        ////////red 5th
        glColor3ub (255 ,228 ,181);
        glBegin(GL_POLYGON);
        glVertex2f(471+50, 345-50);
        glVertex2f(509+50, 345-50);
        glVertex2f(506+50, 370-50);
        glVertex2f(474+50, 370-50);
        glEnd();
        /////////red
        //glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(465+50, 370-50);
        glVertex2f(515+50, 370-50);
        glVertex2f(515+50, 375-50);
        glVertex2f(465+50, 375-50);
        glEnd();
        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(463+50, 340-50);
        glVertex2f(463+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 340-50);
        glVertex2f(463+50, 340-50);
        glVertex2f(463+50, 360-50);
        glVertex2f(461+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(471+50, 340-50);
        glVertex2f(473+50, 340-50);
        glVertex2f(473+50, 360-50);
        glVertex2f(471+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(481+50, 340-50);
        glVertex2f(483+50, 340-50);
        glVertex2f(483+50, 360-50);
        glVertex2f(481+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(491+50, 340-50);
        glVertex2f(493+50, 340-50);
        glVertex2f(493+50, 360-50);
        glVertex2f(491+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(500+50, 340-50);
        glVertex2f(502+50, 340-50);
        glVertex2f(502+50, 360-50);
        glVertex2f(500+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(509+50, 340-50);
        glVertex2f(511+50, 340-50);
        glVertex2f(511+50, 360-50);
        glVertex2f(509+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(517+50, 340-50);
        glVertex2f(519+50, 340-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(517+50, 360-50);
        glEnd();

        glColor3ub (255, 255,255);
        glBegin(GL_POLYGON);
        glVertex2f(461+50, 360-50);
        glVertex2f(519+50, 360-50);
        glVertex2f(519+50, 362-50);
        glVertex2f(461+50, 362-50);
        glEnd();

        /////////chad
    glLineWidth(3.0);

        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(470.0f+50, 375.0f-50);
        glVertex2f(470.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(480.0f+50, 375.0f-50);
        glVertex2f(480.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(490.0f+50, 375.0f-50);
        glVertex2f(490.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(500.0f+50, 375.0f-50);
        glVertex2f(500.0f+50, 395.0f-50);    // x, y

        glEnd();
        glBegin(GL_LINES);
        glColor3ub (51, 51, 51);
        glVertex2f(510.0f+50, 375.0f-50);
        glVertex2f(510.0f+50, 395.0f-50);    // x, y
        glEnd();
        /////////chowni
        glColor3ub (255, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(465+50, 395-50);
        glVertex2f(515+50, 395-50);
        glVertex2f(515+50, 400-50);
        glVertex2f(465+50, 400-50);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3ub (255, 0, 0); // Red

        glVertex2f(466.0f+50, 400.0f-50);    // x, y
        glVertex2f(514.0f+50, 400.0f-50);
        glVertex2f(490.0f+50,  420.0f-50);

        glEnd();

        ///////door
        glColor3ub (102, 51, 0);
        glBegin(GL_POLYGON);
        glVertex2f(482+50, 225-50);
        glVertex2f(498+50, 225-50);
        glVertex2f(498+50, 245-50);
        glVertex2f(482+50, 245-50);
        glEnd();
        ///////////light
         glColor3ub (28, 28, 28);
       glBegin(GL_POLYGON);
        glVertex2f(485+50, 375-50);
        glVertex2f(495+50, 375-50);
        glVertex2f(495+50, 380-50);
        glVertex2f(485+50, 380-50);
        glEnd();
glColor3ub (233, 211, 164);
        DrawCircle(490+50, 386-50, 6, 6000);
        glEnd();
    }
}
void land(){
    glColor3ub (3, 90, 30);
    glBegin(GL_POLYGON);
    glVertex2f(640, 150);
    glVertex2f(500, 150);
    glVertex2f(450, 225);
    glVertex2f(640, 225);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(640, 225);
    glVertex2f(450, 225);
    glVertex2f(450, 235);
    glVertex2f(640, 235);
    glEnd();
        //glFlush();
}
void cloud(){
    glColor3ub(245,245,245);
    glPushMatrix();
    glTranslatef(cloudPosition, 0.0,0.0);
    DrawCircle(100,460,15,2000);
    DrawCircle(115,460,10,2000);
    DrawCircle(85,460,10,2000);

    DrawCircle(200,360,15,2000);
    DrawCircle(215,360,10,2000);
    DrawCircle(185,360,10,2000);

    DrawCircle(300,400,15,2000);
    DrawCircle(315,400,10,2000);
    DrawCircle(285,400,10,2000);

    DrawCircle(400,360,15,2000);
    DrawCircle(415,360,10,2000);
    DrawCircle(385,360,10,2000);

    DrawCircle(500,460,15,2000);
    DrawCircle(515,460,10,2000);
    DrawCircle(485,460,10,2000);

    DrawCircle(-100,460,15,2000);
    DrawCircle(-115,460,10,2000);
    DrawCircle(-85,460,10,2000);

    DrawCircle(-100,360,15,2000);
    DrawCircle(-115,360,10,2000);
    DrawCircle(-85,360,10,2000);
    glPopMatrix();
        //glFlush();

}
void ground(){
    glColor3ub (189 ,183 ,107);
    glBegin(GL_QUADS);
    glVertex2f(0, 255);
    glVertex2f(0, 260);
    glVertex2f(640, 260);
    glVertex2f(640, 255);
    glEnd();
        //glFlush();
}
void hills(){
    glColor3ub(107, 142, 35);
    glBegin(GL_TRIANGLES);////// from left
    glVertex2f(80, 255);
    glVertex2f(120, 290);
    glVertex2f(160, 255);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(140, 255);
    glVertex2f(170, 280);
    glVertex2f(200, 255);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(120, 255);
    glVertex2f(200, 310);
    glVertex2f(270, 255);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(180, 255);
    glVertex2f(270, 320);
    glVertex2f(360, 255);
    glEnd();

   /* ///line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(180, 255);
    glVertex2f(270, 320);

    glVertex2f(270, 320);
    glVertex2f(360, 255);
    glEnd(); */

    //glColor3ub(107, 142, 35);
    glBegin(GL_TRIANGLES);
    glVertex2f(260, 255);
    glVertex2f(320, 300);
    glVertex2f(380, 255);
    glEnd();
    //////line shape
    /*glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(260, 255);
    glVertex2f(320, 300);

    glVertex2f(320, 300);
    glVertex2f(380, 255);
    glEnd();*/

    //glColor3ub(107, 142, 35);
    glBegin(GL_TRIANGLES);
    glVertex2f(370, 255);
    glVertex2f(420, 275);
    glVertex2f(470, 255);

    glEnd();
        //glFlush();
}
void sun(){
    glColor3ub(250 ,250, 210);
    glPushMatrix();
    glTranslatef(0.0, SetPosition,0.0);
    DrawCircle(500.0,480.0,20,2000);
    glPopMatrix();
        //glFlush();

    glPushMatrix();
    glTranslatef(0.0, RisePosition,0.0);
    DrawCircle(100,0.0,20,2000);
    glPopMatrix();

        //glFlush();


}

void river(){
    //sndPlaySound("E:\\CG\\finalProjectDone\\Stoomboot.wav",SND_ASYNC);
    glColor3ub (32, 178, 170);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(640, 0);
    glVertex2f(640, 255);
      glVertex2f(0, 255);

    glEnd();

        //glFlush();
}
void srot(){

    glColor3ub (248, 248, 255);
    glPushMatrix();
    glTranslatef(srotPosition, 0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 250);
    glVertex2f(50, 250);

    glVertex2f(0, 100);
    glVertex2f(50, 100);

    glVertex2f(100, 200);
    glVertex2f(150, 200);

    glVertex2f(200, 200);
    glVertex2f(250, 200);

    glVertex2f(0, 250);
    glVertex2f(50, 250);

    glVertex2f(300, 120);
    glVertex2f(350, 120);

    glVertex2f(400, 250);
    glVertex2f(470, 250);

    glVertex2f(570, 60);
    glVertex2f(600, 60);





    glEnd();
    glPopMatrix();
        //glFlush();
}

////////////////ship///////////////

void ship()
{
    glPushMatrix();
    glTranslatef(shipPositon,shipDown,0.0);
    glColor3f(0.0f, 0.5f, 0.5f);//Blue-Green
    glBegin(GL_QUADS);
    glVertex2f(340, 50);
    glVertex2f(260, 150);
    glVertex2f(620, 150);
    glVertex2f(540, 50);
    glEnd();
    //under the ship purple
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(340, 50);
    glVertex2f(540, 50);
    glVertex2f(540, 45);
    glVertex2f(340, 45);
    glEnd();
     //ship up the body
   glColor3f(1.0f, 0.0f, 1.0f);//Purple
    glBegin(GL_QUADS);
    glVertex2f(290, 150);
    glVertex2f(590, 150);
    glVertex2f(590, 190);
    glVertex2f(290, 190);
    glEnd();
    glColor3ub (175, 3, 60);//lalic
    glBegin(GL_QUADS);
    glVertex2f(290, 190);
    glVertex2f(590, 190);
    glVertex2f(560, 215);
    glVertex2f(320, 215);
    glEnd();
    //window1
    glColor3f(0.5f, 1.0f, 1.0f);//cyan
    glBegin(GL_QUADS);
    glVertex2f(330, 160);
    glVertex2f(360, 160);
    glVertex2f(360, 180);
    glVertex2f(330, 180);
    glEnd();
    //window2
    glColor3f(0.1f, 0.1f, 0.1f);//Dark grey
    glBegin(GL_QUADS);
    glVertex2f(390, 160);
    glVertex2f(420, 160);
    glVertex2f(420, 180);
    glVertex2f(390, 180);
    glEnd();
    //window3
    glColor3f(0.1f, 0.1f, 0.0f);//Bronze
    glBegin(GL_QUADS);
    glVertex2f(450, 160);
    glVertex2f(480, 160);
    glVertex2f(480, 180);
    glVertex2f(450, 180);
    glEnd();
    //window4
    glColor3ub (2, 80, 135);
    glBegin(GL_QUADS);
    glVertex2f(510, 160);
    glVertex2f(540, 160);
    glVertex2f(540, 180);
    glVertex2f(510, 180);
    glEnd();
    //smoke top of the ship1
   glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glBegin(GL_QUADS);
    glVertex2f(350, 215);
    glVertex2f(375, 215);
    glVertex2f(375, 245);
    glVertex2f(350, 245);
    glEnd();

    glColor3ub (0, 0, 3);
    glBegin(GL_QUADS);
    glVertex2f(350, 245);
    glVertex2f(375, 245);
    glVertex2f(375, 250);
    glVertex2f(350, 250);
    glEnd();
    //smoke top of the ship2
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glBegin(GL_QUADS);
    glVertex2f(390, 215);
    glVertex2f(415, 215);
    glVertex2f(415, 245);
    glVertex2f(390, 245);
    glEnd();

    glColor3ub (0, 0, 3);
    glBegin(GL_QUADS);
    glVertex2f(390, 245);
    glVertex2f(415, 245);
    glVertex2f(415, 250);
    glVertex2f(390, 250);
    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);//Blue

    glBegin(GL_QUADS);
    glVertex2f(430, 215);
    glVertex2f(455, 215);
    glVertex2f(455, 245);
    glVertex2f(430, 245);
    glEnd();

    glColor3ub (0, 0, 3);
    glBegin(GL_QUADS);
    glVertex2f(430, 245);
    glVertex2f(455, 245);
    glVertex2f(455, 250);
    glVertex2f(430, 250);
    glEnd();
     //smoke top of the ship4
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glBegin(GL_QUADS);
    glVertex2f(470, 215);
    glVertex2f(495, 215);
    glVertex2f(495, 245);
    glVertex2f(470, 245);
    glEnd();

    glColor3ub (0, 0, 3);
    glBegin(GL_QUADS);
    glVertex2f(470, 245);
    glVertex2f(495, 245);
    glVertex2f(495, 250);
    glVertex2f(470, 250);
    glEnd();
    //smoke top of the ship5
    glColor3f(0.0f, 0.0f, 1.0f);//Blue
    glBegin(GL_QUADS);
    glVertex2f(510, 215);
    glVertex2f(535, 215);
    glVertex2f(535, 245);
    glVertex2f(510, 245);
    glEnd();

    glColor3ub (0, 0, 3);
    glBegin(GL_QUADS);
    glVertex2f(510, 245);
    glVertex2f(535, 245);
    glVertex2f(535, 250);
    glVertex2f(510, 250);
    glEnd();
    glPopMatrix();


}
//////////////Ship end////////////////////

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
   //glLoadIdentity();
sky();
stars();
sun();
moon();
river();
shark();
srot();
cloud();
hills();
ground();
boat();
land();
lightHouse();

//helicopter();
//dayboat();
//boat2();
ship();
//bird();
snow();
rain();
    glFlush();

//mountain();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void keyboard(unsigned char key, int x, int y){
    if (key == 'L' || key == 'l'){
            lightstatus=1;
    }
    if(key == 'x' || key == 'X'){
        lightstatus=0;
    }
    if(key=='w' || key=='W') {
        winter=1;
    }
    if(key=='s' || key=='S'){
        winter=0;
    }
    if(key=='r' || key=='R'){
        rainstatus=1;
    }
    if(key=='c' || key=='C'){
        rainstatus=0;
    }
    if(key=='a' || key=='A'){
        shipMove=2;
    }
    if(key=='k' || key=='K'){
        shipMove=1;
    }
    if(key=='d' || key=='D'){

        sharkStatus=1;
        if(sharkPosition>850)
        sharkPosition=-200;
    }

}



int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE| GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Sea port");


glutDisplayFunc(myDisplay);
//PlaySound(TEXT("rain-01.wav"),NULL,SND_SYNC);

glutKeyboardFunc(keyboard);

myInit ();
//sndPlaySound("E:\\CG\\finalProjectDone\\rain-01.wav",SND_ASYNC);


glutTimerFunc(1000, update, 0);
//sndPlaySound("E:\\CG\\finalProjectDone\\Stoomboot.wav",SND_ASYNC);
if(rainstatus==1){
   // sndPlaySound("E:\\CG\\finalProjectDone\\rain-01.wav",SND_ASYNC);

}
//sndPlaySound("E:\\CG\\finalProjectDone\\rain-1",SND_ASYNC);
glutMainLoop();


  // glutMouseFunc(handleMouse);

}
