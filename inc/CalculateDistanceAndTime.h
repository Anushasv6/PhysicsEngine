/**
 * @file        Update.h
 *
 * @brief       Contains the function declarations related to the verticle movement of the ball...
 *  				
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */
#include <time.h>

#ifndef __CALCULATE_H__
#define __CALCULATE_H__


unsigned long GetTimeInMilliSeconds();

/**
 * @brief  Calculates the time frame dt = t0 - t1 
 */ 
void SetStartTime();
unsigned long  GetDeltaTime();

/**
 * @brief  Calculates the distance d = 4.9*t^2.. 
 */
unsigned long GetDeltaDistanceDown(float deltaTime);
long GetDeltaDistanceUp(float initialVelocity, float deltaTime);

int GetFinalVelocity(float vInitial, unsigned long time);

#endif //__CALCULATE_H__