/**
 * @file        RigidBody.c
 *
 * @brief       Contains the type redeclaration used in this project....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include <stdlib.h>
#include <stdio.h> 

#include "RigidBody.h"
#include "CalculateDistanceAndTime.h"
#include "Colors.h" 
#include "GraphicPrimitives.h"
#include "InternalState.h" 


static RigidBodyNode *rigidBodyListHead  = NULL;

RigidBodyNode* GetLastNode() {

	if(NULL == rigidBodyListHead)
		return NULL;
	else
	{
		RigidBodyNode *currentNode = rigidBodyListHead;

		while(currentNode->next != NULL){
			currentNode = currentNode->next;
		}
		return currentNode;
	}

}
void AddRigidBody(int x, int y, float vInitial, int radius){

	RigidBodyNode *tailNode = GetLastNode();

	RigidBodyNode *newNode = (RigidBodyNode*) malloc(sizeof(RigidBodyNode));

	//To do : Populate other node fields...
	newNode->rigidBody.initialX = x; newNode->rigidBody.initialY = y;
	newNode->rigidBody.currentX = x; newNode->rigidBody.currentY = y;
	newNode->rigidBody.vInitial = vInitial;
	newNode->rigidBody.radius = radius;
	newNode->rigidBody.isFalling = TRUE;
	newNode->rigidBody.tripTime = 1.0f;
	newNode->rigidBody.t0 = GetTimeInMilliSeconds();
	newNode->next = NULL;

	if(NULL == tailNode){
		rigidBodyListHead = newNode;
	}
	else{
		tailNode->next = newNode;
	}
}

void UpdateRigidBodyLocation(RigidBody *rigidBody) {
	
	if(rigidBody->tripTime < 0.02)
		return;

    unsigned long t = GetTimeInMilliSeconds();
	float tDelta = (t - rigidBody->t0)/1000.0f;


	if (rigidBody->isFalling) {// Going down...
    	long boundaryY = (GetBoundaryY0()) + rigidBody->radius;	
		long distance = GetDeltaDistanceDown(tDelta);

		printf("Down->tDelta = %f boundaryY = %ld distance = %ld\n", tDelta, boundaryY, distance);
		if( (rigidBody->initialY - distance) > boundaryY) {
			rigidBody->currentY = rigidBody->initialY - distance;
        }
        else {
        	rigidBody->currentY = boundaryY;
        	rigidBody->initialY = boundaryY;

        	rigidBody->vInitial = GetFinalVelocity(0, tDelta);
        	rigidBody->t0 = t;
        	rigidBody->tripTime = tDelta;
        	rigidBody->isFalling = FALSE;
        }
	} 
	else { // Going up...
		long distance = GetDeltaDistanceUp(rigidBody->vInitial,tDelta);

		printf("Up->tDelta = %f distance = %ld tripTime = %f\n", tDelta, distance, rigidBody->tripTime);

		if(tDelta <= rigidBody->tripTime) {
			rigidBody->currentY = rigidBody->initialY + distance;
        }
        else {
        	rigidBody->isFalling = TRUE;
        	rigidBody->initialY = rigidBody->currentY;
        	rigidBody->currentY = 0;

        	rigidBody->vInitial = 0.0f;
        	rigidBody->t0 = t;
        }

	}

}

void UpdateRigidBodyLocations(){
	RigidBodyNode *currNode = rigidBodyListHead;
	if (currNode != NULL) {
		do {
			UpdateRigidBodyLocation(&currNode->rigidBody);
		} while ( (currNode = currNode->next) != NULL);
	}
}

void PaintRigidBodies(){
	RigidBodyNode *currNode = rigidBodyListHead;
	if (currNode != NULL) {
		do {
			RigidBody *rigidBody = &currNode->rigidBody;

			DrawCircle(rigidBody->currentX, rigidBody->currentY, rigidBody->radius, COLOR3FV_RED);

		} while ( (currNode = currNode->next) != NULL);
	}
}
