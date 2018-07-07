#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27


// Camera position
float x = 0.0, y = -5.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

void changeSize(int w, int h) 
{
    float ratio =  ((float) w) / ((float) h); // window aspect ratio
    glMatrixMode(GL_PROJECTION); // projection matrix is active
    glLoadIdentity(); // reset the projection
    gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation
    glMatrixMode(GL_MODELVIEW); // return to modelview mode
    glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}


void drawSnowman()
{
    // Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
    glColor3f(1.0, 1.0, 1.0); // set drawing color to white
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.75);
        glutSolidSphere(0.75, 20, 20);
    glPopMatrix();

    // Draw the head (a sphere of radius 0.25 at height 1.75)
    glPushMatrix();
        glTranslatef(0.0, 0.0, 1.70); // position head
        glutSolidSphere(0.25, 20, 20); // head sphere

        // Draw Eyes (two small black spheres)
        glColor3f(0.0, 0.0, 0.0); // eyes are black
        glPushMatrix();
            glTranslatef(0.0, -0.18, 0.10); // lift eyes to final position
            glPushMatrix();
                glTranslatef(-0.05, 0.0, 0.0);
                glutSolidSphere(0.05, 10, 10); // right eye
            glPopMatrix();
            glPushMatrix();
                glTranslatef(+0.05, 0.0, 0.0);
                glutSolidSphere(0.05, 10, 10); // left eye
            glPopMatrix();
        glPopMatrix();

        // Draw Nose (the nose is an orange cone)
        glColor3f(1.0, 0.5, 0.5); // nose is orange
        glPushMatrix();
            glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y
            glutSolidCone(0.08, 0.5, 10, 2); // draw cone
        glPopMatrix();


    glPopMatrix();

    // Draw a faux shadow beneath snow man (dark green circle)
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
        glTranslatef(0.2, 0.2, 0.001);  // translate to just above ground
        glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
        glutSolidSphere(0.75, 20, 20); // shadow same size as body
    glPopMatrix();


    glPushMatrix();
        glTranslatef(-1.0, 1.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(1.0, 40.0, 1.0);
        glColor3f(1.0, 1.0, 0.0);
        glutSolidCube(0.125);
    glPopMatrix();

    // Draw the roof posts using cylinders
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();

    // post 1
    glPushMatrix();
    glTranslatef(1.0, 1.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();

    // post 2
    glPushMatrix();
    glTranslatef(1.0, -1.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();

    // post 3
    glPushMatrix();
    glTranslatef(-1.0, -1.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();

    // post 4
    glPushMatrix();
    glTranslatef(-1.0, 1.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();


    // draw roof using a cone
    glPushMatrix();
        glTranslatef(0.0, 0.0, 2.5);
        glColor3f(255, 0.0, 0.0);
        glutSolidCone(1.75, 1, 32, 16);
    glPopMatrix();

}


void update(void) 
{
    if (deltaMove) { // update camera position
        x += deltaMove * lx * 0.1;
        y += deltaMove * ly * 0.1;
    }
    glutPostRedisplay(); // redisplay everything
}


void renderScene(void) 
{
    int i, j;

    // Clear color and depth buffers
    glClearColor(0.0, 0.7, 1.0, 1.0); // sky color is light blue
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera centered at (x,y,1) and looking along directional
    // vector (lx, ly, 0), with the z-axis pointing up
    gluLookAt(
            x,      y,      1.0,
            x + lx, y + ly, 1.0,
            0.0,    0.0,    1.0);

    // Draw ground - 200x200 square colored green
    glColor3f(0.0, 0.7, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-100.0, -100.0, 0.0);
        glVertex3f(-100.0,  100.0, 0.0);
        glVertex3f( 100.0,  100.0, 0.0);
        glVertex3f( 100.0, -100.0, 0.0);
    glEnd();

    // Draw 36 snow men
    for(i = -3; i < 3; i++)
        for(j = -3; j < 3; j++) {
            glPushMatrix();
                glTranslatef(i*7.5, j*7.5, 0);
                drawSnowman();
            glPopMatrix();
        }

    glutSwapBuffers(); // Make it all visible
} 

// processNormalKeys: ESC, q, and Q cause program to exit
// pressSpecialKey: Up arrow = forward motion, down arrow = backwards
// releaseSpecialKey: Set incremental motion to zero
//----------------------------------------------------------------------
void processNormalKeys(unsigned char key, int xx, int yy)
{
    if (key == ESC || key == 'q' || key == 'Q') exit(0);
} 

void pressSpecialKey(int key, int xx, int yy)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 1.0; break;
        case GLUT_KEY_DOWN : deltaMove = -1.0; break;
    }
} 

void releaseSpecialKey(int key, int x, int y) 
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 0.0; break;
        case GLUT_KEY_DOWN : deltaMove = 0.0; break;
    }
} 


void mouseMove(int x, int y) 
{   
    if (isDragging) { // only when dragging
        // update the change in angle
        deltaAngle = (x - xDragStart) * 0.005;

        // camera's direction is set to angle + deltaAngle
        lx = -sin(angle + deltaAngle);
        ly = cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y) 
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) { // left mouse button pressed
            isDragging = 1; // start dragging
            xDragStart = x; // save x where button first pressed
        }
        else  { /* (state = GLUT_UP) */
            angle += deltaAngle; // update camera turning angle
            isDragging = 0; // no longer dragging
        }
    }
}

int main(int argc, char **argv) 
{
    printf("\n\
-----------------------------------------------------------------------\n\
   Controls \n\
  - Drag mouse left-right to rotate camera\n\
  - Hold up-arrow/down-arrow to move camera forward/backward\n\
  - q or ESC to quit\n\
-----------------------------------------------------------------------\n");

    // general initializations
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("OpenGL/GLUT Sampe Program");

    // register callbacks
    glutReshapeFunc(changeSize); // window reshape callback
    glutDisplayFunc(renderScene); // (re)display callback
    glutIdleFunc(update); // incremental update 
    glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
    glutMouseFunc(mouseButton); // process mouse button push/release
    glutMotionFunc(mouseMove); // process mouse dragging motion
    glutKeyboardFunc(processNormalKeys); // process standard key clicks
    glutSpecialFunc(pressSpecialKey); // process special key pressed
                        // Warning: Nonstandard function! Delete if desired.
    glutSpecialUpFunc(releaseSpecialKey); // process special key release

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0; 
}
