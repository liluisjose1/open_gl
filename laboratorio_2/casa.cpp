/*
 * casa.cpp
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

 
//Definimos variables
double rotate_y=25;
double rotate_x=-7;
double rotate_z=0;

 
GLfloat X = 0.0f;
GLfloat Y = -0.2f;
GLfloat Z = 0.0f;
GLfloat scale = 0.5f;

//Definición del modelo de una luz
GLfloat light_Ambient [4] = { 0.5, 0.6, 0.6, 1.0};
GLfloat light_Diffuse [4] = { 1.0, 1.0, 1.0, 1.0};
GLfloat light_Position [4] = {0.0, 7.0, -0.5, 10.0};
//Materiales
GLfloat verdeMaterial [4] = {0.0, 1.0, 0.0, 0.0 };
GLfloat rojoMaterial [4] = {1.0, 0.0, 0.0, 0.0 };
GLfloat azulMaterial [4] = {0.0, 0.0, 1.0, 0.0 };
GLfloat naranjaMaterial [4] = {1.0, 0.5, 0.0, 0.0 };
GLfloat blancoMaterial [4] = {1.0, 1.0, 1.0, 1.0 };

void luces(void){
    //glShadeModel(GL_SMOOTH);

    // Activamos la fuente de luz
		glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT0, GL_POSITION, light_Position );
}
void ejes ()
{
      glLineWidth(1);
      //EJE X 
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0); //ROJO
    glVertex3f( -1.5, 0.0, 0.0 );
    glVertex3f(  1.5, 0.0, 0.0 );
    glEnd();
      // EJE Y
    glBegin(GL_LINES);
    glColor3f(0.15, 0.85, 0.29); //VERDE
    glVertex3f( 0.0, -1.5, 0.0 );
    glVertex3f(  0.0, 1.5, 0.0 );
    glEnd();
      
      // EJE Z
    glBegin(GL_LINES);
    glColor3f(0.18, 0.14, 0.79); //AZUL
    glVertex3f(  0.0, 0.0, 1.5 );
    glVertex3f( 0.0, 0.0, -1.5 );
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
void dibujo(){
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoMaterial);
	glColor3f(1.0,1.0,1.0);
       //texturas
            
           texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/cesped.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                     
           texture[1] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/piso.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                     
           texture[2] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ladrillos.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                     
           texture[3] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/techo.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                     
           texture[4] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ventana1.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );     
                
           texture[5] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ventana2.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );        
                
           texture[6] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ventana3.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );  
                
           texture[7] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ventana4.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                
           texture[8] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/porton.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );                 
                
           texture[9] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/puerta.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );     
                
           texture[10] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/cafe.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                );
                
           texture[11] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/gris.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                 );
                
           texture[12] = SOIL_load_OGL_texture // cargamos la imagen
                (
           "images/casa/ventana5.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                 );
                                   
    //PISO
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(  1.5, 0.0,  1.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( -1.5, 0.0,  1.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( -1.5, 0.0, -1.5 );
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(  1.5, 0.0, -1.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED DERECHA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( 1.0, 1.2, -0.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 1.0, 1.2,  0.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 1.0, 0.0,  0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 1.0, 0.0, -0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED IZQUIERDA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -1.0, 1.2, -0.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( -1.0, 1.2,  0.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( -1.0, 0.0,  0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 0.0, -0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED FRENTE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -1.0, 1.2, -0.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(  1.0, 1.2, -0.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(  1.0, 0.0, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 0.0, -0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED ATRAS
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -1.0, 1.2, 0.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f(  1.0, 1.2, 0.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f(  1.0, 0.0, 0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 0.0, 0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TRIANGULO DERECHO
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 1.0, 1.2, 0.5 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( 1.0, 1.7, 0.0 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 1.0, 1.2,-0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TRIANGULO IZQUIERDO
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 1.2, 0.5 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( -1.0, 1.7, 0.0 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( -1.0, 1.2,-0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TECHO FRENTE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.05, 1.7,  0.0 );
		glTexCoord2f(2.0f, 1.0f);  glVertex3f( 1.05, 1.7,  0.0 );
		glTexCoord2f(2.0f, 0.0f);  glVertex3f( 1.05, 1.2, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.05, 1.2, -0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TECHO ATRAS
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.05, 1.7, 0.0 );
		glTexCoord2f(2.0f, 1.0f);  glVertex3f( 1.05, 1.7, 0.0 );
		glTexCoord2f(2.0f, 0.0f);  glVertex3f( 1.05, 1.2, 0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.05, 1.2, 0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //VENTANA IZQUIERDA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.8, 1.19, -0.52 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5, 1.2,  -0.52 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( -0.5, 0.85, -0.52 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.8, 0.84, -0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //VENTANA CENTRAL
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.18, 1.19,-0.52 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.00, 1.2,  -0.52 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.00, 0.8,  -0.52 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.18, 0.79,-0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //VENTANA DERECHA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.75, 1.2,  -0.52 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.35, 1.19, -0.52 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.35, 0.85, -0.52 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.75, 0.84, -0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //RECTANGULO VENTANA DERECHA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.85, 1.25, -0.52 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.25, 1.24, -0.52 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.25, 1.20, -0.52 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.85, 1.20, -0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TRIANGULO FRONTAL
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.85, 1.24, -0.52 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.60, 1.50, -0.52 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.25, 1.24, -0.52 );       
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //CONTORNO TRIANGULO FRONTAL
    
         //CUADRITO DERECHO
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.92, 1.25, -0.52 );
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.85, 1.24, -0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.85, 1.20, -0.52 );    
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.92, 1.19, -0.52 );      
		     glEnd();
         glDisable(GL_TEXTURE_2D);
    
         //CUADRITO IZQ
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.18, 1.25, -0.52 );
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.25, 1.24, -0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.25, 1.20, -0.52 );    
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.18, 1.19, -0.52 );      
		     glEnd();
         glDisable(GL_TEXTURE_2D);
    
         //PENDIENTE IZQ
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.18, 1.25, -0.52 );
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.55, 1.56, -0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.60, 1.50, -0.52 );    
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.18, 1.19, -0.52 );      
		     glEnd();
         glDisable(GL_TEXTURE_2D);
    
         //PENDIENTE DER
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.92, 1.25, -0.52 );
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.55, 1.56, -0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.48, 1.50, -0.52 );    
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.92, 1.19, -0.52 );      
		     glEnd();
         glDisable(GL_TEXTURE_2D);
    
    //TECHO DER VENTANA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.55, 1.56, -0.52 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.55, 1.56,-0.15 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.92, 1.19,-0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TECHO IZQ VENTANA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.55, 1.56, -0.52 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.55, 1.56,-0.15 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.19, 1.19,-0.52 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //VENTANA INFERIOR
    
         //FRONTAL
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[7]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_QUADS);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.7, 0.6, -0.6 );
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.3, 0.59, -0.6 );
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.3, 0.3,  -0.6 );    
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.7, 0.29,-0.6 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
         
         //LADO DER
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[12]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_QUADS);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.7, 0.6, -0.6 );
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.8, 0.57, -0.51 );
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.8, 0.3,  -0.51 );    
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.7, 0.29,-0.6 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
         
         //LADO IZQ
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[12]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_QUADS);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.3, 0.6, -0.6 );
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.25, 0.57, -0.51 );
		     glTexCoord2f(0.0f, 1.0f);  glVertex3f( 0.25, 0.3,  -0.51 );    
		     glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.3, 0.29,-0.6 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
         
         //TECHO DER VENTANA
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.7, 0.6, -0.6 );
		     glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.8, 0.57,-0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.55, 0.7,-0.52 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
         
         //TECHO IZQ VENTANA
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.4, 0.6, -0.6 );
		     glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.3, 0.58,-0.52 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.55, 0.7,-0.52 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
         
         //TECHO CENTRAL VENTANA
         glEnable(GL_TEXTURE_2D);
		     glBindTexture(GL_TEXTURE_2D, texture[11]);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		     glBegin(GL_POLYGON);
		     glColor3f(1.0,1.0,1.0);
		     glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.7, 0.6, -0.6 );
		     glTexCoord2f(0.5f, 0.5f);  glVertex3f( 0.3, 0.57,-0.6 );
		     glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.55, 0.7,-0.52 );    
		     glEnd();
         glDisable(GL_TEXTURE_2D);
      
    //TECHO COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -1.03, 0.7,-0.5 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.15, 0.7, -0.5 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.11, 0.4, -0.7 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.05, 0.4, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
         
    //PARED DERECHA COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.5f);  glVertex3f( -0.4, 0.4, -0.7 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( -0.4, 0.4, -0.5 );
		glTexCoord2f(0.5f, 0.0f);  glVertex3f( -0.4, 0.0, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.4, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED IZQUIERDA COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.3f);  glVertex3f( -1.0, 0.4, -0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( -1.0, 0.4, -0.5 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( -1.0, 0.0, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);   
      
    //PARED FRENTE COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.5f);  glVertex3f( -1.0, 0.4, -0.7 );
		glTexCoord2f(0.5f, 0.5f);  glVertex3f( -0.4, 0.4, -0.7 );
		glTexCoord2f(0.5f, 0.0f);  glVertex3f( -0.4, 0.0, -0.7 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -1.0, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PORTON COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f( -0.9, 0.4, -0.71 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( -0.5, 0.4, -0.71 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( -0.5, 0.0, -0.71 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.9, 0.0, -0.71 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
     //PUERTA PRINCIPAL
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 1.0f);  glVertex3f(-0.35, 0.45, -0.51 );
		glTexCoord2f(1.0f, 1.0f);  glVertex3f( 0.0, 0.45, -0.51 );
		glTexCoord2f(1.0f, 0.0f);  glVertex3f( 0.0, 0.0, -0.51 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-0.35, 0.0, -0.51 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TRIANGULO DERECHO COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( -0.4, 0.4,-0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( -0.4, 0.7,-0.5 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( -0.4, 0.0,-0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TRIANGULO IZQUIERDO COCHERA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.4, -0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( -1.0, 0.7,-0.5 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( -1.0, 0.4,-0.5 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED DERECHA BASE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.3f);  glVertex3f( 0.2, 0.2, -0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( 0.2, 0.2, -0.5 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( 0.2, 0.0, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.2, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED FRENTE BASE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.3f);  glVertex3f( 0.05, 0.2, -0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( 0.2, 0.2, -0.7 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( 0.2, 0.0, -0.7 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.05, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //PARED IZQUIERDA BASE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.3f);  glVertex3f( 0.05, 0.2, -0.7 );
		glTexCoord2f(0.3f, 0.3f);  glVertex3f( 0.05, 0.2, -0.5 );
		glTexCoord2f(0.3f, 0.0f);  glVertex3f( 0.05, 0.0, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.05, 0.0, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);  
    
    //PARED ENCIMA BASE
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_POLYGON);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.0f, 0.2f);  glVertex3f( 0.05, 0.2, -0.7 );
		glTexCoord2f(0.2f, 0.2f);  glVertex3f( 0.05, 0.2, -0.5 );
		glTexCoord2f(0.2f, 0.0f);  glVertex3f( 0.2, 0.2, -0.5 );    
		glTexCoord2f(0.0f, 0.0f);  glVertex3f( 0.2, 0.2, -0.7 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //POSTE PUERTA
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[11]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glLineWidth(10.0);
        glBegin(GL_LINES);
   		glColor3f( 1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.07,0.2,-0.68);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.07,0.43,-0.68);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //TUBERIA LATERAL
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[11]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glLineWidth(6.0);
        
        glBegin(GL_LINES);
   		glColor3f( 1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.03,0.0,-0.4);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.03,0.97,-0.4);
        glEnd();
        
        glBegin(GL_LINES);
   		glColor3f( 1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.03,1.1,-0.52);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.03,1.22,-0.52);
        glEnd();
        
        glBegin(GL_LINES);
   		glColor3f( 1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.03,0.95,-0.4);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.03,1.1,-0.52);
        glEnd();
        
    glDisable(GL_TEXTURE_2D);
    
    
    }
    
void display()
{   
    //  Borrar pantalla y Z-buffer
    glClearColor(1.0,1.0,1.0,1.0);;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix(); 
    //funciones
    movimiento();
    //ejes();
    luces();
    dibujo();
    glPopMatrix();
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
   //glClearColor (0.0, 0.0, 0.0, 0.0);
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
    glutInitWindowSize (600, 600);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-600)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    
   // init();
   //luces();
    // Crear ventana
    glutCreateWindow("Casa Controlada por Teclas AG18");
    
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    //glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
