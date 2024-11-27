#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27

int sunce = 0;
// Camera position
float x = 15.0, y = -120.0, z = 22.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

GLuint texture1;
GLuint texture2;
GLuint texture3;

//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}
void tepih()
{
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture1);
        glEnable(GL_TEXTURE_2D);
        glTranslatef(57.0,-2.0,0);
        glScalef(1.0,8,1.0);
        glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glTexCoord2d(1.0, 0.0); glVertex3f(5.55, 2, 1.2);
        glTexCoord2d(1.0, 1.0); glVertex3f(5.55, -2.2, 1.2);
        glTexCoord2d(0.0, 1.0); glVertex3f(1.2, -2.2, 1.2);
        glTexCoord2d(0.0, 0.0); glVertex3f(1.2, 2, 1.2);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

 void crtajVodu() {
    int gridSize = 90;
    float talasAmplituda = 1;
    float talasFrekvencija = 0.8;
    glColor3f(0.0, 0.5, 0.8);
    glPushMatrix();
    glTranslatef(170.0, 0.0, -1.0);
    glBegin(GL_QUADS);
    for (int i = -gridSize; i < gridSize; i++) {
        for (int j = -gridSize; j < gridSize; j++) {
            float x = i * 0.6;
            float y = j * 0.6;
            float z1 = talasAmplituda *
            sin((i * talasFrekvencija + glutGet(GLUT_ELAPSED_TIME) * 0.005));
            float z2 = talasAmplituda *
            sin(((i + 1) * talasFrekvencija + glutGet(GLUT_ELAPSED_TIME) * 0.005));
            float z3 = talasAmplituda *
            sin((j * talasFrekvencija + glutGet(GLUT_ELAPSED_TIME) * 0.005));
            float z4 = talasAmplituda *
            sin(((j + 1) * talasFrekvencija + glutGet(GLUT_ELAPSED_TIME) * 0.005));
            glVertex3f(x, y, z1);
            glVertex3f(x + 0.5, y, z2);
            glVertex3f(x + 0.5, y + 0.5, z3);
            glVertex3f(x, y + 0.5, z4);
        }
    }
    glEnd();
 }

void crtajBazen()
{

    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
         glTranslatef(170,50,0);
         glScalef(120, 2, 20);
         glutSolidCube(0.9);
    glPopMatrix();

      glPushMatrix();
         glTranslatef(170,-54,0);
         glScalef(120, 2, 20);
         glutSolidCube(0.9);
    glPopMatrix();


     glPushMatrix();
         glTranslatef(225,0,0);
         glScalef(2, 120, 20);
         glutSolidCube(0.9);
    glPopMatrix();


     glPushMatrix();
         glTranslatef(115,0,0);
         glScalef(2, 120, 20);
         glutSolidCube(0.9);
    glPopMatrix();


    ///mreze
    glColor3f(1,1,1);
    for (int i = 0; i < 52; i++) {
    glPushMatrix();
        glTranslatef(170, 50 - i * 2, 0);
        glScalef(120, 0.5, 0.6);
        glutSolidCube(0.9);
    glPopMatrix();


for (int i = 0; i < 55; i++) {
    glPushMatrix();
        glTranslatef(225 - i * 2, 0, 0); // Smanjujemo X koordinatu za 2 pri svakoj iteraciji
        glScalef(0.5, 120, 0.6);
        glutSolidCube(0.9);
    glPopMatrix();
}



}



}


void changeSize(int w, int h)
{
	float ratio =  ((float) w) / ((float) h); // window aspect ratio
	glMatrixMode(GL_PROJECTION); // projection matrix is active
	glLoadIdentity(); // reset the projection
	gluPerspective(45.0, ratio, 0.1, 1000.0); // perspective transformation
	glMatrixMode(GL_MODELVIEW); // return to modelview mode
	glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}
