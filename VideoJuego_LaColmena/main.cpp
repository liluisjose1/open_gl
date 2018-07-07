#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SOIL/SOIL.h>
#include <SDL2/SDL.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RUTA_AUDIO "../sources/song/vuelo_abeja.wav"	//nombre del archivo de audio
using namespace std;
// funcion para cargar audio
void my_audio_callback(void *userdata, Uint8 * stream, int len);

// variables para audio
static Uint8 *audio_pos;		// global pointer to the audio buffer to be played
static Uint32 audio_len;		// remaining length of the sample we have to play

GLuint texture[18];

// ángulo de rotación para la dirección de la cámara
float angle = 0.0f;

// vector real que representa la dirección de la cámara
float lx=0.0f,lz=-1.0f, ly=0.0f;
float rotY=0.0;

// XZ posición de la cámara
float x=0.0f, z=20.0f, y=1.0;
// vector real que representa la dirección de la cámara

float Ydes=1.0;


// Variable Y de la abeja
GLfloat Yf=1.0;
GLfloat Yr=0.5;
// Variable X del avion
GLfloat Xg=-14.0;
//Fin
GLfloat yFin=-10.0;

// Estas variables serán cero cuando no se presiona ninguna tecla
float deltaAngle = 0.0f;
float deltaMove = 0;

// Escala
float scale = 1.0f;

//variables de pozos
float difp1=2.5,difp2=2.5,difp3=2.5,difp4=2.5;
int p1=1,p2=1,p3=1,p4=1;



//cuadrante1
float difp11=2.5,difp12=2.5,difp13=2.5,difp14=2.5;
int p11=1,p12=1,p13=1,p14=1;
//cuadrante2
float difp21=2.5,difp22=2.5,difp23=2.5,difp24=2.5;
int p21=1,p22=1,p23=1,p24=1;
//cuadrante3
float difp31=2.5,difp32=2.5,difp33=2.5,difp34=2.5;
int p31=1,p32=1,p33=1,p34=1;
//cuadrante4
float difp41=2.5,difp42=2.5,difp43=2.5,difp44=2.5;
int p41=1,p42=1,p43=1,p44=1;


// Fuente por defecto
void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *font1 = GLUT_BITMAP_TIMES_ROMAN_24;

// ancho y alto de ventana
int h,w;

// variables para calcular cuadros por segundo FPS
int frame;
int frameBuffer;
long time, timebase;
long time2, timebase2;
char s[60];
//time
char t[60];
char r[60];
char currentMode[80];

int colection = 0;
int deposit = 20;
int timelimi = 180;

// esta cadena mantiene la última configuración para el modo de juego
char gameModeString[40] = "640x480";

//salida de mensajes
char mensaje[100];
//validaciones
bool valido = false;
bool valReina = false;
bool valCartel = false;
bool valFinish = false;
bool valDeposit = false;



//radio de dibujos
float radioAbe=0.7;
float radioMiel=0.8;

//animacion
int animating = 0;

void init();


//--llamado de funciones--

#include "sources/funciones.h"

// -----------------------------------
//             Logica
// -----------------------------------
void gameOver()
{
	sprintf(mensaje,"%s","");
	x=0,lx=0;
	z=25,lz=-1;
	rotY=0;
	colection=0;
	
	p1=1,p2=1,p3=1,p4=1;
	p11=1,p12=1,p13=1,p14=1;
	p21=1,p22=1,p23=1,p24=1;
	p31=1,p32=1,p33=1,p34=1;
	p41=1,p42=1,p43=1,p44=1;
	
	radioAbe=0.7,radioMiel=0.8;
}

