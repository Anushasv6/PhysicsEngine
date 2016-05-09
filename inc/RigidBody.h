/**
 * @file        RigidBody.h
 *
 * @brief       Contains the type redeclaration used in this project....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include "Types.h"
 
#ifndef __RIGIDBODY_H__ 
#define __RIGIDBODY_H__

/*
 *@brief 
 *
 */

typedef struct RigidBody {

	int   initialX;
	int   initialY;
	int   currentX;
	int   currentY;
	float vInitial;
	float vFinal;
	BOOL  isUnderGravity;
	BOOL  isFalling;
	unsigned long t0;
	float tripTime;
	int radius;

} RigidBody;

typedef struct RigidBodyNode{

	RigidBody rigidBody;
	struct RigidBodyNode *next;

}RigidBodyNode;

void AddRigidBody(int x,int y, float vInitial, int radius);

void UpdateRigidBodyLocations();

void PaintRigidBodies();
void PaintInitialBlueRigidBody();

#endif // __RIGIDBODY_H__
