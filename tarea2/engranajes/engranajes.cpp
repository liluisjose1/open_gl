/*
 * engranajes.cpp
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
    GLfloat angulo,angulo1,i; 
    glColor3f(0,0,0);
	//negro
	//dientes
	glBegin(GL_QUADS);
	for (i = 0; i <= 2*M_PI; i+=M_PI/5)
	{
		angulo = i ;
		glVertex2f(1*cos(angulo),1+1*sin(angulo));
		glVertex2f(1*cos(angulo+M_PI/10),1+1*sin(angulo+M_PI/10));
		glVertex2f(0.7*cos(angulo+M_PI/10),1+0.7*sin(angulo+M_PI/10));
		glVertex2f(0.7*cos(angulo),1+0.7*sin(angulo));
		
	}
	glEnd();
	//Aros
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 2*M_PI; i+=0.01)
		{
			angulo = i ;
			glVertex2f(0.3*cos(angulo),1+0.3*sin(angulo));
			glVertex2f(0.7*cos(angulo),1+0.7*sin(angulo));
		}
		glEnd();
	
	//Verde
	//dientes
	glColor3f(0.13,0.38,0.24);
	glBegin(GL_QUADS);
	for (i = 0; i <= 2*M_PI; i+=M_PI/5)
	{
		angulo = i ;
		glVertex2f(-1.7+1*cos(angulo),1*sin(angulo));
		glVertex2f(-1.7+1*cos(angulo+M_PI/10),1*sin(angulo+M_PI/10));
		glVertex2f(-1.7+0.7*cos(angulo+M_PI/10),0.7*sin(angulo+M_PI/10));
		glVertex2f(-1.7+0.7*cos(angulo),0.7*sin(angulo));
		
	}
	glEnd();
	//Aros
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 2*M_PI; i+=0.01)
		{
			angulo = i ;
			glVertex2f(-1.7+0.3*cos(angulo),0.3*sin(angulo));
			glVertex2f(-1.7+0.7*cos(angulo),0.7*sin(angulo));
		}
		glEnd();
	
	//Gris
	//dientes
	glColor3f(0.61,0.61,0.61);
	glBegin(GL_QUADS);
	for (i = 0; i <= 2*M_PI; i+=M_PI/5)
	{
		angulo = i ;
		glVertex2f(1.7+1*cos(angulo),1*sin(angulo));
		glVertex2f(1.7+1*cos(angulo+M_PI/10),1*sin(angulo+M_PI/10));
		glVertex2f(1.7+0.7*cos(angulo+M_PI/10),0.7*sin(angulo+M_PI/10));
		glVertex2f(1.7+0.7*cos(angulo),0.7*sin(angulo));
		
	}
	glEnd();
	//Aros
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= 2*M_PI; i+=0.01)
		{
			angulo = i ;
			glVertex2f(1.7+0.3*cos(angulo),0.3*sin(angulo));
			glVertex2f(1.7+0.7*cos(angulo),0.7*sin(angulo));
		}
		glEnd();

		
	glutSwapBuffers();
	glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //definiendo los limites de los ejes
    glOrtho(-3.0,3.0,-3.0,3.0,-3.0,3.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
    glutCreateWindow ("Engranajes IM15005");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
