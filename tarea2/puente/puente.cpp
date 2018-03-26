#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(2.0);
    glColor3f(0,0,0);
    //dibujando lineas horizontales
    glBegin(GL_LINES);
		glVertex2f(-2.7f,0.0f);
		glVertex2f(2.7f,0.0f);
		glVertex2f(-2.8f,0.3f);
		glVertex2f(2.8f,0.3f);
		glVertex2f(-2.8f,0.35f);
		glVertex2f(2.8f,0.35f);
		//cierre
		glVertex2f(-2.7f,0.0f);
		glVertex2f(-2.7f,0.3f);
		glVertex2f(2.7f,0.0f);
		glVertex2f(2.7f,0.3f);
		
		glVertex2f(-2.8f,0.3f);
		glVertex2f(-2.8f,0.35f);
		glVertex2f(2.8f,0.3f);
		glVertex2f(2.8f,0.35f);
	glEnd();
	glColor3f(0,0,0);
    //dibujando lineas verticales
    glBegin(GL_LINES);
		//iquierda
		glVertex2f(-2.65f,0.0f);
		glVertex2f(-2.5f,-0.5f);
		glVertex2f(-2.29f,0.0f);
		glVertex2f(-2.44f,-0.5f);
		
		glVertex2f(-2.61f,0.0f);
		glVertex2f(-2.5f,-0.4f);
		glVertex2f(-2.33f,0.0f);
		glVertex2f(-2.44f,-0.4f);

		
		glVertex2f(-2.5f,0.0f);
		glVertex2f(-2.5f,-2.75f);
		glVertex2f(-2.44f,0.0f);
		glVertex2f(-2.44f,-2.4536f);
		
		glVertex2f(-2.0f,0.0f);
		glVertex2f(-2.0f,-0.5f);
		glVertex2f(-1.96f,0.0f);
		glVertex2f(-1.96f,-0.3416f);
		
		glVertex2f(-1.5f,0.35f);
		glVertex2f(-1.5f,0.725f);
		glVertex2f(-1.46f,0.35f);
		glVertex2f(-1.46f,0.85524f);
		
		glVertex2f(-1.0f,0.35f);
		glVertex2f(-1.0f,2.1f);
		glVertex2f(-0.96f,0.35f);
		glVertex2f(-0.96f,2.18624);
		
		glVertex2f(-0.5f,0.35f);
		glVertex2f(-0.5f,2.925f);
		glVertex2f(-0.46f,0.35f);
		glVertex2f(-0.46f,2.96724f);
		
		//en medio
		glVertex2f(-0.02f,0.35f);
		glVertex2f(-0.02f,3.2f);
		glVertex2f(0.02f,0.35f);
		glVertex2f(0.02f,3.2f);
		
		//derecha
		glVertex2f(1.5f,0.35f);
		glVertex2f(1.5f,0.725f);
		glVertex2f(1.46f,0.35f);
		glVertex2f(1.46f,0.85524f);
		
		glVertex2f(1.0f,0.35f);
		glVertex2f(1.0f,2.1f);
		glVertex2f(0.96f,0.35f);
		glVertex2f(0.96f,2.18624);
		
		glVertex2f(0.5f,0.35f);
		glVertex2f(0.5f,2.925f);
		glVertex2f(0.46f,0.35f);
		glVertex2f(0.46f,2.96724f);
		
		glVertex2f(2.0f,0.0f);
		glVertex2f(2.0f,-0.5f);
		glVertex2f(1.96f,0.0f);
		glVertex2f(1.96f,-0.3416f);
		
		glVertex2f(2.5f,0.0f);
		glVertex2f(2.5f,-2.75f);
		glVertex2f(2.44f,0.0f);
		glVertex2f(2.44f,-2.4536f);
		
		
		glVertex2f(2.65f,0.0f);
		glVertex2f(2.5f,-0.5f);
		glVertex2f(2.29f,0.0f);
		glVertex2f(2.44f,-0.5f);
		
		glVertex2f(2.61f,0.0f);
		glVertex2f(2.5f,-0.4f);
		glVertex2f(2.33f,0.0f);
		glVertex2f(2.44f,-0.4f);

		
		
	glEnd();
	
    //dibujando ecuacion de la recta
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    GLfloat x,y,y2,i,i2;
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =-2.5; i <= 2.5; i+=0.001)
	{
		x=i;
		//ecuacion de la parabola externa de puente
		y=-x*x+3.5;
		//pasando parametros de x,y del punto por el cual esta pasando
		glVertex2f(x,y);
	}
		glEnd();
    //dibujando ecuacion de la recta
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i2 =-2.33; i2 <= 2.33; i2+=0.001)
	{
		x=i2;
		//parabola interna 3.5-0.7
		y2=-1.1*x*x+3.2;
		//pasando parametros de x,y del punto por el cual esta pasando
		glVertex2f(x,y2);
	}
	glEnd();
	//Cierre de parabolas
	glBegin(GL_LINES);
	glColor3f(0,0,0);
		glVertex2f(-2.5,-2.75);
		glVertex2f(-2.33,-2.75);
		glVertex2f(2.5,-2.75);
		glVertex2f(2.33,-2.75);
	glEnd();
	
	
   glFlush ();
   glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-3.0,3.0,-4.0,4.0,-4.0,4.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Puente IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}