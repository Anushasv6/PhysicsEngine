/**
 * @file        EVentHandlers.c
 *
 * @brief       Contains the function implementation related to glut event handlers....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include <GL/glut.h> 
#include <stdio.h>
 
#include "EventHandlers.h"
#include "InternalState.h" 
#include "RigidBody.h"
#include "CalculateDistanceAndTime.h"

extern double radius;


//double xmin = 200, xmax = 650, ymin = 200, ymax = 650;
/**
 * @brief Callback function called by GLUT to handle mouse events...
 */
void MouseEventHandler(int btn, int state, int x, int y) {
    //printf("MouseHandler: Button=%d, State=%d, x=%d, y=%d\n", btn, state, x, y);
    if(GLUT_LEFT_BUTTON == btn) {
        SetMouseX(x);
        SetMouseY(-y + GetWindowHeight());

        AddRigidBody(x, -y + GetWindowHeight(), 0.0, radius);

        if ((GLUT_DOWN == state)) {
            SetAnimation(0);
        }
        else {
            SetAnimation(1);
        }
        // Lastly Refresh the screen on mouse up...
        glutPostRedisplay();
    }
}

/**
 * @brief Callback function called by GLUT to Special key down events...
 */
void KeyboardEventHandler(unsigned char key, int x, int y) {
    //printf("SpecialKeyDownEventHandler: Key=%d, x=%d, y=%d\n", key, x, y);
    if ('g' == key || 'G' == key) { // if R or r key is pressed, then reset the rotation...
        
        printf("Gravity is enabled\n");
        // Lastly Refresh the screen
        glutPostRedisplay();
    }
}