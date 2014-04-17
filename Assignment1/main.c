/*
 * Copyright (c) 2009 University of Michigan, Ann Arbor.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of Michigan, Ann Arbor. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Authors: Manoj Rajagopalan, Sugih Jamin
 */
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "shapes.h"
#include <math.h>
#define GL_PI 180
#define NENDS 2           /* number of end "points" to draw */

GLdouble width, height;   /* window width and height */

//angle of rotation
float xpos = -100, ypos = -10, zpos = 0, xrot = 0, yrot = 90, angle=0.0;
float angleIncrement=0;//angle increment controls the speed of the fans
float MAX_ANGLE_INCREMENT=25;
//initial
float radius = 100;

float theta =0;

int lit;//indicates light on/off.lit = 0 for off.
int fanStop;//controls fan stopping


/* Program initialization NOT OpenGL/GLUT dependent,
 as we haven't created a GLUT window yet */
void init(void)
{
    width  = DEFAULT_WIDTH;                 /* initial window width and height, */
    height = DEFAULT_HEIGHT;
    lit =0;
    fanStop =0;
    
}
//RETURNS A NEW 3D Point
Point3D newPoint3d(float x,float y,float z)
{
    Point3D point;
    point.x=x;
    point.y=y;
    point.z=z;
    return point;
}
void drawLines(void)
{
    glBegin(GL_LINES);
    
    float x,y,z;
    // All lines lie in the xy plane.
    z = 0.0f;
    float radius = 5.0f;
    for(angle = 0.0f; angle <= GL_PI; angle += (GL_PI/20.0f))
    {
        // Top half of the circle
        x = radius*sin(angle);
        y = radius*cos(angle);
        glVertex3f(z, y, x);    // First endpoint of line
        
    }
    
    // Done drawing points
    glEnd();
}



void showCameraValues()
{
    printf("xpos:%f ypos:%f zpos:%f theta:%f\n\n",xpos,ypos,zpos,theta);
}


/* Callback functions for GLUT */

/* Draw the window - this is where all the GL actions are */
void display(void)
{
    /* set the screen clearing color */
    glClearColor(1.0, 1.0, 1.0, 1.0);//white
    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //camera settings
    gluLookAt (xpos,ypos,zpos, radius*cos(theta*DEG2RAD), 5, radius*sin(theta*DEG2RAD), 0.0,1,0);
 
    //quadric objects
    //this object will be needed to create cylinders
    GLUquadric *quadObject=gluNewQuadric();
    gluQuadricDrawStyle(quadObject, GLU_FILL);
    
    float distanceBetwnFirstTableSetsOnColumn = 22;
    float floorLevel = -20;
    //the table with computer
    glPushMatrix();
    glTranslated(0, -5, 0);
    {
        glPushMatrix();
        glTranslated(24,-7.8, -18);
        glScaled(0.8, 0.8, 0.8);
        drawComputer(quadObject, -25, -5, 0);
        glPopMatrix();
        //table
        
        glPushMatrix();
        glTranslated(6, floorLevel,-20);
        glRotated(180, 0, 1, 0);
        drawTable(quadObject, 0, 0, 0,0.8);
        glPopMatrix();
    }
    glPopMatrix();
    //RIGHT COLUMN OF CHAIRS & TABLES
    glPushMatrix();
    //THE MORE THE TRANSLATION THE MORE THE DISTANCE BETWN 2 CHAIR-TABLE SET ON FIRST ROW.
    glTranslated(0,floorLevel, distanceBetwnFirstTableSetsOnColumn);
    glRotated(5, 0, 1, 0);
    float Y=6;
    float Z=0;
    float chairWidth=10;
    for(int i=1;i<=6;i++)
    {
        float X=-(i*10+(i-1)*5);
        drawTable(quadObject, X, -Y, Z, 2);
        drawChair(quadObject, X-3,-Y,Z);
        drawChair(quadObject, X-3,-Y,Z-chairWidth);
        drawChair(quadObject, X-3,-Y,Z+chairWidth);
    }
    glPopMatrix();
    
    //LEFT COLUMN
    glPushMatrix();
    glTranslated(0,floorLevel, -distanceBetwnFirstTableSetsOnColumn);
    glRotated(-5, 0, 1, 0);
    for(int i=1;i<=6;i++)
    {
        float X=-(i*10+(i-1)*5);
        drawTable(quadObject, X, -Y, Z, 2);
        drawChair(quadObject, X-3,-Y,Z);
        drawChair(quadObject, X-3,-Y,Z-chairWidth);
        drawChair(quadObject, X-3,-Y,Z+chairWidth);
    }
    glPopMatrix();
    
    
    Color floorColor;
    Color wallColor;
    
    floorColor.r = 250;
    floorColor.g = 233;
    floorColor.b = 207;
    
    wallColor.r = 212;
    wallColor.g = 212;
    wallColor.b = 212;
    
    float frontScaleY=50;
    float frontScaleZ=150;
        
    //LIGHTS
    for(int i= 0; i<7;i++)
    {
        drawLightBar(quadObject, 200, 55, -90+i*30, 20,lit);
    }
    
    //ROOM
    drawRoom(20, 0, 0,300,frontScaleY,frontScaleZ, floorColor, wallColor);
    
    //FANS
    glColor3ub(70, 70, 70);
    for(int i=1;i<=2;i++)
    {
        float X= -10+(i-1)*100;
        //left
        drawFan(quadObject, X,35, -50,2, angle);
        glPushMatrix();
        glTranslated(X,45,-50);
        glRotated(90, 1, 0,0);
        gluCylinder(quadObject, 0.3,0.3,10, 40, 100);
        glPopMatrix();
        
        //right
        drawFan(quadObject, X,35,50,2, angle);
        glPushMatrix();
        glTranslated(X,45,50);
        glRotated(90, 1, 0,0);
        gluCylinder(quadObject, 0.3,0.3,10, 40, 100);
        glPopMatrix();
    }
    
    
    glutSwapBuffers(); //swap the buffers
    
    
    gluDeleteQuadric(quadObject);//RELEASE FOR MEMORY
    
//    angle++; //increase the angle
//    glFlush();
}

