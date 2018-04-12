#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float fronteras = 4.0;
GLfloat scale = 0.45f;
void Ruedas(GLfloat xp1, GLfloat yp1, GLfloat anguloI, GLfloat anguloF,float ra, float r, float g, float b){
  
  glLoadIdentity();
   glScalef(scale, scale, scale);
  glColor3f(r,g,b);
  glBegin(GL_POLYGON);
  GLfloat cx=xp1;
  GLfloat cy=yp1;
  GLfloat angulo;
  for (GLfloat i=anguloI; i<anguloF; i+=0.01){
    angulo= i*M_PI/180.0f;
    cx=ra*cos(angulo)+xp1;
    cy=ra*sin(angulo)+yp1;
    glVertex2f(cx,cy);
  }
   glEnd();
}

void display(void)
{
	  glClearColor(1,1,1,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	 glScalef(scale, scale, scale);
    Ruedas(0,0, 0,360,2, 0,0,0);
    Ruedas(0,1.5, 0,360,1, 1,1,1);
    Ruedas(-0.7,-1.7, 0,360,0.7, 1,1,1);
    Ruedas(0.7,-1.7, 0,360,0.7, 1,1,1);
    Ruedas(0,-2.5, 0,360,0.7, 1,1,1);
    Ruedas(-1.6,-0.7, 0,360,0.7, 1,1,1);
    Ruedas(-1.6,-0.9, 0,360,0.7, 1,1,1);
    Ruedas(1.6,-0.7, 0,360,0.7, 1,1,1);
    Ruedas(1.6,-0.9, 0,360,0.7, 1,1,1);

    glColor3f(0,0,0);
    
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,0);
    glVertex2f(-0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    
    glBegin(GL_POLYGON);
    glVertex2f(0.3,0);
    glVertex2f(0.1,1.4);
    glVertex2f(0,0);
    glEnd();

    glColor3f(0,0,0);
    
    glBegin(GL_POLYGON);
    glVertex2f(-0.1,0);
    glVertex2f(-0.1,1);
    glVertex2f(0.1,1);
    glVertex2f(0.1,0);
    glEnd();

       glFlush();
    glutSwapBuffers();
}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(fronteras), (fronteras), -(fronteras), (fronteras), -(fronteras),(fronteras));
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 420);
    glutInitWindowPosition (100, 100);
        glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-600)/2,(glutGet(GLUT_SCREEN_HEIGHT)-420)/2);
    glutCreateWindow ("Murcielago im15005 ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
