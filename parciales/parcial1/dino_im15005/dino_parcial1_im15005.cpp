/*
 * dino_parcial1_im15005.cpp
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


#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.1f;
GLfloat Z = 0.0f;
GLfloat scale = 0.1f;
void escena(){
		//suelo
		glBegin(GL_QUADS);
			glColor3f(0,0,0);
			
			//izquierda
			glVertex2f(-1.5,-1.7);
			glVertex2f(-1.5,-1.8);
			glVertex2f(-2.5,-1.8);
			glVertex2f(-2.5,-1.7);
			
			glVertex2f(-2.5,-2.2);
			glVertex2f(-2.5,-2.3);
			glVertex2f(-2.0,-2.3);
			glVertex2f(-2.0,-2.2);
			
			glVertex2f(-1.4,-2.0);
			glVertex2f(-1.2,-2.0);
			glVertex2f(-1.2,-2.05);
			glVertex2f(-1.4,-2.05);
			
			//derecha
			glVertex2f(1.5,-1.7);
			glVertex2f(1.5,-1.8);
			glVertex2f(2.5,-1.8);
			glVertex2f(2.5,-1.7);
			
			glVertex2f(1.4,-2.0);
			glVertex2f(1.2,-2.0);
			glVertex2f(1.2,-2.05);
			glVertex2f(1.4,-2.05);
		glEnd();

}
void dino_movimiento(){
		

    // Resetear transformaciones
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Rotar en el Eje Y
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glTranslatef(X, Y, Z); 	// Transladar en los 3 Ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
    

      glBegin(GL_QUADS);
			//OJO
			glColor3f(1,1,1);
			glVertex2f(0.8,0.0);
			glVertex2f(1.0,0.0);
			glVertex2f(1.0,-0.2);
			glVertex2f(0.8,-0.2);
			
			//CABEZA
			glColor3f(0,0,0);
			glVertex2f(0.0,-0.2);
			glVertex2f(0.4,-0.2);
			glVertex2f(0.4,-1.2);
			glVertex2f(0.0,-1.2);
			
			glVertex2f(0.4,0.2);
			glVertex2f(0.8,0.2);
			glVertex2f(0.8,-1.4);
			glVertex2f(0.4,-1.4);

			glVertex2f(0.8,0.2);
			glVertex2f(2.0,0.2);
			glVertex2f(2.0,-0.9);
			glVertex2f(0.8,-0.9);
			
			glVertex2f(0.6,0.2);
			glVertex2f(1.8,0.2);
			glVertex2f(1.8,0.4);
			glVertex2f(0.6,0.4);
			
			glVertex2f(0.8,-1.1);
			glVertex2f(1.5,-1.1);
			glVertex2f(1.5,-1.4);
			glVertex2f(0.8,-1.4);
			//ESPALDA
			glColor3f(0,0,0);
			glVertex2f(0.0,0.0);
			glVertex2f(0.0,-1.8);
			glVertex2f(-0.4,-1.8);
			glVertex2f(-0.4,0.0);
			
			glVertex2f(-0.4,-0.3);
			glVertex2f(-0.4,-1.6);
			glVertex2f(-0.7,-1.6);
			glVertex2f(-0.7,-0.3);
			
			glVertex2f(-0.7,-0.5);
			glVertex2f(-0.7,-1.8);
			glVertex2f(-1.1,-1.8);
			glVertex2f(-1.1,-0.5);
				
			
			//PATAS
			
				//DERECHA
			glVertex2f(-0.0,-0);
			glVertex2f(-0.0,-2.3);
			glVertex2f(-0.2,-2.3);
			glVertex2f(-0.2,-0);
			
			glVertex2f(-0.2,-2.1);
			glVertex2f(0.25,-2.1);
			glVertex2f(0.25,-2.3);
			glVertex2f(-0.2,-2.3);
			
				//IZQUIERDA
			glVertex2f(-0.7,-1.8);
			glVertex2f(-0.7,-2.3);
			glVertex2f(-0.90,-2.3);
			glVertex2f(-0.90,-1.8);
			
			glVertex2f(-0.7,-2.1);
			glVertex2f(-0.50,-2.1);
			glVertex2f(-0.50,-2.3);
			glVertex2f(-0.7,-2.3);
			
			
			
			//COLA
			glVertex2f(-1.1,-0.3);
			glVertex2f(-1.1,-1.6);
			glVertex2f(-1.3,-1.6);
			glVertex2f(-1.3,-0.3);
			
			glVertex2f(-1.3,-0.2);
			glVertex2f(-1.3,-1.5);
			glVertex2f(-1.5,-1.5);
			glVertex2f(-1.5,-0.2);
			
			glVertex2f(-1.5,0.2);
			glVertex2f(-1.5,-1.2);
			glVertex2f(-1.7,-1.2);
			glVertex2f(-1.7,0.2);
	  glEnd();
	  
	  glPopMatrix();
	  glPushMatrix();
	      
    
	}
void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	 
	 //funciones
	 
	  dino_movimiento();
	  escena();
	  glFlush();
	  glutSwapBuffers();

 
}
 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
 
    //  Flecha derecha: aumentar rotación 7 grados
    if (key == GLUT_KEY_RIGHT){
        //dino_movimiento();
        X += 0.1;
	}
    //  Flecha izquierda: rotación en Eje Y negativo 7 grados
    else if (key == GLUT_KEY_LEFT){
        //dino_movimiento();
        X -= 0.1;
    }
    //  Flecha arriba: rotación en Eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_y += 180;
    //  Flecha abajo: rotación en Eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_y -= 180;
 
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
        scale=0.4;
        break;
    case 'd':
        scale=0.2;
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
 
 
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
} 
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    
    init();
    // Crear ventana
    glutCreateWindow("Dino Controlado por Teclas IM15005");
	
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
