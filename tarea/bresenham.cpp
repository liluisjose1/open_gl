#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-4, 4, -4, 4);
}

void draw_pixel(double x, double y) {

	glBegin(GL_POINTS);
	glPointSize(2.0);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) {
	glPointSize(2.0);
    glColor3f(1.0,1.0,1.0);
    //dibujando los ejes coordenados
    glBegin(GL_LINES);
		glVertex2f(-10.0f,0.0f);
		glVertex2f(10.0f,0.0f);
		glVertex2f(0.0f,10.0f);
		glVertex2f(0.0f,-10.0f);
	glEnd();
	
	//Variables de uso
	double dx, dy, i, e;
	double incx, incy, inc1, inc2;
	double x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) 
	incx = -0.1;
	incy = 1;
	if (y2 < y1) 
	incy = -0.1;
	x = x1;
	y = y1;
	
	if (dx > dy) {
		draw_pixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i+=0.1) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			draw_pixel(x, y);
		}

	} else {
		draw_pixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i+=0.1) {
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

void myDisplay() {
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
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}
