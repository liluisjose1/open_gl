#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
	//Senos
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(2);
    glColor3f(1,0.5,0);
    glBegin(GL_POINTS);
    GLfloat x,y,i;
    for (i =-3.0; i <= 3.0; i+=0.001)
	{
		x=i;
		y=sin((M_PI)*x);
		glVertex2f(x,y);
	}
    glColor3f(1,0.2,0);
    for (i =-3.0; i <= 3.0; i+=0.001)
	{
		x=i;
		y=cos((M_PI)*x);
		glVertex2f(x,y);
	}
	glEnd();
   glFlush ();
    glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3.0,3.0,-3.0,3.0,-3.0,3.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize (500, 500);
    glViewport(0,0,GLUT_SCREEN_WIDTH,GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Ejemplo Puntos Senos");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
