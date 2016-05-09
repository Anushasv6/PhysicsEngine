/**
 * @file        GraphicsPrimitives.c
 *
 * @brief       Contains the function implementation related to helper functions 
 *              related to Graphics Primitives ..
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include <GL/glut.h> 
#include <math.h>
#include "GraphicPrimitives.h"

/**
 * @brief Draws a colored rectangle given the coorindates and color.
 */
void DrawColoredRect(double x0, double y0, 
                     double x1, double y1, 
                     double x2, double y2, 
                     double x3, double y3, 
                     const GLfloat *color) 
{
    glColor3fv(color);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void DrawColoredRectUsingOnlyTwoPoints(int x0, int y0, int x1, int y1, const GLfloat *color){
    DrawColoredRect(x0, y0, 
                    x0, y1,
                    x1, y1,
                    x1, y0,
                    color);

}

/**
 * @brief Draws a colored line given the coorindates and color.
 */
void DrawColoredLine(double x0, double y0, double x1, double y1, const GLfloat *color) {
    glColor3fv(color);
    glBegin(GL_LINES);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
    glEnd();
}

/**
 * @brief Draws a colored circle given the center and radius.
 */

void DrawCircle(double x, double y, double radius, const GLfloat *color)
{
    //Take the max number of triangle fans.More the number of TriangleAmount more rounder will be the circle...
    int TriangleAmount = 20;

    //Two times of PI because we are drawing a circle of full 360 degrees...2*PI = 360 in degrees.
    GLfloat TwicePi = 2.0f * 3.141;

    glColor3fv(color);
    glBegin(GL_TRIANGLE_FAN);
        
        //Mark the Center of the Circle...
        glVertex2f(x, y);
        for (int i = 0; i <= TriangleAmount; ++i)
        {
            glVertex2f( x +(radius * cos(i * TwicePi/TriangleAmount)),
                        y +(radius * sin(i * TwicePi/TriangleAmount)));
        }

    glEnd();    
}  
