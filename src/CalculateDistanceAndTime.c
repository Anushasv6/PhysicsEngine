/**
 * @file        Update.c
 *
 * @brief       Contains the function declarations related to the verticle movement of the ball...
 *              
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include <time.h>
#include <sys/time.h>
#include <stdio.h>

#include "CalculateDistanceAndTime.h"

//static unsigned long g_startTime;

unsigned long GetTimeInMilliSeconds()
{
	struct timeval tv;
	if(gettimeofday(&tv, NULL) != 0) 
		return 0;
	else
		return (unsigned long) ((tv.tv_sec * 1000ul) + (tv.tv_usec / 1000ul ) );
}

//void SetStartTime(){
//	g_startTime = GetTimeInMilliSeconds();
//}

//unsigned long GetDeltaTime(unsigned long t0) { 
//	unsigned long deltaTime = GetTimeInMilliSeconds() - g_startTime;
//	return deltaTime;
//}

/**
 * Using equation d = 1/2 a*t*t
 */
 unsigned long GetDeltaDistanceDown(float deltaTime){

	//float  deltaTime = GetDeltaTime()/1000.0f;
	//printf("deltaTime %f\n", deltaTime);
	
	unsigned long  deltaDistance = 4.9 * (deltaTime * deltaTime);

	return deltaDistance;
}

/**
 * Using equation d = vi + 1/2 a*t*t
 */
long GetDeltaDistanceUp(float initialVelocity, float deltaTime){

	//float  deltaTime = GetDeltaTime()/1000.0f;
	//printf("deltaTime %f\n", deltaTime);
	
	long  deltaDistance = (initialVelocity * deltaTime) - (4.9 * deltaTime * deltaTime);

	return deltaDistance;
}

/**
 * Using equation vf = vi + a*t
 */
int GetFinalVelocity(float vInitial, unsigned long time) {
	float vFinal = vInitial + 9.8 * time;
	return vFinal;
}

