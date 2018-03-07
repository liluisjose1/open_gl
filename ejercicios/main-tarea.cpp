#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
	//Circunferencia
	glClear(GL_COLOR_BUFFER_BIT);
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
    
    
    /*glBegin(GL_POINTS);
    GLfloat angulo;
    for (int i = 0; i < 360; i++)
	{
			angulo = i*M_PI/180.0f;
			//glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(cos(angulo),sin(angulo),0.0f);
	}
	glEnd();
	
    glPointSize(5);
    glColor3f(1,0.5,0);
    glBegin(GL_POINTS);
    GLfloat angulo1;
    glVertex3f(0.5,0.5,.0f);
    glVertex3f(-0.5,0.5,.0f);
    for (int i = 180; i < 360; i++)
	{
			
			angulo1 = i*M_PI/180.0f;
			//glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(cos(angulo1)-0.5,sin(angulo1)-0.5-0.5,0.0f);
	}
	glEnd();*/
    /*//glRotated(90,1,1,1);
    glBegin(GL_QUAD_STRIP);
//FIRST QUAD
	glColor3f(1,0.5,0);
    glVertex3f(0.0f,-0.5f,0.0f);
    glVertex3f(.5f,-.5f,0.0f);
    glVertex3f(-.5f,0.0f,0.0f);
    glVertex3f(.5f,0.0f,0.0f);

//SECOND QUAD
	glColor3f(1,0,0);
	glVertex3f(-.7f,0.5f,0.0f);
	glVertex3f(.7f,0.5f,0.0f);
//THIRD QUAD
	glColor3f(1,0,0.25);
	glVertex3f(-.8f,0.8f,0.0f);
	glVertex3f(.9f,0.8f,0.0f);
	
    glEnd();*/
   glFlush ();

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
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Ejemplo Puntos");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
