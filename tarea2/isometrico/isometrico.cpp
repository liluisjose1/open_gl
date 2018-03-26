#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //triangulo
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
		glVertex2f(0,0);
		glVertex2f(0,5);
		glVertex2f(3,-2);
		glVertex2f(0,0);
    glEnd();
    //cuadrado exterior
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
		glVertex2f(0,0);
		glVertex2f(0,5);
		glVertex2f(-3,3);
		glVertex2f(-3,-2);
		glVertex2f(0,0);
    glEnd();
    
    //cuadrado interior
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
		glVertex2f(-0.5,0.5);
		glVertex2f(-0.5,3.5);
		glVertex2f(-2.5,2.2);
		glVertex2f(-2.5,-0.9);
		glVertex2f(-0.5,0.5);
    glEnd();
    //rectangulo arriba
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
		glVertex2f(-3,3);
		glVertex2f(-4,3.5);
		glVertex2f(0.2,6.2);
		glVertex2f(1.0,5.7); 	
		glVertex2f(0,5); 		
    glEnd();
    //lineas
    glBegin(GL_LINES);
    glColor3f(0,0,0);
		//semi cuadrado abajo
		glVertex2f(-3,-2);
		glVertex2f(-1.0,-3.5);
		glVertex2f(1.0,-3.5);
		glVertex2f(3,-2);
		//lineas de cuadrado interior
		glVertex2f(-0.5,0.5);
		glVertex2f(-1.2,0.8);
		glVertex2f(-1.2,0.8);
		glVertex2f(-1.2,3);
		glVertex2f(-1.2,0.8);
		glVertex2f(-2.5,-0.01);
		
		//rampa
		glVertex2f(1.0,5.7);
		glVertex2f(4.0,-1.1);
        glVertex2f(4.0,-1.1);
		glVertex2f(3,-2);
		
		//L
		glVertex2f(-4,3.5);
		glVertex2f(-4,-2.5);
		glVertex2f(-4,-2.5);
		glVertex2f(-1.0,-4.8);
		glVertex2f(4.0,-1.1);
		glVertex2f(4,-2.5);
		glVertex2f(4,-2.5);
		glVertex2f(1,-4.8);
    glEnd();
    
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    GLfloat x,y,i, angulo;
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =0; i <= 2*M_PI; i+=0.001)
	{
		x=cos(i);
		//ecuacion de la parabola externa de puente
		y=sin(i);
		//pasando parametros de x,y del punto por el cual esta pasando
		glVertex2f(0.6*x,-2.7+0.6*y);
	}
    for (i =210; i <= 325 ; i+=0.001)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		x=cos(angulo);
		//ecuacion de la parabola externa de puente
		y=sin(angulo);
		//pasando parametros de x,y del punto por el cual esta pasando
		glVertex2f(1.2*x,-3.2+0.5*y);
	}
    for (i =210; i <= 325 ; i+=0.001)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		x=cos(angulo);
		//ecuacion de la parabola externa de puente
		y=sin(angulo);
		//pasando parametros de x,y del punto por el cual esta pasando
		glVertex2f(1.2*x,-4.5+0.5*y);
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
    glOrtho(-5.0,5.0,-7.0,7.0,-4.0,4.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Isometrico IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
