#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
int material=3;
int winw, winh;               // Ancho y alto de nuestra ventana, en pixeles, la guardamos para utilizarla en reshape
int mouse_state,mouse_button;
//Variables de posicion
GLfloat pos_x = 0.0;
GLfloat pos_y = 0.0;
GLfloat pos_z = 0.0;
//Variables para guardar las posiciones del mouse
bool mouseleftdown = false;   // Es verdadero si precionamos el boton izquierdo de nuestro mouse
bool mouseleftdownmotion = false; // Es verdadero si precionamos el clic izquierdo y movemos el puntero de nuestro mouse
int mousex, mousey;   //En esta variables guardamos las posiciones que toma el puntero en "X" y "Y"


void tipo_material(void){
	
	if (material==3) {
		// Propiedades del material
		GLfloat mat_ambient[] = { 0.24725,0.1995,0.0745};
		GLfloat mat_diffuse[] = { 0.75164,0.60648,0.22648};
		GLfloat mat_specular[] = { 0.628281,0.555802,0.366065};
		GLfloat shine[]={40.8974f};
		
		//setMaterial
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	}
	if (material==2) {
		// Propiedades del material
		GLfloat mat_ambient[] = { 0.19125,0.0735,0.0225};
		GLfloat mat_diffuse[] = { 0.7038,0.27048,0.0828};
		GLfloat mat_specular[] = { 0.256777,0.137622,0.086014};
		GLfloat shine[]={40.8974f};
		
		//setMaterial
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	}
	if (material==1) {
		// Propiedades del material
		GLfloat mat_ambient[] = { 0.0,0.0,0.0};
		GLfloat mat_diffuse[] = { 0.5,0.0,0.0};
		GLfloat mat_specular[] = { 0.7,0.6,0.6};
		GLfloat shine[]={40.8974f};
		
		//setMaterial
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	}
	if (material==4) {
		// Propiedades del material
		GLfloat mat_ambient[] = {0.329412,0.223529,0.027451};
		GLfloat mat_diffuse[] = { 0.780392,0.568627,0.113725};
		GLfloat mat_specular[] = { 0.992157,0.941176,0.807843};
		GLfloat shine[]={40.8974f};
		
		//setMaterial
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	}
	if (material==5) {
		// Propiedades del material
		GLfloat mat_ambient[] = {0.19225,0.19225,0.19225};
		GLfloat mat_diffuse[] = { 0.50754,0.50754,0.50754};
		GLfloat mat_specular[] = { 0.508273,0.508273,0.508273};
		GLfloat shine[]={40.8974f};
		
		//setMaterial
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, shine);
	}
		// "Limpiamos" el frame buffer con el color de "Clear", en este
		// caso negro.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode( GL_MODELVIEW_MATRIX );
		glLoadIdentity();
		gluLookAt(1.0, 0.1, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	    glScaled(1.0, 1.0, 1.0);
		glPushMatrix();
		glTranslatef(0.0f,0.0f,0.0f);
}

void init(void)
{
	winw=200; 
	winh=200;
	 //Convirtiendo las posiciones tomadas con el mouse a cordenadas del sistema OpenGL
    GLfloat posicionx = mousex/winw;
    GLfloat posiciony = 1-mousey/winh;
	GLfloat punto_luz[]={pos_x,pos_y,pos_z};
	GLfloat luz_ambiental[]={1.0,1.0,1.0};
	// Activamos la fuente de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); //Activamos las luces en 0
	glDepthFunc(GL_LESS); //comparación de profundidad
	glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
	glLightfv(GL_LIGHT0,GL_POSITION,punto_luz);
	//glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_FALSE);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,luz_ambiental);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glShadeModel(GL_SMOOTH);
}

//funcion que ejerce el motion cuando se presiona el click izquierdo y arrastres
void motion(int x, int y)
{
	GLdouble model[4*4];
	GLdouble proj[4*4];
	GLint view[4];
	GLdouble pan_x, pan_y, pan_z;
	if (mouse_state == GLUT_DOWN && mouse_button == GLUT_LEFT_BUTTON) 
	{
		glGetDoublev(GL_MODELVIEW_MATRIX, model);//devuelve el valor o valores de un parametro seleccionado 
		glGetDoublev(GL_PROJECTION_MATRIX, proj);
		glGetIntegerv(GL_VIEWPORT, view);

		
		gluProject((GLdouble)x, (GLdouble)y, 0.0,model, proj, view,&pan_x, &pan_y, &pan_z);
		
		gluUnProject((GLdouble)x, (GLdouble)y, pan_z,model, proj, view,&pan_x, &pan_y, &pan_z);
		pan_y = -pan_y;

        init();
		pos_x = pan_x;
		pos_y = pan_y;
		pos_z = pan_z;

		glutPostRedisplay();
	}
}


//La funcion GLUT mouse que llamaremos en glutMouseFunc dentro de su estructura capturamos las posiciones del mouse haciendo uso de otras funciones
void mouse(int button, int state, int x, int y)
{
   //Guarda el estado del boton izquierdo del mouse
   if (button == GLUT_LEFT_BUTTON)
   {
      mouseleftdown = (state == GLUT_DOWN);
      glutPostRedisplay();  // Cuando hay un cambio en el boton izquierdo vuelve a dibujar
   }
   init();
   //Guarda las posiciones del mouse
   mousex = x;
   mousey = y;
   
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	// Activamos la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// "limpiamos" esta con la matriz identidad.
	glLoadIdentity();
	// Usamos proyeccion ortogonal
	glOrtho(-300, 300, -300, 300, -300, 300);
	// Activamos la matriz de modelado/visionado.
	glMatrixMode(GL_MODELVIEW);
	// "Limpiamos" la matriz
	glLoadIdentity();
}

void display(void)
{
	tipo_material();
	glScalef(100, 100, 100);	
	glutSolidTetrahedron();
	glFlush();
}
// Función para controlar teclas normales del teclado.
void keyboard(unsigned char key, int x, int y)
{
    //control de teclas que hacen referencia a Escalar y transladar el cubo en los ejes X,Y,Z.
    switch (key)
    {
    case 'c':
    case 'C':
        material=1;
        break;
    case 'r':
    case 'R':
		material=2;
		break;
	case 'g':
	case 'G':
		material=3;
		break;
	case 'b':
	case 'B':
		material=4;
		break;
	case 's':
	case 'S':
		material=5;
		break;
     }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
	// Inicializo OpenGL
	glutInit(&argc, argv);
	// Activamos buffer simple y colores del tipo RGB
	glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
	// Definimos una ventana de medidas 800 x 600 como ventana
	// de visualizacion en pixels
	glutInitWindowSize (600, 600);
	// Posicionamos la ventana en la esquina superior izquierda de
	// la pantalla.
	glutInitWindowPosition (250, 150);
	// Creamos literalmente la ventana y le adjudicamos el nombre que se
	// observara en su barra de titulo.
	glutCreateWindow ("Esfera con materiales");
	// Inicializamos el sistema
	init();
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutMainLoop();
	return 0;
}
