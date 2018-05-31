#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <SDL2/SDL.h>


using namespace std;


float scale = 0.1;
int ResX = 1500, ResY = 500;

//Variables de Moviento de escena en ejeX
GLfloat X = 0.0f;
float Xob = 10.0;
float Xdino = -0.5;
//Variables de Moviento de escena en ejeY
GLfloat Y = -0.2f;
float Yob = 0.0f;
//Texto de nombre
// buffer and score
int buffer = 0;
GLfloat salto = 0.0;
//interrupciones
bool pause = false;
char text[32];
float velX = 0.1f, velY = 0.0f;
float posX = 10.0f, posY = 1.0f;
float posXtnt = 20.0f;
float posXbird = 30.0f;

GLuint texture[0];

void text1() {
	glPushMatrix();
	char text[32];
	sprintf(text, "Score:%d", buffer);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.8, 0.8);
	for (int i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	glPopMatrix();
}
void nameText1(char *s) {
    glColor3f(0, 0, 0);
    glRasterPos3f( -0.2 , 0.4 , 1);
    for(int i = 0; text[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void escena1() {
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(X, 0.0f, 0.0f);
	//texturas
	texture[0] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/dino1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(-20, 18);
	glTexCoord2f(30.0f, 1.0f);
	glVertex2f(20, 18);
	glTexCoord2f(30.0f, 0.0f);
	glVertex2f(20, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(-20, -10);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();


}
void escena0() {
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(X, 0.0f, 0.0f);
	//texturas
	texture[1] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/dino2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(-20, 30);
	glTexCoord2f(30.0f, 1.0f);
	glVertex2f(20, 30);
	glTexCoord2f(30.0f, 0.0f);
	glVertex2f(20, -10);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(-20, -10);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();


}
void win() {
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glTranslatef(0.0, 0.0f, 0.0f);
	//texturas
	texture[5] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/win.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(-5, 10);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(5, 10);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(5, -10);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(-5, -10);
	glEnd();
	glPopMatrix();
	glutPostRedisplay();


}
void objetos() {
	glPushMatrix();
		glScalef(scale, scale, scale);
	glTranslatef(posX, -2.0, 0.0f);
		texture[2] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/arbol.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0,4);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1,4);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1,0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0,0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
		glScalef(scale, scale, scale);
	glTranslatef(posXtnt, -2.0, 0.0f);
		texture[3] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/tnt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0,2);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1,2);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1,0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0,0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
		glScalef(scale, scale, scale);
	glTranslatef(posXbird, 5.0, 0.0f);
		texture[4] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/bird.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0,2);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1,2);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1,0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0,0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void dino() {

	// Resetear transformaciones
	glPushMatrix();
	// Trasladar en el Eje Y

	glTranslatef(-0.5, posY, 0.0);
	glScalef(0.03, scale, scale);
	//glTranslatef(0, Y, 0);        // Transladar en los 3 Ejes

	glBegin(GL_QUADS);

	//CABEZA
	glColor3f(0, 0, 0);
	glVertex2f(0.5, -1.5);
	glVertex2f(0.5, 1.6);
	glVertex2f(-0.2, 1.6);
	glVertex2f(-0.2, -1.5);
	//TRONCO
	glVertex2f(0.7, 0);
	glVertex2f(0.7, -1);
	glVertex2f(0, -1);
	glVertex2f(0, 0);


	glColor3f(0, 0, 0);
	//MANITO
	glVertex2f(0.7, -0.2);
	glVertex2f(0.7, -0.4);
	glVertex2f(0.9, -0.4);
	glVertex2f(0.9, -0.2);

	glVertex2f(0.9, -0.2);
	glVertex2f(1.1, -0.2);
	glVertex2f(1.1, -0.6);
	glVertex2f(0.9, -0.6);

	//BOCA
	glVertex2f(0, 0);
	glVertex2f(1.5, 0);
	glVertex2f(1.5, 0.3);
	glVertex2f(0, 0.3);

	glVertex2f(2, 0.5);
	glVertex2f(2, 1.6);
	glVertex2f(0, 1.6);
	glVertex2f(0, 0.5);

	glVertex2f(1.8, 1.6);
	glVertex2f(1.8, 1.8);
	glVertex2f(0.0, 1.8);
	glVertex2f(0.0, 1.6);

	//ESPALDA
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, -1.8);
	glVertex2f(-0.4, -1.8);
	glVertex2f(-0.4, 0.0);

	glVertex2f(-0.4, -0.3);
	glVertex2f(-0.4, -1.6);
	glVertex2f(-0.7, -1.6);
	glVertex2f(-0.7, -0.3);

	glVertex2f(-0.7, -0.5);
	glVertex2f(-0.7, -1.8);
	glVertex2f(-1.1, -1.8);
	glVertex2f(-1.1, -0.5);

	//COLA
	glVertex2f(-1.1, -0.3);
	glVertex2f(-1.1, -1.6);
	glVertex2f(-1.3, -1.6);
	glVertex2f(-1.3, -0.3);

	glVertex2f(-1.3, -0.2);
	glVertex2f(-1.3, -1.5);
	glVertex2f(-1.5, -1.5);
	glVertex2f(-1.5, -0.2);

	glVertex2f(-1.5, 0.2);
	glVertex2f(-1.5, -1.2);
	glVertex2f(-1.7, -1.2);
	glVertex2f(-1.7, 0.2);
	glEnd();

	//si buffer es par que levante pata derecha
	if (buffer % 2 == 0) {
		glBegin(GL_QUADS);
		//buffer

		//DERECHA ARRIBA
		glVertex2f(-0.0, -0);
		glVertex2f(-0.0, -2.2);
		glVertex2f(-0.2, -2.2);
		glVertex2f(-0.2, -0);

		glVertex2f(-0.2, -2.0);
		glVertex2f(0.25, -2.0);
		glVertex2f(0.25, -2.2);
		glVertex2f(-0.2, -2.2);

		//IZQUIERDA ABAJO
		glVertex2f(-0.7, -1.8);
		glVertex2f(-0.7, -2.3);
		glVertex2f(-0.90, -2.3);
		glVertex2f(-0.90, -1.8);

		glVertex2f(-0.7, -2.1);
		glVertex2f(-0.50, -2.1);
		glVertex2f(-0.50, -2.3);
		glVertex2f(-0.7, -2.3);
		glEnd();
	} else {
		glBegin(GL_QUADS);
		//buffer

		//DERECHA ABAJO
		glVertex2f(-0.0, -0);
		glVertex2f(-0.0, -2.3);
		glVertex2f(-0.2, -2.3);
		glVertex2f(-0.2, -0);

		glVertex2f(-0.2, -2.1);
		glVertex2f(0.25, -2.1);
		glVertex2f(0.25, -2.3);
		glVertex2f(-0.2, -2.3);

		//IZQUIERDA ARRIBA
		glVertex2f(-0.7, -1.8);
		glVertex2f(-0.7, -2.2);
		glVertex2f(-0.90, -2.2);
		glVertex2f(-0.90, -1.8);

		glVertex2f(-0.7, -2.0);
		glVertex2f(-0.50, -2.0);
		glVertex2f(-0.50, -2.2);
		glVertex2f(-0.7, -2.2);

		glEnd();
	}
	//OJO
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);


	glVertex2f(0.4, 1.2);
	glVertex2f(0.4, 1.4);
	glVertex2f(0.2, 1.4);
	glVertex2f(0.2, 1.2);
	glEnd();
	glPopMatrix();
}

