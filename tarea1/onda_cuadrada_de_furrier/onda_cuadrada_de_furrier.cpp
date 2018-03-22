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
		glVertex2f(-10.0f,0.0f);
		glVertex2f(10.0f,0.0f);
		glVertex2f(0.0f,30.0f);
		glVertex2f(0.0f,-30.0f);
	glEnd();
    
    
    //dibujando ecuacion con puntos
    glBegin(GL_POINTS);
    glPointSize(3.0);
    glColor3f(1.0,0.0,0.0);
    GLfloat x,y,i;
    GLfloat angulo;
    //f(t)=
    //for para que dibuje punto por punto la ecuacion para los limites de -3π<x<5π 
    for (i =-3*M_PI; i <= 5*M_PI; i+=0.001)
	{
		x=i;
		//funcion de onda
		y=0.5*(sin(3*M_PI/4));
		//y=1+(4*1)/M_PI + (sin(x)+ (1/3)*sin(3*x)+ (1/5)*sin(5*x)+(1/7)*sin(7*x)+(1/7)*sin(7*x)+(1/111)*sin(11*x)+(1/13)*sin(13*x));
		glVertex2f(x,y);
		//y=(4/M_PI)*(sin(0.5*i)+(1/3)*sin(3*0.5*i)+(1/5)*sin(5*0.5*i));
		//pasando parametros de x,y del punto por el cual esta pasando
		/*if (y>0)
		{
			glVertex2f(x,1);
		}
		else
		{
			glVertex2f(x,-1);
		}
		*/
		
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
    glOrtho(-10.0,10.0,-10.0,10.0,-1.0,1.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Onda cuadrada de furrier IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