void crtajKlupeZaPubliku()
{
    //daske
    glColor3f(0.35, 0.22, 0.11);
    glPushMatrix();
         glTranslatef(-50.5,32,2.4);
         glScalef(9.0, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-50.5,34.8,4.0);
         glScalef(9.0, 2.8, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();


    //nogare
    glColor3f(0.1, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(-54.5,33.5,1.1);
         glScalef(0.3, 5.6, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.5,1.1);
         glScalef(0.3, 5.6, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-54.5,31.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,33.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,33.8,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-54.5,35.6,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    //////////////////////////////////
    glPushMatrix();
         glTranslatef(-46.5,31.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.0,1.8);
         glScalef(0.1, 0.2, 1.5);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,33.8,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-46.5,35.6,2.5);
         glScalef(0.1, 0.2, 3.2);
         glutSolidCube(0.9);
    glPopMatrix();
}

void update(void)
{
	if (deltaMove) { // update camera position
		x += deltaMove * lx * 0.1;
		y += deltaMove * ly * 0.1;
	}
	glutPostRedisplay(); // redisplay everything
}


void crtajPod()
{
    //beton
   glColor3f(0.48, 0.78, 0.28);
    glPushMatrix();
         glTranslatef(0,0,0);
         glScalef(210.5, 0.1, 300);
         glutSolidCube(0.9);
    glPopMatrix();
}

void crtajDrvo()
{
    //stablo
    glColor3f(0.647059, 0.4, 0.2);
    glPushMatrix();
         glTranslatef(0,0,6.2);
         glScalef(1.4, 1.4, 10);
         glutSolidCube(0.9);
    glPopMatrix();

    //zimzeleno
    glColor3f(0.2, 0.4, 0.0);
    glPushMatrix();
         glTranslatef(0.0, 0.0, 5.6);
        glutSolidCone(6,5,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 7.6);
        glutSolidCone(5,4,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 9.6);
        glutSolidCone(4,3,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 11.6);
        glutSolidCone(3,2,15,21);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.0, 0.0, 13.1);
        glutSolidCone(2,2,15,21);
    glPopMatrix();

}

void crtajStaze()
{
    //////////////////////////////////////// Prva staza /////////////////////////////////////////////////

    glColor3f(0.50, 0.50, 0.52);
    glPushMatrix();
         glTranslatef(0,-30,1.4);
         glScalef(210, 35, 1);

         glutSolidCube(0.9);
    glPopMatrix();
    //////////////////////////////////////// Druga staza ///////////////////////////////////////////////
    glColor3f(0.50, 0.50, 0.52);
    glPushMatrix();
         glTranslatef(11,0.0,1.5);
         glScalef(20, 299, 1);
         glutSolidCube(0.9);
    glPopMatrix();
}
void crtajTerenZaOdbojku()
{
 //////////////////////////////////////// TEREN  /////////////////////////////////////////////////

    glColor3f(0.63, 0.40, 0.211);

    glPushMatrix();
         glTranslatef(55,-100,0.6);
         glScalef(40, 70.1, 3);
         glutSolidCube(0.9);
    glPopMatrix();

     ///////////////////////////////////////// MREZA  ///////////////////////////////////////////////
    ///////////////////////////////////////// OVO SU ONE MALE LINIJE  ///////////////////////////////////////////////
glColor3f(0,0,0);
    glPushMatrix();

        glTranslatef(73.5,-100.0,2);
         glScalef(0.3, 0.1, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(36.8,-100.0,2);
         glScalef(0.3, 0.1, 7.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(55,-100.0,5);
         glScalef(41, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.8,-100.0,1.8);
         glScalef(22, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(55,-100.0,1.8);
         glScalef(41, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(55,-100.4,2.3);
         glScalef(41, 0.4, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    //bijele linije
    glColor3f(1, 1, 1);
    glPushMatrix();
        glTranslatef(73.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(72.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(72.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(71.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(71.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(70.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(69.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(69.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(68.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(68.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(67.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(67.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(66.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(66.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(65.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(65.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(64.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(64.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(63.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(63.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(62.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(62.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(60.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(60.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(59.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(59.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(58.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(58.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(57.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(57.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(56.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(56.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(53.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(53.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(52.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(52.0, -100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(51.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(51.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(50.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(50.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(49.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(49.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(48.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(48.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(47.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(47.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(46.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(46.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(45.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(45.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(44.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(44.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(43.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(43.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(42.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(42.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(41.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(41.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(40.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(40.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(39.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(39.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(38.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(38.0,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(37.5,-100.0,2);
         glScalef(0.1, 0.1, 7.0);
         glutSolidCube(0.9);
    glPopMatrix();
    //horizontalna mreza
    glPushMatrix();
         glTranslatef(55,-100.0,5);
         glScalef(41, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55,-100.0,4.4);
         glScalef(41, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55,-100.0,3.9);
         glScalef(41, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55,-100.0,3.5);
         glScalef(41, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55,-100.0,3.1);
         glScalef(41, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(55,-100.0,2.7);
         glScalef(41, 0.01, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    //horizontalne linije
    glPushMatrix();
         glTranslatef(55,-100.0,1.8);
         glScalef(41, 0.1, 0.1);
         glutSolidCube(0.9);
    glPopMatrix();
    //vertikalne linije
  //////////////////////////////////////// OVO SU LINIJE ZA OKVIR  /////////////////////////////////////////////////
    glPushMatrix();
         glTranslatef(38.2,-100.0,2);
         glScalef(0.6, 57, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(71,-100.0,2);
         glScalef(0.6, 57, 0.1);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(54.6,-128.5,2);
         glScalef(33, 0.4, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.6,-71,2);
         glScalef(33.3, 0.4, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    //////////////////////////////////////// OVO SU LINIJE UNTAR OKVIRA  /////////////////////////////////////////////////
 glPushMatrix();
         glTranslatef(45,-100.0,2);
         glScalef(0.6, 71, -0.1);
         glutSolidCube(0.8);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(62.6,-100.0,2);
         glScalef(0.6, 71, -0.1);
         glutSolidCube(0.8);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(54.1,-120.5,2);
         glScalef(22, 0.4, -0.1);
         glutSolidCube(0.8);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(54.1,-80.5,2);
         glScalef(22, 0.4, -0.1);
         glutSolidCube(0.8);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(53.5,-100.5,2);
         glScalef(0.6, 50, -0.1);
         glutSolidCube(0.8);
    glPopMatrix();
}

void crtajDrvenuKucu()
{
     glColor3f(0.63, 0.40, 0.211);
    glPushMatrix();
        glTranslatef(42.5,70.0,2);
         glScalef(0.6, 0.4, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(59.5,70.0,2);
         glScalef(0.6, 0.4, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42.5,43.0,2);
         glScalef(0.6, 0.4, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(59.5,43.0,2);
         glScalef(0.6, 0.4, 1.0);
         glutSolidCube(1);
    glPopMatrix();
///////////////////////////////////PODLOGA////////////////////////////////////////////////////////
    glColor3f(0.63, 0.40, 0.211);
    glPushMatrix();
        glTranslatef(51.5,57.0,3);
         glScalef(20, 30, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    /////////////////////////////////OKO KUCE ////////////////////////////////////////////
 glColor3f(0.86,0.63,0.28);
////////ovo je desna strana/////////////////////////////////////

    glPushMatrix();
        glTranslatef(61.5,43.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,45.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,47.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,49.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,51.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,53.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,55.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,57.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,59,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,61,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
    glTranslatef(61.5,63,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,65,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
   glPopMatrix();
   glPushMatrix();
        glTranslatef(61.5,67,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(61.5,69,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(61.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    /////gore////////////
    glPushMatrix();
        glTranslatef(60,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(58.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(57,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(55.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(54,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();

        glTranslatef(52.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(51,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(49.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(48,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(46.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(45,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(43.5,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
        glPushMatrix();
        glTranslatef(42,71,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
///////////////////////leva strana////////////////////////////

 glPushMatrix();
        glTranslatef(42,69,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,67,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,65,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,63,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,61,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,59,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,57,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,55,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,53,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,51,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,49,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,47,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,45,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42,43,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    /////////////////////////////dole////////////////////////////////////
    glPushMatrix();
        glTranslatef(43.5,43,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(45,43,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(46.5,43,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
    //dole al sa desne strane//
     glPushMatrix();
        glTranslatef(60,43.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
 glPushMatrix();
        glTranslatef(58.5,43.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(57,43.0,7);
         glScalef(0.7, 0.7, 7.0);
         glutSolidCube(1);
    glPopMatrix();

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

           glColor3f(0.63, 0.40, 0.211);
       glPushMatrix();
        glTranslatef(44.5,43.0,11);
         glScalef(4.5, 0.3, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(42.2,57.0,11);
         glScalef(0.6, 28.3, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(52.1,71.0,11);
         glScalef(19, 0.3, 1.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(61.5,57.0,11);
         glScalef(0.6, 28.3, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(59,43.0,11);
         glScalef(4.5, 0.3, 1.0);
         glutSolidCube(1);
    glPopMatrix();
  //////////////////////////////////////////////////////////////  //ploca he/////////////////////////////////////
  glColor3f(0.63, 0.40, 0.211);
    glPushMatrix();
        glTranslatef(51.5,57.0,20.2);
         glScalef(20, 30, 1.0);
         glutSolidCube(1);
    glPopMatrix();
//////////////////////////////OVO SU STUBOVI //////////////////////////////////////////
  glColor3f(0.86,0.63,0.28);
 glPushMatrix();
  glTranslatef(61.1,43.0,16);
         glScalef(0.7, 0.7, 9.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
      glTranslatef(61.2,70.5,16);
         glScalef(0.7, 0.7, 9.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
  glTranslatef(42.4,70.5,16);
         glScalef(0.7, 0.7, 9.0);
         glutSolidCube(1);
    glPopMatrix();
 glPushMatrix();
  glTranslatef(42.4,43.0,16);
         glScalef(0.7, 0.7, 9.0);
         glutSolidCube(1);
    glPopMatrix();
    ///////////////////////////////CRTANJE KROVA //////////////////////////////////////////////////

  glColor3f(0.63, 0.40, 0.211);
    glPushMatrix();
        glTranslatef(51.5,57.0,20.5);
        glutSolidCone(10,3, 30, 5);
    glPopMatrix();
}
void crtanjeKlupeZaKucu()
{

     glColor3f(0.43,0.28, 0.062);
    glPushMatrix();
        glTranslatef(57,57,6.5);
         glScalef(4, 17, 1.0);
         glutSolidCube(1);
    glPopMatrix();
//CRTANJE NOGARA//////////////////
      glColor3f(0.86,0.63,0.28);
    glPushMatrix();
        glTranslatef(58,50,5);
         glScalef(0.6, 0.4, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(56,50,5);
         glScalef(0.6, 0.4, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(58,66,5);
         glScalef(0.6, 0.4, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(56,66,5);
         glScalef(0.6, 0.4, 3.0);
         glutSolidCube(1);
    glPopMatrix();


}
void crtanjeStepenica()
{
   glColor3f(0.43,0.28, 0.062);
    glPushMatrix();
        glTranslatef(52,38.5,1);
         glScalef(6, 3, 1.5);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(52,41,2.2);
         glScalef(6, 2.4, 1.0);
         glutSolidCube(1);
    glPopMatrix();
}
void crtajKlackalicu()
{
/////////////////////////////////OVO JE ISPOD KLACKLICE//////////////////////////////////////
     glColor3f(0.50, 0.50, 0.52);
    glPushMatrix();
        glTranslatef(-9,-100,1.0);
          glScalef(1.5, 2, 14.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-3.1,-100,1.0);
          glScalef(1.5, 2, 14.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-5.5,-100,6.0);
          glScalef(6,2, 1.0);
         glutSolidCube(1);
    glPopMatrix();
//////////////////////////////////////////////////////////////////
glColor3f(0.26,0.50,0.69);
     glPushMatrix();
        glTranslatef(-6,-100,7.0);
          glScalef(4, 35, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    /////////////////////////////////D////////////////////
   glColor3f(0.43, 0.45, 0.45);
        glPushMatrix();
        glTranslatef(-4.5,-87,9.0);
          glScalef(0.2, 0.2, 3);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-7,-87,9.0);
          glScalef(0.2, 0.2, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-5.7,-87,10.0);
          glScalef(2.5, -0.1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
//////drugi deo d//////////////////
   glPushMatrix();
        glTranslatef(-4.5,-114,9.0);
          glScalef(0.2, 0.2, 3);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-7,-114,9.0);
          glScalef(0.2, 0.2, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-5.7,-114,10.0);
          glScalef(2.5, -0.1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
/////////////////////////////////DRUGA///////////////////////////////////////////////
    glColor3f(0.50, 0.50, 0.52);
    glPushMatrix();
        glTranslatef(-59,-100,1.0);
          glScalef(1.5, 2, 14.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-53.1,-100,1.0);
          glScalef(1.5, 2, 14.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-55.5,-100,6.0);
          glScalef(6,2, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    ///podloga////
    glColor3f(0.96,0.50,0.52);
    glPushMatrix();
        glTranslatef(-56,-100,7.0);
          glScalef(4, 35, 1.0);
         glutSolidCube(1);
    glPopMatrix();
   glColor3f(0.43, 0.45, 0.45);
        glPushMatrix();
        glTranslatef(-55.5,-87,9.0);
          glScalef(0.2, 0.2, 3);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-58,-87,9.0);
          glScalef(0.2, 0.2, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-56.9,-87,10.0);
          glScalef(2.5, -0.1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
   ///////////////////////////////DRUGI DEO DRZACA///////////////////////////////////
   glColor3f(0.50, 0.50, 0.52);
        glPushMatrix();
        glTranslatef(-55.5,-114,9.0);
          glScalef(0.2, 0.2, 3);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-58,-114,9.0);
          glScalef(0.2, 0.2, 3.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-56.9,-114,10.0);
          glScalef(2.5, -0.1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
  // Textura za klupe1
    //////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(123, 12, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(123, 30, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(118.7, 30, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(118.7, 12, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za klupe2
    //////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(134, 12, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(134, 30, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(129.7, 30, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(129.7, 12, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za klupe3
    /////////////////////////////////////////////////////////////////////18//4///////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(134, -105, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(134, -123, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(129.7, -123, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(129.7, -105, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////

// Textura za klupe4
    //////////////////////////////////////////////////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(123, -105, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(123, -123, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(118.7, -123, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(118.7, -105, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////

// Textura za klupe5 uzduz
    ///////////////////////////////////18////////5///////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-1.-15,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(-41, -49, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(-41, -54, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(-23, -54, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(-23, -49, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za klupe6 uzduz
    ///////////////////////////////////18////////5///////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-1.-15,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(-41, -30.5, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(-41, -25.5, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(-23, -25.5, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(-23, -30.5, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
 // Textura za klupe6 uzduz
    ///////////////////////////////////18////////5///////////////////////////////////
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-1.-15,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(82.5, -30.5, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(82.5, -25.5, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(64.5, -25.5, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(64.5, -30.5, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////

 glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-1.-15,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(82.5, -49, 3);
    glTexCoord2d(1.0, 1.0); glVertex3f(82.5, -54, 3);
    glTexCoord2d(0.0, 1.0); glVertex3f(64.5, -54, 3);
    glTexCoord2d(0.0, 0.0); glVertex3f(64.5, -49, 3);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    //////////////////////////////////////////////////////Teksture za one velike klupe///////////////////////////////
    // Textura za pprvu vrliku
    //////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(142, -85, 1.14);
    glTexCoord2d(1.0, 1.0); glVertex3f(142, -137, 1.14);
    glTexCoord2d(0.0, 1.0); glVertex3f(146.7, -137, 1.14);
    glTexCoord2d(0.0, 0.0); glVertex3f(146.7, -85, 1.14);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za pprvu malu
    //////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(145, -85, -0.5);
    glTexCoord2d(1.0, 1.0); glVertex3f(145, -137, -0.5);
    glTexCoord2d(0.0, 1.0); glVertex3f(149.7, -137, -0.5);
    glTexCoord2d(0.0, 0.0); glVertex3f(149.7, -85, -0.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za drugu veliku vrliku
    //////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(197, -85, 1.14);
    glTexCoord2d(1.0, 1.0); glVertex3f(197, -137, 1.14);
    glTexCoord2d(0.0, 1.0); glVertex3f(201.7, -137, 1.14);
    glTexCoord2d(0.0, 0.0); glVertex3f(201.7, -85, 1.14);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
    // Textura za pprvu malu
    //////////////////////////////////////////////////////////////////////////////
     glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture3);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-10.-105,10,3);
    glScalef(1,1,1);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 0.0); glVertex3f(194, -85, -0.5);
    glTexCoord2d(1.0, 1.0); glVertex3f(194, -137, -0.5);
    glTexCoord2d(0.0, 1.0); glVertex3f(198.7, -137, -0.5);
    glTexCoord2d(0.0, 0.0); glVertex3f(198.7, -85, -0.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////





}
void crtajPesak()
{
    glColor3f(0.26,0.50,0.69);
     glPushMatrix();
        glTranslatef(-34,-100,1.0);
          glScalef(14, 14, 1.4);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-33,-100,2.3);
          glScalef(20, 20, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glColor3f(0.26,0.50,0.69);
    glPushMatrix();
        glTranslatef(-43,-100,3.3);
          glScalef(1, 19, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-23,-100,3.3);
          glScalef(1, 19, 1.0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-33,-90,3.3);
          glScalef(20, 1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-33,-110,3.3);
          glScalef(20, 1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
     glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-33,-100,3.5);
          glScalef(18, 18, 0.2);
         glutSolidCube(1);
    glPopMatrix();

    }
void crtajLjuljasku()
{
    ///////////////////////////////////okvir///////////////////////////
 glColor3f(0.50, 0.50, 0.52);
    glPushMatrix();
        glTranslatef(-40,-55,1.0);
          glScalef(1, 1, 40.0);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-60,-55,1.0);
          glScalef(1, 1, 40.0);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(-50,-55,21.0);
          glScalef(21, 1, 1.0);
         glutSolidCube(1);
    glPopMatrix();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glColor3f(0.80,0.63,0.54);
    glPushMatrix();
        glTranslatef(-57,-55,14.0);
          glScalef(0.2, 0.2, 10);
          glRotatef(45,0,1,0);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
        glTranslatef(-52,-55,14.0);
          glScalef(0.2, 0.2, 10);
          glRotatef(-30,0,1,0);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-48,-55,14.0);
          glScalef(0.2, 0.2, 10);
          glRotatef(45,0,1,0);
         glutSolidCube(1);
    glPopMatrix();
   glPushMatrix();
        glTranslatef(-43,-55,14.0);
          glScalef(0.2, 0.2, 10);
          glRotatef(-30,0,1,0);
         glutSolidCube(1);
    glPopMatrix();
    //////////////////////////podloga//////////////////////
    glColor3f(0.96,0.50,0.52);
   glPushMatrix();
        glTranslatef(-54.5,-55,7.0);
          glScalef(4.3, 4, 0.5);
         glutSolidCube(1);
    glPopMatrix();
       glColor3f(0.26,0.50,0.69);
     glPushMatrix();
        glTranslatef(-46,-55,7.0);
          glScalef(4.3, 4, 0.5);
         glutSolidCube(1);
    glPopMatrix();


}

void crtajLinijeOkoStaza()
{
//prva///
     glColor3f(0.69,0.66,0.67);
     glPushMatrix();
        glTranslatef(2.2,-91,2.0);
          glScalef(2, 88, 1);
         glutSolidCube(1);
    glPopMatrix();
//preko puta prve//
    glPushMatrix();
        glTranslatef(20,-91,2);
          glScalef(2, 89, 1);
         glutSolidCube(1);
    glPopMatrix();
    ///treca
    glPushMatrix();
        glTranslatef(20,58.5,1.8);
          glScalef(2, 148.9, 1);
         glutSolidCube(1);
    glPopMatrix();
    ///cetvrta
    glPushMatrix();
        glTranslatef(2.2,58.5,1.8);
          glScalef(2, 148.9, 1);
         glutSolidCube(1);
    glPopMatrix();
    ///peta
    glPushMatrix();
        glTranslatef(-45.8,-46,1.8);
          glScalef(97.5, 2.0, 1);
         glutSolidCube(1);
    glPopMatrix();
    ///pored pete //
    glPushMatrix();
        glTranslatef(-45.8,-15,1.8);
          glScalef(97.8, 2.0, 1);
         glutSolidCube(1);
    glPopMatrix();
    ///sesta
    glPushMatrix();
        glTranslatef(57,-46,1.8);
          glScalef(75, 2.0, 1);
         glutSolidCube(1);
    glPopMatrix();
///sedma
    glPushMatrix();
        glTranslatef(56.7,-15,1.8);
          glScalef(75, 2.0, 1);
         glutSolidCube(1);
    glPopMatrix();
}

void crtajFontanu()
{
    /////////////ovo je prvi deo/////////////////////
 glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-1, -32, 2);	// translate to just above ground
		glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
		glutSolidSphere(13, 60, 25); // shadow same size as body
	glPopMatrix();
	///////////drugi deo/////////
	glColor3f(0,1,1);
	glPushMatrix();
		glTranslatef(-1, -32, 0.9);	// translate to just above ground
		glScalef(1.0, 1.0, 0.2); // scale sphere into a flat pancake
		glutSolidSphere(11, 100, 40); // shadow same size as body
	glPopMatrix();
	//stub
	glColor3f(0.78,0.79,0.80);
	glPushMatrix();
        glTranslatef(-0.6,-33,-6);
         glScalef(4, 3, 50);
         glutSolidCube(1);
    glPopMatrix();
    glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-1, -32, 19.2);	// translate to just above ground
		glScalef(1.1, 1.1, 0.1); // scale sphere into a flat pancake
		glutSolidSphere(10, 60, 40); // shadow same size as body
	glPopMatrix();
    glColor3f(0.50, 0.50, 0.52);
	glPushMatrix();
		glTranslatef(-0.4, -33, 19.8);	// translate to just above ground
		glScalef(1.0, 1.0, 0.12); // scale sphere into a flat pancake
		glutSolidSphere(8, 60, 40); // shadow same size as body
	glPopMatrix();

}

void crtajSvetiljku()
{
     glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(6.5, -130, 2);	// translate to just above ground
		glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
		glutSolidSphere(1.5, 60, 25); // shadow same size as body
	glPopMatrix();
//stub
	glColor3f(0.69,0.66,0.67);
	glPushMatrix();
         glTranslatef(6.5,-130,4);
         glScalef(1.5, 1.5, 4);
         glutSolidCube(1);
    glPopMatrix();
    //drugi krug
     glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(6.5, -130, 6.1);	// translate to just above ground
		glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
		glutSolidSphere(1.5, 60, 25); // shadow same size as body
	glPopMatrix();
	///drugi stub
	glColor3f(0.69,0.66,0.67);
	glPushMatrix();
         glTranslatef(6.5,-130,7);
         glScalef(1, 1, 19);
         glutSolidCube(1);
    glPopMatrix();
    ///vrh
    glColor3f(0,0,0);
	glPushMatrix();
          glTranslatef(6.5,-130,16.6);
         glScalef(2, 2, 0);
         glutSolidCube(1);
    glPopMatrix();
    /////stapici
    glColor3f(1,0,0);
	glPushMatrix();
         glTranslatef(7.3,-130.9,17.6);
         glScalef(0.1, 0.2, 2);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(7.3,-129.2,17.6);
         glScalef(0.1, 0.2, 2);
         glutSolidCube(1);
    glPopMatrix();
    //drugi stapici
     glColor3f(1,0,0);
	glPushMatrix();
        glTranslatef(5.7,-130.9,17.6);
         glScalef(0.1, 0.2, 2);
         glutSolidCube(1);
    glPopMatrix();
 glPushMatrix();
         glTranslatef(5.7,-129.2,17.6);
         glScalef(0.1, 0.2, 2);
         glutSolidCube(1);
    glPopMatrix();
    ///vrh
    glColor3f(0,0,0);
	glPushMatrix();
         glTranslatef(6.5,-130,18.66);
         glScalef(2, 2, 0);
         glutSolidCube(1);
    glPopMatrix();
     //unutra
     	glColor3f(0.69,0.66,0.67);
	glPushMatrix();
         glTranslatef(6.5,-130,16.7);
         glScalef(0.1, 0.1, 1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
     glColor3f(1,1,0);
        glTranslatef(6.5, -130, 17.5);
        glutSolidSphere(0.4, 20, 70);
     glPopMatrix();

}

void crtajKlupeZaStazu()
{
    ///nogare
    glColor3f(0,0,0);
glPushMatrix();
         glTranslatef(5,-110.5,1);
         glScalef(0.4, 0.2,11);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(5,-97.5,1);
         glScalef(0.4, 0.2,11);
         glutSolidCube(0.9);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(7,-110.5,1);
         glScalef(0.4, 0.2,11);
         glutSolidCube(0.9);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(7,-97.5,1);
         glScalef(0.4, 0.2,11);
         glutSolidCube(0.9);
    glPopMatrix();
    //////////naslon
    glColor3f(0.4, 0.2, 0.2);
    glPushMatrix();
         glTranslatef(6,-104,5.9);
         glScalef(3, 18, 0.2);
         glutSolidCube(0.9);
    glPopMatrix();
    /////////////////////////////////////////////////////////////////////////////////
}

void crtajTertanu()
{
     /////podloga///////////////////////////////
    glColor3f(0.63, 0.40, 0.211);
     glPushMatrix();
        glTranslatef(-65 ,10,2.0);
          glScalef(25, 40, 0.5);
         glutSolidCube(1);
    glPopMatrix();
/////////////
     glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-65 ,-3,2.5);
          glScalef(15, 4, 0.3);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
        glTranslatef(-65 ,18,2.5);
          glScalef(15, 4, 0.3);
         glutSolidCube(1);
    glPopMatrix();
}
void crtajTeren2()
{
   /////podloga///////////////////////////////
    glColor3f(0.63, 0.40, 0.211);
     glPushMatrix();
        glTranslatef(-20 ,20,2.0);
          glScalef(40, 60, 0.5);
         glutSolidCube(1);
    glPopMatrix();
    glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-30 ,19,2.5);
          glScalef(4, 49, 0.3);
         glutSolidCube(1);
    glPopMatrix();
     glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-5 ,19,2.5);
          glScalef(4, 49, 0.3);
         glutSolidCube(1);
    glPopMatrix();
    ////////////////////////////
    glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-30, -3.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
    glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-5, -3.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-30, 39.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-5, 39.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();

}
void crtajDrzace()
{
///
    glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-68, -3.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
glColor3f(0,0,0);
	glPushMatrix();
    glTranslatef(-68,-3.5,4);
         glScalef(0.5, 1.5, 15);
         glutSolidCube(1);
    glPopMatrix();
    ////////////////////////////za drugu////////////////////////
     glColor3f(0.69,0.66,0.67);
    glPushMatrix();
		glTranslatef(-68, 18, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
glColor3f(0,0,0);
	glPushMatrix();
         glTranslatef(-68,18.5,4);
         glScalef(0.5, 1.5, 24);
         glutSolidCube(1);
    glPopMatrix();
    //////////////////////////////////////////
    glPushMatrix();
        glTranslatef(-68,7.5,14);
        glRotatef(200,1,1,0);
         glScalef(23, 1.5, 1);
         glutSolidCube(1);
    glPopMatrix();
     glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-60, -3.5, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
  glColor3f(0,0,0);
	glPushMatrix();
         glTranslatef(-60,-3.5,4);
         glScalef(0.5, 1.5, 15);
         glutSolidCube(1);
    glPopMatrix();
    ///za drugu
     glColor3f(0.69,0.66,0.67);
    glPushMatrix();
		glTranslatef(-60, 18, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	glColor3f(0,0,0);
	glPushMatrix();
         glTranslatef(-60,18.5,4);
         glScalef(0.5, 1.5, 24);
         glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
         glTranslatef(-60,7.5,14);
       glRotatef(200,1,1,0);
         glScalef(23, 1.5, 1);
         glutSolidCube(1);
    glPopMatrix();
}

void crtajDrzace2()
{
    glColor3f(0,0,0);
	glPushMatrix();
       glTranslatef(-30,-3.5,4);
         glScalef(0.1, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
	glPushMatrix();
 glTranslatef(-30,39.5,4);
         glScalef(0.1, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-5,-3.5,4);
         glScalef(0.1, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
    	glPushMatrix();
         glTranslatef(-5,39.5,4);
         glScalef(0.1, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    glColor3f(1,1,1);
    glPushMatrix();
         glTranslatef(-18,-2.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
         glTranslatef(-18,1.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,4.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,7.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
      glPushMatrix();
         glTranslatef(-18,10.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,13.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,16.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,19.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-18,22.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-18,25.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-18,28.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-18,31.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-18,34.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-18,37.5,27 );
         glScalef(26, 0.2, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glColor3f(1,0,0);
     glPushMatrix();
         glTranslatef(-30,18,27 );
         glScalef(0.2, 44, 0.1);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-5,18,27 );
         glScalef(0.2, 44, 0.1);
         glutSolidCube(1);
    glPopMatrix();
}

void crtajTeren3()
{
     /////podloga///////////////////////////////
    glColor3f(0.63, 0.40, 0.211);
     glPushMatrix();
        glTranslatef(-42 ,80,2.0);
          glScalef(80, 40, 0.5);
         glutSolidCube(1);
    glPopMatrix();
    glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-39 ,67,2.5);
          glScalef(60, 4, 0.3);
         glutSolidCube(1);
    glPopMatrix();
       glColor3f(0.78,0.59,0.41);
     glPushMatrix();
        glTranslatef(-39 ,88,2.5);
          glScalef(60, 4, 0.3);
         glutSolidCube(1);
    glPopMatrix();
}
void crtajDrzace3()
{
     glColor3f(0.69,0.66,0.67);
	glPushMatrix();
		glTranslatef(-13, 88, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-64, 88, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-13, 67, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
		glPushMatrix();
		glTranslatef(-64, 67, 2.7);	// translate to just above ground
		glScalef(1.0, 1.0, 0); // scale sphere into a flat pancake
		glutSolidSphere(1, 20, 25); // shadow same size as body
	glPopMatrix();
	 glColor3f(0,0,0);
	glPushMatrix();
         glTranslatef(-64,67,4);
         glScalef(0.2, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
         glTranslatef(-13,67,4);
         glScalef(0.2, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-64,88,4);
         glScalef(0.2, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-13,88,4);
         glScalef(0.2, 1.5, 50);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-39,88.5,29 );
         glScalef(51.4, 0.8, 0.1);
         glutSolidCube(1);
    glPopMatrix();
     glPushMatrix();
         glTranslatef(-39,67.5,29 );
         glScalef(51.4, 0.8, 0.1);
         glutSolidCube(1);
    glPopMatrix();
}
void lightoff(unsigned char key, int x, int y) {

    key = tolower(key);
    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }
    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}
void renderScene(void)
{

/*
    glShadeModel(GL_SMOOTH);
     glEnable(GL_DEPTH_TEST);
     glDepthFunc(GL_LESS);
     glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);

     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.9 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 0.0 };
     GLfloat light_positionSunce[] = { 100.0, 100.0, 100.0, 0.0 };

     GLfloat mat_amb_diff[] = { 0.9, 0.9, 0.9, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

     glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0, GL_POSITION, light_positionSunce);
     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);

*/
	int i, j;


	glClearColor(0.0, 0.7, 1.0, 0.4); // sky color is light blue
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera centered at (x,y,1) and looking along directional
	// vector (lx, ly, 0), with the z-axis pointing up
	gluLookAt(
            x,      y,      z,
			x + lx, y + ly, z,
			0.0,    0.0,    1.0);

	// Draw ground - 200x200 square colored green
	glColor3f(0.0, 0.7, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(-1000.0, -1000.0, 0.0);
		glVertex3f(-1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0,  1000.0, 0.0);
		glVertex3f( 1000.0, -1000.0, 0.0);
	glEnd();



crtajFontanu();
glTranslated(0,-1,0);
glTranslated(-13,0,0);
glTranslated(-8,0,0);
crtanjeKlupeZaKucu();
glTranslated(10,1,0);
crtajDrvenuKucu();
glPushMatrix();
glTranslatef(0, 0, 1);
crtajVodu();
glRotatef(90, 1, 0,0);
glTranslated(-170,0,0);
crtajPod();
crtajStaze();
crtajBazen();
crtajTerenZaOdbojku();
crtanjeKlupeZaKucu();
crtanjeStepenica();
crtajKlackalicu();
crtajPesak();
crtajLjuljasku();
crtajLinijeOkoStaza();
crtajKlupeZaStazu();
crtajTertanu();
crtajDrzace();
crtajTeren2();
crtajDrzace2();
crtajTeren3();
crtajDrzace3();

/////////////////////////////////////////////////////OVO SU KLUPE ZA PUBLIKU////////////////////////////////////////////////

glRotatef(-90,0,0,1);
glTranslatef(130,50,0);
crtajKlupeZaPubliku();
glTranslatef(7,0,0);
crtajKlupeZaPubliku();
glTranslatef(8,0,0);
crtajKlupeZaPubliku();
glTranslatef(8.2,0,0);
crtajKlupeZaPubliku();
glTranslatef(8.2,0,0);
crtajKlupeZaPubliku();
glTranslatef(8.2,0,0);
crtajKlupeZaPubliku();
glRotatef(180,0,0,1);
glTranslatef(98,-14,0);
crtajKlupeZaPubliku();
glTranslatef(7,-0,0);
crtajKlupeZaPubliku();
glTranslatef(7.2,-0,0);
crtajKlupeZaPubliku();
glTranslatef(7.2,-0,0);
crtajKlupeZaPubliku();
glTranslatef(7.2,-0,0);
crtajKlupeZaPubliku();
glTranslatef(7.2,-0,0);
crtajKlupeZaPubliku();
glTranslatef(7.2,0,0);
crtajKlupeZaPubliku();
//// ///////////////////////////////////////////////////////


/**/
///ovo su one cetiri u gornjem levom ////
glRotatef(-180,0,0,1);
glTranslatef(-12,0,0);
crtajSvetiljku();
glTranslatef(0,35,0);
crtajSvetiljku();
glTranslatef(20,0,0);
crtajSvetiljku();
glTranslatef(0,-35,0);
crtajSvetiljku();
glTranslatef(40,71,0);
crtajSvetiljku();
glTranslatef(0,12,0);
crtajSvetiljku();
glTranslatef(40,0,0);
crtajSvetiljku();
glTranslatef(0,-12,0);
crtajSvetiljku();

///gornji desni
glTranslatef(-122,0,0);
crtajSvetiljku();
glTranslatef(0,12,0);
crtajSvetiljku();
glTranslatef(-70,0,0);
crtajSvetiljku();
glTranslatef(0,-12,0);
crtajSvetiljku();
///dole desno >
glTranslatef(90,34,0);
crtajSvetiljku();
glTranslatef(20,0,0);
crtajSvetiljku();
glTranslatef(0,34,0);
crtajSvetiljku();
glTranslatef(-22,0,0);
crtajSvetiljku();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
glTranslatef(0,-42,0);
crtajKlupeZaStazu();
glTranslatef(23,0,0);
crtajKlupeZaStazu();
glTranslatef(0,-105,0);
crtajKlupeZaStazu();
glTranslatef(-23,0,0);
crtajKlupeZaStazu();
glTranslatef(110,10,0);
crtajKlupeZaStazu();//////////////ovo je kod klacklica
glTranslatef(0,20,0);
crtajKlupeZaStazu();
glRotatef(-90,0,0,1);
glTranslatef(63,-50,0);
crtajKlupeZaStazu();
glTranslatef(11,0,0);
crtajKlupeZaStazu();
glTranslatef(-11,135,0);
crtajKlupeZaStazu();
glTranslatef(0,-71,0);
crtajDrvo();
glTranslatef(-12,0,0);
crtajDrvo();
glTranslatef(-12,0,0);
crtajDrvo();
glTranslatef(-12,0,0);
crtajDrvo();
glTranslatef(-12,0,0);
crtajDrvo();
glTranslatef(-12,0,0);
crtajDrvo();
glTranslatef(-12,-1,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
crtajDrvo();
glTranslatef(0,-12,0);
glTranslatef(0,-12,0);
glTranslatef(0,-12,0);
glTranslatef(0,-3,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(0,-14,0);
crtajDrvo();
glTranslatef(10,-7,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
glTranslatef(10,0,0);
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,0,0);
crtajDrvo();
glTranslatef(10,7,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
glTranslatef(0,12,0);
glTranslatef(0,12,0);
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(0,12,0);
crtajDrvo();
glTranslatef(-14,12,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();
glTranslatef(-14,0,0);
crtajDrvo();



glutSwapBuffers(); // Make it all visible
}


void processNormalKeys(unsigned char key, int xx, int yy)
{
	if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 4; break;
		case GLUT_KEY_DOWN : deltaMove = -4; break;
	}
}

void releaseSpecialKey(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.0; break;
		case GLUT_KEY_DOWN : deltaMove = 0.0; break;
	}
}

void mouseMove(int x, int y)
{
	if (isDragging) { // only when dragging
		// update the change in angle
		deltaAngle = (x - xDragStart) * 0.005;

		// camera's direction is set to angle + deltaAngle
		lx = -sin(angle + deltaAngle);
		ly = cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) { // left mouse button pressed
			isDragging = 1; // start dragging
			xDragStart = x; // save x where button first pressed
		}
		else  { /* (state = GLUT_UP) */
			angle += deltaAngle; // update camera turning angle
			isDragging = 0; // no longer dragging
		}
	}
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
void menu (int b)
{
     if(b==1)
     {
            x=0.0;
            y=-190.0;
            z=30.0;
     }
     if(b==2)
     {
			x=2.0;
            y=-140.0;
            z=4;
     }
     if(b==3)
     {
			x=40.0;
            y=-12.0;
            z=10.0;
     }
     if(b==4)
     {
			x=-40.0;
            y=-130.0;
            z=12.0;
     }
     if(b==5)
     {
			x=43.0;
            y=-135.0;
            z=8.0;
     }
     if(b==6)
     {
			if(sunce == 0)
            {
                glEnable(GL_LIGHT0);
                sunce = 1;
            }
            else
            {
                glDisable(GL_LIGHT0);
                sunce = 0;
            }
     }
     glutPostRedisplay();
}
void kreirajMeni()
{
     glutCreateMenu(menu);
     glutAddMenuEntry("Pticiji pogled",1);
     glutAddMenuEntry("Ulaz",2);
     glutAddMenuEntry("Kuca",3);
     glutAddMenuEntry("Igraliste",4);
     glutAddMenuEntry("Teren za igru",5);
     glutAddMenuEntry("Sunce ON/OFF",6);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
	printf("\n\
-----------------------------------------------------------------------\n\
  OpenGL Sample Program:\n\
  - Drag mouse left-right to rotate camera\n\
  - Hold up-arrow/down-arrow to move camera forward/backward\n\
  - q or ESC to quit\n\
-----------------------------------------------------------------------\n");

	// general initializations
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("OpenGL/GLUT Sampe Program");
	kreirajMeni();
	// register callbacks

	glutReshapeFunc(changeSize); // window reshape callback
	glutDisplayFunc(renderScene); // (re)display callback

	glutIdleFunc(update); // incremental update
	glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
	glutMouseFunc(mouseButton); // process mouse button push/release
	glutMotionFunc(mouseMove); // process mouse dragging motion
	glutKeyboardFunc(processNormalKeys); // process standard key clicks
	glutSpecialFunc(pressSpecialKey); // process special key pressed
						// Warning: Nonstandard function! Delete if desired.
	glutSpecialUpFunc(releaseSpecialKey); // process special key release


//pozivanje texture
    texture1=LoadTexture("front.bmp",259, 259);
    texture2=LoadTexture("texture2.raw",260, 256);
    texture3=LoadTexture("texture3.raw",200, 30);


	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0; // this is just to keep the compiler happy
}