void RenderScene(void) {

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if (buffer>=1000)
	{
		win();
	}
	else if (buffer > 500) {
		escena1();
		dino();
		objetos();
		text1();
		nameText1(text);
	}
	else {
		escena0();
		dino();
		objetos();
		text1();
		nameText1(text);

	}
	glFlush();
	glutSwapBuffers();
}

//rebote
void animacion(void) {

	float dif = (abs(posX - (-5)) + abs(posY - (-0.5)));
	float dif1 = (abs(posXtnt - (-5)) + abs(posY - (-0.5)));
	float dif2 = (abs(posXbird - (-5)) + abs(posY - (1.0)));
	if (dif < 0.5) {
		//colision

		sprintf(text, "GAME OVER Press [s] to Start");
    
		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
		SDL_PauseAudio(1);

	}else if (dif1 < 0.5)
	{
		
		sprintf(text, "GAME OVER Press [s] to Start");
    
		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
	}else if (dif2 < 0.5)
	{
		
		sprintf(text, "GAME OVER Press [s] to Start");
    
		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
	}
	 
	else {
		if (pause != true) {
			SDL_PauseAudio(0);
			buffer += 1.0;
			if (posX < -15 ) {
				posX = 10;
				

			} else if (X < -5.0f) {
				X = 0;
			}else if (posXtnt<-15)
			{
				posXtnt = 20;
			}else if (posXbird<-15)
			{
				posXbird=30;
			}
			 
			else {

				posX -= 0.15;
				posXtnt -= 0.15;
				posXbird -= 0.15;
				X -= 0.15;
				velY += -0.0005f;
				posY += velY;
				if (posY < 0.0f) {
					posY -= 0.1f;
					velY *= 0;
					if (velY < 0.01f) {
						velY = 0.0f;
						posY = 0;
					}
				}
			}
		} else {
			//pause
		}

	}



	glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
	//control de teclas que hacen
	switch (key) {
		//barra espaciadora para detener
	case 32:
		pause = true;
		break;
		//tecla s para reaunidar escena
	case 's':
		pause = false;
		buffer=0;
		sprintf(text, " ");
		break;
	case 'q':
		exit(0);				// exit
	}
	glutPostRedisplay();
}
void specialKeys(int key, int x, int y) {


	if (key == GLUT_KEY_RIGHT) {
		X += 0.1;
	}
	//  Flecha izquierda: Desacelerar scena 
	else if (key == GLUT_KEY_LEFT) {
		X -= 0.1;
	}
	//  Flecha arriba: Saltar
	else if (key == GLUT_KEY_UP) {
		posY = 0.8;
	}
	//Y = 0.2;
	//  Flecha abajo: Saltar
	else if (key == GLUT_KEY_DOWN) {
		Y = -0.5;
	}

}

void init(void) {
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), ResY);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - ResX) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - ResY) / 2);
	glutCreateWindow("Dino Game");
	init();
	glutDisplayFunc(RenderScene);
	glutIdleFunc(animacion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	animacion();
	glutMainLoop();
	return 0;
}
