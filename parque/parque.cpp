#include <GL/gl.h>
#include <GL/glut.h> //agregar < >
#include <stdlib.h> //agregar < >
#include <math.h> //agregar < >
//#define PI 3.1415926535898

//parametros para construir la grilla
#define DEF_floorGridScale 5.0
#define DEF_floorGridXSteps 10.0
#define DEF_floorGridZSteps 30.0

#define angulo 45
static int slices = 16;
static int stacks = 16;

double j=0.1;
int i,c;
float x;
int planox=15,planoy=180,planoz=0;

float puntovistax=0.0,puntovistay=-40.0,puntovistaz=240.0;

double luz;
double vo;

int ek;
double vk=0;
float tiempok=0;
int topek=0;

int er,aux;
float vr=0,tiempor=0;


int ecv1;
int ecv2;
float vcv=0;
float ccv=0;
int aux1=0;
int a=9;

float vcs;
int r,cx,z,rotar;

float vbz,vby;
int eb=0;
double angle,circle_points;

void Rueda();
void kamikaze();
void c_voladores();
void ovni();
void carrusel();
void cuncuna();
void Boomerang();
void arbol(int,int);
void Panel_control(float,float,float);
void PosicionPC();
void tren();
void xtremfall();
void Postes(int,int);
void personas(float,float,float,int);


/* GLUT callback Handlers */
static void
resize(int width, int height){

const float ar = (float) width / (float) height;

glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-ar, ar, -1.0, 1.0, 3.0, 390.0);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


void specialFunc( int key, int x, int y )
{
switch( key ){

//giro a la izquierda
case GLUT_KEY_LEFT:
planoy--;
break;

// giro a la derecha.
case GLUT_KEY_RIGHT:
planoy++;
break;

// mirar hacia arriba.
case GLUT_KEY_UP:
planox--;
break;

// mirar hacia abajo
case GLUT_KEY_DOWN:
planox++;
break;
}
}

void keyboard(unsigned char key, int x, int y){

GLfloat angulo_camara;
#define M_PI 3.141592653 
switch(key){

// Zoom: movimiento hacia adelante
case 'g': case 'G': 
angulo_camara = ( ( -planoy + 180 ) * M_PI / 180.0 );
puntovistax -= 2*sin( angulo_camara );
puntovistaz -= 2*cos( angulo_camara );
break;

// desplazamiento hacia el lado izquierdo
case 'c': case 'C':
angulo_camara = ( ( -planoy + 270 ) * M_PI / 180.0 );
puntovistax -= sin( angulo_camara );
puntovistaz -= cos( angulo_camara );
break;

// desplazamiento hacia el lado derecho
case 'b': case 'B':
angulo_camara = ( ( -planoy + 90 ) * M_PI / 180.0 );
puntovistax -= sin( angulo_camara );
puntovistaz -= cos( angulo_camara );
break;

// retroceder: desplazamiento hacia atrás
case 'v': case 'V':
angulo_camara = ( ( -planoy + 0 ) * M_PI / 180.0 );
puntovistax -= sin( angulo_camara );
puntovistaz -= cos( angulo_camara );
break;

//subir: desplazamiento hacia arriba
case 'k': case 'K':
puntovistay=puntovistay-2;
break;

//bajar: desplazamiento hacia abajo
case 'm': case 'M':
puntovistay=puntovistay+2;
break;

//rotar en el eje z
case 'z': case 'Z':
planoz++;
break;
case 'x': case 'X':
planoz--;
break;

//Esc salir
case 27: case'q': case 'Q': 
exit(0);
break;
}

}



void grilla(){ 

GLfloat zExtent, xExtent, xLocal, zLocal, loopX, loopZ;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//Dibujo la Grilla
glPushMatrix();
glPushAttrib( GL_LIGHTING_BIT );
glDisable( GL_LIGHTING );
glColor3f(0.6,0.4,0.14);
glBegin( GL_LINES );
zExtent = DEF_floorGridScale * DEF_floorGridZSteps;
for(loopX = -DEF_floorGridXSteps; loopX <= DEF_floorGridXSteps; loopX++ )
{
xLocal = DEF_floorGridScale * loopX;
glVertex3f( xLocal, 0.0, -zExtent );
glVertex3f( xLocal, 0.0, zExtent );
}
xExtent = DEF_floorGridScale * DEF_floorGridXSteps;
for(loopZ = -DEF_floorGridZSteps; loopZ <= DEF_floorGridZSteps; loopZ++ )
{
zLocal = DEF_floorGridScale * loopZ;
glVertex3f( -xExtent, 0.0, zLocal );
glVertex3f( xExtent, 0.0, zLocal );
}
glEnd();
glPopAttrib();
glPopMatrix();
}


