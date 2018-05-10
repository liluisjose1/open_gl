/*
 * conos.cpp
 * 
 * Copyright 2018 luis <luis@debian>
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


GLuint texture[0];
GLuint texture1[0];

 
//Definimos variables
double rotate_y=25;
double rotate_x=-21;
double rotate_z=0;

 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.4f;

void resize(int h, int w) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(0.0, 0, -900, 900);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

void ejes ()
{
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
    

    
} 
void movimiento()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Rotar en el Eje Y
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 1.0 );
    glTranslatef(X, Y, Z);  // Transladar en los 3 Ejes
    // Otras transformaciones
    glScalef(scale, scale, scale);
}
void cubo()
{
	
            //texturas
                texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "src/cesped1.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[1] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "src/agua.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[2] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "src/pared.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
       
    //plano abajo              
    //Cesped exterior
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.24, 0.63, 0.34);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.0, 1.0 );
		glTexCoord2f(20.0f, 0.0f);      glVertex3f(  -1.5, 0.0, 1.0 );
		glTexCoord2f(20.0f, 20.0f); glVertex3f(  -1.5, 0.0, -1.0 );
		glTexCoord2f(0.0f,  20.0f);   glVertex3f(  1.5, 0.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.24, 0.63, 0.34);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.3, 1.0 );
		glTexCoord2f(20.0f, 0.0f);      glVertex3f(  -1.5, 0.3, 1.0 );
		glTexCoord2f(20.0f, 20.0f); glVertex3f(  -1.5, 0.3, -1.0 );
		glTexCoord2f(0.0f,  20.0f);   glVertex3f(  1.5, 0.3, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.24, 0.63, 0.34);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.3, 1.0 );
		glTexCoord2f(20.0f, 0.0f);      glVertex3f(  -1.5, 0.3, 1.0 );
		glTexCoord2f(20.0f, 20.0f); 	glVertex3f(  -1.5, 0.0, 1.0 );
		glTexCoord2f(0.0f,  20.0f);   	glVertex3f(  1.5, 0.0, 1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.24, 0.63, 0.34);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.3, -1.0 );
		glTexCoord2f(20.0f, 0.0f);      glVertex3f(  -1.5, 0.3, -1.0 );
		glTexCoord2f(20.0f, 20.0f); 	glVertex3f(  -1.5, 0.0, -1.0 );
		glTexCoord2f(0.0f,  20.0f);   	glVertex3f(  1.5, 0.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PAREDES
    //DERECHA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		//glColor3f(0.0,0.0,0.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  1.5,1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  1.5, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  1.5, 0.0, 1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		//glColor3f(0.0,0.0,0.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.55, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  1.55, 1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  1.55, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  1.55, 0.0, 1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  1.5, 1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  1.55, 1.0, -1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  1.55, 0.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 1.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  1.5, 1.0, 1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  1.55, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  1.55, 1.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //IZQUIERDA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		//glColor3f(0.0,0.0,0.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  -1.5, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  -1.5,1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  -1.5, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  -1.5, 0.0, 1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		//glColor3f(0.0,0.0,0.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  -1.55, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  -1.55, 1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  -1.55, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  -1.55, 0.0, 1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  -1.5, 0.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  -1.5, 1.0, -1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  -1.55, 1.0, -1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  -1.55, 0.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  -1.5, 1.0, -1.0 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  -1.5, 1.0, 1.0 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  -1.55, 1.0, 1.0 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  -1.55, 1.0, -1.0 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //FRENTE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.5, 0.53, 0.53);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5555, 1.0, 1.01 );
		glTexCoord2f(1.0f, 0.0f);      glVertex3f(  -1.5555, 1.0, 1.01 );
		glTexCoord2f(1.0f, 1.0f); 	glVertex3f(  -1.5555, 0.0, 1.01 );
		glTexCoord2f(0.0f,  1.0f);   	glVertex3f(  1.5555, 0.0, 1.01 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    
    //RIO
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.35, 0.75, 0.8);

		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.30005, 0.2 );
		glTexCoord2f(10.0f, 0.0f);      glVertex3f(  -1.5, 0.30005, 0.2 );
		glTexCoord2f(10.0f, 1.0f); glVertex3f(  -1.5, 0.30005, -0.2 );
		glTexCoord2f(0.0f,  1.0f);   glVertex3f(  1.5, 0.30005, -0.2 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
}
void pinos(){
    
    //pinos
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.0, 0.33, 0.3);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.5,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                 
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(-0.33, 0.33, 0.3);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.2,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                 
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(-0.4, 0.3, -0.5);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                 
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(-0.4, 0.3, -0.5);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.4, 0.3, -0.5);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(-0.6, 0.33, -0.5);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.6, 0.33, -0.5);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.7, 0.33, -0.56);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.65, 0.33, -0.7);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(-0.65, 0.33, -0.7);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
    glPushMatrix();
		glColor3f(0.21, 0.46, 0.16);
		glTranslatef(0.65, 0.33, 0.7);
		glRotatef( 270, 1.0, 1.0, 1.0 );
		glutSolidCone(0.1,0.6,100,100);
		glColor3f(0.49, 0.39, 0.19);
		glutSolidCube(0.07);
    glPopMatrix();                    
            
}
    
void esfereas()
{
	//ESFERAS FONDO
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(0.8, 0.5, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(0.5, 0.6, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(0.2, 0.7, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(-0.8, 0.5, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(-0.5, 0.6, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
	 glPushMatrix();
		glColor3f(0.57, 0.59, 0.61);
		glTranslatef(-0.2, 0.4, 1.0);
		glutSolidSphere(0.1,100,100);
	 glPopMatrix(); 
		
		
            //texturas
                texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "src/roca.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
	
	    //Esferas
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[0]);
	    glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_T);
        glEnable(GL_TEXTURE_GEN_S);
		glColor3f(0.23, 0.26, 0.26);
		glTranslatef(0.8, 0.333, 0.0);
		glutSolidSphere(0.1,100,100);
		
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_2D);
    
    glPopMatrix(); 
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[0]);
	    glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_T);
        glEnable(GL_TEXTURE_GEN_S);
		glColor3f(0.23, 0.26, 0.26);
		glTranslatef(0.4, 0.333, 0.0);
		glutSolidSphere(0.1,100,100);
		
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_2D);
    
    glPopMatrix(); 
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[0]);
	    glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_T);
        glEnable(GL_TEXTURE_GEN_S);
		glColor3f(0.23, 0.26, 0.26);
		glTranslatef(-0.4, 0.333, 0.0);
		glutSolidSphere(0.1,100,100);
		
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_2D);
    
    glPopMatrix(); 
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[0]);
	    glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_T);
        glEnable(GL_TEXTURE_GEN_S);
		glColor3f(0.23, 0.26, 0.26);
		glTranslatef(-0.8, 0.333, 0.0);
		glutSolidSphere(0.1,100,100);
		
        glDisable(GL_TEXTURE_GEN_T);
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_2D);
    
    glPopMatrix(); 
}
void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     
     //glPushMatrix();
     //funciones
     glPushMatrix();
      movimiento();
     // ejes();
      cubo();
     
      pinos();
      esfereas();
glPopMatrix();	
      //glPopMatrix();
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
        rotate_y -= 8;
    //  Flecha arriba: rotación en eje X positivo 7 grados
    else if (key == GLUT_KEY_UP)
        rotate_x += 8;
    //  Flecha abajo: rotación en eje X negativo 7 grados
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 8;
    //  Tecla especial F2 : rotación en eje Z positivo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z += 8;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F2)
        rotate_z -= 8;
 
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
        scale-=0.1;
        break;
    case 'd':
        scale+=0.1;
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

 
void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-20.0,20.0,-20.0,20.0,-20.0,20.0);
} 
int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-900)/2,(glutGet(GLUT_SCREEN_HEIGHT)-900)/2);
    
   init();
    // Crear ventana
    glutCreateWindow("Bosque por Teclas AG18");
    
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
