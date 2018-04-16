#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>

 
bool fullscreen = false;
bool mouseDown = false;
 
float xrot = 0.0f;
float yrot = 0.0f;
 
float xdiff = 0.0f;
float ydiff = 0.0f;
 
void drawBox()
{
glutWireSphere(0.8,10,10);
glEnd();
}
 int opcion = 1;

void menuAction(int valor) //creando la funcion menu 
{
   opcion = valor;
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glColor3f(0.5,0.2,0.9);
      switch (valor)// creando switch 
    {
          case 1://case 1 adentro del case se crea la figura de la tetera con color magenta
                 glTranslatef(0.0f, 0.0f, -5.0f);
                 glutWireTeapot(1.0);
          break;
          case 2: //case 2 adentro del case se crea la figura de Torus con otro color
                   glColor3f(0.0,1.0,1.0);
                   glTranslatef(0.0f, 0.0f, -5.0f);
                   glutWireTorus(0.5, 1.0, 20, 20);
                    break;
          case 3://case 3 se crea la figura del cubo con el tamano mas grande de 3.5f
                  glColor3f(1.0,0.5,0.0);
                  glTranslatef(0.0f, 0.0f, -5.0f);
                  glutWireCube(2.0f);
                    break;
          case 4://se crea la figura de la pelota como esfera case 4 con un nuevo color y
                 glColor3f(0.5,1.0,0.0);
                 glTranslatef(0.0f, 0.0f, -5.0f);
                 glutWireSphere(0.8,10,10);
                    break;
          case 5:// case 5 con la figura alambrica de un cono
                   glColor3f(0.5,0.5,0.5);
                   glTranslatef(0.0f, 0.0f, -5.0f);
                   glutWireCone(1,1,10,10); 
                    break;
          case 6://se crea la figura alambrica de Octahedron y asignandole color
                    glColor3f(1.0,0.0,0.0);
                    glutWireOctahedron();
                    break;
          case 7://case 7 figura alambrica de Icosahedron y asignandole un color
                    glColor3f(1.0,1.0,0.0);
                    glutWireIcosahedron();
                    break;
          case 8:// case 8 asignandole color y creando la figura alambrica de Tetrahedron
                    glColor3f(0.0,0.0,1.0);
                    glutWireTetrahedron();
                     break;
          case 9://case 9 saliendo del switch exit 0
             exit(0);
             break;       
    }
    glutSwapBuffers();
}

bool init()
{
glClearColor(0.93f, 0.93f, 0.93f, 0.0f);
 
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
glClearDepth(1.0f);
 
return true;
}
 
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(
0.0f, 0.0f, 3.0f,
0.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f);
 
glRotatef(xrot, 1.0f, 0.0f, 0.0f);
glRotatef(yrot, 0.0f, 1.0f, 0.0f);

drawBox();
menuAction(0);
glFlush();
glutSwapBuffers();
}
 
void resize(int w, int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glViewport(0, 0, w, h);
gluPerspective(45.0f, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
//gluPerspective(45.0f, 1.0f * w / h, 1.0f, 100.0f);
 
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
 void menu()//creando la funcion de menu_opciones
{
	glutCreateMenu(menuAction);//creando el menu para poder ver el listado de las figuras alambricas
	glutAddMenuEntry("TETERA",1);//primera opcion del menu TETERA
	glutAddMenuEntry("TORO",2);//segunda opcion del menu TORO
	glutAddMenuEntry("CUBO",3);//tercera opcion del menu CUBO
	glutAddMenuEntry("ESFERA",4);//Cuarta opcion del menu ESFERA
	glutAddMenuEntry("CONO",5);//quinta Opcion del menu CONO
	glutAddMenuEntry("OCTAEDRO",6);//sexta opcion del menu OCTAEDRO
	glutAddMenuEntry("ICOSAEDRO",7);//septima opcion del menu con la opcion de ICOSAEDRO
    glutAddMenuEntry("TETRAEDRO",8);//Octava opcion del menu con la opcion de TETRAEDRO
    glutAddMenuEntry("SALIR",9);//Novena opcion del menu para SALIR del menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

 
void mouse_rotar_y(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    yrot += 30.0f;
    glutPostRedisplay();
}
}
 
 
void keyboard(unsigned char key, int x, int y)
{
switch(key)
{
case 27 : 
exit(1); break;
}
}
 
void specialKeyboard(int key, int x, int y)
{
if (key == GLUT_KEY_F1)
{
fullscreen = !fullscreen;
 
if (fullscreen)
glutFullScreen();
else
{
glutReshapeWindow(500, 500);
glutPositionWindow(50, 50);
}
}
}
 
void mouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseDown = true;
 
xdiff = x - yrot;
ydiff = -y + xrot;
}
else
mouseDown = false;
}
 
void mouseMotion(int x, int y)
{
if (mouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;
 
glutPostRedisplay();
}
}
 
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowPosition(50, 50);
glutInitWindowSize(500, 500);
 
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
 
glutCreateWindow("13 - Solid Shapes");
 
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutSpecialFunc(specialKeyboard);
//glutMouseFunc(mouse);
menu();
glutMouseFunc(mouse_rotar_y);
//glutMotionFunc(mouseMotion);
glutReshapeFunc(resize);
//glutIdleFunc(idle);
 
if (!init())
return 1;
 
glutMainLoop();
 
return 0;
}