static float y=2;
int flag1=1,flag2=0;
static float donay=4.0; //variables funcion xtremfall

static void display(void){

glPushMatrix();
glRotated(planox,1,0,0);
glRotated(planoy,0,1,0);
glRotated(planoz,0,0,1);

glTranslated(0,0,puntovistaz);
glTranslated(0,puntovistay,0);
glTranslated(puntovistax,0,0);

int i; 
const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor3d(1,0,0);

grilla(); 

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 5.5f, -4.0f, 0.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

glClearColor(0,0,0,0);
glEnable(GL_CULL_FACE);
glCullFace(GL_BACK);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LESS);
glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHTING);
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


for(i=0,z=150;i<6;i++){z-=50; arbol(-50,z);}
for(i=0,z=150;i<6;i++){z-=50; arbol(50,z);}
for(i=0,z=75;i<5;i++){z-=25; arbol(z,150);}

for(i=0,z=125;i<6;i++){Postes(-50,z);z-=50;}
for(i=0,z=125;i<6;i++){Postes(50,z);z-=50;}

for(i=0,z=-100;i<5;i++){personas(10,1.6,z,0);z+=2;}
for(i=0,z=-100;i<7;i++){personas(35,1.6,z,0);z+=2;}
for(i=0,z=-80;i<4;i++){personas(-22,1.6,z,0);z-=3;}
for(i=0,z=-10;i<5;i++){personas(-22,1.6,z,0);z-=5;}
for(i=0,z=-20;i<4;i++){personas(3,1.6,z,0);z-=4;}
for(i=0,z=-32.5;i<4;i++){personas(14,1.6,z,0);z-=3;}
for(i=0,z=45;i<4;i++){personas(-3,1.6,z,0);z-=3;}

//operadores de los paneles de control
personas(39,1.6,-100,1);
personas(9,1.6,-105,1);
personas(-25,1.6,-80,1);
personas(-25,1.6,-10,1);
personas(0,1.6,-20,1);
personas(12.5,1.6,-32.5,1);
personas(0,1.6,45,1);

//JUEGOS:

tren();
xtremfall();
cuncuna();
carrusel();
Rueda();
ovni();
Boomerang();
kamikaze();
c_voladores();
PosicionPC();

glutSwapBuffers();

luz+=0.66;

glPopMatrix();

glutSwapBuffers();
}

void PosicionPC()
{

Panel_control(39,-100,90);
Panel_control(10,-112.5,90);
Panel_control(-25,-80,0);
Panel_control(-25,-10,-90);
Panel_control(0,-20,0);
Panel_control(12.5,-32.5,90);
Panel_control(0,45,0);


}


void Panel_control(float a,float b,float alfa){

glPushMatrix();
glTranslated(a,1,b);
glRotated(alfa,0,1,0);
glRotated(-90,1,0,0);
glScalef(0.8,0.5,0.5);
glutSolidCube(3.0);
glColor3d(sin(luz),0,0);
glTranslated(1,1,1.5);
glutSolidSphere(0.25,slices,stacks);
glColor3d(cos(luz/2),cos(luz),0);
glTranslated(-1,0,0);
glutSolidSphere(0.25,slices,stacks);
glColor3d(0,0,sin(luz));
glTranslated(-1,0,0);
glutSolidSphere(0.25,slices,stacks);
glPopMatrix();
glColor3d(1,0,0);
}


