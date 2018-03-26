#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPointSize(2.0);
	//planta arriba
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(0,0);
		glVertex2f(-5,1);
		glVertex2f(-5,3);
		glVertex2f(-3,5);
		glVertex2f(0,2);
		glVertex2f(1,3);
		glVertex2f(2,2.75);
		glVertex2f(3,5);
		glVertex2f(4,4);
		glVertex2f(4,2);
		glVertex2f(2,0.75);
		glVertex2f(1,1);
		glVertex2f(0,0);
	glEnd();
	//techo derecha
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(3,5);
		glVertex2f(0,5.5);
		glVertex2f(1,3);
		glVertex2f(1,1);
		glVertex2f(2,0.75);
		glVertex2f(2,2.75);
	glEnd();
	
	//techo izquierda
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(2,5.20);
		glVertex2f(0,7);
		glVertex2f(-3,5);
	glEnd();
	
	//garage y planta abajo
		//pared derecha
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(4,2);
		glVertex2f(4,-0.75);
		glVertex2f(2,-2);
		glVertex2f(1,-1.75);
		glVertex2f(0,-3);
		glVertex2f(0,0);
		glVertex2f(1,1);
		glVertex2f(1,-1.75);
		glVertex2f(2,-2);
		glVertex2f(2,0.75);
	glEnd();
	
	//Garaje
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-5,1);
		glVertex2f(-5,0.5);
		glVertex2f(-5.9,0.60);
		glVertex2f(-7,-0.5);
		glVertex2f(-7,-3);
		glVertex2f(-2.5,-5);
		glVertex2f(-2.5,-2);
		glVertex2f(-1.6,-0.5);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-5,0.5);
		glVertex2f(-5.9,0.60);
		glVertex2f(-1.6,-0.5);
	glEnd();
	//Garaje
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-2.5,-5);
		glVertex2f(-2.25,-4.75);
		glVertex2f(-2.25,-2.25);
		glVertex2f(-1.5,-3.5);
		glVertex2f(0,-2.5);
		glVertex2f(-0.8,-1.2);
		glVertex2f(-2.25,-2.25);
	glEnd();
	
	//Garaje
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-5,1);
		glVertex2f(-5,0.5);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,-1.60);
		//glVertex2f(-0.5,-2.75);
		//glVertex2f(0,-3);
	glEnd();
	//Garaje
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-0.5,-2.80);
		glVertex2f(0,-3);
	glEnd();
	
	//lineas
	glBegin(GL_LINES);
	glColor3f(0,0,0);
		//arriba puerta
		glVertex2f(0,0);
		glVertex2f(0,2);
		
		//garaje
		glVertex2f(-7,-0.5);
		glVertex2f(-2.5,-2);
		
	glEnd();
	//Puerta principal
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(0.25,-2.60);
		glVertex2f(0.25,-0.5);
		glVertex2f(0.75,0.0);
		glVertex2f(0.75,-2.0);
	glEnd();
	//ventana planta baja
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(2.5,0.40);
		glVertex2f(2.5,-1.0);
		glVertex2f(3.5,-0.40); 		
		glVertex2f(3.5,1);
		glVertex2f(2.5,0.40); 		
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(0,0);
	glEnd();

	
	
   glFlush ();
   glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-8.0,5.0,-6.0,8.0,-10.0,10.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Casa IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