void positionspozos()
{
	 difp1 = abs((x+lx)-(-50))+abs((z+lz)-(-45));
	 
		 difp11 = abs((x+lx)-(-30))+abs((z+lz)-(-25));
		 difp12 = abs((x+lx)-(-30))+abs((z+lz)-(-65));
		 difp13 = abs((x+lx)-(-70))+abs((z+lz)-(-25));
		 difp14 = abs((x+lx)-(-70))+abs((z+lz)-(-65));
	 
	 difp2 = abs((x+lx)-(50))+abs((z+lz)-(-45));
		 difp21 = abs((x+lx)-(30))+abs((z+lz)-(-25));
		 difp22 = abs((x+lx)-(30))+abs((z+lz)-(-65));
		 difp23 = abs((x+lx)-(70))+abs((z+lz)-(-25));
		 difp24 = abs((x+lx)-(70))+abs((z+lz)-(-65));
	 
	 difp3 = abs((x+lx)-(-50))+abs((z+lz)-(55));
	 	 difp31 = abs((x+lx)-(-30))+abs((z+lz)-(35));
		 difp32 = abs((x+lx)-(-30))+abs((z+lz)-(75));
		 difp33 = abs((x+lx)-(-70))+abs((z+lz)-(35));
		 difp34 = abs((x+lx)-(-70))+abs((z+lz)-(75));
		 
	 difp4 = abs((x+lx)-(50))+abs((z+lz)-(55));
	 	 difp41 = abs((x+lx)-(30))+abs((z+lz)-(35));
		 difp42 = abs((x+lx)-(30))+abs((z+lz)-(75));
		 difp43 = abs((x+lx)-(70))+abs((z+lz)-(35));
		 difp44 = abs((x+lx)-(70))+abs((z+lz)-(75));
	 
	 
	 
}

void logica()
{
	//colisiones con arboles
	
	for (int i = 1; i <=5; i+=1)		
		for(float j=M_PI/1800; j < 2*M_PI; j+=M_PI/7) {
			float dif11 = abs((x+lx)-(cos(j)*i*15))+abs((z+lz)-(sin(j)*i*15));
		
			if(dif11<0.5)
			{
				gameOver();
			}
		}
	
	
	for(int i = -2; i < 2; i++){
		for(int j=-2; j < 2; j++) {
			float dif1 = abs((x+lx)-(-40+i*20))+abs((z+lz)-(-35+j*20));
			float dif2 = abs((x+lx)-(60+i*20))+abs((z+lz)-(-35+j*20));
			float dif3 = abs((x+lx)-(-40+i*20))+abs((z+lz)-(65+j*20));
			float dif4 = abs((x+lx)-(60+i*20))+abs((z+lz)-(65+j*20));
			if(dif1<2.0 || dif2<2.0  || dif3<2.0 || dif4<2.0)
			{
				gameOver();
			}
		}
	}
	
	//limites del cubo
	if(abs((z+lz))>98.0 || abs((x+lx))>98.0)
		{
				gameOver();
		}
		
	//validaciones casa
	if(abs((x+lx)-(0))+abs((z+lz)-(0))<2.0)
	{
		valido=false;
		valReina =true;
		sprintf(mensaje,"%s","Presiona [q] para depositar");
		
		if (colection<=0)
		{
			sprintf(mensaje,"%s","Debes de ir a recolectar");
			//colection=0;
		}
		
		
	}
	
	//no tocar abeja reina
	/*if(abs((x+lx)-(0))+abs((z+lz)-(0))<0.5  )
	{
		sprintf(mensaje,"%s","No me toques");
		gameOver();
	
	}
	*/
	//colision con enemigo frontal
	if(abs((x+lx)-(-50))+abs((z+lz)-(-42))<0.7  )
	{

		gameOver();
	
	}
	//colision con enemigos frontales
	if(abs((x+lx)-(-50))+abs((z+lz)-(52))<0.7  )
	{

		gameOver();
	
	}
	if(abs((x+lx)-(50))+abs((z+lz)-(-42))<0.7  )
	{

		gameOver();
	
	}
	if(abs((x+lx)-(50))+abs((z+lz)-(52))<0.7  )
	{

		gameOver();
	
	}
	
	//colision con enemigo lateral
	if(abs((x+lx)-(-47))+abs((z+lz)-(-45))<0.7  )
	{

		gameOver();
	
	}
	//colision con enemigos laterales
	if(abs((x+lx)-(-47))+abs((z+lz)-(55))<0.7  )
	{

		gameOver();
	
	}
	if(abs((x+lx)-(47))+abs((z+lz)-(-45))<0.7  )
	{

		gameOver();
	
	}
	if(abs((x+lx)-(47))+abs((z+lz)-(55))<0.7  )
	{

		gameOver();
	
	}
		// recoleccion en pozos
	if(difp1<2.0 || difp2<2.0 || difp3<2.0 || difp4<2.0 )
	{
		
			sprintf(mensaje,"%s","Presiona [x] recolectar nectar ");
			valido=true;		
	}
	//segundo nivel
	
	if (colection<=16)
	{
			// recoleccion en pozos
		if(difp11<2.0 || difp12<2.0 || difp13<2.0 || difp14<2.0 )
		{
			
				sprintf(mensaje,"%s","Presiona [x] recolectar nectar ");
				valido=true;		
		}
		
		if(difp21<2.0 || difp22<2.0 || difp23<2.0 || difp24<2.0 )
		{
			
				sprintf(mensaje,"%s","Presiona [x] recolectar nectar ");
				valido=true;		
		}
		if(difp31<2 || difp32<2 || difp33<2 || difp34<2 )
		{
			
				sprintf(mensaje,"%s","Presiona [x] recolectar nectar ");
				valido=true;		
		}
		if(difp41<2 || difp42<2 || difp43<2 || difp44<2 )
		{
			
				sprintf(mensaje,"%s","Presiona [x] recolectar nectar ");
				valido=true;		
		}
	}
	
	


}