void Postes(int a,int b){

glPushMatrix();
glTranslated(a,0,b);
glScalef(2,3,2);

glRotated(-90,1,0,0);
glColor3f(0.75,0.75,0.75);
glutSolidCone(0.15,4.0,slices,stacks);
glTranslated(0,0,3.8);
glutSolidSphere(0.12,slices,stacks);
for(i=0;i<4;i++)
{
glPushMatrix();
glColor3f(0.75,0.75,0.75);
glRotated(-90,1,0,0);
glRotated(90*i,0,1,0);
glutSolidCone(0.1,1.0,3,3);
glTranslated(0,0,1);
glColor3d(sin(luz/2),sin(luz/2),0);
glutSolidSphere(0.1,3,3);
glPopMatrix();
}
glPopMatrix();

}

void arbol(int a,int b)
{ 

glPushMatrix();
glTranslated(a,5,b);
GLUquadricObj *obj;
obj = gluNewQuadric();
gluQuadricDrawStyle(obj,GLU_FILL);

glPushMatrix();
glColor3f(0.60,0.40,0.12);
glRotated(90,1,0,0);
glScalef(0.3,0.8,0.8);
gluCylinder(obj,3,3,6,20,20);
glRotated(180,0,1,0);

for(i=0;(12-i/2)>=0;i+=1)
{
glColor3d(0,1,0);
glPushMatrix();
glTranslated(0,0,-3);
glRotated(0,0,1,0);
glTranslated(0,0,0.5*i);
glutSolidTorus(0.5,12-i/2,slices,stacks);
glPopMatrix();
}
glPopMatrix();
glPopMatrix();
}


