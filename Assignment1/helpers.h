//
//  helpers.h
//  Assignment1
//
//  Created by Md. Abdul Munim Dibosh on 12/31/13.
//  Copyright (c) 2013 Md. Abdul Munim Dibosh. All rights reserved.
//

#ifndef Assignment1_helpers_h
#define Assignment1_helpers_h
#include "definitions.h"

void initWindow(char title[],float width,float height,int fullScreen)
{
    //  There are modes of Glut windows and we set these modes through this call. Here, GLUT_RGB means red-blue-green framebuffer for rendering and GLUT_DOUBLE means to enable use of double buffers. Double buffering is a concept used in drawing graphics to reduce flickering. One buffer is used to display and other is used to compute the next frame, and the technique keeps swapping these buffers.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    //initial window position
    glutInitWindowPosition(DEFAULT_X, DEFAULT_Y);
    /* set the initial window size */
    glutInitWindowSize((int) width, (int) height);
    
    /* create the window and store the handle to it */
    glutCreateWindow(title /* title */ );
    
    
    if(fullScreen == 1)
    {
        //make full screen
        glutFullScreen();
    }
}
void initModes(float width,float height)
{
    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    //for setting up camera
    glMatrixMode( GL_PROJECTION );
    //perspective setup
    //angle of view frustum
    glLoadIdentity();
    float angle = 60;
    float aspectRatio = width/height;
    float nearPlaneDistance = 0.1;
    float farPlaneDistance = 1000;
    gluPerspective( angle,aspectRatio,nearPlaneDistance,farPlaneDistance);
//    gluOrtho2D(0, width, 0, height);
    //get back to drawing/transformation mode
    glMatrixMode(GL_MODELVIEW);
}

#endif
