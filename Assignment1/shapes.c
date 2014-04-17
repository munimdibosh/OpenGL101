//
//  shapes.c
//  Assignment1
//
//  Created by Md. Abdul Munim Dibosh on 12/8/13.
//  Copyright (c) 2013 Md. Abdul Munim Dibosh. All rights reserved.
//

#include <stdio.h>
#include "definitions.h"
#include "shapes.h"
#include <math.h>

//the shapes are being drawn on Z-Y Plane
//Z-Y Plane is the 2d one we are looking at.
//X is the depth of the shapes(which would be Z in normal sense),the - value
//indicates the direction coming out of this screen
//the + value indicates the direction going into the screen.
void drawComputer(GLUquadric *quadObject,float posX,float posY,float posZ)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    {
        //CPU
        glColor3ub(105, 105, 105);
        glPushMatrix();
        glTranslated(0,0,-4);
        glScaled(2,1.5,0.8);
        glutSolidCube(2);
        glPopMatrix();
        //monitor
        glColor3ub(105, 105, 105);
        glPushMatrix();
        glTranslated(0, 1, 0);
        glScaled(0.2,1.5,2);
        glutSolidCube(2);
        glPopMatrix();
        //stand
        glColor3ub(89, 89, 89);
        glPushMatrix();
        glRotated(90, 1, 0, 0);
        gluCylinder(quadObject,0.3,0.3,2, 20, 20);
        glPopMatrix();
        //lowerbase
        glColor3ub(89, 89, 89);
        glPushMatrix();
        glTranslated(0, -2, 0);
        glScaled(0.8, 0.2, 1);
        glutSolidCube(2);
        glPopMatrix();
    }
    glPopMatrix();
}
//angle CONTROLS THE ROTATION OF THE FAN
void drawFan(GLUquadric *quadObject, float posX,float posY,float posZ,float scaleFactor,float angle)
{
    float FAN_HEAD_WIDTH =2;
    float SLICES =20;
    float STACKS=6;
    
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    glRotated(angle, 0, 1, 0);
    glScaled(scaleFactor, scaleFactor, scaleFactor);
    {
        //WINGS
        glColor3ub(127, 127, 127);
        
        glPushMatrix();
        glScaled(10,0.2,1);
        glutSolidCube(2);
        glPopMatrix();
        
        glPushMatrix();
        glRotated(90, 0, 1, 0);
        glScaled(10, 0.2,1);
        glutSolidCube(2);
        glPopMatrix();
        //HEAD
        glColor3ub(90, 90, 90);
        glPushMatrix();
        glTranslated(0, -0.8, 0);
        glRotated(-90, 1, 0, 0);
        gluDisk(quadObject, 0, 2, SLICES, STACKS);
        glColor3ub(110, 110, 110);
        
        gluCylinder(quadObject, FAN_HEAD_WIDTH, FAN_HEAD_WIDTH, 1, SLICES, STACKS);
        glPopMatrix();
    }
    glPopMatrix();
}
//INDICATES WHERE THE LIGHT IS LIT,0 is OFF
void drawLightBar(GLUquadric *quadObject, float posX,float posY,float posZ,float scaleFactor,int lit)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    glScaled(3*scaleFactor, 0.4*scaleFactor, 0.6*scaleFactor);
    {
        //LIGHT
        
        glColor3ub(255, 255, 255);
        
        if(lit == 0)
        {
            //OFF
            glColor3ub(150, 150, 150);
        }
        
        glPushMatrix();
        glTranslated(0, -1, 0);
        glScaled(0.6, 0.2,0.1);
        glutSolidCube(2);
        glPopMatrix();
        
        glColor3ub(204, 175, 130);
        glutSolidCube(2);
    }
    glPopMatrix();
}

