#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h> 
#include <SOIL/SOIL.h>

//Definimos variables
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.5f;
GLfloat Z = 0.0f;
GLfloat scale = 1.4f;

GLuint texture[0];

void luz(void)
{
    // acitivamos la fuente de luz
     glShadeModel (GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TES
   
}

void reshape(int w, int h)
{
	//glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	// Activamos la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// "limpiamos" esta con la matriz identidad.
	glLoadIdentity();
	// Usamos proyeccion ortogonal
	glOrtho(-15, 10, -10, 10, -50.0, 50);
	//gluLookAt (15.0, 5.0, 15.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0);
	//glFrustum(-100, 100, -100.0, 100.0, 0.0, 90.0);
	//gluPerspective(30.0, 3.0, 1.0, 80.0);
	// Activamos la matriz de modelado/visionado.
	   //glMatrixMode(GL_MODELVIEW);
     //gluLookAt(5.0, 20.0, 20.0, 3.0, 4.0, 10.0, 0.0, 0.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	// "Limpiamos" la matriz
	glLoadIdentity();
}

void imagen (void)
{
	
    texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/pared1.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

     texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/pared2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
    texture[2] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/piso.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
      texture[3] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/venta.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
     texture[4] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/lado1.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
      texture[5] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/lado2.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
     
      texture[6] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/frente.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    
      texture[7] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "images/cuarto/mantel.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
 }
 
 void parametros(){
		imagen();
		glEnable(GL_TEXTURE_2D);

        //float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
}
 
 void cuarto(){   
	// allocate a texture name

   glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-5, 0.0, 0.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(7, 0.0,  0.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(7, 0.0, 15.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-5, 0.0,  15.0 );
    glEnd();
    
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-5.0, 0.0, 0.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-5.0, 4.0,  0.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-5.0, 4.0, 15.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-5.0, 0.0,  15.0 );
    glEnd();
    
   
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-5.0, 0.0, 0.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-5.0, 4.0,  0.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(7.0, 4.0, 0.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(7.0, 0.0,  0.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 1.7, 0.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 3.1,  0.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(2.0, 3.1, 0.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(2.0, 1.7,  0.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-5.0, 0.0, 14.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-5.0, 2.0,  14.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0, 2.0, 14.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.0,  14.0 );
    glEnd();
    
  
    
       glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-5.0, 0.0, 7.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-5.0, 2.0,  7.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0, 2.0, 7.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.0,  7.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 2.0, 14.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 2.0,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-5.0, 2.0, 13.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-5.0, 2.0,  14.0 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 2.0, 8.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 2.0,  7.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-5.0, 2.0, 7.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-5.0, 2.0,  8.0 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 2.0, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 1.7,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-4.0, 1.7, 13.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-4.0, 2.0,  13.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 2.0, 8.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 1.7,  8.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-4.0, 1.7, 8.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-4.0, 2.0,  8.0 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 1.7, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 1.7,  8.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-4.0, 1.7, 8.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-4.0, 1.7,  13.0 );
    glEnd();
    
      glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-4.0, 2.0, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-4.0, 2.0,  8.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-5.0, 2.0, 8.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-5.0, 2.0,  13.0 );
    glEnd();
    
      glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-4.0, 1.7, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-4.0, 1.7,  8.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-4.0, 2.0, 8.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-4.0, 2.0,  13.0 );
    glEnd();
}
  void sillon(){
		
      glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 0.0, 14.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 2.0,  14.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0, 2.0, 13.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.0,  13.0 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 0.0, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 1.7,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0, 1.7, 8.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.0,  8.0 );
    glEnd();
    
      glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
     glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(-1.0, 0.0, 8.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(-1.0, 2.0,  8.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(-1.0, 2.0, 7.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(-1.0, 0.0,  7.0 );
    glEnd();
}

void patasmesa(){

    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 0.0, 12.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.3,  12.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.2, 2.3, 12.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.2, 0.0,  12.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.2, 0.0, 12.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.2, 2.3,  12.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.2, 2.3, 11.7 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.2, 0.0,  11.7 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 0.0, 12.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.3,  12.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.0, 2.3, 11.7 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.0, 0.0,  11.7 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 0.0, 11.7 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.3,  11.7 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.2, 2.3, 11.7 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.2, 0.0,  11.7 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 2.3, 12.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.3,  11.7 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.2, 2.3, 11.7 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.2, 2.3,  12.0 );
    glEnd();
}

void mesa(){
	
	
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 2.4, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.1,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.8, 2.1, 13.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.8, 2.4,  13.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 2.4, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.1,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(5.0, 2.1, 6.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(5.0, 2.4,  6.0 );
    glEnd();
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(1.8, 2.4, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(1.8, 2.1,  13.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.8, 2.1, 6.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.8, 2.4,  6.0 );
    glEnd();
    
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 2.4, 6.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.1,  6.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.8, 2.1, 6.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.8, 2.4,  6.0 );
    glEnd();
    
      glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(5.0, 2.4, 13.0 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(5.0, 2.4,  6.0 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(1.8, 2.4, 6.0 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(1.8, 2.4,  13.0 );
    glEnd();
    
     glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0f, 0.0f);  glVertex3f(4.6, 2.401, 12.2 );
    glTexCoord2f(1.0f, 1.0f);  glVertex3f(4.6, 2.401,  6.8 );
    glTexCoord2f(0.0f, 1.0f);  glVertex3f(2.2, 2.401, 6.8 );
    glTexCoord2f(0.0f, 0.0f);  glVertex3f(2.2, 2.401,  12.2 );
    glEnd();
}

void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(1,1,1,1);
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

	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	parametros();
	cuarto();
	patasmesa();
	mesa();
	sillon();
	glPopMatrix ();
	
	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	glTranslatef(0.0 , 0.0, -5);
	patasmesa();
	glPopMatrix ();
	
	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	glTranslatef(-3.2 , 0.0, 0.0);
	patasmesa();
	glPopMatrix ();
	
	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	glTranslatef(-3.2 , 0.0, -5);
	patasmesa();
	glPopMatrix ();
	glEnd();
	
	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	glTranslatef(0.05 , -0.05, 0.05);
	mesa();
	glPopMatrix ();
	
	glPushMatrix ();
	glRotatef(30.0,10.0,-8.0,-2.0);
	glTranslatef(0.05 , 0.0, 0.0);
	sillon();
	glPopMatrix ();
	 
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
    else if (key == GLUT_KEY_F6)
        rotate_z += 7;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F7)
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
    case 27:
        exit(0);			// exit
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    //luz();
    glutCreateWindow("Mesa");
    glEnable(GL_DEPTH_TEST);
	
	glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);

    /////////////////////////////////////
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutMainLoop();
}
