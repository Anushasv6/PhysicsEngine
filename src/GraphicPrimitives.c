/**
 * @file        GraphicsPrimitives.h
 *
 * @brief       Contains the function implementation related to helper functions 
 *              related to Graphics Primitives ..
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include "GraphicPrimitives.h"
#include <GL/glut.h> 

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

