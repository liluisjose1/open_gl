#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>


//definiendo variables globales para pasar a funciones
int x1, y1, x2, y2;

void init() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-4, 4, -4, 4);
}
//funcion para dibujar los puntos del algoritmo
void draw_pixel(double x, double y) {
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x, y);
	glEnd();
}
//algoritmo de bresenham
void draw_line(int x1, int x2, int y1, int y2) {
	glPointSize(2.0);
    glColor3f(1.0,1.0,1.0);
    //dibujando los ejes coordenados
    glBegin(GL_LINES);
		glVertex2f(-10.0f,0.0f);
		glVertex2f(10.0f,0.0f);
		glVertex2f(0.0f,10.0f);
		glVertex2f(0.0f,-10.0f);
		//trasando linea guia por donde pasan los puntos
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
	glEnd();
	
	//Variables de uso
	double dx, dy, i, e;
	double incx, incy, inc1, inc2;
	double x,y;

	dx = x2-x1;
	dy = y2-y1;
	//Conociendo el signo de las distancias de x and y, 
	//si estas son menores que cero, en teoria tendria que ser pequeño
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	
	//asignando valores a las pendientes
	incx = 1;
	if (x2 < x1) 
	incx = -1;
	incy = 1;
	if (y2 < y1) 
	incy = -1;
	x = x1;
	y = y1;
	
	//si la diferencia en x es mayor que en y dibujar en las posuciones
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		//cambiando los valores de las inclinaciones
		for (i=0; i<dx; i+=1) {
			//asignar valores a "y,e" si e es mayor que cero
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	}
	//si la diferencia de x es menor que la de y que haga los pasos para y 
	else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i+=1) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}
}
//funcion display, para dibujar funcion
void display() {
	draw_line(x1, x2, y1, y2);
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv){

	printf( "Ingresa x1, y1, x2, y2  en intervalo desde [-4,4] \n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition ((glutGet(GLUT_SCREEN_WIDTH)-500)/2,(glutGet(GLUT_SCREEN_HEIGHT)-500)/2);
	glutCreateWindow("Bresenham's Algoritmo de la linea Recta IM15005");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
