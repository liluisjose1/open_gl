#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//Base de columpio
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-8.0f,0.0f);
		glVertex2f(-6.5f,1.5f);
		glVertex2f(6.0f,0.0f);
		glVertex2f(4.5f,-1.5f);
		glVertex2f(-8.0f,0.0f);
	glEnd();
	//Cara izquierda
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-8.0f,0.0f);
		glVertex2f(-8.0f,3.5f);
		glVertex2f(-7.25f,7.0f);
		glVertex2f(-6.5f,5.0f);
		glVertex2f(-6.5f,1.5f);
	glEnd();
	//Cara par izquierda
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-6.0f,-0.20f);
		glVertex2f(-6.0f,3.35f);
		glVertex2f(-5.25f,6.85f);
		glVertex2f(-4.5f,4.85f);
		glVertex2f(-4.5f,1.30f);
	glEnd();
    //cuadro1
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-8.0f,3.5f);
		glVertex2f(-6.5f,5.0f);
		glVertex2f(-4.5f,4.85f);
		glVertex2f(-6.0f,3.35f);
		glVertex2f(-8.0f,3.5f);
		
	glEnd();
    //cuadro2
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-8.0f,2.0f);
		glVertex2f(-6.5f,3.5f);
		glVertex2f(-4.5f,3.35f);
		glVertex2f(-6.0f,1.85f);
		glVertex2f(-8.0f,2.0f);
		
	glEnd();
	
    //rampa
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-6.0f,1.85f);
		glVertex2f(-7.0f,-1.85f);
		glVertex2f(-9.0f,-1.65f);
		glVertex2f(-8.0f,2.0f);
	glEnd();
    //columpio izquierda
    glBegin(GL_LINES);
		glVertex2f(-3.0f,2.0f);
		glVertex2f(-3.0f,6.70f);
		glVertex2f(-1.0f,1.80f);
		glVertex2f(-1.0f,6.53f);
	glEnd();
	//silla columpio izquierda
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(-3.2f,1.9f);
		glVertex2f(-2.9f,2.0f);
		glVertex2f(-0.9f,1.80f);
		glVertex2f(-1.2f,1.70f);
		glVertex2f(-3.2f,1.9f);
	glEnd();
	
    //columpio derecha
    glBegin(GL_LINES);
		glVertex2f(1.0f,1.5f);
		glVertex2f(1.0f,6.38f);
		glVertex2f(3.0f,1.25f);
		glVertex2f(3.0f,6.20f);
	glEnd();
		//silla columpio derecha
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(0.7f,1.45f);
		glVertex2f(1.08f,1.55f);
		glVertex2f(3.1f,1.30f);
		glVertex2f(2.95f,1.19f);
		glVertex2f(0.7f,1.45f);
	glEnd();
	//cara derecha  
    glBegin(GL_LINE_STRIP);
    glPointSize(2.0);
    glColor3f(0,0,0);
		glVertex2f(6.0f,0.0f);
		glVertex2f(5.25f,6.0f);
		glVertex2f(4.5f,-1.5f);
	glEnd();
	//biga arriba
    glBegin(GL_LINES);
    glVertex2f(-7.25f,7.0f);
    glVertex2f(5.25f,6.0f);
    glColor3f(0,0,0);
		
	glEnd();
	
   glFlush ();
   glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-10.0,8.0,-3.0,8.0,-2.0,2.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Columpos IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
