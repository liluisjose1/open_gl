/*
 * chorro.cpp
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
#include <math.h>

void display(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //dibujando ecuacion de la recta
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    GLfloat x,y,i,angulo;
    
    //for para que dibuje punto por punto la ecuacion para los limites de -4<x<4 
    for (i =-70; i <= 250; i+=0.001)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		x=0.5*cos(angulo);
		y=3+0.5*sin(angulo);
		glVertex2f(x,y);
	}
	glEnd();
	//lineas llave derecha
    glBegin(GL_LINE_STRIP);
		glVertex2f(0.5,2.95);
		glVertex2f(1.5,2.80);
		glVertex2f(1.5,3.20);
		glVertex2f(0.5,3.05);
	glEnd();
	
	//lineas llave izquierda
    glBegin(GL_LINE_STRIP);
		glVertex2f(-0.5,2.95);
		glVertex2f(-1.5,2.80);
		glVertex2f(-1.5,3.20);
		glVertex2f(-0.5,3.05);
	glEnd();

    //paralelas 
    glBegin(GL_LINES);
		glVertex2f(-0.18,2.0);
		glVertex2f(-0.18,2.53);
		glVertex2f(0.18,2.0);
		glVertex2f(0.18,2.53);
	glEnd();
    //horizontales 
    glBegin(GL_LINES);
		glVertex2f(-1.40,0.5);
		glVertex2f(-1.60,0.5);
		glVertex2f(-0.7,-0.29);
		glVertex2f(-1.3,-0.29);
		
		glVertex2f(1.4,0.5);
		glVertex2f(1.6,0.5);
		
		glVertex2f(0.7,-0.29);
		glVertex2f(1.6,-0.29);
		
	glEnd();
    //rosca y cuello
    glBegin(GL_LINE_STRIP);
		glVertex2f(-0.6,1.5);
		glVertex2f(-0.6,2.0);
		glVertex2f(0.6,2.0);
		glVertex2f(0.6,1.5);
	glEnd();
    //cuello
    glBegin(GL_LINE_STRIP);
		glVertex2f(-0.9,1.0);
		glVertex2f(-0.9,1.5);
		glVertex2f(0.9,1.5);
		glVertex2f(0.9,1.0);
	glEnd();
    //cuello derecha
    glBegin(GL_LINE_STRIP);
		glVertex2f(1.80,0.7);
		glVertex2f(2.1,0.7);
		glVertex2f(2.1,-0.5);
		glVertex2f(1.8,-0.5);
	glEnd();
			//giros izquierda
			  glBegin(GL_POINTS);
			for (i =270; i <= 360; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=-1.40+0.5*cos(angulo);
				y=1+0.5*sin(angulo);
				glVertex2f(x,y);
			}
			for (i =90; i <= 180; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=-1.60+0.5*cos(angulo);
				y=-0.5+sin(angulo);
				glVertex2f(x,y);
			}
			for (i =90; i <= 180; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=-1.3+0.2*cos(angulo);
				y=-0.5+0.2*sin(angulo);
				glVertex2f(x,y);
			}
			for (i =0; i <= 90; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=-0.7+0.2*cos(angulo);
				y=-0.5+0.2*sin(angulo);
				glVertex2f(x,y);
			}
			glEnd();
			//boquilla
			glBegin(GL_LINE_STRIP);
				glVertex2f(-2.1,-0.5);
				glVertex2f(-2.1,-0.9);
				glVertex2f(-1.5,-0.9);
				glVertex2f(-1.5,-0.5);
			glEnd();
	
	
	//media circunferencia centro
	  glBegin(GL_POINTS);
	for (i =180; i <= 360; i+=0.001)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		x=0.5*cos(angulo);
		y=-0.5+0.3*sin(angulo);
		glVertex2f(x,y);
	}
	glEnd();
	
	//giro derecha
	  glBegin(GL_POINTS);
	  
			for (i =90; i <= 180; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=0.7+0.2*cos(angulo);
				y=-0.5+0.2*sin(angulo);
				glVertex2f(x,y);
			}
			for (i =0; i <= 90; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=1.6+0.2*cos(angulo);
				y=-0.5+0.2*sin(angulo);
				glVertex2f(x,y);
			}
			
			for (i =270; i <= 360; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=1.6+0.2*cos(angulo);
				y=0.7+0.2*sin(angulo);
				glVertex2f(x,y);
			}
			for (i =180; i <= 270; i+=0.001)
			{
				angulo =i*M_PI/180.0f; //grados a radianes
				x=1.40+0.5*cos(angulo);
				y=1+0.5*sin(angulo);
				glVertex2f(x,y);
			}

			
	glEnd();
	
   glFlush ();
   glutSwapBuffers();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-4.0,4.0,-2.0,4.0,-4.0,4.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-800)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Chorro IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
