#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>


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

void material(float a[3], float b[3], float c[3], float d[]){
    glMaterialfv(GL_FRONT, GL_AMBIENT, a);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, b);
    glMaterialfv(GL_FRONT, GL_SPECULAR, c);
    glMaterialfv(GL_FRONT, GL_SHININESS, d);

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
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
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    glPushMatrix();
    glTranslated(0.0,1.2,-6);

    GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { 20.0f, 50.0f, -50.0f, 0.0f };
   // GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutSolidSphere (100, 160, 160);
    glPopMatrix();

    glPushMatrix ();
    glTranslatef (-200, 100, 100);
    glRotatef(30.0, 200, -200, -50.0);
    glRotatef(-45.0, 1.0, 0.0, 0.0);
    //seteando colores

    /*
     GLfloat light_ambient1[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
     GLfloat light_diffuse1[]  = { 1.0f, 1.0f, 0.0f, 0.0f };
     GLfloat light_specular1[] = { 1.0f, 1.0f, 1.0f, 0.0f };
     GLfloat light_position1[] = { 20.0f, 30.0f, -30.0f, 0.0f };
     GLfloat spot_direction1[] = { -1.0, -1.0, 1.0};


     glEnable(GL_LIGHT1);
     glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
     glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
     glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
     glLightfv(GL_LIGHT1, GL_POSITION, light_position);
     */
    GLfloat mat_a3[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_d3[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
    GLfloat mat_s3[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
    GLfloat shine4[] = {27.8974f};
    material(mat_a3,mat_d3,mat_s3,shine4);
    glutSolidTorus (30, 50, 200, 200);
    glPopMatrix ();

    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Fifuras color");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
