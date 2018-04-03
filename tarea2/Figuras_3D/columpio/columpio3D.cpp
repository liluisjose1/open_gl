/*
 * columpio3D.cpp
 * 
 * Copyright 2018 Luis Iraheta <liluisjose1@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
 
//Definimos variables
double rotate_y=25;
double rotate_x=-14;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;
 
 
void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el Eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 Ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    
    // Eje x
    glBegin(GL_LINES);
		 glColor3f(1.0, 0.0, 0.0);
		glVertex3f(  -1.5, 0.0, 0.0 );
		glVertex3f(  1.5, 0.0, 0.0 );
      glEnd();
      // Eje y
       glBegin(GL_LINES);
		glColor3f(0.15, 0.85, 0.29);
		glVertex3f(  0.0, -1.5, 0.0 );
		glVertex3f(  0.0, 1.5, 0.0 );
      glEnd();
      
        // Eje z
       glBegin(GL_LINES);
		glColor3f(0.18, 0.14, 0.79);
		glVertex3f(  0.0, 0.0, 1.5 );
		glVertex3f(  0.0, 0.0, -1.5 );
      glEnd();
      

    
 
   //cuadro de abajo
   glBegin(GL_LINE_STRIP); 
 
    glColor3f( 0, 0, 0 );
   glVertex3f(  -0.7, -0.4, 0.2 );
   glVertex3f(  0.7, -0.4, 0.2 );
   glVertex3f(  0.7, -0.4, -0.2 );
   glVertex3f(  -0.7, -0.4, -0.2 );
   glVertex3f(  -0.7, -0.4, 0.2 );
   glEnd();
  // triangulo de lado derecho
   
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  0.7, -0.4, -0.2 );
    glVertex3f(  0.7, -0.4, 0.2 );
    glVertex3f(  0.7, 0.7, 0.0 );
    glVertex3f(  0.7, -0.4, -0.2 );
    glEnd();
    
    // linea de arriba
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  0.7, 0.7, 0.0 );
    glVertex3f(  -0.7, 0.7, 0.0 );
    glEnd();
    
    // cuadro 1
    glBegin(GL_LINE_STRIP); 
   glVertex3f(  -0.7, -0.15, 0.2 );
   glVertex3f(  -0.45, -0.15, 0.2 );
   glVertex3f(  -0.45, -0.15, -0.2 );
   glVertex3f(  -0.7, -0.15, -0.2 );
   glVertex3f(  -0.7, -0.15, 0.2 );
    glEnd();
    
      // cuadro 2
    glBegin(GL_LINE_STRIP); 
   glVertex3f(  -0.7, 0.1, 0.2 );
   glVertex3f(  -0.45, 0.1, 0.2 );
   glVertex3f(  -0.45, 0.1, -0.2 );
   glVertex3f(  -0.7, 0.1, -0.2 );
   glVertex3f(  -0.7, 0.1, 0.2 );
    glEnd();
    
      // triangulo pequeno 1
   
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.7, 0.1, -0.2 );
    glVertex3f(  -0.7, 0.1, 0.2 );
    glVertex3f(  -0.7, 0.7, 0.0 );
    glVertex3f(  -0.7, 0.1, -0.2 );
    glEnd();
    
       // triangulo pequeno 2
   
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.45, 0.1, -0.2 );
    glVertex3f(  -0.45, 0.1, 0.2 );
    glVertex3f(  -0.45, 0.7, 0.0 );
    glVertex3f(  -0.45, 0.1, -0.2 );
    glEnd();
    
     // lineas interconectadas
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.7, -0.4, 0.2 );
    glVertex3f(  -0.7, 0.1, 0.2 );
    glEnd();
      
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.45, -0.4, 0.2 );
    glVertex3f(  -0.45, 0.1, 0.2 );
    glEnd();   

    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.7, -0.4, -0.2 );
    glVertex3f(  -0.7, 0.1, -0.2 );
    glEnd();
      
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.45, -0.4, -0.2 );
    glVertex3f(  -0.45, 0.1, -0.2 );
    glEnd();
    
       // lineas  columpio izquierda
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  -0.1, -0.1, 0.0 );
    glVertex3f(  -0.1, 0.7, 0.0 );
    glEnd();
    
           // lineas  columpio izquierda
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  0.1, -0.1, 0.0 );
    glVertex3f(  0.1, 0.7, 0.0 );
    glEnd();
    
       // lineas  columpio derecha
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  0.3, -0.1, 0.0 );
    glVertex3f(  0.3, 0.7, 0.0 );
    glEnd();
    
           // lineas  columpio derecha
    glBegin(GL_LINE_STRIP); 
    glVertex3f(  0.5, -0.1, 0.0 );
    glVertex3f(  0.5, 0.7, 0.0 );
    glEnd();

 
      // columpio Izquierda
    glBegin(GL_LINE_STRIP); 
   glVertex3f(  -0.1, -0.1, 0.05 );
   glVertex3f(  0.1, -0.1, 0.05 );
   glVertex3f(  0.1, -0.1, -0.05 );
   glVertex3f(  -0.1, -0.1, -0.05 );
   glVertex3f(  -0.1, -0.1, 0.05 );
    glEnd(); 
 
 
       // columpio Derecha
    glBegin(GL_LINE_STRIP); 
   glVertex3f(  0.3, -0.1, 0.05 );
   glVertex3f(  0.5, -0.1, 0.05 );
   glVertex3f(  0.5, -0.1, -0.05 );
   glVertex3f(  0.3, -0.1, -0.05 );
   glVertex3f(  0.3, -0.1, 0.05 );
    glEnd();
     
     
          // Rampa
    glBegin(GL_LINE_STRIP); 
   glVertex3f(  -0.7, -0.15, -0.2 );
   glVertex3f(  -0.45, -0.15, -0.2 );
   glVertex3f(  -0.45, -0.4, -0.5 );
   glVertex3f(  -0.7, -0.4,   -0.5 );
   glVertex3f(  -0.7, -0.15, -0.2 );
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
 
    //  Flecha izquierda: rotación en Eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    //  Flecha arriba: rotación en Eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    //  Flecha abajo: rotación en Eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    //  Tecla especial F2 : rotación en Eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en Eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 7;
 
    //  Solicitar actualización de visualización
    glutPostRedisplay();
 
}
 
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los Ejes X,Y,Z.
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
 
 
 
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    
    // Crear ventana
    glutCreateWindow("Columpio 3D Controlado por Teclas IM15005");
 
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
