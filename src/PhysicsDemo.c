#include <stdio.h>
#include <GL/glut.h>

#include "Colors.h"
#include "Types.h"
#include "EventHandlers.h"
#include "GraphicPrimitives.h"


/**
 * @brief Callback function called by GLUT for every frame to draw the screen.
 */
void SceneRenderFunc() {
    double x0=60,y0=20,x1=80,y1=120;
    glClear(GL_COLOR_BUFFER_BIT);         
    
    //Draw a red colored viewport
    DrawColoredRect(100, 100, 100, 200, 200, 200, 200, 100, COLOR3FV_RED);

    // Draw a gray line without any clipping...
    //DrawColoredLine(g_x0, g_y0, g_x1, g_y1, COLOR3FV_LGRAY);
    
    glFlush();
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
    //g_width = w; g_height = h;

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

    // The Size of the pencil...
    glPointSize(1.0);
}

/**
 * @brief The entry point to this program...
 */
int main(int argC, char *argV[]) {

    // Initialize the GLUT Library
    glutInit(&argC,argV);

    // Set the Display Mode. Single Buffer/RGB Color...
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

    // Set the Window size
    glutInitWindowSize(500, 500);

    // Create the Window. All drawing operations happen inside it...
    glutCreateWindow("Physics Engine");

    // The function that will be called to render the scene by glutMainLoop.
    glutDisplayFunc(SceneRenderFunc);

    // The function that will be called to change the viewport, when the window size changes...
    glutReshapeFunc(ChangeScreenSize);

    // Register the mouse event handler...
    glutMouseFunc(MouseEventHandler);

    glutKeyboardFunc(KeyboardEventHandler);

    // Setup the context...
    SetupRenderConfig();

    // Starts the drawing loop, which internally calls SceneRenderFunc...
    glutMainLoop();
}