// -----------------------------------
//             Escena
// -----------------------------------
bool valInfo=false;
void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	// Clear Color and Depth Buffers
	glClearColor(0.55, 0.64, 0.74,1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, y, z,
			x+lx, 1.0,  z+lz,
			0.0f, 1.0f,  0.0f);
	logica();
	positionspozos();
	pozos();
	

	
	camino();
	drawCielo();
	drawSoil();
	
	cilueta(0, Yf-1, 0);
	house();
	reina();
    avionmov(Xg+14, 0, 0);
	
	info();
	
	carteles();
    
    descarga();
    
    enemigo();
    enemigo2();
    enemigo3();
    enemigo4();
    
    
    
	drawForest();
	

	// Code to compute frames per second
	glColor3f(1.0,1.0,1.0);
	frame++;
	frameBuffer++;
		if (frameBuffer==100)
		{
			frameBuffer=0;
		}
		
	
	time=glutGet(GLUT_ELAPSED_TIME);
	//tiempo segundos
	time2=glutGet(GLUT_ELAPSED_TIME);
	
	sprintf(r,"Time: %4.2f",(time)/1000.0);
	
	
	
	
	
	//segundos para juego
	if ((time)/1000.0>timelimi)
	{
		gameOver();
		sprintf(r,"%s","");
	}
	
	if (timelimi>=1000)
	{
		sprintf(r,"%s","");
	}
	
	
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}
	
	setOrthographicProjection();

	void *font= GLUT_BITMAP_TIMES_ROMAN_24;
	glPushMatrix();
	
	glLoadIdentity();
	
	renderBitmapString(0.1,9.6,0,font,s);
	sprintf(t,"Recolecciones: %4.2f",colection/1.0);
	renderBitmapString(0.1,9.3,0,font,t);
	
	//salida tiempo
	renderBitmapString(0.1,9.0,0,font,r);
	
	glColor3f(0.0,1.0,0.0);
	renderBitmapString(0.1,8.7,0,font1,mensaje);
	
	if(valFinish==true)
	{
		fin();
	}
	
	if(valInfo==true)
	{	renderBitmapString(0.1,9.0,0,font1,mensaje);
	

		info2();
	}
	
	glPopMatrix();
	
	restorePerspectiveProjection();
	glutSwapBuffers();
}

//-------------------------
// Animacion
//-------------------------
// 0 sin animación 
		// Se cambia con la llamada a las funciones startAnimation() and pauseAnimation()

void pauseAnimation() {
	// Llamamo a la función para detener la animación 
	animating = 0;
}



