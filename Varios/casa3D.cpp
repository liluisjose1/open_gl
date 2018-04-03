#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
 
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.25f;
 
 
void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    // Primera cara, se identica por multiples colores
    
    //Frente
    glColor3f( 0, 0,0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(  0.0, 0.0, 0.0 );
    glVertex3f(  1,  0.0, 0.0 );
    glVertex3f(  1,  2.0, 0.0 );
    glVertex3f(  0.5,  3.0, 0.0 );
    glVertex3f(  0,  2.0, 0.0 );
    glVertex3f(  0,  0.0, 0.0 );
	
    glEnd();
        glColor3f( 0, 0,0);
    glBegin(GL_LINES);
    //x
    glVertex3f(  -20.0, 0.0, 0.0 );
    glVertex3f(  20.0, 0.0, 0.0 );
    glVertex3f(  0.0, -20.0, 0.0 );
    glVertex3f(  0.0, 20.0, 0.0 );
    glVertex3f(  0.0, 0.0, -20.0 );
    glVertex3f(  0.0, 0.0, 20.0 );

	
    glEnd();
		
    glFlush();
    glutSwapBuffers();
 
}
 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
 
    //  Flecha izquierda: rotación en eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'd':
        scale=1.5;
        break;
    case 'x' :
        X += 0.1f;
        break;
    case 'X' :
        X -= 0.1f;
        break;
    case 'y' :
        Y += 0.1f;
        break;
    case 'Y' :
        Y -= 0.1f;
        break;
    case 'z':
        Z -= 0.1f;
        break;
    case 'Z':
        Z += 0.1f;
        break;
    case 'q':
        exit(0);			// exit
    }
    glutPostRedisplay();
}
 
 
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-20.0,20.0,-20,20.0,-20.0,20.0);
}
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    glutCreateWindow ("Casa IM15005");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
	init();
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
