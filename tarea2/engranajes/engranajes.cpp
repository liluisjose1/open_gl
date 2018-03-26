#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(2.0);
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    GLfloat x,y,i;
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =0; i <= 2*M_PI; i+=0.001)
	{
		x=cos(i);
		//ecuacion de la parabola externa de puente
		y=sin(i);
		//pasando parametros de x,y del punto por el cual esta pasando
		
		glVertex2f(0.2*x,0.5+0.2*y);
		//glVertex2f(0.5*x,0.5+0.5*y);
	}
	glEnd();
    glBegin(GL_QUAD_STRIP);
    glPointSize(30.0);
    glColor3f(0,0,0);
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =0; i <= 2*M_PI; i+=0.001)
	{
		x=cos(i);
		//ecuacion de la parabola externa de puente
		y=sin(i);
		//pasando parametros de x,y del punto por el cual esta pasand
		glVertex2f(0.5*x,0.5+0.5*y);
	}
	glEnd();

	
   glFlush ();
   glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Engranajes IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