void personas(float a,float b,float c,int d){


glPushMatrix();
glTranslated(a,b,c);
glScalef(0.5,0.5,0.5);

glPushMatrix();
glColor3d(1,1,0);
glTranslated(0,1,-8);
glRotated(60,1,0,0);
glutSolidSphere(0.7,slices,stacks);
glPopMatrix();

glPushMatrix();
if(d==0)glColor3d(0,0.8,0);
else if(d==1)glColor3d(0,1,1);
glTranslated(0,-2,-8);
glRotated(270,1,0,0);
glutSolidCone(1,3,slices,stacks);
glPopMatrix();

GLUquadricObj *obj;
obj = gluNewQuadric();

glPushMatrix();
glColor3d(0,0.8,0);
glTranslated(-1,0,-8);
glRotated(90,0,1,0);
gluCylinder(obj,0.2,0.2,2,10.0,10.0);
glPopMatrix();

glPushMatrix();
glColor3d(0.8,0.8,0);
glTranslated(-1.2,0,-8);
glutSolidSphere(0.3,slices,stacks);
glPopMatrix(); 

glPushMatrix();
glTranslated(1.2,0,-8);
glutSolidSphere(0.3,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3d(0.8,0,0);
glTranslated(0.5,-2,-8);
glRotated(90,1,0,0);
gluCylinder(obj,0.2,0.2,1,10.0,10.0);
glPopMatrix();

glPushMatrix();
glColor3d(0.8,0,0);
glTranslated(-0.5,-2,-8);
glRotated(90,1,0,0);
gluCylinder(obj,0.2,0.2,1,10.0,10.0);
glPopMatrix();

glPushMatrix();
glColor3d(1,0,0);
glTranslated(-0.5,-3,-8);
glutSolidCube(0.5);
glPopMatrix();

glPushMatrix();
glColor3d(1,0,0);
glTranslated(0.5,-3,-8);
glutSolidCube(0.5);
glPopMatrix();

glPopMatrix();
}


void Boomerang()
{
glColor3d(1,0,0);

for(i=0,c=0;i<5;i++)
{glPushMatrix();
if(c==0){glColor3d(0,0,sin(luz*(i+1))); c=1;}
else if(c==1){glColor3d(0,sin(luz*(i+1)),sin(luz*(i+1))); c=0;}
glTranslated(45,0,-106+(25*i)); glRotated(-90,1,0,0); glutSolidCone(0.5,2.0,slices,stacks);
glTranslated(0,0,2); glutSolidSphere(0.2,slices,stacks);
glTranslated(-5,0,-2); glutSolidCone(0.5,2.0,slices,stacks);
glTranslated(0,0,2); glutSolidSphere(0.2,slices,stacks);
glPopMatrix();
}

glPushMatrix();
glColor3d(1,1,1);
glTranslated(45,0,40); glRotated(-90,1,0,0); glutSolidCone(1,37,slices,stacks);
glTranslated(-5,0,0); glutSolidCone(1,37,slices,stacks);
glColor3d(sin(luz),sin(luz),0);
glTranslated(0,0,37);
glutSolidSphere(1.5,slices,stacks);
glTranslated(5,0,0);
glutSolidSphere(1.5,slices,stacks);
glPopMatrix();


glColor3d(1,1,1);
glPushMatrix();
glTranslated(45,3,0);
glRotated(-90,0,1,0);
glRotated(270,0,0,1);
GLint circle_points = 100;
glLineWidth(4);
glBegin(GL_LINE_STRIP);
glVertex2f(0.999,-106);
for (i=0; i < 16; i++)
{angle=2*PI*i/circle_points; glVertex2f(cos(angle),sin(angle));}
glVertex2f(-33.5,40);
glEnd();
glPopMatrix();

glPushMatrix(); 
glTranslated(40,3,0);
glRotated(-90,0,1,0);
glRotated(270,0,0,1);
glBegin(GL_LINE_STRIP);
glVertex2f(0.999,-106);
for (i=0; i < 16; i++)
{angle=2*PI*i/circle_points; glVertex2f(cos(angle),sin(angle));}
glVertex2f(-33.5,40);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(42.5,2.0,-106);
if(eb==0){ vbz+=1; glTranslated(0,0,vbz); if(vbz>106){eb=1; rotar=1;}}
else if(eb==1){ vbz+=1; vby+=0.89; glTranslated(0,vby,vbz); if(vby>=35){eb=2;}}
else if(eb==2){ vbz-=1*8; vby-=0.89*8; glTranslated(0,vby,vbz); if(vby<1.5){eb=3; rotar=-1;} }
else if(eb==3){ vbz-=4; glTranslated(0,0,vbz); if(vbz<0){eb=0;}}
if(rotar==1)glRotated(-30,1,0,0); if(rotar==-1)glRotated(0,1,0,0);
glPushMatrix();
glColor3d(1,1,0);
glScalef(2.5,2.5,8);
glutSolidSphere(0.5,slices,stacks);
glRotated(90,0,1,0); glutSolidCone(0.1,1.2,slices,stacks);
glRotated(-180,0,1,0); glutSolidCone(0.1,1.2,slices,stacks);
glPopMatrix();
glPopMatrix();
glLineWidth(1);

}

void cuncuna(){

glPushMatrix();
glTranslated(15,0,-10);
glScalef(0.6,0.6,0.6);

int i,j;
glPushMatrix(); 
glColor3d(0,0,0);
glTranslated(36,3,139.50);
glRotated(angulo,1,0,0);
glutSolidTorus(0.65,3,slices,stacks);
glPopMatrix();
glPushMatrix(); 
glColor4f(0.60,0.40,0.12,0);
glTranslated(36,5,141);
glutSolidSphere(6,slices,stacks);
glTranslated(3,0,-4);
glColor3d(1,1,1);
glutSolidSphere(3,slices,stacks);
glTranslated(0,0,-2.5);
glColor3d(0,0,0);
glutSolidSphere(1,slices,stacks);
glPopMatrix();
glPushMatrix(); 
glColor3d(1,1,1);
glTranslated(36,5,141);
glTranslated(-3,0,-4);
glutSolidSphere(3,slices,stacks);
glColor3d(0.75,0.75,0.75);
glTranslated(0,0,-0.98);
glutSolidSphere(2.25,slices,stacks);
glTranslated(0,0,-1.4);
glColor3d(0,0,0);
glutSolidSphere(1.1,slices,stacks);

glPopMatrix();

glPushMatrix();
glColor4f(0.60,0.40,0.12,0);
float b=0;
glTranslated(36,4,150);
glutSolidSphere(5.5,slices,stacks);

for(x=6.5,i=0;i<14;x-=1.5,i++)
{ if (i<=6)glTranslated(-5.5,x,0);
if(i>6){b+=0.65;glTranslated(-(5.5-b),-(5.5-b),0);}
glutSolidSphere(5.5-b,slices,stacks); 
}

glPopMatrix();

glPopMatrix();
}//end cuncuna


void carrusel(){

int j;
vcs+=1;

glPushMatrix();
glTranslated(0,0,80);
glScalef(2,3,2);

glPushMatrix();
glColor3d(sin(luz),0,0.5);
glTranslated(-15,4.5,-40);
glRotated(vcs,0,1,0);
glutSolidSphere(0.5,slices,stacks);
glRotated(-90,1,0,0);
glTranslated(0,0,-0.7);
glColor3d(0,0.5,1);

glutSolidCone(3.0,1.0,slices,stacks);
glRotated(180,0,1,0);

glutSolidCone(3.0,0,slices,stacks);

for(i=0,c=0,x=0,j=-1;i<8;i++,j*=-1)
{
glPushMatrix();
glRotated(-90,1,0,0);
glRotated(45*i,0,1,0);
glRotated(vcs,0,1,0);
glTranslated(0,0,3.0);
if(x==0){ glColor3d(0,sin(luz),0); x=1;}
else if(x==1){ glColor3d(sin(luz),sin(luz),0); x=0;}


glutSolidSphere(0.1,slices,stacks);
glRotated(90,1,0,0);
glutWireCone(0,3,2,1);
glTranslated(0,0,3);
glutSolidSphere(0.1,slices,stacks);


glPushMatrix();

if(c==0){glColor3d(1,0,1); c=1;}
else if(c==1){glColor3d(0,1,0); c=2;}
else if(c==2){glColor3d(1,1,0); c=0;}

glTranslated(0,0,-1);
glTranslated(0,0,sin(vcs*(j*0.1))/3);
glutSolidSphere(0.3,slices,stacks);
glTranslated(0.3,0,-0.3);
glutSolidSphere(0.2,slices,stacks);
glTranslated(-0.3,0,0.5);
glRotated(-135,0,1,0);
glutSolidCone(0.1,0.7,slices,stacks);
glTranslated(0,-0.2,0);
glutSolidSphere(0.1,slices,stacks);
glTranslated(0,0.4,0);
glutSolidSphere(0.1,slices,stacks);
glPopMatrix();
glPopMatrix();


}
glColor3d(0,0.5,1);
glTranslated(0,0,3);
glRotated(-180,0,1,0);
glutSolidCone(3.0,0,slices,stacks); 
glTranslated(0,0,-0.5);
glColor3d(1,1,1);
glutSolidCone(0.5,5.3,slices,stacks); 
glPopMatrix();

glPopMatrix(); 
}//end carrusel


void ovni(){

int y;
vo+=0.073;

glPushMatrix();
glTranslated(0,25,-3);
glColor3f(0.75,0.75,0.75);
glRotated((vo*2),0,1,0);
glTranslated(0,sin(vo),-50);
glRotated(vo*9,0,1,0);

glScalef(3.0f, 2.0f, 3.0f);
glutSolidSphere(0.9,slices,stacks);
glTranslated(0,-0.3,0);
glRotated(-90,1,0,0);
glutSolidCone(2.0,1.0,slices,stacks);
glutSolidTorus(0.2,2.0,slices,stacks);
glRotated(-180,1,0,0);
glutSolidCone(2.0,0.6,slices,stacks);
for(i=0,y=0;i<18;i++)
{glPushMatrix();
glRotated(90,1,0,0);
glRotated(20*i,0,1,0);
glTranslated(0,0,2.05);
if(y==0){glColor3d(sin(luz),0,0);y=1;}
else if(y==1){glColor3d(0,sin(luz),0);y=2;}
else if(y==2){glColor3d(0,0,sin(luz));y=0;}
glutSolidSphere(0.2,slices,stacks);
glPopMatrix();
} 
glPopMatrix();
}//end ovni


void Rueda(){ 

if(er==1)vr-=1;
else vr+=1;
if(vr>180)er=1;
else if(vr<-180) er=2;

glColor3d(1,1,0);

glPushMatrix();
glTranslated(-25,0,0);
glScalef(4,4,4); 

glPushMatrix();
glTranslated(10,4,-8.3);
glRotated(vr,0,0,1);
glColor3d(sin(luz/9),1,0); c=1; 
glutWireTorus(0.3,2.2,6,stacks);

glColor3d(1,0,0);
for(i=0;i<30;i++)//30
{
glPushMatrix(); 
glRotated(90,0,1,0);
glRotated(12*i,1,0,0);
glutWireCone(0,1.89,2,1);
glPopMatrix();
}

for(i=0;i<=12;i++)
{
glPushMatrix();
glColor3d(0,1,1);
glRotated(90,0,1,0);
glRotated(30*i,1,0,0);
glTranslated(0,2.4,0);
glTranslated(-0.2,0,0);
glRotated(270,1,0,0);
glutSolidCone(0.05,0.5,slices,stacks);
glTranslated(0.4,0,0);
glutSolidCone(0.05,0.5,slices,stacks);
glTranslated(-0.2,0,0.5);
glRotated(vr,1,0,0);
glutSolidCube(0.2);
glTranslated(0,0.1,0);
glutSolidCube(0.1);
glPopMatrix();
} 

glutSolidCone(0.2,0.7,slices,stacks);
glRotated(180,1,0,0);
glutSolidCone(0.2,0.7,slices,stacks);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,1);
glTranslated(10,4,-9);
glRotated(90,0,1,0);
glutSolidSphere(0.1,slices,stacks);
glTranslated(-1.4,0,0);
glutSolidSphere(0.1,slices,stacks);
glTranslated(0,-3.4,0);
glRotated(180,0,1,1);
glutSolidCone(0.2,3.4,slices,stacks);
glColor3d(0,0,1);
glutSolidCube(0.8);
glTranslated(-1.4,0,0);
glColor3d(1,1,1);
glutSolidCone(0.2,3.4,slices,stacks);
glColor3d(0,0,1);

glutSolidCube(0.8);
glPopMatrix();
glPopMatrix();
}//end Rueda