void drawFrontScreen(float posX,float posY,float posZ,float scaleY,float scaleZ)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    {
        //SCREEN
        
        glColor3ub(70,70,70);
        glPushMatrix();
        glTranslated(0, .5, 0);
        glScaled(0.7,scaleY/1.5, scaleZ/2);
        glutSolidCube(2);
        glPopMatrix();
        //shadow
        glColor3ub(80,80,80);
        glPushMatrix();
        glTranslated(0, .3, 0.2);
        glScaled(0.7,scaleY/1.5, scaleZ/2);
        glutSolidCube(2);
        glPopMatrix();
        //WOODEN FRAME
        glColor3ub(141, 88, 6);
        glPushMatrix();
        glScaled(0.6, scaleY, scaleZ/1.5);
        glutSolidCube(2);
        glPopMatrix();
        //BACK
        glColor3ub(230, 230, 230);
        glPushMatrix();
        glScaled(0.5, scaleY, scaleZ);
        glutSolidCube(2);
        glPopMatrix();
    }
    glPopMatrix();
}
void drawRoom(float posX,float posY,float posZ,float xScale,float yScale,float zScale,Color floorColor,Color wallColor)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    glScaled(xScale, yScale, zScale);
    {
        //FLOOR
        glColor3ub(floorColor.r, floorColor.g, floorColor.b);
        glPushMatrix();
        glTranslated(0,-1,0);
        glScaled(1, 0.01, 1);
        glutSolidCube(2);
        glPopMatrix();
        //TOP
        
        glPushMatrix();
        glTranslated(0,1,0);
        glScaled(1, 0.01, 1);
        glutSolidCube(2);
        glPopMatrix();
        
        //WALLS
        glColor3ub(wallColor.r, wallColor.g, wallColor.b);
        //RIGHT
        glPushMatrix();
        glTranslated(0, 0,1);
        glScaled(1, 1, 0.01);
        glutSolidCube(2);
        glPopMatrix();
        //LEFT
        glPushMatrix();
        glTranslated(0, 0,-1);
        glScaled(1, 1, 0.01);
        glutSolidCube(2);
        glPopMatrix();
        //BEHIND
        glPushMatrix();
        glTranslated(-1, 0,0);
        glScaled(0.01, 1, 1);
        glutSolidCube(2);
        glPopMatrix();
        //FRONT
        
        //SCREEN
        
        glColor3ub(70,70,70);
        glPushMatrix();
        glTranslated(0.97, 0.04, 0);
        glScaled(0.01,0.6,0.7);
        glutSolidCube(2);
        glPopMatrix();
        //shadow
        glColor3ub(90,90,90);
        glPushMatrix();
        glTranslated(0.975, 0.02, 0.01);
        glScaled(0.01,0.6,0.7);
        glutSolidCube(2);
        glPopMatrix();
        //WOODEN FRAME
        glColor3ub(141, 88, 6);
        glPushMatrix();
        glTranslated(0.98, 0, 0);
        glScaled(0.01,1,0.8);
        glutSolidCube(2);
        glPopMatrix();
        //BACK
        glColor3ub(230, 230, 230);
        glPushMatrix();
        glTranslated(1, 0, 0);
        glScaled(0.01,1, 1);
        glutSolidCube(2);
        glPopMatrix();
    }

    glPopMatrix();
    
}
//SCALE FACTOR DEFINES HOW LONG THE TABLE IS GOING TO BE
void drawTable(GLUquadric*quadObject,float posX,float posY,float posZ,float scaleFactor)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    glScaled(1, 1, scaleFactor);
    {
        float TABLE_WIDTH = 15;
        float TABLE_HEIGHT = 5;

        //BACK
        glColor3ub(106, 106, 106);
        glPushMatrix();
        {
            glTranslated(2, TABLE_HEIGHT, 0);
            glRotated(90, 0, 0, 1);
            glScaled(1.5, 0.2, TABLE_WIDTH/2);
            glutSolidCube(2);
        }
        glPopMatrix();
        //TOP
        glColor3ub(54, 55, 55);
        glPushMatrix();
        {
            glTranslated(-1.5, TABLE_HEIGHT+1.5, 0);
            glScaled(4, 0.2, TABLE_WIDTH/2);
            glutSolidCube(2);
        }
        glPopMatrix();
        //LEFT
        glPushMatrix();
        {
            glTranslated(0, 0, -TABLE_WIDTH/2);
            {
                //LEFT LOWER
                glColor3ub(106, 106, 106);
                glPushMatrix();
                {
                    glRotated(90, 1, 0, 0);
                    glScaled(2.5, 0.2, 1.5);
                    glutSolidCube(2);
                }
                glPopMatrix();
                //LEFT UPPER
                glColor3ub(80, 80, 80);
                glPushMatrix();
                {
                    glTranslated(-1.5,3.5, 0);
                    glRotated(90, 1, 0, 0);
                    glScaled(4, 0.3, 3);
                    glutSolidCube(2);
                }
                glPopMatrix();
            }
        }
        glPopMatrix();
        //RIGHT
        glPushMatrix();
        {
            glTranslated(0, 0, TABLE_WIDTH/2);
            
            {
                //RIGHT LOWER
                glColor3ub(106, 106, 106);
                glPushMatrix();
                {
                    glRotated(90, 1, 0, 0);
                    glScaled(2.5, 0.2, 1.5);
                    glutSolidCube(2);
                }
                glPopMatrix();
                //RIGHT UPPER
                glColor3ub(80, 80, 80);
                glPushMatrix();
                {
                    glTranslated(-1.5,3.5, 0);
                    glRotated(90, 1, 0, 0);
                    glScaled(4, 0.3, 3);
                    glutSolidCube(2);
                }
                glPopMatrix();
            }
        }
        glPopMatrix();
    }
    glPopMatrix();

}
void drawChair(GLUquadric*quadObject,float posX,float posY,float posZ)
{
    glPushMatrix();
    glTranslated(posX, posY, posZ);
    {
        float BASE=3;
        float TOP=3;
        float HEIGHT = 0.3;
        float SLICES =20;
        float STACKS=6;
        float STAND_HEIGHT=3;
        float LOWER_BASE_TRANSLATE_FACTOR=1.5;
        float SEAT_WIDTH = 3;
        //HAND REST
        glColor3ub(221, 105, 11);
        //LEFT
        glPushMatrix();
        {
            glTranslated(-0.5,STAND_HEIGHT+SEAT_WIDTH/2-0.5,-2*SEAT_WIDTH-0.1);
            //TOP BAR
            glPushMatrix();
            {
                glTranslated(1.4,1.2, 3);
                glScaled(2, 0.1,0.6);
                glutSolidCube(2);
            }
            glPopMatrix();
            //SECOND BAR
            glPushMatrix();
            {
                glTranslated(2,0, 3);
                glRotated(10, 0, 0, 1);
                glScaled(0.1, 1.2,0.2);
                glutSolidCube(2);
            }
            glPopMatrix();
            //FIRST BAR
            glPushMatrix();
            {
                glTranslated(0,0, 3);
                glRotated(10, 0, 0, 1);
                glScaled(0.1, 1.2,0.2);
                glutSolidCube(2);
            }
            glPopMatrix();
            
            
        }
        glPopMatrix();
        //RIGHT
        glPushMatrix();
        {
            glTranslated(-0.5,STAND_HEIGHT+SEAT_WIDTH/2-0.5,0.1);
            //TOP BAR
            glPushMatrix();
            {
                glTranslated(1.4,1.2, 3);
                glScaled(2, 0.1,0.6);
                glutSolidCube(2);
            }
            glPopMatrix();
            //SECOND BAR
            glPushMatrix();
            {
                glTranslated(2,0, 3);
                glRotated(10, 0, 0, 1);
                glScaled(0.1, 1.2,0.2);
                glutSolidCube(2);
            }
            glPopMatrix();
            //FIRST BAR
            glPushMatrix();
            {
                glTranslated(0,0, 3);
                glRotated(10, 0, 0, 1);
                glScaled(0.1, 1.2,0.2);
                glutSolidCube(2);
            }
            glPopMatrix();
            
            
        }
        glPopMatrix();
        //BACK STAND
        glColor3ub(100, 100, 100);
        glPushMatrix();
        {
            glTranslated(-SEAT_WIDTH-0.25,SEAT_WIDTH+STAND_HEIGHT-0.5, 0);
            glRotated(100, 0, 0, 1);
            glScaled(2.5, 0.2,0.5);
            glutSolidCube(2);
        }
        glPopMatrix();
        //BACK
        glColor3ub(165, 165, 165);
        glPushMatrix();
        {
            glTranslated(-SEAT_WIDTH-0.5,SEAT_WIDTH+STAND_HEIGHT+1.5, 0);
            glRotated(100, 0, 0, 1);
            glScaled(1, 0.3,2);
            glutSolidCube(2);
        }
        glPopMatrix();
        //SEAT
        glColor3ub(165, 165, 165);
        glPushMatrix();
        {
            glTranslated(0,STAND_HEIGHT, 0);
            glScaled(SEAT_WIDTH, 0.2, SEAT_WIDTH);
            glutSolidCube(2);
        }
        glPopMatrix();
        //STAND
        glColor3ub(70, 70, 70);
        glPushMatrix();
        {
            glTranslated(0, -LOWER_BASE_TRANSLATE_FACTOR, 0);
            glRotated(-90, 1, 0, 0);
            gluCylinder(quadObject, 0.5,0.5,STAND_HEIGHT+LOWER_BASE_TRANSLATE_FACTOR, 30, 40);
        }
        glPopMatrix();
        //LOWER BASE
        glColor3ub(83, 83, 83);
        glPushMatrix();
        {
            glTranslated(0, -LOWER_BASE_TRANSLATE_FACTOR, 0);
            glRotated(90, 1, 0, 0);
            gluDisk(quadObject, 0, BASE, SLICES, STACKS);
            gluCylinder(quadObject,BASE,TOP,HEIGHT, SLICES, STACKS);
        }
        glPopMatrix();
    }
    glPopMatrix();
    
}
void drawCircle(float radius)
{
    glBegin(GL_LINE_LOOP);
    
    for (int i=0; i < 360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex3f(0,sin(degInRad)*radius,cos(degInRad)*radius);
    }
    
    glEnd();
}
void drawRect(Point3D origin,float w,float h)
{
    glBegin(GL_QUADS);
        glVertex3f(origin.z, origin.y,origin.x);
        glVertex3f(origin.z, origin.y+h,origin.x);
        glVertex3f(origin.z, origin.y+h,origin.x+w);
        glVertex3f(origin.z, origin.y,origin.x+w);
    glEnd();
}

void drawPoly(Point3D* array,int no_of_vertices)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<no_of_vertices;i++)
    {
        Point3D p = array[i];
        glVertex3f(p.x, p.y, p.z);
    }
    glEnd();
}
