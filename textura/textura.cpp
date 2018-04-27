#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


GLuint texture[0];

void resize(int height, int width) {
    const float ar = (float) width / (float) height;
    glViewport(0, 10, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 90.0);
    //gluLookAt(0, 2, 0, -1, 1, -3, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-5.0f);
    texture[0] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "sample.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );

     texture[1] = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture
    (
        "img.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
	// allocate a texture name

    glBindTexture(GL_TEXTURE_2D, texture[1]);

  /*
	glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 1.0, -1.0, -1.0 );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 1.0, 1.0, -1.0 );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -0.5,  0.5, -1.0 );
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( -1.0, -1.0, -1.0 );
    glEnd();
    */

    glBegin(GL_TRIANGLES);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.0,1.0,0.0);
    glTexCoord2f(0.1f, 0.0f);
    glVertex3f(-1.0,-0.4,0.0);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.8,-0.4,0.0);
    glEnd();

    glutSwapBuffers();


}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("ejemplo1");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);

    /////////////////////////////////////
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glutMainLoop();
}
