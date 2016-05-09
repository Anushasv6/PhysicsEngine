/**
 * @file        InternalState.c
 *
 * @brief       Contains the function Implementaion related to Internal State of the Application....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */


#include "InternalState.h"

static int g_x0 = 0;
static int g_y0 = 0;
static int g_x1 = 0;
static int g_y1 = 0;


static int g_mouseX = 0; 
static int g_mouseY = 0;

static int g_winH = 0; 
static int g_winW = 0;


static BOOL g_animationStatus = 0;

int GetMouseX() { return g_mouseX; }
int GetMouseY() { return g_mouseY; }

void SetMouseX(int x) { g_mouseX = x; }
void SetMouseY(int y) { g_mouseY = y; }

BOOL  IsAnimationOn() { return g_animationStatus; }
void  SetAnimation(BOOL animationStatus) { g_animationStatus = animationStatus; }

int GetWindowHeight() { return g_winH; }
int GetWindowWidth()  { return g_winW; }

void SetWindowHeight(int h) { g_winH = h; }
void SetWindowWidth(int w)  { g_winW = w; }

void SetBoundary(int x0, int y0, int x1, int y1){
	g_x0 = x0; g_y0 = y0;  // bottom left point..
	g_x1 = x1; g_y1 = y1;  // top right point..
}

int GetBoundaryX0() { return g_x0; }
int GetBoundaryY0() { return g_y0; }
int GetBoundaryX1() { return g_x1; }
int GetBoundaryY1() { return g_y1; }


