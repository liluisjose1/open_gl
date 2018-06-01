#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#define RUTA_AUDIO "../song/flauta_naruto.wav"	//nombre del archivo de audio
using namespace std;
// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 * stream, int len);

// variables para audio
static Uint8 *audio_pos;		// global pointer to the audio buffer to be played
static Uint32 audio_len;		// remaining length of the sample we have to play

//transformaciones de pantalla
float scale = 0.1;
int ResX = 1500, ResY = 500;

//Variables de Moviento de escena en ejeX
GLfloat X = 0.0f;
//Variables de Moviento de escena en ejeY
GLfloat Y = -0.2f;
//Texto de nombre
// buffer and score
int buffer = 0;
//interrupciones
bool pause = false;
char text[32];
//salto de dino
float posY = 1.0f, velY = 0.0f;
float posX = 10.0f;
float posXtnt = 20.0f;
float posXbird = 30.0f;
//Texturas
GLuint texture[0];
GLuint texture1[0];
//-------------------------------- FUNCION IMPRIME TEXTO SCORE ---------------------------
void text1() {
	glPushMatrix();
	char text[32];
	sprintf(text, "Score:%d", buffer);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(0.8, 0.8);
	for (int i = 0; text[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glPopMatrix();
	glutPostRedisplay();
}
//-------------------------------- FUNCION IMPRIME TEXTO PERDEDOR ---------------------------
void nameText1(char *s) {
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(-0.2, 0.4);
	for (int i = 0; text[i] != '\0'; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
	}
	glPopMatrix();
	glutPostRedisplay();
}
//-------------------------------- FUNCION DE ESCENA INICIAL ---------------------------
void escena0() {
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(X, 0.0f, 5.0f);
	//texturas
	texture[1] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/dino2.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	//MAPEANDO 30 VECES LA ESCENA
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(-20, 30);
	glTexCoord2f(30.0f, 1.0f);	glVertex2f(20, 30);
	glTexCoord2f(30.0f, 0.0f);	glVertex2f(20, -10);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(-20, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glutPostRedisplay();


}
//-------------------------------- FUNCION DE ESCENA SEGUNDARIA ---------------------------
void escena1() {
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(X, 0.0f, 5.0f);
	//texturas
	texture[0] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/dino1.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	//MAPEANDO 30 VECES LA ESCENA
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(-20, 18);
	glTexCoord2f(30.0f, 1.0f);	glVertex2f(20, 18);
	glTexCoord2f(30.0f, 0.0f);	glVertex2f(20, -10);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(-20, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glutPostRedisplay();


}
//-------------------------------- FUNCION DE ESCENA GANADOR ---------------------------
void win() {
	//-------------------------------- textura ganador ---------------------------
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	glTranslatef(0.0, 0.0f, 5.0f);
	//texturas
	texture1[2] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/win.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(-5, 10);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(5, 10);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(5, -10);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(-5, -10);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glutPostRedisplay();


}
void objetos() {
	//-------------------------------- textura arbol ---------------------------
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(posX, -2.5, 0.0f);
	texture[2] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/arbol.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//ACTIVANDO FILTROS DE TRANSPARENCIA 
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0, 4);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1, 4);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1, 0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0, 0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
		//-------------------------------- textura caja TNT ---------------------------
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(posXtnt, -2.0, 0.0f);
	texture1[0] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/tnt.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0, 2);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1, 2);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1, 0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0, 0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//-------------------------------- textura elicoptero ---------------------------
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(posXbird, 5.0, 0.0f);
	texture1[1] = SOIL_load_OGL_texture	// cargamos la imagen
		("../img/bird.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1[1]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor3f(1.0, 0.3, 0.86);
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0f, 1.0f);	glVertex2f(0, 2);
	glTexCoord2f(1.0f, 1.0f);	glVertex2f(1, 2);
	glTexCoord2f(1.0f, 0.0f);	glVertex2f(1, 0);
	glTexCoord2f(0.0f, 0.0f);	glVertex2f(0, 0);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void dino() {

	// Resetear transformaciones
	glPushMatrix();
	glTranslatef(-0.5, posY, 0.0);
	glScalef(0.03, scale, scale);
	//OJO
	if (pause==false)
	{
		glColor3f(1.0, 1.0, 1.0);
	}
	else
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	glBegin(GL_QUADS);


	glVertex2f(0.4, 1.2);
	glVertex2f(0.4, 1.4);
	glVertex2f(0.2, 1.4);
	glVertex2f(0.2, 1.2);
	glEnd();
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

	glPopMatrix();
}
//-------------------------------- FUNCION RENDER DE ESCENAS ---------------------------
void display() {
	glClearColor(0.94, 0.92, 0.94,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	if (buffer >= 1000) {
		win();
		sprintf(text, " YOU WIN! Press [s] to Start");
		glColor3f(0.62, 0.09, 0.02);
		glRasterPos2f(-0.2, -0.8);
		for (int i = 0; text[i] != '\0'; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
		}
	} else if (buffer > 500) {
		escena1();
		nameText1(text);
		dino();
		objetos();
		text1();
	} else {
		escena0();
		nameText1(text);
		dino();
		objetos();
		text1();
	}
	glFlush();
	glutSwapBuffers();
}


// --------------- Para animación  ------------------------------------------

int animating = 0;				// 0 sin animación 
						// Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
	// Llamamo a la función para detener la animación 
	animating = 0;
}

void updateFrame() {
	//COLISIONES
	//COLISION CON PRIMER OBJETO
	float dif = (abs(posX - (-5)) + abs(posY - (0)));
	//COLISION CON SEGUNDO OBJETO
	float dif1 = (abs(posXtnt - (-5)) + abs(posY - (0)));
	//COLISION CON TERCER OBJETO
	float dif2 = (abs(posXbird - (-5)) + abs(posY - (1.0)));
	if (dif < 0.5) {
		//colision

		sprintf(text, "GAME OVER Press [s] to Start");

		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
		SDL_PauseAudio(1);

	} else if (dif1 < 0.5) {

		sprintf(text, "GAME OVER Press [s] to Start");

		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
	} else if (dif2 < 0.5) {

		sprintf(text, "GAME OVER Press [s] to Start");

		pause = true;
		posX = 10;
		posXtnt = 20;
		posXbird = 30;
	}

	else {
		//ACTUALIZAR ESCENAS SI EL ESTADO NO ES VERDADERO
		if (pause != true) {
			SDL_PauseAudio(0);
			buffer += 1.0;
			if (posX < -15) {
				posX = 10;


			} else if (X < -5.0f) {
				X = 0;
			} else if (posXtnt < -15) {
				posXtnt = 20;
			} else if (posXbird < -15) {
				posXbird = 30;
			}

			else {

				posX -= 0.2;
				posXtnt -= 0.25;
				posXbird -= 0.3;
				X -= 0.15;
				velY += -0.005f;
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
			SDL_PauseAudio(1);
		}

	}



	glutPostRedisplay();
}

void timerFunction(int timerID) {
	// Invocamos la funcion para controlar el tiempo de la ejecucion de funciones 
	if (animating) {
		updateFrame();
		glutTimerFunc(30, timerFunction, 0);
		glutPostRedisplay();
	}
}

void startAnimation() {
	// llamamos la función para iniciar la animación 
	if (!animating) {
		animating = 1;
		glutTimerFunc(30, timerFunction, 1);
	}
}



// ------------- Manejo de Teclado-----------------------------------------------

void key(unsigned char key, int x, int y) {
	// La animación inicia al presionar la tecla espaciadora de igual forma se detiene
	switch (key) {
		//barra espaciadora para detener
	case 32:
		pause = true;
		break;
		//tecla s para reaunidar escena
	case 's':
		pause = false;
		buffer = 0;
		sprintf(text, " ");
		break;
	case 27:
		exit(0);				// exit
	}
	glutPostRedisplay();
}

void special(int key, int x, int y) {
	// control de teclas especiales 
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

// ----------------------  Funcion principal ------------------

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), ResY);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - ResX) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - ResY) / 2);
	glutCreateWindow("Dino Game");
	init();
		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return 1;

	// Variables locales
	static Uint32 wav_length;	// Longitud de nuestra muestra
	static Uint8 *wav_buffer;	// Buffer que contiene nuestro archivo de audio
	static SDL_AudioSpec wav_spec;	// Las especificaciones de nuestra pieza de música

	/* Cargar el WAV */
	// Las especificaciones, la longitud y el búfer de nuestro wav se llenan
	if (SDL_LoadWAV(RUTA_AUDIO, &wav_spec, &wav_buffer, &wav_length) == NULL) {
		return 1;
	}
	// Establecer la función de devolución de llamada
	wav_spec.callback = my_audio_callback;
	wav_spec.userdata = NULL;

	// Establecer nuestras variables estáticas globales
	audio_pos = wav_buffer;		// Copia el buffer de sonido
	audio_len = wav_length;		// Copia la longitud del archivo

	/*Abrir el dispositivo de audio */
	if (SDL_OpenAudio(&wav_spec, NULL) < 0) {
		fprintf(stderr, "No se pudo abrir el audio: %s\n", SDL_GetError());
		exit(-1);
	}
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutSpecialFunc(special);
	glEnable(GL_DEPTH_TEST);

	// animación inicie al levantar el script
	startAnimation();

	glutMainLoop();
	return 0;


	//SDL_PauseAudio(0);
	while (audio_len > 0) {
		SDL_Delay(0);			// espera un segundo para la pausa
	}
	SDL_CloseAudio();
	SDL_FreeWAV(wav_buffer);
}

//Función de devolución de llamada de audio donde se recoren los valores del bufer
void my_audio_callback(void *userdata, Uint8 * stream, int len) {

	if (audio_len == 0)
		return;

	len = (len > audio_len ? audio_len : len);

	SDL_memcpy(stream, audio_pos, len);	// Simplemente copie desde un buffer en el otro
	//SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME / 2); // Mezclar de un buffer a otro

	audio_pos += len;
	audio_len -= len;
}