void kamikaze(){

if(ek==1)vk-=9*tiempok;
else vk+=9*tiempok;
if(vk>topek){topek+=25; ek=1;}
if(vk<-topek){topek+=25; ek=2;}
if(topek<600)tiempok+=0.002;
if(topek>600 && topek<750){ tiempok-=0.0041;}
if(topek==750){tiempok=0;topek=25; vk=0;}

glPushMatrix();
glTranslated(0,0,-75);
glRotated(90,0,1,0);
glScalef(3,5,3); 

glPushMatrix();
glColor3d(1,1,1);
glTranslated(-0.4,4.4,-9);
glRotated(angulo*2,0,1,0);
glutSolidCone(0.3,1.5,slices,stacks);
glTranslated(0,0,-0.65);
glColor3d(1,1,0);
glutSolidSphere(0.1,slices,stacks);
glRotated(-angulo*2,1,0,0);
glTranslated(0,0,-3.9);
glutSolidCone(0.35,4.0,slices,stacks); 
glColor3d(1,0,0);
glutSolidCube(0.8);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,1);
glTranslated(0.4,4.4,-9);
glRotated(angulo*-2,0,1,0);
glutSolidCone(0.3,1.5,slices,stacks);
glTranslated(0,0,-0.65);
glColor3d(1,1,0);
glutSolidSphere(0.1,slices,stacks);
glRotated(-angulo*2,1,0,0);
glTranslated(0,0,-3.9);
glutSolidCone(0.35,4.0,slices,stacks);
glColor3d(1,0,0);
glutSolidCube(0.8);
glPopMatrix();