void keyboard (unsigned char key, int x, int y) {
    
    if(key == 'l' || key == 'L')
    {
        if(lit == 0)lit=1;
        else lit =0;
    }
    
    if(key == 'f' || key == 'F')
    {
        if(fanStop == 0)
        {
            fanStop=1;
        }
        else
        {
            fanStop =0;
        }
        
    }
    if(key == 'w')
    {
        ypos+=2;
    }
    if(key == 's')
    {
        ypos-=2;
    }
    if (key=='d')
    {
        theta+=4;
    }
    
    if (key=='a')
    {
        theta-=4;
    }
    if (key=='e')
    {
        exit(0); //quit the program
    }
    
    if(xpos < -130)xpos= -130;
    if(xpos > -45) xpos = -45;
    if(ypos >5)ypos = 5;
    if(ypos<-19)ypos=-19;
    
    showCameraValues();
    
}

void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			xpos-=2;
			break;
		case GLUT_KEY_UP:		// up arrow key
			xpos+=2;
			break;
            
		case GLUT_KEY_RIGHT:
            zpos+=2;
			break;
		case GLUT_KEY_LEFT:
            zpos-=2;
			break; 
		default:
			break;
	}
    if(xpos < -130)xpos= -130;
    if(xpos > -45) xpos = -45;
    
    if(zpos > 65)zpos = 65;
    if(zpos < -65)zpos = -65;
    
    showCameraValues();
}


/* Called when window is resized,
 also when window is first created,
 before the first call to display(). */
void reshape(int w, int h)
{
    /* save new screen dimensions */
    width = (GLdouble) w;
    height = (GLdouble) h;
    initModes(width,height);
    
}



void animate(){
	//codes for any changes in Camera
    
    if(fanStop == 1)
    {
        angleIncrement+=0.1;
        if(angleIncrement > MAX_ANGLE_INCREMENT) angleIncrement =MAX_ANGLE_INCREMENT;
    }
    if(fanStop == 0)
    {
        angleIncrement -=0.1;
        if(angleIncrement < 0) angleIncrement =0;
    }
	angle += angleIncrement;
	//codes for any changes in Models
    
	//MISSING SOMETHING?
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    init();
    /* initialize GLUT, let it extract command-line
     GLUT options that you may provide
     - NOTE THE '&' BEFORE argc */
    glutInit(&argc, argv);
    
    initWindow("OpenGL Experiments",width,height,0);//passing 1 will make it fullscreen

    //initial viewport setting
    initModes(width, height);
    
    
    //optional
    glEnable( GL_DEPTH_TEST );
   
    /* --- register callbacks with GLUT --- */
    
    /* register function to handle window resizes */
    glutReshapeFunc(reshape);
    
    /* register function that draws in the window */
    glutDisplayFunc(display);
    //do the calculation
    glutIdleFunc(animate);
    //keyboard functioin
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyListener);
    
    /* start the GLUT main loop */
    glutMainLoop();
    
    return 0;
}