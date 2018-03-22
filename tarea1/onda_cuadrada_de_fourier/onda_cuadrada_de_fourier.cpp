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
    glPointSize(2.0);
    glColor3f(1.0,0.0,0.0);
    GLfloat x,y,i;
    GLfloat angulo;
    //f(t)=
    //for para que dibuje punto por punto la ecuacion para los limites de -3π<x<5π 
    for (i =-3*M_PI; i <= 5*M_PI; i+=0.001)
	{
		x=i;
		//funcion de onda  de fourier
		y = (20/M_PI)*(((sin(i))/1)+((sin(3*i))/3)+((sin(5*i))/5)+((sin(7*i))/7)+((sin(9*i))/9)+((sin(11*i))/11)+((sin(13*i))/13)+((sin(15*i))/15)+((sin(17*i))/17)+((sin(19*i))/19)+((sin(21*i))/21)+((sin(23*i))/23)+((sin(25*i))/25)+((sin(27*i))/27)+((sin(29*i))/29));
		glVertex2f(x,y);
	}
	glEnd();
    glutSwapBuffers();
	glFlush ();

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
