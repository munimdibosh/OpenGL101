//
//  shapes.h
//  Assignment1
//
//  Created by Md. Abdul Munim Dibosh on 12/8/13.
//  Copyright (c) 2013 Md. Abdul Munim Dibosh. All rights reserved.
//

#ifndef Assignment1_shapes_h
#define Assignment1_shapes_h
void drawFrontScreen(float posX,float posY,float posZ,float scaleY,float scaleZ);
void drawChair(GLUquadric*quadObject,float posX,float posY,float posZ);
void drawTable(GLUquadric*quadObject,float posX,float posY,float posZ,float scaleFactor);
void drawRoom(float posX,float posY,float posZ,float xScale,float yScale,float zScale,Color floorColor,Color wallColor);
void drawCircle(float radius);
void drawLightBar(GLUquadric *quadObject, float posX,float posY,float posZ,float scaleFactor,int lit);
void drawFan(GLUquadric *quadObject, float posX,float posY,float posZ,float scaleFactor,float angle);
void drawComputer(GLUquadric *quadObject,float posX,float posY,float posZ);

void drawRect(Point3D origin,float w,float h);
//Will take an array of 3d points to draw the polygon in CCW fashion
void drawPoly(Point3D* array,int no_of_vertices);

#endif