void startAnimation(int value) {
	// llamamos la función para iniciar la animación 
	
	
	//deposito
	if (valDeposit==true)
	{
		Ydes-=0.1;	
	}
		if (Ydes<=0.0)
		{
			Ydes=1.0;
			valDeposit=false;
		}
		
	
	//animacion avion
	if (Xg>=100)
	{
		Xg=200;
	}
	
	if(animating==0)
	{
		Xg+=0.1;

	}
	
    
	//animacion final
	if(colection<=0 && deposit<=1)
	{
		Yr+=0.1;
		z=25;
		yFin+=0.02;
		valFinish=true;
	}
	if(yFin>=10)
    {
		exit (-1);
	}
	if(Yr>=8.0)
    {
		sprintf(mensaje,"%s","FIN");
		Yr=8.0;
	}
	
	//animacion abeja bajando
	if (difp1<2.0 && animating==1 && p1>=1) 
    {
		Yf-=0.01;
    }
    		//----cuadrante2 Nivel2
		if (difp11<2.0 && animating==1 && p11>=1) 
		{
			Yf-=0.01;
		}
		if (difp12<2.0 && animating==1 && p12>=1) 
		{
			Yf-=0.01;
		}
		if (difp13<2.0 && animating==1 && p13>=1) 
		{
			Yf-=0.01;
		}
		if (difp14<2.0 && animating==1 && p14>=1) 
		{
			Yf-=0.01;
		}
		//----cuadrante2 Nivel2
		if (difp21<2.0 && animating==1 && p21>=1) 
		{
			Yf-=0.01;
		}
		if (difp22<2.0 && animating==1 && p22>=1) 
		{
			Yf-=0.01;
		}
		if (difp23<2.0 && animating==1 && p23>=1) 
		{
			Yf-=0.01;
		}
		if (difp24<2.0 && animating==1 && p24>=1) 
		{
			Yf-=0.01;
		}
		//----cuadrante3 Nivel2
		if (difp31<2 && animating==1 && p31>=1) 
		{
			Yf-=0.01;
		}
		if (difp32<2 && animating==1 && p32>=1) 
		{
			Yf-=0.01;
		}
		if (difp33<2 && animating==1 && p33>=1) 
		{
			Yf-=0.01;
		}
		if (difp34<2 && animating==1 && p34>=1) 
		{
			Yf-=0.01;
		}
		//----cuadrante4 Nivel2
		if (difp41<2 && animating==1 && p41>=1) 
		{
			Yf-=0.01;
		}
		if (difp42<2 && animating==1 && p42>=1) 
		{
			Yf-=0.01;
		}
		if (difp43<2 && animating==1 && p43>=1) 
		{
			Yf-=0.01;
		}
		if (difp44<2 && animating==1 && p44>=1) 
		{
			Yf-=0.01;
		}
	if (difp2<2.0 && animating==1 && p2>=1) 
    {
		Yf-=0.01;
    }
	if (difp3<2.0 && animating==1 && p3>=1) 
    {
		Yf-=0.01;
    }
	if (difp4<2.0 && animating==1 && p4>=1) 
    {
		Yf-=0.01;
    }
    
    if(Yf<=0.8)
    {
		colection+=1.0;
		radioAbe+=0.0125;
		
		if (difp1<2.0)
			{
				p1-=1;
				
			}
			//posiciones cuadrante1
			if (difp11<2.0)
				{
					p11-=1;
					
				}
			if (difp12<2.0)
				{
					p12-=1;
					
				}
			if (difp13<2.0)
				{
					p13-=1;
					
				}
			if (difp14<2.0)
				{
					p14-=1;
					
				}
		if (difp2<2.0)
			{
				p2-=1;
			}
			//posiciones cuadrante2
			if (difp21<2.0)
				{
					p21-=1;
					
				}
			if (difp22<2.0)
				{
					p22-=1;
					
				}
			if (difp23<2.0)
				{
					p23-=1;
					
				}
			if (difp24<2.0)
				{
					p24-=1;
					
				}
			
		if (difp3<2.0)
			{
				p3-=1;
			}
			//posiciones cuadrante3
			if (difp31<2)
				{
					p31-=1;
					
				}
			if (difp32<2)
				{
					p32-=1;
					
				}
			if (difp33<2)
				{
					p33-=1;
					
				}
			if (difp34<2)
				{
					p34-=1;
					
				}
		if (difp4<2.0)
			{
				p4-=1;
			}
			//posiciones cuadrante4
			if (difp41<2)
				{
					p41-=1;
					
				}
			if (difp42<2)
				{
					p42-=1;
					
				}
			if (difp43<2)
				{
					p43-=1;
					
				}
			if (difp44<2)
				{
					p44-=1;
					
				}
        Yf = 1.0, animating=0;
        
    }
    
        glutPostRedisplay();
		glutTimerFunc(30, startAnimation, 0);
}

// -----------------------------------
//             Teclado Normal
// -----------------------------------

void processNormalKeys(unsigned char key, int xx, int yy) {

	switch (key) {
		case 27:
			if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) != 0)
				glutLeaveGameMode();
			exit(0);
			break;
		//View plant
		case '1': y+=5.0f;break;
		//Normal View
		case '2': y-=5.0f;break;
		case '3': valCartel=true;break;
		case 'w': deltaMove = 3.0f; break;
		case 's': deltaMove = -3.0f; break;
		case 'a': rotY+=10.0; break;
		case 'd': rotY-=10.0; break;
		case 'x': if (valido==true ){animating =1;}	break;
		case 'q': if(colection>=1 && valReina == true ){valDeposit=true,colection-=1,deposit-=1;radioAbe-=0.01; radioMiel+=0.05; }break;
		case 'p': pauseAnimation();sprintf(mensaje,"%s","Escena Pausada"); break;
		case 'h': valInfo=true; break;
		case 'H': valInfo=false; break;
			
	}
}

