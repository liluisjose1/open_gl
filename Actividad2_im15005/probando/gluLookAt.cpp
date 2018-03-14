#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

void renderScene() // this function is called when you need to redraw the scene 
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // clear the scene

	glMatrixMode(GL_MODELVIEW); // enter in model view matrix
	glLoadIdentity(); // load the identity matrix, to reset transformations

	// set the observer 
	// he's in position in (0,0,-10)
	// he's looking on (0,0,0)
	// he's in (0,1,0) direction
	gluLookAt(0,0,-10, 0,0,0, 0,1,0);
	
	/*
	NOW HERE YOU CAN DRAW WHAT YOU WANT! :)
	*/
	

	// swap the buffer on the screen (real draw)
	glutSwapBuffers();
}

// this function is called when the window is resized
void reshapeScene(int w, int h)
{
	glMatrixMode(GL_PROJECTION); // enter in projection matrix mode
	glLoadIdentity(); // load the identity, to reset transformations
	glViewport(0, 0, w, h); // set the viewport (window) size
	// apply a perspective
	// 1: the "visual angle"
	// 2: the viewport ratio
	// 3: the minimum distance of view
	// 4: the maximum distance of view
	gluPerspective(20, w*1.0f/h, 0.1f, 100);
	glMatrixMode(GL_MODELVIEW); // revert to model view
}

 void selectObject(int x, int y)
 {
 	GLuint buff[64] = {0}; // the buffer
 	GLint hits, view[4];
 
 	glSelectBuffer(64, buff); // This choose the buffer where store the values for the selection data
 	glGetIntegerv(GL_VIEWPORT, view); // This retrieve info about the viewport
 	glRenderMode(GL_SELECT); // Switching in selecton mode
 	glInitNames(); // This stack contains all the info about the objects
 	glPushName(0); // Now fill the stack with one element (or glLoadName will generate an error)
 
 	// Now modify the vieving volume, restricting selection area around the cursor
 	glMatrixMode(GL_PROJECTION);
 	glPushMatrix();
 	
 	glLoadIdentity();
 	gluPickMatrix(x, y, 1.0, 1.0, view); // restrict the draw to an area around the cursor
 	
 	// [IMPORTANT] apply the same perspective in the reshapeFunc
 	gluPerspective(20, view[2]*1.0f/view[3], 0.1f, 100); 
 	glMatrixMode(GL_MODELVIEW); // Draw the objects onto the screen
 
 	glutSwapBuffers(); // draw only the names in the stack, and fill the array
 	renderScene(); // render
 
 	glMatrixMode(GL_PROJECTION); // Do you remeber? We do pushMatrix in PROJECTION mode
 	glPopMatrix();
 
 	hits = glRenderMode(GL_RENDER); // get number of objects drawed in that area and return to render mode

 	// NOW 
 	// hits: number of hits
 	// buff[ (hits*x)+3] the ID
 	std::cout<<"Hits: "<<hits<<"\n"<<"ID: "<<buff[3]<<"\n";
 
 	glMatrixMode(GL_MODELVIEW); // and revert again
 }

 void mouseHandler(int button, int state, int x, int y) // mouse handler callbacks
 {
    if 	((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		selectObject(x, y);
	}
 }

void init() // called to glEnable features or to init display lists
{
	glEnable(GL_DEPTH_TEST); // to enable when you draw in 3D
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // init OpenGL
	glutInitDisplayMode( GLUT_RGB | GLUT_DEPTH ); // set the display mode
	glutInitWindowSize(1000, 600); // set the window size
	glutCreateWindow("Base | OpenGL"); // set the window title

	glutDisplayFunc(renderScene); // set the callback to render
	glutReshapeFunc(reshapeScene); // set the callback to reshape

	glutMouseFunc(mouseHandler);

	init(); // init
	
	glutMainLoop(); // enter in a loop
}
