/*
 * tierra.cpp
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
double rotate_y=0;
double rotate_x=80;
double rotate_z=168;

 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 0.3f;
//Definición del modelo de una luz
GLfloat light_Ambient [4] = { 0.2, 0.2, 0.2, 1.0};
GLfloat light_Diffuse [4] = { 1.0, 1.0, 1.0, 1.0};
GLfloat light_Position [4] = {0.0, 1.0, -10.0, 5.0};
//Materiales
GLfloat verdeMaterial [4] = {0.0, 1.0, 0.0, 0.0 };
GLfloat rojoMaterial [4] = {1.0, 0.0, 0.0, 0.0 };
GLfloat azulMaterial [4] = {0.0, 0.0, 1.0, 0.0 };
GLfloat naranjaMaterial [4] = {1.0, 0.5, 0.0, 0.0 };
GLfloat blancoMaterial [4] = {1.0, 1.0, 1.0, 0.0 };

void luces(void){
    //glShadeModel(GL_SMOOTH);

    // Activamos la fuente de luz
		glEnable (GL_LIGHTING);
        glEnable (GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_Ambient );
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Diffuse );
        glLightfv(GL_LIGHT0, GL_POSITION, light_Position );
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
      //glLineWidth(1);
      //Eje X    rojo
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(  -1.5, 0.0, 0.0 );
    glVertex3f(  1.5, 0.0, 0.0 );
    glEnd();
      // EJE Y  Verde
    glBegin(GL_LINES);
    glColor3f(0.15, 0.85, 0.29);
    glVertex3f(  0.0, -1.5, 0.0 );
    glVertex3f(  0.0, 1.5, 0.0 );
    glEnd();
      
        // EJE z  Azul
    glBegin(GL_LINES);
    glColor3f(0.18, 0.14, 0.79);
    glVertex3f(  0.0, 0.0, 1.5 );
    glVertex3f(  0.0, 0.0, -1.5 );
    glEnd();
    
    glFlush();    
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

//funcion que dibuja y mapea esp
void drawSphere(int nMaj, int nMin, float radius) {
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blancoMaterial);
	// cargamos la imagen
	  texture[0] = SOIL_load_OGL_texture 
                     (
                "images/tierra/tierra.bmp",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );
	
	double majorStep= M_PI / nMaj, minorStep= 2*M_PI / nMin;
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	//Creando vectores para las 3 dimensiones
	for (float i = 0; i <= nMaj; ++i) { 
		double a,b,r0,r1; 
		GLfloat z0,z1;
		
		//vertice1 del trangulo
		a = i * majorStep;
		// vertice que  
		b = a + majorStep;
		//vectores iniciales rz
		r0 = radius * sin(a);
		z0 = radius * cos(a);
		z1 = radius * cos(b);
		r1 = radius * sin(b);
		//dibujando paso de vector anterior y posicionando coordenadas de mapeo
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0, 1.0, 1.0);
		for (float j = 0; j <= nMin; ++j) { 
			GLfloat x,y;
			//vector inicial
			double c = j * minorStep;
			
			//funciones de onda para x,y 
			x = cos(c); 
			y = sin(c);
			
		//SEGMENTOS
			//PRIMER TRIANGULO
			//vector inicial determinado por el paso
			glNormal3f( (x*r0)/radius, (y*r0)/radius, z0/radius);
			//cordenadas de mapeo definidas por el reccorrido
			glTexCoord2f( j/(GLfloat) nMin, i/(GLfloat)nMaj);
			//Dibujo de lineas de primer
			glVertex3f( x * r0, y * r0, z0);
			
			//SEGUNDO TRIANGULOS
			//para coordenas y vectores del paso en posicion final
			glNormal3f( (x*r1)/radius, (y*r1)/radius, z1/radius);
			glTexCoord2f( j/(GLfloat)nMin, (i+1)/(GLfloat)nMaj);
			glVertex3f( x * r1, y * r1, z1);
		} /* for j */
		glEnd(); /* triangle strip */
	} /* for i */
	glDisable (GL_TEXTURE_2D); 
	//glDisable(GL_CULL_FACE);
} /* drawSphere */
void sphereOther()
{
	//Azul
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, azulMaterial);
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(1.0,0.0,-1.5);
	glutSolidSphere(0.5,100,100);
	
	//Verde
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, verdeMaterial);
	glColor3f(0.0, 0.55, 0.0);
	glTranslatef(1.0,0.0,1.3);
	glutSolidSphere(0.7,100,100);
	
	//Roja
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, rojoMaterial);
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(1.0,-1.3,0.0);
	glutSolidSphere(0.7,100,100);
	
	//Naranja
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, naranjaMaterial);
	glColor3f(1.0, 0.51, 0.0);
	glTranslatef(0.2,-0.2,1.7);
	glutSolidSphere(0.5,100,100);
}
void display()
{
    //  Borrar pantalla y Z-buffer
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		 //FUNCIONES
		 luces();
			movimiento();
			//ejes();
			//pasando parametro a funcion creada
			drawSphere(100,100,1.0);
			sphereOther();
		glPopMatrix();
	glFlush();
	glutSwapBuffers();

 
}
 
void update(int value)
{
		rotate_z+=8;

		glutPostRedisplay();
		glutTimerFunc(25, update, 0);
} 
void init(void)
{
    //glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);

    // Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    //glEnable(GL_LIGHT2);
    //glEnable(GL_LIGHT3);
    //glEnable(GL_LIGHT4);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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
    else if (key == GLUT_KEY_F7)
        rotate_z += 8;
    //  Tecla especial F2 : rotación en eje Z negativo 7 grados
    else if (key == GLUT_KEY_F8)
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
        break;
    case 'q':
        exit(0);            // exit
    }
    
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
 
    //  Inicializar los parámetros GLUT y de usuario proceso
    glutInit(&argc,argv);
 
    // Solicitar ventana con color real y doble buffer con Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-600)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
    
    //init();
    luces();
    
    // Crear ventana
    glutCreateWindow("Tierra por Teclas AG18");
    
    // Habilitar la prueba de profundidad de Z-buffer
    glEnable(GL_DEPTH_TEST);
 
    // Funciones de retrollamada
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutTimerFunc(30, update, 0);
 
    // Pasar el control de eventos a GLUT
    glutMainLoop();
 
    // Regresar al sistema operativo
    return 0;
 
}