// -----------------------------------
//             Teclado Especial
// -----------------------------------
void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_UP : 
		deltaMove = 1.5f,sprintf(mensaje,"%s",""); break;
		case GLUT_KEY_DOWN : deltaMove = -1.5f,sprintf(mensaje,"%s",""); break;
		case GLUT_KEY_LEFT : deltaAngle = -0.02f, rotY+=10.0,sprintf(mensaje,"%s",""); break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.02f, rotY-=10.0,sprintf(mensaje,"%s",""); break;
		//View planta
		case GLUT_KEY_PAGE_DOWN :y=1.0; break;
		//View principal
		case GLUT_KEY_PAGE_UP : y=200.0; break;
		
		case GLUT_KEY_F1:
			//valInfo=true;
			// define resolution, color depth
			glutGameModeString("640x480:32");
			// enter full screen
			if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
				glutEnterGameMode();
				sprintf(gameModeString,"640x480:32");
				// register callbacks again
				// and init OpenGL context
				init();
				loadTextures();
			}
			else
				glutGameModeString(gameModeString);
			break;
		case GLUT_KEY_F2:
			// define resolution, color depth
			glutGameModeString("800x600:32");
			// enter full screen
			if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
				glutEnterGameMode();
				sprintf(gameModeString,"800x600:32");
				// register callbacks again
				// and init OpenGL context
				init();
				loadTextures();
			}
			else
				glutGameModeString(gameModeString);
			break;
		case GLUT_KEY_F3:
			// define resolution, color depth
			glutGameModeString("1024x768:32");
			// enter full screen
			if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
				glutEnterGameMode();
				sprintf(gameModeString,"1024x768:32");
				// register callbacks again
				// and init OpenGL context
				init();
				loadTextures();
			}
			else
				glutGameModeString(gameModeString);
			break;
		case GLUT_KEY_F4:
			// define resolution, color depth
			glutGameModeString("1280x1024:32");
			// enter full screen
			if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
				glutEnterGameMode();
				sprintf(gameModeString,"1280x1024:32");
				// register callbacks again
				// and init OpenGL context
				init();
				loadTextures();
			}
			else
				glutGameModeString(gameModeString);
			break;
		case GLUT_KEY_F5:
			// define resolution, color depth
			glutGameModeString("1920x1080");
			// enter full screen
			if (glutGameModeGet(GLUT_GAME_MODE_POSSIBLE)) {
				glutEnterGameMode();
				sprintf(gameModeString,"1920x1080");
				// register callbacks again
				// and init OpenGL context
				init();
				loadTextures();
				
			}
			else
				glutGameModeString(gameModeString);
			break;
		case GLUT_KEY_F6:
			// return to default window
			w = 800;h = 600;
			if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) != 0) {
				glutLeaveGameMode();
				//init();
			}
			break;
		case GLUT_KEY_F7:
			valInfo=true;
	}
	if (glutGameModeGet(GLUT_GAME_MODE_ACTIVE) == 0)
		sprintf(currentMode,"Current Mode: Window");
	else
		sprintf(currentMode,
			"Current Mode: Game Mode %dx%d at %d hertz, %d bpp",
			glutGameModeGet(GLUT_GAME_MODE_WIDTH),
			glutGameModeGet(GLUT_GAME_MODE_HEIGHT),
			glutGameModeGet(GLUT_GAME_MODE_REFRESH_RATE),
			glutGameModeGet(GLUT_GAME_MODE_PIXEL_DEPTH));
}

// -----------------------------------
//  Funcion para ver si se estan presionando teclas
// -----------------------------------
void releaseKey(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f,rotY=rotY;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0,rotY=rotY;break;
	}
}


void init() {

	// register callbacks
	//carga de texturas
	loadTextures();
	//startAnimation();
	//funciones glut
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
}

// -----------------------------------
//             MAIN
// -----------------------------------

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH),glutGet(GLUT_SCREEN_HEIGHT));
	glutCreateWindow("Game The Bee AG-18");

	// register callbacks
	init();
    glutTimerFunc(25, startAnimation, 0);
	
	
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
	SDL_PauseAudio(0);
	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;

	//SDL_PauseAudio(0);
	while (audio_len > 0) {
		SDL_Delay(0);	// espera un segundo para la pausa
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
