

// -----------------------------------
//             Ajuste de ventana
// -----------------------------------

void changeSize(int ww, int hh) {

	h = hh;
	w = ww;
// Prevenir una división por cero, cuando la ventana es demasiado corta
// (no puedes hacer una ventana de ancho cero).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);


	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 300.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

// -----------------------------------
//             Texturas
// -----------------------------------
void loadTextures()
{
	texture[0] = SOIL_load_OGL_texture	
		("../sources/imgs/images.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[1] = SOIL_load_OGL_texture	
		("../sources/imgs/celdas.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[2] = SOIL_load_OGL_texture	
		("../sources/imgs/tronco.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[3] = SOIL_load_OGL_texture	
		("../sources/imgs/abe.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[4] = SOIL_load_OGL_texture	
		("../sources/imgs/cielo2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[5] = SOIL_load_OGL_texture	
		("../sources/imgs/guardia.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[6] = SOIL_load_OGL_texture	
		("../sources/imgs/reina.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[7] = SOIL_load_OGL_texture	
		("../sources/imgs/info.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[8] = SOIL_load_OGL_texture	
		("../sources/imgs/info2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[9] = SOIL_load_OGL_texture	
		("../sources/imgs/1.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[10] = SOIL_load_OGL_texture	
		("../sources/imgs/2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[11] = SOIL_load_OGL_texture	
		("../sources/imgs/3.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[12] = SOIL_load_OGL_texture	
		("../sources/imgs/4.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	texture[13] = SOIL_load_OGL_texture	
		("../sources/imgs/fin.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texture[14] = SOIL_load_OGL_texture	
		("../sources/imgs/enemigo.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
    texture[15] = SOIL_load_OGL_texture	
		("../sources/imgs/avion.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

}


// --------------------------------
// Función para mapear una esfera
// --------------------------------
void mappinSphere()
{
	glEnable(GL_TEXTURE_2D);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    
}
// -----------------------------------
//             Textos
// -----------------------------------
void renderBitmapString(float x,float y,float z,void *font,char *string)
{

	char *c;
	glRasterPos3f(x, y,z);
	for (c=string; *c != '\0'; c++) {
		glutBitmapCharacter(font, *c);
	}
}

void renderStrokeFontString(float x,float y,float z,void *font,	char *string) {  

	char *c;
	glPushMatrix();
	glTranslatef(x,y,z);
	glScalef(0.002f, 0.002f, 0.002f);
	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(font, *c);
	}
	glPopMatrix();
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);
	// restore previous projection matrix
	glPopMatrix();

	// get back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {

	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	// reset matrix
	glLoadIdentity();

	// set a 2D orthographic projection
	gluOrtho2D(0, 10, 0, 10);

	// switch back to modelview mode
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}
void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

// -----------------------------------
//             Soldados
// -----------------------------------
void soldado()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex3f(0.5f, 0.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(0.5f, 1.0f,  0.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 1.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 1.0f, 0.0f, 0.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void soldado2()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex3f(0.0f, 0.0f, 0.5f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(0.0f, 1.0f,  0.5f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 0.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 0.0f, 0.0f, 1.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

// -----------------------------------
//             Casa
// -----------------------------------
void house()
{ 
	
	//casa
	glPushMatrix();
	glScalef(scale, scale, scale);
	glColor3f(1.0, 0.47, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	
	glutSolidSphere(5.0,50,50);
	glPushMatrix();
	glTranslatef(0.0,5.0,0.0);
	glutSolidSphere(2.0,50,50);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0,7.0,0.0);
	glutSolidSphere(0.5,50,50);
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	
	//----Adelante, Atras
	//Puerta
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(0.0,-0.1,-5.1);
	glColor3f(0.49, 0.18, 0.02);
	glBegin(GL_POLYGON);
	for (float i = 0; i <M_PI ; i+=0.1)
	{
		glVertex3f(1.5*cos(i),2.0*sin(i),0.0);
	}
	glEnd();
	glPopMatrix();
		//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(0.2,0.0,-5.2);
	soldado();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(-1.8,0.0,-5.2);
	soldado();
	glPopMatrix();

	
	//puerta
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(0.0,-0.1,5.0);
	glColor3f(0.49, 0.18, 0.02);
	glBegin(GL_POLYGON);
	for (float i = 0; i <M_PI ; i+=0.1)
	{
		glVertex3f(1.5*cos(i),2.0*sin(i),0.0);
	}
	glEnd();
	glPopMatrix();
	
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(0.2,0.0,5.01);
	soldado();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(-1.8,0.0,5.01);
	soldado();
	glPopMatrix();


	//----Izquierda,Derecha	


	//Puerta
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(5.0,-0.1,0.0);
	glColor3f(0.49, 0.18, 0.02);
	glBegin(GL_POLYGON);
	for (float i = 0; i <M_PI ; i+=0.1)
	{
		glVertex3f(0,2.0*sin(i),1.5*cos(i));
	}
	glEnd();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(5.01,0.0,0.2);
	soldado2();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(5.01,0.0,-1.8);
	soldado2();
	glPopMatrix();
	
	//Puerta
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(-5.0,-0.1,0.0);
	glColor3f(0.49, 0.18, 0.02);
	glBegin(GL_POLYGON);
	for (float i = 0; i <M_PI ; i+=0.1)
	{
		glVertex3f(0,2.0*sin(i),1.5*cos(i));
	}
	glEnd();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(-5.01,0.0,0.2);
	soldado2();
	glPopMatrix();
	//soldados
	glPushMatrix();
	glScalef(scale, scale, scale);
	glTranslatef(-5.01,0.0,-1.8);
	soldado2();
	glPopMatrix();
	
	

}

// -----------------------------------
//             Abeja
// -----------------------------------
void drawBee()
{
		
	//cabeza
	glPushMatrix();
	glLineWidth(1.0);
	glTranslatef(x+lx,Yf,z+lz);
	glRotatef(rotY,0,1,0);
	//glRotatef(45,0,0,1);
	glScalef(0.1, 0.1, 0.1);
	


    glPushMatrix();
	glColor3f(1.000, 0.843, 0.000);
	glTranslatef(0.0,0.5,-1.0);
	glutSolidSphere(0.5,100,100);
	glEnd();
	glPopMatrix();
	
	//tronco
	glPushMatrix();
	GLUquadric *quad;
	quad = gluNewQuadric();
	gluQuadricTexture(quad, GL_TRUE);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	
	gluSphere(quad,radioAbe,100,100);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	
	//antena1
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(0.3,0.8,-1.0);
	glVertex3f(0.3,1.3,-1.0);
	glPopMatrix();
	
	//antenas2
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3f(-0.3,0.8,-1.0);
	glVertex3f(-0.3,1.3,-1.0);
	glEnd();
	glPopMatrix();
	
	
	glPushMatrix();
	//Aleteo
	if (frameBuffer%4==0)
	{
		glTranslatef(0.1,0.13,0.35);
	}
	else
	{
		glTranslatef(-0.1,0.13,0.35);
	}

	//ala1
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.2,0.5,-0.3);
	glVertex3f(-0.2,1.0,-0.3);
	glVertex3f(-0.2,1.3,-0.2);
	glVertex3f(-0.2,1.5,-0.0);
	glVertex3f(-0.2,1.5,0.3);
	glVertex3f(-0.2,1.3,0.4);
	glVertex3f(-0.2,1.0,0.2);
	glEnd();
	glPopMatrix();
	
	//ala2
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.2,0.5,-0.3);
	glVertex3f(0.2,1.0,-0.3);
	glVertex3f(0.2,1.3,-0.2);
	glVertex3f(0.2,1.5,-0.0);
	glVertex3f(0.2,1.5,0.3);
	glVertex3f(0.2,1.3,0.4);
	glVertex3f(0.2,1.0,0.2);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	
	
	//nariz
	glPushMatrix();
	glTranslatef(0.0,0.5,-1.5);
	glColor3f(0.75, 0.51, 0.0);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
	
	//boca
	glPushMatrix();
	glTranslatef(0.0,0.3,-1.47);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (float i = M_PI; i <2*M_PI ; i+=0.1)
	{
		glVertex3f(0.1*cos(i),0.1*sin(i),0.0);
	}
	glEnd();
	
	glPopMatrix();
	
	//bolas-antenas
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(0.3,1.3,-1.0);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
	//2
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(-0.3,1.3,-1.0);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
	
	//ojos
	glPushMatrix();
	glColor3f(1.000, 0.894, 0.710);
	glTranslatef(0.15,0.7,-1.4);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
	//2
	glPushMatrix();
	glColor3f(1.000, 0.894, 0.710);
	glTranslatef(-0.15,0.7,-1.4);
	glutSolidSphere(0.1,100,100);
	glPopMatrix();
	//ojos afuera celeste
	glPushMatrix();
	glColor3f(0.12, 0.56, 1.0);
	glTranslatef(-0.15,0.7,-1.48);
	glutSolidSphere(0.05,100,100);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.12, 0.56, 1.0);
	glTranslatef(0.15,0.7,-1.48);
	glutSolidSphere(0.05,100,100);
	glPopMatrix();
	
	//aguijon
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0,-0.0,0.6);
	glRotatef(40, 0.0,0.0, 1.0);
	glutSolidCone(0.15,0.8,100,100);
	glPopMatrix();
	glPopMatrix();

}

// -----------------------------------
// Para mover la abeja en el eje y
// -----------------------------------
void descarga()
{
   if(abs((x+lx)-(0))+abs((z+lz)-(0))<4.0  )
   {
   glPushMatrix();
   glTranslatef(x+lx,Ydes,z+lz);
   	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
   glColor3f(1.0, 0.65, 0.0);
   glutSolidSphere(0.02,20,20);   
   	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
  glPopMatrix();
  }
}
// -----------------------------------
// Para mover la abeja en el eje y
// -----------------------------------
void cilueta(float Xa, float Ya, float Za)
{
   glPushMatrix();
	glTranslatef(Xa, Ya, Za);
	drawBee();
  glPopMatrix();
}

// -----------------------------------
//             Cielo
// -----------------------------------
void drawCielo()
{
// Draw ground  textura de suelo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.64, 0.74);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(-100.0f, 100.0f,  -100.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 100.0f, 100.0f, -100.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
		
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.64, 0.74);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-100.0f, 0.0f, -100.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(-100.0f, 100.0f,  -100.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( -100.0f, 100.0f, 100.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( -100.0f, 0.0f, 100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.64, 0.74);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-100.0f, 0.0f, 100.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(-100.0f, 100.0f, 100.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 100.0f, 100.0f, 100.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 100.0f, 0.0f, 100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.64, 0.74);
		glTexCoord2f(0.00f,00.0f); glVertex3f(100.0f, 0.0f, -100.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(100.0f, 100.0f, -100.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 100.0f, 100.0f, 100.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 100.0f, 0.0f, 100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
}

// -----------------------------------
//             Suelo
// -----------------------------------
void drawSoil()
{
// Draw ground  textura de suelo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glBegin(GL_QUADS);
	//glColor3f(1.0f, 1.0f, 1.0f);
	glColor3f(0.2f, 0.75f, 0.2f);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-100.0f, 0.001f, -100.0f);
		glTexCoord2f(0.00f,200.0f); glVertex3f(-100.0f, 0.001f,  100.0f);
		glTexCoord2f(200.0f,200.0f); glVertex3f( 100.0f, 0.001f,  100.0f);
		glTexCoord2f(200.0f,0.00f); glVertex3f( 100.0f, 0.001f, -100.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);	
}

// -----------------------------------
//             Carteles
// -----------------------------------

void carteles()
{
	glPushMatrix();
	glTranslatef(-50,2.0,-50);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex2f(-1.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(-1.0f, 1.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 1.0f, 1.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 1.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	// Draw tronco    
	glPushMatrix();
	glTranslatef(0.0,-2.0,0.0);
	glColor3f(0.55, 0.41, 0.08);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glRotatef(90.0,-200.0,1.0, 0.0);
    GLUquadricObj *obj1 = gluNewQuadric();
    gluCylinder(obj1, 0.1, 0.1, 2.0, 10, 10);  
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-50,2.0,60);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.00f,0.0f); glVertex2f(-1.0f, 0.0f);
		glTexCoord2f(1.00f,1.0f); glVertex2f(-1.0f, 1.0f);
		glTexCoord2f(0.0f,1.0f); glVertex2f( 1.0f, 1.0f);
		glTexCoord2f(0.0f,0.00f); glVertex2f( 1.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	// Draw tronco    
	glPushMatrix();
	glTranslatef(0.0,-2.0,0.0);
	glColor3f(0.55, 0.41, 0.08);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glRotatef(90.0,-200.0,1.0, 0.0);
    gluCylinder(obj1, 0.1, 0.1, 2.0, 10, 10);  
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(50,2.0,-50);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex2f(-1.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(-1.0f, 1.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 1.0f, 1.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 1.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	// Draw tronco    
	glPushMatrix();
	glTranslatef(0.0,-2.0,0.0);
	glColor3f(0.55, 0.41, 0.08);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glRotatef(90.0,-200.0,1.0, 0.0);
//    GLUquadricObj *obj1 = gluNewQuadric();
    gluCylinder(obj1, 0.1, 0.1, 2.0, 10, 10);  
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(50,2.0,60);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.00f,00.0f); glVertex2f(-1.0f, 0.0f);
		glTexCoord2f(1.00f,1.0f); glVertex2f(-1.0f, 1.0f);
		glTexCoord2f(0.0f,1.0f); glVertex2f( 1.0f, 1.0f);
		glTexCoord2f(0.0f,0.00f); glVertex2f( 1.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	// Draw tronco    
	glPushMatrix();
	glTranslatef(0.0,-2.0,0.0);
	glColor3f(0.55, 0.41, 0.08);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glRotatef(90.0,-200.0,1.0, 0.0);
    gluCylinder(obj1, 0.1, 0.1, 2.0, 10, 10);  
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix();
	glPopMatrix();

}

// -----------------------------------
//             Arbol
// -----------------------------------
void drawTree() {

// Draw hojas
	glPushMatrix();
	glScalef(scale, scale, scale);
	glColor3f(0.0, 0.5, 0.0);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTranslatef(0.0f ,0.75f, 0.0f);
    glRotatef(90.0,-200.0,1.0,0.0);
    
    glutSolidCone(2.0,4.5,10,10);
    glTranslatef(0.0f ,0.0f, 1.0f);
    glutSolidCone(2.0,4.5,10,10);
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix(); 
    
// Draw tronco    
	glPushMatrix();
	glScalef(scale, scale, scale);
	glColor3f(0.55, 0.41, 0.08);
	mappinSphere();
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	glRotatef(90.0,-200.0,1.0, 0.0);
    GLUquadricObj *obj1 = gluNewQuadric();
    gluCylinder(obj1, 0.70, 0.70, 0.8, 10, 10);  
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_GEN_S);   
	glPopMatrix();

}

// -----------------------------------
//             Enemigos
// -----------------------------------

//frontal
 void enemigo()
 {
 
 	glPushMatrix();
 	glTranslatef(-50,0.0,-42.0);
 	glEnable(GL_TEXTURE_2D);
 	glBindTexture(GL_TEXTURE_2D, texture[14]);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glEnable(GL_BLEND);
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	glBegin(GL_QUADS);
 
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glTexCoord2f(0.00f,00.0f); glVertex2f(-0.5f, 0.0f);
 		glTexCoord2f(0.00f,1.0f); glVertex2f(-0.5f, 2.0f);
 		glTexCoord2f(1.0f,1.0f); glVertex2f( 0.5f, 2.0f);
 		glTexCoord2f(1.0f,0.00f); glVertex2f( 0.5f, 0.0f);
 	glEnd();
 	glDisable(GL_BLEND);
 	glDisable(GL_TEXTURE_2D);
 	glPopMatrix();
 }
//Frontales
void enemigo2()
{

	glPushMatrix();
	glTranslatef(0.0,0.0,94.0);
    enemigo();
	glPopMatrix();
    
    glPushMatrix();
	glTranslatef(100,0.0,0.0);
    enemigo();
	glPopMatrix();
    
    glPushMatrix();
	glTranslatef(100,0.0,94.0);
    enemigo();
	glPopMatrix();
}

//Lateral
 void enemigo3()
 {
 
 	glPushMatrix();
 	glTranslatef(-47,0.0,-45.0);
 	glEnable(GL_TEXTURE_2D);
 	glBindTexture(GL_TEXTURE_2D, texture[14]);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 	glEnable(GL_BLEND);
 	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 	glBegin(GL_QUADS);
 
 		glColor3f(1.0f, 1.0f, 1.0f);
 		glTexCoord2f(0.00f,00.0f); glVertex3f(-0.0f, 0.0f,-0.5f);
 		glTexCoord2f(0.00f,1.0f); glVertex3f(-0.0f, 2.0f,-0.5f);
 		glTexCoord2f(1.0f,1.0f); glVertex3f( 0.0f, 2.0f,0.5f);
 		glTexCoord2f(1.0f,0.0f); glVertex3f( 0.0f, 0.0f,0.5f);
 	glEnd();
 	glDisable(GL_BLEND);
 	glDisable(GL_TEXTURE_2D);
 	glPopMatrix();
 }
 //Laterales
void enemigo4()
{

	glPushMatrix();
	glTranslatef(0.0,0.0,100.0);
    enemigo3();
	glPopMatrix();
    
    glPushMatrix();
	glTranslatef(94,0.0,0.0);
    enemigo3();
	glPopMatrix();
    
    glPushMatrix();
	glTranslatef(94,0.0,100.0);
    enemigo3();
	glPopMatrix();
}

void avion()
{

	glPushMatrix();
	glTranslatef(Xg, 8, -10.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex2f(0.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(0.0f, 4.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 2.0f, 4.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 2.0f, 0.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

// -----------------------------------
// Para mover el avion en el eje X
// -----------------------------------
void avionmov(float Ba, float Na, float Ma)
{
   glPushMatrix();
	glTranslatef(Ba, Na, Ma);
	avion();
  glPopMatrix();
}

// -----------------------------------
//             Pozos
// -----------------------------------

void pozos21()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(0.0,0.0,0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
}
void pozos22()
{
	glPushMatrix();	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(0.0,-0.4,0.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(0.8,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
}

void pozos()
{
	if (deposit<=16)
	{	
	glPushMatrix();
	glTranslatef(-30,0,-25);
	pozos21();
		if (p11<=0)
		{
			p11=0;
			glTranslatef(200.0,0,0.0);
			if (difp11<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-30,0,-65);
	pozos21();
		if (p12<=0)
		{
			p12=0;
			glTranslatef(200.0,0,0.0);
			if (difp12<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(-70,0,-25);
	pozos21();
		if (p13<=0)
		{
			p13=0;
			glTranslatef(200.0,0,0.0);
			if (difp13<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-70,0,-65);
	pozos21();
		if (p14<=0)
		{
			p14=0;
			glTranslatef(200.0,0,0.0);
			if (difp14<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(30,0,35);
	pozos21();
		if (p41<=0)
		{
			p41=0;
			glTranslatef(200.0,0,0.0);
			if (difp41<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(30,0,75);
	pozos21();
		if (p42<=0)
		{
			p42=0;
			glTranslatef(200.0,0,0.0);
			if (difp42<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(70,0,35);
	pozos21();
		if (p43<=0)
		{
			p43=0;
			glTranslatef(200.0,0,0.0);
			if (difp43<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(70,0,75);
	pozos21();
		if (p44<=0)
		{
			p44=0;
			glTranslatef(200.0,0,0.0);
			if (difp44<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(-30,0,35);
	pozos21();
		if (p31<=0)
		{
			p31=0;
			glTranslatef(200.0,0,0.0);
			if (difp31<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-30,0,75);
	pozos21();
		if (p32<=0)
		{
			p32=0;
			glTranslatef(200.0,0,0.0);
			if (difp32<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(-70,0,35);
	pozos21();
		if (p33<=0)
		{
			p33=0;
			glTranslatef(200.0,0,0.0);
			if (difp33<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-70,0,75);
	pozos21();
		if (p34<=0)
		{
			p34=0;
			glTranslatef(200.0,0,0.0);
			if (difp34<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();	
	
	glPushMatrix();
	glTranslatef(30,0,-25);
	pozos21();
		if (p21<=0)
		{
			p21=0;
			glTranslatef(200.0,0,0.0);
			if (difp21<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(30,0,-65);
	pozos21();
		if (p22<=0)
		{
			p22=0;
			glTranslatef(200.0,0,0.0);
			if (difp22<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	
	
	
	glPushMatrix();
	glTranslatef(70,0,-25);
	pozos21();
		if (p23<=0)
		{
			p23=0;
			glTranslatef(200.0,0,0.0);
			if (difp23<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(70,0,-65);
	pozos21();
		if (p24<=0)
		{
			p24=0;
			glTranslatef(200.0,0,0.0);
			if (difp24<3.0)
			{
				sprintf(mensaje,"%s","Pozo Vacio");
			}
		}
	pozos22();
	glPopMatrix();	
	
	
	}
	
	
	
	//poso reina
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(0.0,0.0,0.0);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	if (colection<=0)
	{
		radioMiel=0.0;
	}
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(0.0,-0.4,0.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(radioMiel,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(-50,0.0,-45);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	if (p1<=0)
	{
		p1=0;
		glTranslatef(200.0,0,0.0);
		if (difp1<3.0)
		{
			sprintf(mensaje,"%s","Pozo Vacio");
		}
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(-50.0,-0.4,-45.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(0.8,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(50,0.0,-45);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	if (p2<=0)
	{
		p2=0;
		glTranslatef(200.0,0,0.0);
		if (difp2<3.0)
		{
			sprintf(mensaje,"%s","Pozo Vacio");
		}
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(50.0,-0.4,-45.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(0.8,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(-50,0.0,55);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	if (p3<=0)
	{
		p3=0;
		glTranslatef(200.0,0,0.0);
		if (difp3<3.0)
		{
			sprintf(mensaje,"%s","Pozo Vacio");
		}
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(-50.0,-0.4,55.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(0.8,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(50,0.0,55);
	glColor3f(0.5, 0.5, 0.5);
	glRotatef(90.0,-200.0,1.0, 0.0);
	glutSolidTorus(0.5,1.2,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
	
	glPushMatrix();
	if (p4<=0)
	{
		p4=0;
		glTranslatef(200.0,0,0.0);
		if (difp4<3.0)
		{
			sprintf(mensaje,"%s","Pozo Vacio");
		}
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	mappinSphere();
	glTranslatef(50.0,-0.4,55.0);
	glColor3f(1.0, 0.65, 0.0);
	glutSolidSphere(0.8,20,20);
	
	glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glDisable(GL_TEXTURE_2D); 
	glPopMatrix();
}

// -----------------------------------
//             Bosque
// -----------------------------------
void drawForest()
{
	glPushMatrix();
	glTranslatef(-40, 0.0f, -35.0f);
	// Draw 36 Tree
	for(int i = -2; i < 2; i++)
		for(int j=-2; j < 2; j++) {
			glPushMatrix();
			//glScalef(scale,scale,scale);
			glTranslatef(i*20.0f, 0.0f, j * 20.0f);
			drawTree();
			glPopMatrix();
		}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(60, 0.0f, -35.0f);
	// Draw 36 Tree10
	for(int i = -2; i < 2; i++)
		for(int j=-2; j < 2; j++) {
			glPushMatrix();
			glTranslatef(i*20.0f, 0.0f, j * 20.0f);
			drawTree();
			glPopMatrix();
		}
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-40, 0.0f, 65.0f);
	// Draw 36 Tree
	for(int i = -2; i < 2; i++)
		for(int j=-2; j < 2; j++) {
			glPushMatrix();
			glTranslatef(i*20.0f, 0.0f, j * 20.0f);
			drawTree();
			glPopMatrix();
		}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(60, 0.0f, 65.0f);
	// Draw 36 Tree
	for(int i = -2; i < 2; i++)
		for(int j=-2; j < 2; j++) {
			glPushMatrix();
			glTranslatef(i*20.0f, 0.0f, j * 20.0f);
			drawTree();
			glPopMatrix();
			
		}
	glPopMatrix();
	
		//arboles en circulos
		glPushMatrix();
		for (int i = 1; i <=5; i+=1)		
			for(float j=M_PI/1800; j < 2*M_PI; j+=M_PI/7) {
				glPushMatrix();
				glScalef(0.5,0.5,0.5);
				glTranslatef(cos(j)*i*30, 0.0f, sin(j)*i*30);
				drawTree();
				glPopMatrix();
			}
		glPopMatrix();
}

// -----------------------------------
//             Reina
// -----------------------------------

void reina()
{

	glPushMatrix();
	glTranslatef(0.0,Yr,0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-0.5f, 0.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex3f(-0.5, 2.0f,  0.0f);
		glTexCoord2f(1.0f,1.0f); glVertex3f( 0.5f, 2.0f, 0.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 0.5f, 0.0f, 0.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
// -----------------------------------
//             Fin
// -----------------------------------

void fin()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslatef(0.0,yFin,0.0);
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.00f,00.0f); glVertex2f(0.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(0.0f, 10.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 10.0f, 10.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 10.0f, 0.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

}
// -----------------------------------
//             Info2
// -----------------------------------

void info2()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);
		glColor3f(1.0,1.0,1.0);
		glTexCoord2f(0.00f,00.0f); glVertex2f(0.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(0.0f, 10.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 10.0f, 10.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 10.0f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();	

}
void info()
{

	glPushMatrix();
	glTranslatef(-5,0.0,5.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(0.00f,00.0f); glVertex2f(-1.0f, 0.0f);
		glTexCoord2f(0.00f,1.0f); glVertex2f(-1.0f, 5.0f);
		glTexCoord2f(1.0f,1.0f); glVertex2f( 1.0f, 5.0f);
		glTexCoord2f(1.0f,0.00f); glVertex2f( 1.0f, 0.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void camino()
{
	glPushMatrix();
	//glTranslatef(0.0,0.5,0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.41, 0.08);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-2.0f, 0.05f, 100.0f);
		glTexCoord2f(0.00f,200.0f); glVertex3f(-2.0, 0.05f,  -100.0f);
		glTexCoord2f(1.0f,200.0f); glVertex3f( 2.0f, 0.05f, -100.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( 2.0f, 0.05f, 100.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_QUADS);
	glColor3f(0.55, 0.41, 0.08);
		glTexCoord2f(0.00f,00.0f); glVertex3f(-100.0f, 0.05f, 2.0f);
		glTexCoord2f(0.00f,200.0f); glVertex3f(100.0, 0.05f,  2.0f);
		glTexCoord2f(1.0f,200.0f); glVertex3f( 100.0f, 0.05f, -2.0f);
		glTexCoord2f(1.0f,0.00f); glVertex3f( -100.0f, 0.05f, -2.0f);
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
