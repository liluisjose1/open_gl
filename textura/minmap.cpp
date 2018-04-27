#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL/SOIL.h>


GLuint texture[0];

void resize(int h, int w) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(80.0, (float)w / (float)h, 1.0, 120.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
}

static void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(0.0f,0.0f,-5.0f);

        texture[0] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "textura_lava.jpg",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );

        texture[1] = SOIL_load_OGL_texture // cargamos la imagen
                     (
                "rec.png",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
                     );

        glEnable(GL_TEXTURE_2D);

        //float color[] = { 1.0f, 0.0f, 0.0f, 1.0f };
        //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
		
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glutSolidSphere(1.5,100,100);
		/*
        glBegin(GL_POLYGON);
        glNormal3f( 0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -2.0f, 0.0f);
        glTexCoord2f(2.0f, 0.0f); glVertex3f( 2.0f, -2.0f, 0.0f);
        glTexCoord2f(2.0f, 2.0f); glVertex3f( 2.0f, 2.0f, 0.0f);
        glTexCoord2f(0.0f, 2.0f); glVertex3f(-2.0f, 2.0f, 0.0f);
        glEnd();*/
        glutSwapBuffers();


}

int main(int argc, char **argv)
{
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInit(&argc, argv);
        glutInitWindowSize(600, 600);
        glutCreateWindow("ejmplo1");
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
