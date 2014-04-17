//
//  definitions.h
//  Assignment1
//
//  Created by Md. Abdul Munim Dibosh on 12/8/13.
//  Copyright (c) 2013 Md. Abdul Munim Dibosh. All rights reserved.
//

#ifndef Assignment1_definitions_h
#define Assignment1_definitions_h

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define DEG2RAD 3.14159/180

#define DEFAULT_WIDTH 1024
#define DEFAULT_HEIGHT 720
#define DEFAULT_X 100
#define DEFAULT_Y 100

typedef struct point3d{
    float x;
    float y;
    float z;
    
} Point3D;
typedef struct color{
    float r;
    float g;
    float b;
    
} Color;



#endif
