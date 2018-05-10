#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


GLuint texture[0];

 
//Definimos variables
double rotate_y=45;
double rotate_x=-21;
double rotate_z=0;

 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.5f;

//Definición del modelo de una luz
GLfloat light_Ambient [4] = { 0.2, 0.2, 0.2, 1.0};
GLfloat light_Diffuse [4] = { 1.0, 1.0, 1.0, 1.0};
GLfloat reflector1 [4] = {0.0, 3.0, -2.0, 5.0};
GLfloat reflector2 [4] = {0.0, 3.0, 2.0, 5.0};
//Materiales
GLfloat blancoMaterial [4] = {1.0, 1.0, 1.0, 0.0 };

//luces para relfector1
void luces(void){
    //glShadeModel(GL_SMOOTH);

    // Activamos la fuente de luz
	glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT0, GL_POSITION, reflector1 );
        
}
//luces para relfector1
void luces2(void){
    //glShadeModel(GL_SMOOTH);

    // Activamos la fuente de luz
	glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT1, GL_POSITION, reflector2 );
        
}

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
void dibujo(){
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoMaterial);
    
            //texturas
                texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/cesped.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[1] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/cesped1.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                     
                texture[2] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/gradas.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[3] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/pared.png",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[4] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/banner.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[5] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/balla.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                texture[6] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/techo.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                     
                texture[7] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/ues.png",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                
                texture[8] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "images/estadio/luces.png",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
                     
    //Cesped exterior
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBegin(GL_QUADS);
		glColor3f(0.24, 0.63, 0.34);
		glTexCoord2f(0.0f,   0.0f);     glVertex3f(  1.5, 0.0, 1.4 );
		glTexCoord2f(20.0f, 0.0f);      glVertex3f(  -1.7, 0.0, 1.4 );
		glTexCoord2f(20.0f, 20.0f); glVertex3f(  -1.7, 0.0, -1.4 );
		glTexCoord2f(0.0f,  20.0f);   glVertex3f(  1.5, 0.0, -1.4 );    
		glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //Cesped interior
    glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glLineWidth(2.5);
		glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0f, 0.0f);   glVertex3f(  0.9, 0.0001, 0.5 );
		glTexCoord2f(2.0f, 0.0f);   glVertex3f(  -0.9, 0.0001, 0.5 );
		glTexCoord2f(2.0f, 2.0f);   glVertex3f(  -0.9, 0.0001, -0.5 );
		glTexCoord2f(0.0f, 2.0f);   glVertex3f(  0.9, 0.0001, -0.5 );
		glEnd();
    glDisable(GL_TEXTURE_2D);
      
      //Lineas
    glLineWidth(2.5);
    glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  0.9, 0.0, 0.5 );
		glVertex3f(  -0.9, 0.0, 0.5 );
		glVertex3f(  -0.9, 0.0, -0.5 );
		glVertex3f(  0.9, 0.0, -0.5 );
    glEnd();
        
    glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  0.0, 0.0, 0.5 );
		glVertex3f(  0.0, 0.0, -0.5 );
    glEnd();
        
        //circulos 
    glBegin(GL_LINE_LOOP);
      for (float i = 0; i <2*M_PI ; i+=0.001)
      {
          float x,z;
          x=0.1*cos(i);
          z=0.1*sin(i);
           glVertex3f(x, 0.0, z);
      }
    glEnd();
    glBegin(GL_LINE_LOOP);
      for (float i = M_PI/2; i <3*M_PI/2 ; i+=0.001)
      {
          float x,z;
          x=0.1*cos(i);
          z=0.1*sin(i);
           glVertex3f(0.5+x, 0.0, z);
      }
    glEnd();
    glBegin(GL_LINE_LOOP);
      for (float i = 3*M_PI/2; i <2*M_PI ; i+=0.001)
      {
          float x,z;
          x=0.1*cos(i);
          z=0.1*sin(i);
           glVertex3f(-0.5+x, 0.0, z);
      }
      for (float i = 0; i <0.5*M_PI ; i+=0.001)
      {
          float x,z;
          x=0.1*cos(i);
          z=0.1*sin(i);
           glVertex3f(-0.5+x, 0.0, z);
      }
    glEnd();
    //banner izquierda
     glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.2, 0.1, -0.7);
        glTexCoord2f(10.0f, 1.0f); glVertex3f(  -1.2, 0.1, 0.7);
        glTexCoord2f(10.0f, 0.0f); glVertex3f(  -1.2, 0.0, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.2, 0.0, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);  
          //Gradas
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.5,0.2,-0.7);
        glTexCoord2f(4.0f, 1.0f); glVertex3f(  -1.5, 0.2, 0.7);
        glTexCoord2f(4.0f, 0.0f); glVertex3f(  -1.20001, 0.0, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.20001,0.0,-0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);
          //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.5, 0.5, -0.7);
        glTexCoord2f(4.0f, 1.0f); glVertex3f(  -1.5, 0.5, 0.7);
        glTexCoord2f(4.0f, 0.0f); glVertex3f(  -1.5, 0.2, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.5, 0.2, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);
          //gradas arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.5f); glVertex3f( -1.6, 0.6, -0.7);
        glTexCoord2f(4.0f, 0.5f); glVertex3f( -1.6, 0.6, 0.7);
        glTexCoord2f(4.0f, 0.0f); glVertex3f( -1.5, 0.5, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.5, 0.5, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);
              //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.6, 0.7, -0.7);
        glTexCoord2f(4.0f, 1.0f); glVertex3f( -1.6, 0.7, 0.7);
        glTexCoord2f(4.0f, 0.0f); glVertex3f( -1.6, 0.6, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.6, 0.6, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);
            //techo
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.6, 0.7, -0.7);
        glTexCoord2f(15.0f, 0.0f); glVertex3f(  -1.6, 0.7, 0.7);
        glTexCoord2f(15.0f, 1.0f); glVertex3f( -1.4, 0.8, 0.7);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.4, 0.8, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    //paredes exteriores
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.60001, 0.7, 0.70001 );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  -1.60001, 0.7, -0.70001 );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  -1.60001, 0.0, -0.70001);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.60001, 0.0, 0.70001 );
        glEnd();
    glDisable(GL_TEXTURE_2D);
    
    
    //frente
      //banner
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.2, 0.1, 0.7);
        glTexCoord2f(10.0f, 1.0f); glVertex3f(  1.2, 0.1, 0.7);
        glTexCoord2f(10.0f, 0.0f); glVertex3f(  1.2, 0.0, 0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.2, 0.0, 0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);      
      //Gradas
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  1.2, 0.0, 0.7);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  -1.2, 0.0, 0.7);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  -1.2, 0.2, 1.2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.2, 1.2);
        glEnd();
    glDisable(GL_TEXTURE_2D);
       
      //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.2, 0.2, 1.2);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.2, 1.2);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  1.2, 0.5, 1.2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.2, 0.5, 1.2);
        glEnd();
    glDisable(GL_TEXTURE_2D);
      //gradas arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.2, 0.5, 1.2);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.5, 1.2);
        glTexCoord2f(5.0f, 0.5f); glVertex3f(  1.2, 0.6, 1.3);
        glTexCoord2f(0.0f, 0.5f); glVertex3f( -1.2, 0.6, 1.3);
        glEnd();
    glDisable(GL_TEXTURE_2D);
      //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.2, 0.6, 1.3);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.6, 1.3);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  1.2, 0.7, 1.3);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.2, 0.7, 1.3);
        glEnd();
    glDisable(GL_TEXTURE_2D);
        //techo
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.7, 1.3);
        glTexCoord2f(15.0f, 0.0f); glVertex3f(  -1.2, 0.7, 1.3);
        glTexCoord2f(15.0f, 1.0f); glVertex3f( -1.2, 0.8, 1.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  1.2, 0.8, 1.0);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    //atras
      //banner
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(    1.2, 0.1, -0.7);
        glTexCoord2f(10.0f, 1.0f); glVertex3f(  -1.2, 0.1, -0.7);
        glTexCoord2f(10.0f, 0.0f); glVertex3f(  -1.2, 0.0, -0.7);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.0, -0.7);
        glEnd();
    glDisable(GL_TEXTURE_2D);      
      //Gradas
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  1.2, 0.0, -0.7);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  -1.2, 0.0, -0.7);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  -1.2, 0.2, -1.2);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.2, -1.2);
        glEnd();
    glDisable(GL_TEXTURE_2D);
       
      //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.2, 0.2, -1.2);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.2, -1.2);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  1.2, 0.5, -1.2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.2, 0.5, -1.2);
        glEnd();
    glDisable(GL_TEXTURE_2D);
      //gradas arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.2, 0.5, -1.2);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.5, -1.2);
        glTexCoord2f(5.0f, 0.5f); glVertex3f(  1.2, 0.6, -1.3);
        glTexCoord2f(0.0f, 0.5f); glVertex3f( -1.2, 0.6, -1.3);
        glEnd();
    glDisable(GL_TEXTURE_2D);
      //pared arriba
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.2, 0.6, -1.3);
        glTexCoord2f(5.0f, 0.0f); glVertex3f(  1.2, 0.6, -1.3);
        glTexCoord2f(5.0f, 1.0f); glVertex3f(  1.2, 0.7, -1.3);
        glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.2, 0.7, -1.3);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    //techo
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[6]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.7, -1.3);
        glTexCoord2f(15.0f, 0.0f); glVertex3f(  -1.2, 0.7, -1.3);
        glTexCoord2f(15.0f, 1.0f); glVertex3f( -1.2, 0.8, -1.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  1.2, 0.8, -1.0);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    
    //paredes exteriores
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  -1.2, 0.0, -1.30001 );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  -1.2, 0.7, -1.30001 );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  1.2, 0.7, -1.30001 );
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  1.2, 0.0, -1.30001 );
        glEnd();
    glDisable(GL_TEXTURE_2D);
    //paredes exteriores
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[7]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(  -1.2, 0.0, 1.30001 );
        glTexCoord2f(1.0f, 1.0f); glVertex3f(  -1.2, 0.7, 1.30001 );
        glTexCoord2f(0.0f, 1.0f); glVertex3f(  1.2, 0.7, 1.30001 );
        glTexCoord2f(0.0f, 0.0f); glVertex3f(  1.2, 0.0, 1.30001 );
        glEnd();
    glDisable(GL_TEXTURE_2D);
    
      //cubriendo pared
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(1.2,0.0,1.3);
		glVertex3f(1.2,0.6,1.3);
		glVertex3f(1.2, 0.5, 1.2);
		glVertex3f(1.2, 0.2, 1.2);
		glVertex3f(1.2, 0.0, 0.7);
    glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(-1.2,0.0,1.3);
		glVertex3f(-1.2,0.6,1.3);
		glVertex3f(-1.2, 0.5, 1.2);
		glVertex3f(-1.2, 0.2, 1.2);
		glVertex3f(-1.2, 0.0, 0.7);
    glEnd();
      //cubriendo pared
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(1.2,0.0,-1.3);
		glVertex3f(1.2,0.6,-1.3);
		glVertex3f(1.2, 0.5, -1.2);
		glVertex3f(1.2, 0.2, -1.2);
		glVertex3f(1.2, 0.0, -0.7);
    glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(-1.2,0.0,-1.3);
		glVertex3f(-1.2,0.6,-1.3);
		glVertex3f(-1.2, 0.5, -1.2);
		glVertex3f(-1.2, 0.2, -1.2);
		glVertex3f(-1.2, 0.0, -0.7);
    glEnd();
      //cubriendo pared
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(-1.6,0.0,-0.7);
		glVertex3f(-1.6,0.6,-0.7);
		glVertex3f(-1.5,0.5,-0.7);
		glVertex3f(-1.5,0.2,-0.7);
		glVertex3f(-1.2,0.0,-0.7);
    glEnd();
    glBegin(GL_POLYGON);
		glColor3f(0.26, 0.26, 0.26);
		glVertex3f(-1.6,0.0,0.7);
		glVertex3f(-1.6,0.6,0.7);
		glVertex3f(-1.5,0.5,0.7);
		glVertex3f(-1.5,0.2,0.7);
		glVertex3f(-1.2,0.0,0.7);
    glEnd();
      //Areas
    glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  0.9, 0.0, 0.3 );
		glVertex3f(  0.5, 0.0, 0.3 );
		glVertex3f(  0.5, 0.0, -0.3 );
		glVertex3f(  0.9, 0.0, -0.3 );
    glEnd();
    glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  0.9, 0.0, 0.2 );
		glVertex3f(  0.65, 0.0, 0.2 );
		glVertex3f(  0.65, 0.0, -0.2 );
		glVertex3f( 0.9, 0.0, -0.2 );
    glEnd();

    glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  -0.9, 0.0, 0.3 );
		glVertex3f(  -0.5, 0.0, 0.3 );
		glVertex3f(  -0.5, 0.0, -0.3 );
		glVertex3f(  -0.9, 0.0, -0.3 );
    glEnd();
        
    glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  -0.9, 0.0, 0.2 );
		glVertex3f(  -0.65, 0.0, 0.2 );
		glVertex3f(  -0.65, 0.0, -0.2 );
		glVertex3f( -0.9, 0.0, -0.2 );
    glEnd();
    
    //REFLECTORES
    //Luces
    //Frente
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[8]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( -1.55,0.90,0.9 );
		glTexCoord2f(1.0f, 1.0f); glVertex3f( -1.55,1.1,0.9 );
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.25,1.12,1.11 );
		glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.25,0.92,1.11 );
		glEnd();
	glDisable(GL_TEXTURE_2D);
	    //atras
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture[8]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
		glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( -1.55,0.90,-0.9 );
		glTexCoord2f(1.0f, 1.0f); glVertex3f( -1.55,1.1,-0.9 );
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.25,1.12,-1.11 );
		glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.25,0.92,-1.11 );
		glEnd();
	glDisable(GL_TEXTURE_2D);
    //Atras
    glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( -1.55,0.90,0.902 );
		glTexCoord2f(1.0f, 1.0f); glVertex3f( -1.55,1.1,0.902 );
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.25,1.12,1.112 );
		glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.25,0.92,1.112 );
	glEnd();
	
    //Poste
	glLineWidth(5.0);
	glBegin(GL_LINES);
   	glColor3f(0.5, 0.5, 0.5);
   	//Izquierdo Central
	glVertex3f( -1.50,0.0,0.95);
	glVertex3f(  -1.50,1.0,0.95 );
	//Derecho Central
	glVertex3f( -1.35,0.0,1.05 );
	glVertex3f(  -1.35,1.015,1.05 );
	glEnd();
    //Luces

    //Atras
    glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( -1.55,0.90,-0.902 );
		glTexCoord2f(1.0f, 1.0f); glVertex3f( -1.55,1.1,-0.902 );
		glTexCoord2f(0.0f, 1.0f); glVertex3f( -1.25,1.12,-1.112 );
		glTexCoord2f(0.0f, 0.0f); glVertex3f( -1.25,0.92,-1.112 );
	glEnd();
	
    //Poste
	glLineWidth(5.0);
	glBegin(GL_LINES);
   	glColor3f(0.5, 0.5, 0.5);
   	//Izquierdo Central
	glVertex3f( -1.50,0.0,-0.95);
	glVertex3f(  -1.50,1.0,-0.95 );
	//Derecho Central
	glVertex3f( -1.35,0.0,-1.05 );
	glVertex3f(  -1.35,1.015,-1.05 );
	glEnd();
    
        //porterias
     glLineWidth(0.5);
    glBegin(GL_LINE_LOOP);
   		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  0.9, 0.0, 0.15 );
		glVertex3f(  0.9, 0.1, 0.15 );
		glVertex3f(  0.9, 0.1, -0.15 );
		glVertex3f( 0.9, 0.0, -0.15 );
    glEnd();
    glBegin(GL_LINE_LOOP);
   		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(  -0.9, 0.0, 0.15 );
		glVertex3f(  -0.9, 0.1, 0.15 );
		glVertex3f(  -0.9, 0.1, -0.15 );
		glVertex3f( -0.9, 0.0, -0.15 );
    glEnd();
        
    
    }
void display()
{
    //  Borrar pantalla y Z-buffer
    glClearColor(0.0, 0.0, 0.0,1.0);;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     
     glPushMatrix();
     //funciones
      movimiento();
     // ejes();
		//luces();
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
     //encendiendo luz reflector1
    case 'l':
        luces();
        break;
    //apagando luz reflector1
    case 'L':
    	//glDisable (GL_LIGHTING);
        glDisable (GL_LIGHT0);
        break;
    //encendiendo luz reflector2
    case 'k':
        luces2();
        break;
    //apagando luz reflector2
    case 'K':
		//glDisable (GL_LIGHTING);
        glDisable (GL_LIGHT1);
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
    glutInitWindowSize (1500, 900);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-1500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-900)/2);
    
   // init();
    // Crear ventana
    glutCreateWindow("Cancha Controlada por Teclas AG18");
    
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
