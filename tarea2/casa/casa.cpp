/*
 * casa.cpp
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

#include <GL/gl.h>
#include <GL/glut.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

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
	//vetanas arriba
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-1,0.9);
		glVertex2f(-2.5,1.2);
		glVertex2f(-2.5,2.5);
		glVertex2f(-1,2.2);
		glVertex2f(-1,0.9);
	glEnd();
	//marcos
		glBegin(GL_LINE_STRIP);
			glColor3f(0,0,0);
				glVertex2f(-1.10,1.02);
				glVertex2f(-2.4,1.3);
				glVertex2f(-2.4,2.4);
				glVertex2f(-1.10,2.15);
				glVertex2f(-1.10,1.02);
			glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-3,1.3);
		glVertex2f(-4.5,1.6);
		glVertex2f(-4.5,2.8);
		glVertex2f(-3,2.5);
		glVertex2f(-3,1.3);
	glEnd();
		//Marco
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2f(-3.10,1.4);
			glVertex2f(-4.4,1.7);
			glVertex2f(-4.4,2.7);
			glVertex2f(-3.10,2.4);
			glVertex2f(-3.10,1.4);
		glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(0.2,1);
		glVertex2f(0.2,1.98);
		glVertex2f(0.8,2.55);
		glVertex2f(0.8,1.6);
		glVertex2f(0.2,1);
	glEnd();
		//Marco
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2f(0.3,1.2);
			glVertex2f(0.3,1.88);
			glVertex2f(0.7,2.30);
			glVertex2f(0.7,1.65);
			glVertex2f(0.3,1.2);
		glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(2.5,1.5);
		glVertex2f(2.5,2.9);
		glVertex2f(3.5,3.5);
		glVertex2f(3.5,2.1);
		glVertex2f(2.5,1.5);
	glEnd();
		//Marco
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2f(2.6,1.65);
			glVertex2f(2.6,2.8);
			glVertex2f(3.4,3.30);
			glVertex2f(3.4,2.15);
			glVertex2f(2.6,1.65);
		glEnd();
	//chimenea
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-2,5.65);
		glVertex2f(-2,6.1);
		glVertex2f(-1.5,6);
		glVertex2f(-1.5,5.5);
		glVertex2f(-1.1,5.70);
		glVertex2f(-1.1,6.25);
		glVertex2f(-1.5,6);
		glVertex2f(-2,6.1);
		glVertex2f(-1.55,6.30);
		glVertex2f(-1.1,6.25);
		glVertex2f(-1.1,5.70);
		glVertex2f(-1.5,5.5);
		glVertex2f(-1.8,5.8);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-1.8,5.8);
		glVertex2f(-3,5);
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
		glVertex2f(-1.1,6.25);
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
	glEnd();
	//Garaje
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-0.5,-2.80);
		glVertex2f(0,-3);
	glEnd();
	//Ventana
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(-3.5,-2.5);
		glVertex2f(-3.5,-3.5);
		glVertex2f(-4,-3.3);
		glVertex2f(-4,-2.3);
		glVertex2f(-3.5,-2.5);
	glEnd();
		//Marco
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2f(-3.53,-2.53);
			glVertex2f(-3.53,-3.45);
			glVertex2f(-3.95,-3.27);
			glVertex2f(-3.95,-2.37);
			glVertex2f(-3.53,-2.53);
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
		
		
		//Divisiones ventanas
		glVertex2f(-1.8,1.2);
		glVertex2f(-1.8,2.27);
		glVertex2f(-1.75,1.18);
		glVertex2f(-1.75,2.25);
		
		glVertex2f(-3.8,1.55);
		glVertex2f(-3.8,2.57);
		glVertex2f(-3.75,1.53);
		glVertex2f(-3.75,2.57);
		
		glVertex2f(2.80,1.75);
		glVertex2f(2.80,2.95);
		glVertex2f(2.85,1.77);
		glVertex2f(2.85,2.97);
		
		glVertex2f(3.12,1.94);
		glVertex2f(3.12,3.09);
		glVertex2f(3.17,1.98); 	 		
		glVertex2f(3.17,3.15);
		
		glVertex2f(2.80,0.5);
		glVertex2f(2.80,-0.75);
		glVertex2f(2.85,0.53);
		glVertex2f(2.85,-0.70);
		
		glVertex2f(3.12,0.65);
		glVertex2f(3.12,-0.55); 
		glVertex2f(3.17,0.67); 	 		
		glVertex2f(3.17,-0.5);

		
	glEnd();
	//Puerta principal
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0,0);
		glVertex2f(0.25,-2.60);
		glVertex2f(0.25,-0.5);
		//glVertex2f(0.25,-0.3);
		//glVertex2f(0.25,-0.3);
		glVertex2f(0.5,-1.1);
		glVertex2f(1.0,-0.6);
		glVertex2f(0.75,0.0);
		glVertex2f(0.25,-0.5);
		glVertex2f(0.25,-2.67);
		glVertex2f(0.75,-2.05);
		glVertex2f(0.75,-0.85);
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
		//Marco
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0,0);
			glVertex2f(2.6,0.35);
			glVertex2f(2.6,-0.85);
			glVertex2f(3.4,-0.35); 		
			glVertex2f(3.4,0.85);
			glVertex2f(2.6,0.35); 		
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