glColor3d(0,1,1);

glPushMatrix(); 
glTranslated(0.35,4.4,-9);
glRotated(-vk/2,1,0,0);
glutSolidSphere(0.33,slices,stacks);
glRotated(angulo*2,1,0,0);
glutSolidCone(0.3,3,slices,stacks);
glTranslated(0,0,3);
glRotated(25.5,1,0,0);
glutSolidSphere(0.3,slices,stacks);
glRotated(angulo*2,1,0,0);
glutSolidCone(0.3,3,slices,stacks);
glRotated(angulo*3,1,0,0);
glutSolidCone(0.3,3,slices,stacks);
glPopMatrix();

glPushMatrix(); 
glTranslated(-0.35,4.4,-9);

glRotated(vk/2,1,0,0); 
glutSolidSphere(0.33,slices,stacks);
glRotated(angulo*2,1,0,0);
glutSolidCone(0.3,3,slices,stacks);
glTranslated(0,0,3);
glRotated(25.5,1,0,0);
glutSolidSphere(0.3,slices,stacks); 
glRotated(angulo*2,1,0,0);
glutSolidCone(0.3,3,slices,stacks);
glRotated(angulo*3,1,0,0);
glutSolidCone(0.3,3,slices,stacks); 
glPopMatrix();

glPopMatrix();
}//end kamikaze

