/*
 * casa3D.cpp
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
#include <math.h>
 
#define PI 3.1415927
double rotate_y=45;
double rotate_x=-21;
double rotate_z=0;
int i=10;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.6f;

GLint ancho=600;
GLint alto=500;
int perspectiva = 0;

void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(0.7, 0.84, 0.91,0.5);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
    // Resetear transformaciones
    glLoadIdentity();
    // Rotar en el eje X,Y y Z
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);  // Transladar en los 3 glColor3f(0.27, 0.45, 0.54);
    // Otras transformaciones
    glScalef(scale, scale, scale);
    
    // glColor3f(0.27, 0.45, 0.54);   X
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(  -1.5, 0.0, 0.0 );
    glVertex3f(  1.5, 0.0, 0.0 );
    glEnd();
      // EJE Y
    glBegin(GL_LINES);
    glColor3f(0.15, 0.85, 0.29);
    glVertex3f(  0.0, -1.5, 0.0 );
    glVertex3f(  0.0, 1.5, 0.0 );
    glEnd();
      
        // EJE z
    glBegin(GL_LINES);
    glColor3f(0.18, 0.14, 0.79);
    glVertex3f(  0.0, 0.0, 1.5 );
    glVertex3f(  0.0, 0.0, -1.5 );
    glEnd();
    
        //Cesped
    glBegin(GL_QUADS);
    glColor3f(0.24, 0.63, 0.34);
    glVertex3f(  1.2, 0.0, 1.2 );
    glVertex3f(  -1.2, 0.0, 1.2 );
    glVertex3f(  -1.2, 0.0, -1.2 );
    glVertex3f(  1.2, 0.0, -1.2 );
        
      glEnd();

       // Pared Derecha
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.0, 0.0, 0.0 );
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glVertex3f(  0.0, 0.8, 0.0 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.0, 0.8, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glVertex3f(  0.4, 1.1, 0.0 );
   glEnd();
   
    // Pared Posterior
   glBegin(GL_POLYGON);
   glColor3f(0.21, 0.47, 0.54);
   glVertex3f(  0.0, 0.0, 0.0 );
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.0, 0.8, -0.8 );
   glVertex3f(  0.0, 0.8, 0.0 );
   glEnd();
   
      // Pared Izquierda
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.8, 0.0, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.0, 0.8, -0.8 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glVertex3f(  0.0, 0.8, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.4, 1.1, -0.8 );
   glEnd();
   
   // Pared Frontal
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  0.8, 0.0, -0.8 );
   glVertex3f(  0.8, 0.8, -0.8 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glEnd();
  
  // Techo grande
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );
   glVertex3f(  -0.05, 0.79, -0.85 );
   glVertex3f(  0.4, 1.1, -0.85 );
   glVertex3f(  0.4, 1.1, 0.05 );
   glVertex3f(  -0.05, 0.79, 0.05 );
   glEnd();
  
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );
   glVertex3f(  0.4, 1.1, -0.85 );
   glVertex3f(  0.85, 0.79, -0.85 );
   glVertex3f(  0.85, 0.79, 0.05 );
   glVertex3f(  0.4, 1.1, 0.05 ); 
   glEnd();
  
    // Chimenea
    glPushMatrix ();
    glColor3f(0.76, 0.39, 0.02);
    glTranslatef (0.4, 1.1, -0.4); 
    glRotatef(0.0, 0.0, 0.0, 0.0);
    glutSolidCube (0.1);
    glPopMatrix ();
   
    // Costados
     // Frente
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  1.0, 0.0, 0.0 );
   glVertex3f(  1.0, 0.0, -0.5 );
   glVertex3f(  1.0, 0.8, -0.5 );
   glVertex3f(  1.0, 1.0, -0.25 );
   glVertex3f(  1.0, 0.8, 0.0 );
   glEnd();
  
    // Derecha
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.8, 0.0, 0.0 );
   glVertex3f(  1.0, 0.0, 0.0 );
   glVertex3f(  1.0, 0.8, 0.0 );
   glVertex3f(  0.8, 0.8, 0.0 );
   glEnd();
    
    // izquieda
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.8, 0.0, -0.50 );
   glVertex3f(  1.0, 0.0, -0.50 );
   glVertex3f(  1.0, 0.8, -0.50 );
   glVertex3f(  0.8, 0.8, -0.50 );
   glEnd();
  
    //Cochera
   // Izquierda
   glBegin(GL_POLYGON);
   glColor3f(0.33, 0.54, 0.65);
   glVertex3f(  0.0, 0.0, -1.2 );
   glVertex3f(  0.7, 0.0, -1.2 );
   glVertex3f(  0.7, 0.3, -1.2 );
   glVertex3f(  0.0, 0.3, -1.2 );
   glEnd();
   
   // Atras
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.0, 0.0, -0.8 );
   glVertex3f(  0.0, 0.0, -1.2 );
   glVertex3f(  0.0, 0.3, -1.2 );
   glVertex3f(  0.0, 0.3, -0.8 );
   glEnd();
   
   // Frente
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.70, 0.3, -0.8 );
   glVertex3f(  0.70, 0.4, -1.0);
   glVertex3f(  0.70, 0.3, -1.2 );
   glEnd();
   
   // Atras cerrando
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.0, 0.3, -0.8 );
   glVertex3f(  0.0, 0.4, -1.0);
   glVertex3f(  0.0, 0.3, -1.2 );
   glEnd();
   
   // Frente
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.7, 0.0, -0.8 );
   glVertex3f(  0.7, 0.0, -0.85 );
   glVertex3f(  0.7, 0.3, -0.85 );
   glVertex3f(  0.7, 0.3, -0.8 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f(0.27, 0.45, 0.54);
   glVertex3f(  0.7, 0.0, -1.15 );
   glVertex3f(  0.7, 0.0, -1.2 );
   glVertex3f(  0.7, 0.3, -1.2 );
   glVertex3f(  0.7, 0.3, -1.15 );
   glEnd();
   
   // Puerta de Cochera
   glBegin(GL_POLYGON);
   glColor3f(0.89, 0.94, 0.96);
   glVertex3f(  0.7, 0.3, -1.15 );
   glVertex3f(  0.9, 0.15, -1.15 );
   glVertex3f(  0.9, 0.15, -0.85 );
   glVertex3f(  0.7, 0.3, -0.85 );
   glEnd();
   
   // Techo Cochera
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );
   glVertex3f(  -0.03, 0.29, -1.22 );
   glVertex3f(  0.72, 0.29, -1.22 );
   glVertex3f(  0.72, 0.4, -1.0 );
   glVertex3f(  -0.03, 0.4, -1.0 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0 );
   glVertex3f(  -0.03, 0.3, -0.80 );
   glVertex3f(  0.72, 0.3, -0.8);
   glVertex3f(  0.72, 0.4, -1.0 );
   glVertex3f(  -0.03, 0.4, -1.0 );
   glEnd();
  
   // Techo salida
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0.4 );
   glVertex3f(  0.4, 0.79, -0.5 );
   glVertex3f(  1.02, 0.79, -0.5 );
   glVertex3f(  1.02, 1.0, -0.25 );
   glVertex3f(  0.4, 1.0, -0.25 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f( 1, 0.5, 0.4 );
   glVertex3f(  0.4, 0.79, 0.0 );
   glVertex3f(  1.02, 0.79, 0.0);
   glVertex3f(  1.02, 1.0, -0.25 );
   glVertex3f(  0.4, 1.0, -0.25 );
   glEnd();
  
  //Ventanas
  
   glLineWidth(1.5);
  
   // Ventana Cochera
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.5, 0.1, -1.21 );
   glVertex3f(  0.6, 0.1, -1.21 );
   glVertex3f(  0.6, 0.2, -1.21 );
   glVertex3f(  0.5, 0.2, -1.21 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0 );
   glVertex3f(  0.5, 0.1, -1.21 );
   glVertex3f(  0.6, 0.1, -1.21 );
   glVertex3f(  0.6, 0.2, -1.21 );
   glVertex3f(  0.5, 0.2, -1.21 );
   glEnd();
   
    // Ventanas Pared izquierda
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.4, 0.6, -0.81 );
   glVertex3f(  0.6, 0.6, -0.81 );
   glVertex3f(  0.6, 0.8, -0.81 );
   glVertex3f(  0.4, 0.8, -0.81 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   glVertex3f(  0.4, 0.6, -0.81 );
   glVertex3f(  0.6, 0.6, -0.81 );
   glVertex3f(  0.6, 0.8, -0.81 );
   glVertex3f(  0.4, 0.8, -0.81 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   
   glVertex3f(  0.5, 0.6, -0.81 );
   glVertex3f(  0.5, 0.8, -0.81 );
   glEnd();
   
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.1, 0.6, -0.81 );
   glVertex3f(  0.3, 0.6, -0.81 );
   glVertex3f(  0.3, 0.8, -0.81 );
   glVertex3f(  0.1, 0.8, -0.81 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   glVertex3f(  0.1, 0.6, -0.81 );
   glVertex3f(  0.3, 0.6, -0.81 );
   glVertex3f(  0.3, 0.8, -0.81 );
   glVertex3f(  0.1, 0.8, -0.81 );
   glEnd();
  
   glBegin(GL_LINE_STRIP);
   glColor3f( 0, 0, 0 );
   glVertex3f(  0.2, 0.6, -0.81 );
   glVertex3f(  0.2, 0.8, -0.81 );
   glEnd();
  
   // frente ventana izquieda
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  1.01, 0.1, -0.1 );
   glVertex3f(  1.01, 0.1, -0.4 );
   glVertex3f(  1.01, 0.3, -0.4 );
   glVertex3f(  1.01, 0.3, -0.1 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.1 );
   glVertex3f(  1.01, 0.1, -0.4 );
   glVertex3f(  1.01, 0.3, -0.4 );
   glVertex3f(  1.01, 0.3, -0.1 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.3 );
   glVertex3f(  1.01, 0.3, -0.3 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.1, -0.2 );
   glVertex3f(  1.01, 0.3, -0.2 );
   glEnd();
   
   
    // Frente segunda planta
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  1.01, 0.5, -0.1 );
   glVertex3f(  1.01, 0.5, -0.4 );
   glVertex3f(  1.01, 0.7, -0.4 );
   glVertex3f(  1.01, 0.7, -0.1 );
   glEnd();
   
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.1 );
   glVertex3f(  1.01, 0.5, -0.4 );
   glVertex3f(  1.01, 0.7, -0.4 );
   glVertex3f(  1.01, 0.7, -0.1 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.3 );
   glVertex3f(  1.01, 0.7, -0.3 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  1.01, 0.5, -0.2 );
   glVertex3f(  1.01, 0.7, -0.2 );
   glEnd();
   
    // Arriba puerta
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
   glVertex3f(  0.81, 0.5, -0.55 );
   glVertex3f(  0.81, 0.5, -0.75 );
   glVertex3f(  0.81, 0.7, -0.75 );
   glVertex3f(  0.81, 0.7, -0.55 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
   glVertex3f(  0.81, 0.5, -0.55 );
   glVertex3f(  0.81, 0.5, -0.75 );
   glVertex3f(  0.81, 0.7, -0.75 );
   glVertex3f(  0.81, 0.7, -0.55 );
   glEnd();
   
    //      Puerta
   glBegin(GL_POLYGON);
   glColor3f( 04, 1, 0.8 );
       glVertex3f(  0.81, 0.05, -0.60 );
       glVertex3f(  0.81, 0.05, -0.70 );
       glVertex3f(  0.81, 0.35, -0.70 );
       glVertex3f(  0.81, 0.35, -0.60 );
   glEnd();
   
   glBegin(GL_LINE_STRIP);
   glColor3f( 0,0,0);
       glVertex3f(  0.81, 0.05, -0.60 );
       glVertex3f(  0.81, 0.05, -0.70 );
       glVertex3f(  0.81, 0.35, -0.70 );
       glVertex3f(  0.81, 0.35, -0.60 );
   glEnd();

     // Cubertor sol
    glBegin(GL_POLYGON);
    glColor3f( 1, 0.5, 0 );
        glVertex3f(  0.7, 0.40, -0.70 );
        glVertex3f(  0.9, 0.30, -0.70 );
        glVertex3f(  0.9, 0.30, -0.60 );
        glVertex3f(  0.7, 0.40, -0.60 );
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
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los glColor3f(0.27, 0.45, 0.54); X,Y,Z.
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
        exit(0);            // exit
    }
    
    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
    
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-600)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    
    // Crear ventana
    glutCreateWindow("Casa 3D Controlado por Teclas IM15005");
 
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
