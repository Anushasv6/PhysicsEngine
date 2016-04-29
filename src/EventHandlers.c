/**
 * @file        EVentHandlers.h
 *
 * @brief       Contains the function implementation related to glut event handlers....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */

#include "EventHandlers.h"
#include <GL/glut.h> 

/**
 * @brief Callback function called by GLUT to handle mouse events...
 */
void MouseEventHandler(int btn, int state, int x, int y) {
    //printf("MouseHandler: Button=%d, State=%d, x=%d, y=%d\n", btn, state, x, y);
    if(GLUT_LEFT_BUTTON == btn) {
        if (GLUT_DOWN == state) {
            //g_x0 = x;
            //g_y0 = -y + g_height;
        }
        else {
            //g_x1 = x;
            //g_y1 = -y + g_height;
            
            // Lastly Refresh the screen on mouse up...
            glutPostRedisplay();
        }
    }
}

/**
 * @brief Callback function called by GLUT to Special key down events...
 */
void KeyboardEventHandler(unsigned char key, int x, int y) {
    //printf("SpecialKeyDownEventHandler: Key=%d, x=%d, y=%d\n", key, x, y);
    if ('r' == key || 'R' == key) { // if R or r key is pressed, then reset the rotation...
        
        // Lastly Refresh the screen
        glutPostRedisplay();
    }
}