void c_voladores(){

if(ecv1==1)vcv-=2;
else vcv+=2;
if(ecv2==1)ccv-=3;
else ccv+=3;

if(vcv<0) ecv1=2;
else if(vcv>220) ecv1=1;
if(ccv<-180) ecv2=2;
else if(ccv>180) ecv2=1;

glPushMatrix(); 
glTranslated(-15,0,35);
glScalef(3,4,3);

glPushMatrix(); 
glTranslated(10,4,-50);
glRotated(angulo*2,1,0,0);
glColor3d(1,1,1);
glutSolidSphere(0.6,slices,stacks);
glColor3d(1,1,1);
glutSolidCone(0.35,4.0,slices,stacks);
glTranslated(0,0,3.5);
glRotated(180,1,0,0);
glutSolidCone(0.35,4.0,slices,stacks);
glutSolidCube(0.8); 
glPopMatrix();

glPushMatrix();
glColor3d(0,0,1);
glTranslated(10,4,-50);
glRotated(angulo*2,1,0,0);
glRotated(-ccv,0,0,1);
glutSolidTorus(0.28,0.7,slices,stacks);
glPopMatrix();

for(i=0;i<8;i++)
{ 
glPushMatrix();
glColor3d(1,1,1);
glTranslated(10,4,-50);
glRotated(ccv,0,1,0); 
glRotated(angulo*i,0,1,0);
glutSolidCone(0.3,3.0,slices,stacks); 
glTranslated(0,0,-3);
glColor3d(0,0,1);
glutSolidSphere(0.2,3,3);
glRotated(angulo*2,1,0,0); 
glColor3d(1,0,0);
glRotated(vcv/3,1,0,0);
glutWireCone(0.0,2,2,1); 
glTranslated(0,0,2.1);
glutSolidSphere(0.2,9,9); 
glPopMatrix();
}

glPopMatrix();
}//end c_voladores


void tren(){

int i;
const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;

GLUquadricObj *obj;
obj = gluNewQuadric();

glPushMatrix();

glPushMatrix();
glTranslated(0,0,80);
glScalef(0.5,0.5,0.5); 

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glColor3d(1,0,0); //vagon principal 
glTranslated(-10,2,-50);
glRotated(90,0,1,0);
glTranslated(0,0,0);
gluCylinder(obj,3.0,3.0,15.0,20.0,20.0);
glRotated(90,1,0,0); //chimenea
glColor3d(0,1,1);
glTranslated(0,3,-6);
gluCylinder(obj,1.0,1.0,3.0,10.0,10.0);
glRotated(90,1,0,0);
glColor3d(1,1,0);
glTranslated(0,6,3);
gluCylinder(obj,2.5,1.6,2.0,10.0,10.0);
glTranslated(0,-0.7,-22);
glColor3d(1,1,0);
glutSolidCube(7);
glTranslated(0,0,-10);
glutSolidCube(7);
glColor3d(0,1,1);
glTranslated(0,-3.7,19);
glutSolidCube(3);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,0);
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(-8,1.7,-50);
glutSolidSphere(2.8,16,16);
glPopMatrix();

glPushMatrix();
glColor3d(1,1,0);
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(3,1.7,-50);
glutSolidSphere(2.8,16,16);
glPopMatrix();

glColor3d(1,1,1);
glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(-8,-1,-47); //rueda 1 vagon principal
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(-3,-1,-47); //rueda 2 vagon principal
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(2,-1,-47); //rueda 3 vagon principal
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glColor3d(1,1,1);
glPushMatrix();
//ruedas chicas de vagones de carga
glTranslated(0,3,3); //rueda 1 chica vagon de carga 1 lado A
glRotated(a/9,0,1,0);
glTranslated(10.3,-1.6,-46);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 1 chica vagon de carga 1 lado B
glRotated(a/9,0,1,0);
glTranslated(10.3,-1.6,-54);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 2 chica vagon de carga 1 lado A
glRotated(a/9,0,1,0);
glTranslated(13.3,-1.6,-46);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 2 chica vagon de carga 1 lado B
glRotated(a/9,0,1,0);
glTranslated(13.3,-1.6,-54);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 1 chica vagon de carga 2 lado A
glRotated(a/9,0,1,0);
glTranslated(20.3,-1.6,-46);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 1 chica vagon de carga 2 lado B
glRotated(a/9,0,1,0);
glTranslated(20.3,-1.6,-54);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 2 chica vagon de carga 2 lado A
glRotated(a/9,0,1,0);
glTranslated(23.3,-1.6,-46);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3); //rueda 2 chica vagon de carga 2 lado B
glRotated(a/9,0,1,0);
glTranslated(23.3,-1.6,-54);
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(0.5,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);

