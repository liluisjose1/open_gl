#ifdef __APPLE__
#include
#else
#include
#endif

#include
#include "math.h"

GLuint listID;
GLuint list2ID;
GLUquadric *sun, *mercury, *venus, *earth, *mars, *jupiter, *saturn, *uranus, *neptune;
GLfloat zoomx=128000;
GLfloat zoomy=80000;
// angle of rotation for the camera direction
GLfloat angle=0.0;
// actual vector representing the camera's direction
GLfloat lx=0.0f,lz=-1.0f;
// XZ position of the camera
GLfloat x=0.0f,z=5.0f;
GLfloat fraction;

void init()
{
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//store view matrix

glMatrixMode (GL_MODELVIEW);
glLoadIdentity();

angle=0;
glutInitWindowPosition(1,1);
glutInitWindowSize(1024,768);
glutCreateWindow("Solar System");

glClearColor(0,0,0,0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-128000,128000,-80000,80000,1,5000);

glClearColor(0,0,0,1);

//glEnable(GL_DEPTH_TEST);

sun=gluNewQuadric();
mercury=gluNewQuadric();
venus=gluNewQuadric();
earth=gluNewQuadric();
mars=gluNewQuadric();
jupiter=gluNewQuadric();
saturn=gluNewQuadric();
uranus=gluNewQuadric();
neptune=gluNewQuadric();
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glMatrixMode(GL_MODELVIEW);

//glLoadIdentity();
//gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);

//draw sun
glLoadIdentity();
glColor3f(1,0,0);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
//glutPostRedisplay();
gluQuadricDrawStyle(sun, GLU_LINE);
gluSphere(sun,1400,400,400);

//draw mercury
angle=(angle+0.01);
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-397+1930*cos(angle/0.24)*cos(0.51)-1887*sin(angle/0.24)*sin(0.51),1930*cos(angle/0.24)*sin(0.51)+1887*sin(angle/0.24)*cos(0.51),0);
//glutPostRedisplay();
gluQuadricDrawStyle(mercury, GLU_LINE);
gluSphere(mercury,25,20,20);

//draw venus
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-24.4+3607*cos(angle/0.62)*cos(0.5)-3606*sin(angle/0.62)*sin(0.5),3607*cos(angle/0.62)*sin(0.5)+3606*sin(angle/0.62)*cos(0.5),0);
//glutPostRedisplay();
gluQuadricDrawStyle(venus, GLU_LINE);
gluSphere(venus,61,20,20);

//draw earth
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-83+4986*cos(angle)*cos(2)-4985*sin(angle)*sin(2),4986*cos(angle)*sin(2)+4985*sin(angle)*cos(2),0);
//glutPostRedisplay();
gluQuadricDrawStyle(earth, GLU_LINE);
gluSphere(earth,64,10,10);

//draw mars
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-709+7598*cos(angle/1.9)*cos(5)-7560*sin(angle/1.9)*sin(5),7598*cos(angle/1.9)*sin(5)+7560*sin(angle/1.9)*cos(5),0);
//glutPostRedisplay();
gluQuadricDrawStyle(mars, GLU_LINE);
gluSphere(mars,34,10,10);

//draw jupiter
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-1266+25951*cos(angle/11.9)*cos(4.8)-25919*sin(angle/11.9)*sin(4.8),25951*cos(angle/11.9)*sin(4.8)+25919*sin(angle/11.9)*cos(4.8),0);
//glutPostRedisplay();
gluQuadricDrawStyle(jupiter, GLU_LINE);
gluSphere(jupiter,714,100,100);

//draw saturn
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-2664+47783*cos(angle/29.5)*cos(15)-47697*sin(angle/29.5)*sin(15),47783*cos(angle/29.5)*sin(15)+47697*sin(angle/29.5)*cos(15),0);
//glutPostRedisplay();
gluQuadricDrawStyle(saturn, GLU_LINE);
gluSphere(saturn,602,100,100);

//draw uranus
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-4258+95889*cos(angle/84.32)*cos(6)-95769*sin(angle/84.32)*sin(6),95889*cos(angle/84.32)*sin(6)+95769*sin(angle/84.32)*cos(6),0);
//glutPostRedisplay();
gluQuadricDrawStyle(uranus, GLU_LINE);
gluSphere(uranus,255,100,100);

//draw neptune
glLoadIdentity();
glColor3f(0,0,1);
gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
glTranslatef(-1683.4+150114*cos(angle/164.8)*cos(4.6)-150107*sin(angle/164.8)*sin(4.6),150114*cos(angle/164.8)*sin(4.6)+150107*sin(angle/164.8)*cos(4.6),0);
glutPostRedisplay();
gluQuadricDrawStyle(neptune, GLU_LINE);
gluSphere(neptune,247,100,100);
//glLoadIdentity();
glutSwapBuffers();

}

void keysnormal(unsigned char nkey, int x2, int y2)
{
fraction = 0.1f;
switch (nkey) {
case 27 : //Esc key
exit(0);
case 65 : //A key
angle -= 0.01f;
lx = sin(angle);
lz = -cos(angle);
//glLoadIdentity();
//gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
//glutPostRedisplay();
break;
case 68 : //D key
angle += 0.01f;
lx = sin(angle);
lz = -cos(angle);
//glLoadIdentity();
//gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
//glutPostRedisplay();
break;
case 87 : //W key
x += lx * fraction;
z += lz * fraction;
//glLoadIdentity();
//gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
//glutPostRedisplay();
break;
case 83 : //S key
x -= lx * fraction;
z -= lz * fraction;
//glLoadIdentity();
//gluLookAt( x, 1.0f, z,x+lx, 1.0f, z+lz,0.0f, 1.0f, 0.0f);
//glutPostRedisplay();
break;
}

}

void keyspecial( int key, int x1, int y1 )
{
if (key==GLUT_KEY_UP)
{
zoomx=zoomx/2;
zoomy=zoomy/2;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1*zoomx,zoomx,-1*zoomy,zoomy,1,5000);
glutPostRedisplay();
}
if (key==GLUT_KEY_DOWN)
{
zoomx=zoomx*2;
zoomy=zoomy*2;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1*zoomx,zoomx,-1*zoomy,zoomy,1,5000);
glutPostRedisplay();
}
}

int main(int argc, char **argv)
{
glutInit(&argc,argv);

//Initializations
init();

glutDisplayFunc(display);
glutKeyboardFunc(keysnormal);
glutSpecialFunc(keyspecial);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
