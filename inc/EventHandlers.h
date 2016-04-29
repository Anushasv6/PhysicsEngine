/**
 * @file        EVentHandlers.h
 *
 * @brief       Contains the function declarations related to glut event handlers....
 *
 * @date        2016
 * @copyright   Anusha S V and Namratha H R. All rights reserved.
 *
 */



#ifndef __EVENTHANDLERS_H__
#define __EVENTHANDLERS_H__

/**
 * @brief Callback function called by GLUT to handle mouse events...
 */
void MouseEventHandler(int btn, int state, int x, int y);

/**
 * @brief Callback function called by GLUT to Special key down events...
 */
void KeyboardEventHandler(unsigned char key, int x, int y); 

#endif  //__EVENTHANDLERS_H__