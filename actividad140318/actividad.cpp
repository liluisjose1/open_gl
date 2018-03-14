#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
void display(void)
{
	glClearColor(0,1,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);
    glColor3f( 1.0, 1.0, 1.0 );
    
    
    GLfloat angulo;
    int i;
    glBegin(GL_POINTS); //GL_Lines para ver la circunferencias con lineas
    //dibujando Circulo central circunferencia completa
    for (i=0; i<360; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(2*cos(angulo), 2*sin(angulo),0.0f);
     }
     //dibujando saques de esquina
     //saque de esquina superior izquierda
    for (i=180; i<270; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(9+cos(angulo), 9+sin(angulo),0.0f);
     }
     //saque de esquina inferior izquierda
    for (i=0; i<90; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(-9+cos(angulo), -9+sin(angulo),0.0f);
     }
     //saque de esquina inferior derecha
    for (i=90; i<180; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(9+cos(angulo), -9+sin(angulo),0.0f);
     }
      //saque de esquina superior derecha
    for (i=270; i<360; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(-9+cos(angulo), 9+sin(angulo),0.0f);
     }
     
    //Dibujando medias lunas de las areas 
    for (i=0; i<90; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(-6+1*cos(angulo), 2*sin(angulo),0.0f);
     }
    for (i=270; i<360; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		//ubicando posiciones donde dibujar (posicion) + puntos a dibujar
		glVertex3f(-6+1*cos(angulo), 2*sin(angulo),0.0f);
     }
    for (i=90; i<180; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(6+1*cos(angulo), 2*sin(angulo),0.0f);
     }
    for (i=180; i<270; i+=1)
	{
		angulo =i*M_PI/180.0f; //grados a radianes
		glVertex3f(-9.0f,9.0f,0.0f);
		glVertex3f(6+1*cos(angulo), 2*sin(angulo),0.0f);
     }
    glEnd();
    //dibujando las lineas de banda de la cancha
    glBegin(GL_LINES);
    
			//lineas de banda 
			glVertex2f(-9.0f, 9.0f);
			glVertex2f(9.0f, 9.0f);
			glVertex2f(9.0f, 9.0f);
			glVertex2f(9.0f, -9.0f);
			glVertex2f(9.0f, -9.0f);
			glVertex2f(-9.0f, -9.0f);
			glVertex2f(-9.0f, -9.0f);
			glVertex2f(-9.0f, 9.0f);
			glVertex2f(0.0f, 9.0f);
			glVertex2f(0.0f, -9.0f);
			
			//Area pequeña de porteria izquierda
			glVertex2f(-9.0f, 2.0f);
			glVertex2f(-8.0f, 2.0f);
			glVertex2f(-8.0f, 2.0f);
			glVertex2f(-8.0f, -2.0f);
			glVertex2f(-9.0f, -2.0f);
			glVertex2f(-8.0f, -2.0f);
			//Area grande de porteria izquierda
			glVertex2f(-9.0f, 4.0f);
			glVertex2f(-6.0f, 4.0f);
			glVertex2f(-6.0f, 4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-6.0f, -4.0f);
			glVertex2f(-9.0f, -4.0f);
			
			//Area pequeña de porteria derecha
			glVertex2f(9.0f, 2.0f);
			glVertex2f(8.0f, 2.0f);
			glVertex2f(8.0f, 2.0f);
			glVertex2f(8.0f, -2.0f);
			glVertex2f(9.0f, -2.0f);
			glVertex2f(8.0f, -2.0f);
			//Area grande de porteria derecha
			glVertex2f(9.0f, 4.0f);
			glVertex2f(6.0f, 4.0f);
			glVertex2f(6.0f, 4.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(6.0f, -4.0f);
			glVertex2f(9.0f, -4.0f);
	glEnd();
	//Dibujando los puntos 
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	//punto central
	glVertex2f(0.0f, 0.0f);
	//punto penalti izquierda
	glVertex2f(-7.0f, 0.0f);
	//punto penalti derecha
	glVertex2f(7.0f, 0.0f);
	glEnd();
	
    glFlush ();

}
void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   glOrtho(-10.0, 10.0, -10, 10, -10.0, 10.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (600, 420);
    glutCreateWindow ("Actividad Cancha Luis Iraheta - Yenifer Garcia");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
