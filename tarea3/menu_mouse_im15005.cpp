/*
 * menu_mouse_im15005.cpp
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

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>


//DECLARACION DE VARIABLES A UTILIZAR
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;
 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 2.0f;


float winWid,winHeight;
float rx,ry; // variables que representan las coordenadas
int vf[5]={2}; // vector donde almacenaremos el id de la imagen a imprimir

using namespace std;
void init(void)
{
	glEnable(GL_DEPTH_TEST);
	// Ubicamos la fuente de luz en el punto
   // GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	// ejemplo de ambiente
    GLfloat lmodel_ambient [] = { 0.2, 0.2, 0.2, 1.0 };
	// Activamos la fuente de luz

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
   // glLightfv(GL_LIGHT0,GL_POSITION,light_position);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void material(GLfloat amb1,GLfloat amb2,GLfloat amb3,GLfloat dif1,GLfloat dif2,GLfloat dif3,GLfloat spe1,GLfloat spe2,GLfloat spe3) {
	glPushMatrix();
	GLfloat mat_ambient[] = { amb1,amb2,amb3};
    GLfloat mat_diffuse[] = { dif1,dif2,dif3};
    GLfloat mat_specular[] = { spe1,spe2,spe3};
    GLfloat shine[] = {27.8974f};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
    glPushMatrix();
	// Aplicar Material
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    
}
void movimientoTeclas(void)
{
	glPushMatrix();
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glRotatef( rotate_z, 0.0, 0.0, 1.0 );
	//Trasladar con Teclas
	glTranslatef(X, Y, Z); 	
	//trasladar con Mouse
	glTranslated((rx*0.005),(ry*0.005),0.0);
	glScalef(scale, scale, scale);
				
}


//menu de opciones
void menu(int opc){
    vf[1]=opc; // En el vector VF, en su campo 1, se almacenara el id de la imagen
    switch(opc){ // imagen elegida para mostrar
       case 1:
			//Esfera
           //Aplicando material emerald
           material(0.0215,0.1745,0.0215,0.07568,0.61424,0.07568,0.633,0.727811,0.633);
		   movimientoTeclas();
           glutSolidSphere(1.0,100,100);
           break;

       case 2:
           //Cubo
           //Aplicando material jade
           material(0.135,0.2225,0.1575,0.54,0.89,0.63,0.316228,0.316228,0.316228);
           movimientoTeclas();
           glutSolidCube(1.0);
          
           break;
       case 3:
           //Cono
           //Aplicando material pearl
           material(0.25,0.20725,0.20725,1,0.829,0.829,0.296648,0.296648,0.296648);
           movimientoTeclas();
           glutSolidCone(0.5,1.0,50,50);
           break;
       case 4:
           //Tetera
           //Aplicando material brass
           material(0.329412f,0.223529f,0.027451f,0.780392f,0.568627f,0.113725f,0.992157f, 0.941176f, 0.807843f);
           movimientoTeclas();
           glutSolidTeapot(0.7);
           break;
       case 5:
			//Tetraedro	
			//Aplicando material turquiose
			material(0.1,0.18725,0.1745,0.396,0.74151,0.69102,0.297254,0.30829,0.306678);
			movimientoTeclas();
           glutSolidTetrahedron();
           break;
       case 6:
           //Octahedro 
           //Aplicando material red rubber	
           material(0.05,0.0,0.0,0.5,0.4,0.4,0.7,0.04,0.04);
           movimientoTeclas();
           glutSolidOctahedron();

        break;
       case 7:
           //Dodecahedro
           //Aplicando material white rubber
           material(0.05,0.05,0.05,0.5,0.5,0.5,0.7,0.7,0.7);
            movimientoTeclas();
           glutSolidDodecahedron();
			glFlush();
            break;
       case 8:
           //Icosahedro
           //aplicando material green rubber
           material(0.0,0.05,0.0,0.4,0.5,0.4,0.04,0.7,0.04);
			movimientoTeclas();	
			glutSolidIcosahedron();
           break;
       case 9:
           //Torus
           //material Ruby
           material(0.1745,0.01175,0.01175,0.61424,0.04136,0.04136,0.727811,0.626959,0.626959);
		   movimientoTeclas();
           glutSolidTorus(0.5,1.0,50,50);
           break;
       case 10:
           //Salir
			exit(0);
           break;
   }
   glPopMatrix();
   glFlush();
   glutSwapBuffers();
}

// METODO QUE REPINTA LA PANTALLA
void display( void ){
    //Limpiando la pantalla
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // Haciendo uso del metodo menu, pasandoles como paramentro el id
    // de la figura que se eligio, así pues cada vez que se pueda el cursor
    // dicha imagen se repintara
     menu(vf[1]);
    
}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER CLICK REDECHO
void motion(int x, int y){
    cout << "Movimiento. x:" << x << ", y:" << y << " \n";
     rx = float(x);
     ry = winHeight - float(y);

}

// OBTENIENDO EL LA POSICION DEL RATON AL HACER MOVER EL CURSO Y PRESIONAR EL CLICK DERECHO
void mousebutton(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        rx = float(x);
        ry = winHeight - float(y);
        display();
    }
}
 
// Función para controlar teclas especiales
void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 7;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 7;
    else if (key == GLUT_KEY_UP)
        rotate_x += 7;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 7;
    else if (key == GLUT_KEY_F2)
        rotate_z += 7;
    else if (key == GLUT_KEY_F2)
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
        scale=0.7d;
        break;
    case 'd':
        scale=2.0;
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
        exit(0);// exit
    }
    glutPostRedisplay();
}
int main(int argc, char *argv[]){
    winWid = 800.0;
    winHeight = 800.0;
    
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (winWid, winHeight);
   glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-winWid)/2,(glutGet(GLUT_SCREEN_HEIGHT)-winHeight)/2);
   glutCreateWindow ("Menus IM15005");
   init();

    // CREACION DEL MENU PARA ELEGIR ALGUNA IMAGEN
    glutCreateMenu(menu);
      glutAddMenuEntry("ESFERA",1);
      glutAddMenuEntry("CUBO",2);
      glutAddMenuEntry("CONO",3);
      glutAddMenuEntry("TETERA",4);
      glutAddMenuEntry("TETRAHEDRO",5);
      glutAddMenuEntry("OCTAHEDRO",6);
      glutAddMenuEntry("DODECAHEDRO",7);
      glutAddMenuEntry("ICOSAHEDRO",8);
      glutAddMenuEntry("TORUS",9);
      glutAddMenuEntry("SALIR",10);
    glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton
    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);
    glutMouseFunc(mousebutton);
    
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();




    return 0;
}
