#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(2.0);
    glColor3f(1.0,1.0,1.0);
    //dibujando los ejes coordenados
    glBegin(GL_LINES);
		glVertex2f(-4.0f,0.0f);
		glVertex2f(4.0f,0.0f);
		glVertex2f(0.0f,8.0f);
		glVertex2f(0.0f,-8.0f);
	glEnd();
    
    
    //dibujando ecuacion de la recta
    glBegin(GL_POINTS);
    glColor3f(0.2,0.7,0);
    GLfloat x,y,i;
    //Y=3x+7=0
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =-4.0; i <= 4.0; i+=0.001)
	{
		x=i;
		//ecuacion de la parabola
		y= 3*x+7;
		//pasando parametros de x,y del punto por el cual esta pasando
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
    //definiendo alto de ventanda hasta donde llegada la ecuacion un max de 8 
    glOrtho(-4.0,4.0,-8.0,8.0,-4.0,4.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Ecuacion y=3x+7 IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
