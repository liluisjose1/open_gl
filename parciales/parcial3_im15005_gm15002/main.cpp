// Creado por 

//Luis Iraheta IM15005
//Yenifer Garcia GM15002

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

GLuint texture[0];
// XZ posicion de la camara
float X=-5.5f,Z=90.0f;

int dirObjectZ=100; 
float goles=0.0f;
float score=5;

GLUquadricObj *sphere;	

//-----------------------------------------------
//  Porteria
//-----------------------------------------------
void porteria()
{
	glColor3f(1.0,1.0,1.0);
	glPushMatrix(); 
    glTranslatef(-3.5,0.0,85 );
	glRotatef(-90.0,1.0,0.0,0.0);
	glutSolidCylinder(0.05,2.05,100,100);
	glEnd();
	glPopMatrix(); 
	
	glPushMatrix(); 
	glTranslatef(-3.5,2.0,85 );
    glColor3f(1,1,1);
	glRotatef(-90.0,0.0,1.0,0.0);
	glutSolidCylinder(0.05,4,100,100);
	glEnd();
	glPopMatrix(); 
	
	glPushMatrix();
	glTranslatef(-7.5,0.0,85 );
    glColor3f(1,1,1);
	glRotatef(-90.0,1.0,0.0,0.0);
	glutSolidCylinder(0.05,2.05,100,100);
	glEnd();
	glPopMatrix(); 
	
	
}
//-----------------------------------------------
//  Graderias
//-----------------------------------------------
void graderias(){
	    glPushMatrix();

	texture[1] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/fondo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	
  glColor3f(1.0f, 1.0f , 1.0f);
  glTexCoord2f(0.0f, 1.0f);  glVertex3f(-50.0f, 0.0f, 80.0f);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(-50.0f, 20.0f, 80.0f);
  glTexCoord2f(1.0f, 0.0f); glVertex3f( 50.0f, 20.0f, 80.0f);
  glTexCoord2f(0.0f, 0.0f); glVertex3f( 50.0f, 0.0f, 80.0f);
  glEnd();
  glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
//-----------------------------------------------
//  Portero Cubo
//-----------------------------------------------
void portero()
{
  glPushMatrix();
  glTranslatef(-5.25,0.8f, 85);
  glColor3f(0.6,0.8,0.89);
  glutSolidCube(1.0);
  glPopMatrix();
}
//-----------------------------------------------
//  Plano "Cancha"
//-----------------------------------------------
void plano(){

    glPushMatrix();
    texture[2] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/images.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f , 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-25.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 50.0f); glVertex3f(-25.0f, 0.0f, 105.0f);
	glTexCoord2f(50.0f, 50.0f); glVertex3f( 15.0f, 0.0f, 105.0f);
	glTexCoord2f(40.0f, 0.0f); glVertex3f( 15.0f, 0.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


//-----------------------------------------------
//  Pelota
//-----------------------------------------------
void pelota (float r)
{
    glPushMatrix();
    texture[0] = SOIL_load_OGL_texture ("../img/ball.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    
	glRotatef(-90, 1.0, 0.0, 0.0);

	sphere = gluNewQuadric();
	gluQuadricTexture(sphere,texture[1]);
	gluQuadricDrawStyle( sphere, GLU_FILL);
	gluQuadricNormals( sphere, GLU_SMOOTH);
	gluQuadricOrientation( sphere, GLU_OUTSIDE);
	gluSphere(sphere, r, 200, 200);
	glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
//-----------------------------------------------
//  Camara
//-----------------------------------------------
void camara(int w, int h)
{
	if (h == 0)
	h = 1;
	float proporcion = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, proporcion, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

//-----------------------------------------------
//  Animaciones
//-----------------------------------------------
int animating = 0; 

void pauseAnimation() {
        animating = 0;
}
void updateFrame() {
        if(dirObjectZ==81)
        {
                pauseAnimation();
                dirObjectZ=100;
        }
        dirObjectZ--;    

}

void timerFunction(int timerID) {
        // Invocamos la funcion para controlar el tiempo de la ejecucion de funciones
        if (animating) {
                updateFrame();
                glutTimerFunc(45, timerFunction, 0);
                glutPostRedisplay();
        }
}
void startAnimation() {
        // llamamos la función para iniciar la animación
        if ( !animating ) {
                animating = 1;
                glutTimerFunc(30, timerFunction, 1);         
        }      
}
//-----------------------------------------------
//  Textos
//-----------------------------------------------
char text1[60];
char text3[32];
void text(){
	glPushMatrix();
    glColor3f(1, 1, 1);
    glRasterPos3f( -4 ,5 , 90);
    for(int i = 0; text1[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text1[i]);
    glPopMatrix();
}
void text2(){
	glPushMatrix();
    sprintf(text3, "Intentos:%.0f" , score);
    glColor3f(1, 1, 1);
    glRasterPos3f( -10 ,5 , 90);
    for(int i = 0; text3[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text3[i]);
        glPopMatrix();
     glPopMatrix();
}

//-----------------------------------------------
//  Funcion controla colision, score y goleses
//-----------------------------------------------
void logica()
{
	 if(dirObjectZ<=82){
	  sprintf(text1, "Gooooool !");
	  score -=1;
	  pauseAnimation();
	  dirObjectZ=100;
	  
  }
  if (score==0){
	  pauseAnimation();
	  dirObjectZ=200;
  }
  if (X>=-5.5 && X<=-5.0 && dirObjectZ==86){
	  dirObjectZ=100;
	  sprintf(text1, "Fallaste !");
	  score -=1;
	  pauseAnimation();
  }
   if (score==0){
	  glPushMatrix();
	  sprintf(text1, "Fin de juego, presiona [c] para continuar");
	  glPopMatrix();
  }
}
//-----------------------------------------------
//  Escena portero y pelotas en movimiento
//-----------------------------------------------
void renderEscena(){
	
	portero();
		
	glPushMatrix();
	glTranslatef(X,1.0f, dirObjectZ);
	glColor3f(1.0f, 1.0f , 1.0f);
	pelota(0.2);
	glPopMatrix();
}
void display(void)
{
	glClearColor(0.0, 1.0, 1.0, 1.0);
  // Borrar Color and Depth Buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Reseteando transformaciones
  glLoadIdentity();

  
  // Posicionamiento de camara
  gluLookAt(X, 1.5f, 105, X, 1.0f, 80, 0.0f, 1.0f, 0.0f);

 //Invocando funciones	
	text2();
	text();
	plano();
	graderias();
	porteria();
	logica();
	renderEscena();


glutSwapBuffers();
glFlush();

}
//-----------------------------------------------
//  Teclas Normales
//-----------------------------------------------
void normalKeys(unsigned char key, int x, int y)
{

	if ( key == '1' && animating==0) 
			{
			startAnimation();
					
			}
	if ( key == 'c') 
			{
			sprintf(text1, "Inicio de juego, presiona [1] para continuar");
			score=5;	
			dirObjectZ=100;					
			}
	if (key == 27)
	  exit(0);
}
//-----------------------------------------------
//  Teclas Especiales
//-----------------------------------------------
void keyboard(int key, int xx, int yy)
{
  switch (key) {
    case GLUT_KEY_LEFT :
    if(X>=-6.5){
      X -= 0.5f;
  }
    break;
    case GLUT_KEY_RIGHT :
    if(X<=-4.5){
	  X += 0.5f;
  }
    break;
      case GLUT_KEY_UP :
      Z -= 0.5f;
    break;
      case GLUT_KEY_DOWN :
      Z += 0.5f;
    break;
    }
}

int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT));
  glutCreateWindow("Parcial 3 - Penalti"); 

  // register callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(camara);
  glutIdleFunc(display);
  glutKeyboardFunc(normalKeys);
  glutSpecialFunc(keyboard);
	
  sprintf(text1, "Inicio de juego, presiona [1] para continuar");
  // OpenGL init
  glEnable(GL_DEPTH_TEST);

  glutMainLoop();
  return 1;
}

