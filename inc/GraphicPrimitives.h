/**
 * @file        GraphicsPrimitives.h
 *
 * @brief       Contains the function declarations related to helper functions 
 *              related to Graphics Primitives ..
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */
#include <GL/gl.h>

#ifndef __GRAPHICSPRIMITIVES_H__ 
#define __GRAPHICSPRIMITIVES_H__

/**
 * @brief Draws a colored line given the coorindates and color.
 */
void DrawColoredLine(double x0, double y0, double x1, double y1, const GLfloat *color); 

/**
 * @brief Draws a colored rectangle given the coorindates and color.
 */
void DrawColoredRect(double x0, double y0, 
                      double x1, double y1, 
                      double x2, double y2, 
                      double x3, double y3, 
                      const GLfloat *color);

/**
 * @brief Draws a colored rectangle using only two sets of points...
 */
void DrawColoredRectUsingOnlyTwoPoints(int x0, int y0, int x1, int y1, const GLfloat *color);

/**
 * @brief Draws a colored circle given the center and radius.
 */
void DrawCircle(double x, double y, double radius, const GLfloat *color);

#endif // __GRAPHICSPRIMITIVES_H__