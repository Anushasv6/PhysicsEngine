#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#include "Colors.h"
#include "Types.h"
#include "EventHandlers.h"
#include "GraphicPrimitives.h"
#include "InternalState.h"
#include "CalculateDistanceAndTime.h"
//#include "Update.h"
#include "RigidBody.h"


// Boundary Points...
double x0 = 200, y0 = 200; // Bottom Left
double x1 = 650, y1 = 650; // Top Right

// Radius of Circle
double radius = 20;

/**
 * @brief Callback function called by GLUT for every frame to draw the screen.
 */
void SceneRenderFunc() {

    glClear(GL_COLOR_BUFFER_BIT); 

    //Draw a red colored viewport
    DrawColoredRectUsingOnlyTwoPoints(x0, y0, x1, y1, COLOR3FV_RED);


    if(IsAnimationOn() == 0){
        //Draw a BLUE circle...
        DrawCircle(GetMouseX(), GetMouseY(),radius, COLOR3FV_BLUE); 
    }
    else{
        //Get the new values of the circle and redraw the circle at that position..
        //DrawCircle(GetMouseX(), newY , radius, COLOR3FV_RED);
        PaintRigidBodies();
    }

    glutSwapBuffers();
}

void IdleTimeEventHandler(){
    UpdateRigidBodyLocations();

    glutPostRedisplay();

}


/**
 * @brief Callback function which is called by GLUT whenever the window size changes.
 *
 * @desc Also sets the view-port, & projection.
 */
void ChangeScreenSize(GLsizei w, GLsizei h) {
    //printf("Changing the viewport(w=%d, h=%d)\n", w, h);

    // Set viewport to window dimensions...
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Store it for later use in Mouse Event Handler...
    SetWindowHeight(h);
    SetWindowWidth(w);

    SetBoundary(x0, y0, x1, y1);

    // gluOrtho2D(-w/2, w/2, -h/2, h/2);
    gluOrtho2D(0.0, w, 0.0, h);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

/**
 * @brief Set up the Rendering Configuration.
 */
void SetupRenderConfig() {
    // Set the color that would be painted when we clear the screen.
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glLineWidth(2.5);

    // The Size of the pencil...
    glPointSize(1.0);


}


/**
 * @brief The entry point to this program...
 */
int main(int argC, char *argV[]) {

    printf("Press g/G to enable gravity\n");

    // Initialize the GLUT Library
    glutInit(&argC,argV);

    // Set the Display Mode. Single Buffer/RGB Color...
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

    // Set the Window size
    glutInitWindowSize(800, 800);

    // Create the Window. All drawing operations happen inside it...
    glutCreateWindow("Physics Engine");

    // The function that will be called to render the scene by glutMainLoop.
    glutDisplayFunc(SceneRenderFunc);

    // The function that will be called to change the viewport, when the window size changes...
    glutReshapeFunc(ChangeScreenSize);

    // Register the mouse event handler...
    glutMouseFunc(MouseEventHandler);

    glutKeyboardFunc(KeyboardEventHandler);

    glutIdleFunc(IdleTimeEventHandler);

    // Setup the context...
    SetupRenderConfig();

    // Starts the drawing loop, which internally calls SceneRenderFunc...
    glutMainLoop();
}