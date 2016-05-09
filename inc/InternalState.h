/**
 * @file        InternalState.h
 *
 * @brief       Contains the function Declaration related to Internal State of the Application....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */
#include "Types.h"

int GetWindowHeight();
int GetWindowWidth();

void SetWindowHeight(int h);
void SetWindowWidth(int w);

int GetMouseX(); 
int GetMouseY(); 

void SetMouseX(int x);
void SetMouseY(int y);

BOOL  IsAnimationOn();
void  SetAnimation(BOOL animationStatus);

void SetBoundary(int x0, int y0, int x1, int y1);
int GetBoundaryX0();
int GetBoundaryY0();
int GetBoundaryX1();
int GetBoundaryY1();