glLineWidth(2);

glBegin(GL_LINE_STRIP); //linea que une ruedas del vagon 2 de carga lado A
glVertex3d(20.3,-1.6,-46);
glVertex3d(23.3,-1.6,-46);
glEnd();
glBegin(GL_LINE_STRIP); //linea que une ruedas del vagon 2 de carga lado B
glVertex3d(20.3,-1.6,-54);
glVertex3d(23.3,-1.6,-54);
glEnd();

glBegin(GL_LINE_STRIP);
glVertex3d(10.3,-1.6,-46); //linea que une ruedas del vagon 1 de carga lado A
glVertex3d(13.3,-1.6,-46);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex3d(10.3,-1.6,-54); //linea que une ruedas del vagon 1 de carga lado B
glVertex3d(13.3,-1.6,-54);
glEnd();

glColor3d(1,1,1);
glBegin(GL_LINE_STRIP); //adorno vagon principal
glVertex3d(-8,2,-47);
glVertex3d(2,2,-47);
glEnd();

glBegin(GL_LINE_STRIP); //linea que une los vagones
glVertex3d(0,-0.5,-50);
glVertex3d(25,-0.5,-50);
glEnd();

glBegin(GL_LINE_STRIP); //linea desde rueda 1 a rueda 3 lado B
glVertex3d(-8,-1,-53);
glVertex3d(2,-1,-53);
glEnd();

glBegin(GL_LINE_STRIP); //linea desde rueda 1 a rueda 3 lado A
glVertex3d(-8,-1,-47);
glVertex3d(2,-1,-47);
glEnd();

glPopMatrix();

glColor3d(1,1,1);
glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(-8,-1,-53); //rueda 4
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(-3,-1,-53); //rueda 5
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glPushMatrix();
glTranslated(0,3,3);
glRotated(a/9,0,1,0);
glTranslated(2,-1,-53); //rueda 6
glRotated(180,1,0,0);
glRotated(-a/2,0,0,1);
glutWireTorus(1.2,0.8,2,16);
glPopMatrix();

glPopMatrix();

glPopMatrix();
}//end tren


void xtremfall(){

const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
const double a = t*90.0;

glColor3d(1,0,0);

GLUquadricObj *obj;
obj = gluNewQuadric();
glPushMatrix();
glTranslated(20,0,45);
glScalef(2,4,2);
glPushMatrix();
glColor3d(1,1,1); 
glTranslated(-10,12,-30);
glRotated(90,1,0,0);
gluCylinder(obj,0.6,0.6,12.0,20,20);
glPopMatrix();


glPushMatrix();
glColor3d(1,1,0); 
glTranslated(-10,donay,-30);
glRotated(90,90,0,0);
glutSolidTorus(0.5,1.0,slices,stacks);
glPopMatrix();

if(donay>10){
flag1=1;
flag2=0;
}
else{
if(donay<=1){
flag1=0;
flag2=1;
}
}
if(flag1==1&&flag2==0)
donay=donay-0.8;
if(flag2==1&&flag1==0)
donay=donay+0.1; 

glPushMatrix();
glColor3d(sin(luz*4),sin(luz),cos(luz/2));
glTranslated(-10,11,-30);
glutSolidSphere(1.3,slices,stacks);
glPopMatrix();

glPopMatrix();
}


static void idle(void){
glutPostRedisplay();
}


int
main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(1024,768);
glutInitWindowPosition(10,10);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

glutCreateWindow(" <<>> ");

glutReshapeFunc(resize);
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);

glutSpecialFunc( specialFunc );
glutIdleFunc(idle);

glutMainLoop();

return EXIT_SUCCESS;
}
