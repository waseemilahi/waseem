                       /*Puppet Program by Waseem Ilahi*/

#include <Windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Prototypes.
void DrawTail(void);
void DrawLegs(void);
void DrawNeck(void);
void DrawFace(void);
void DrawEyes(void);

float dist = -15.0;		/* distance from camera to object */
float yaw = 0.0;		/* rotate about Y axis */
float pitch = 0.0;	/* rotate about X axis */

/* shading values */

 float ambiantmat[]={0.19225};
 float diffusemat[]={0.50754};
 float specularmat[]={0.508273};
 float shininessmat=51.2;

 float ambiantmattail[]={0.0};
 float diffusemattail[]={0.01};
 float specularmattail[]={0.5};
 float tailshininessmat=32;

 float ambiantmatlegs[]={0.0};
 float diffusematlegs[]={0.01};
 float specularmatlegs[]={0.5};
 float legsshininessmat=32;

 float ambiantmateyes[]={0.0};
 float diffusemateyes[]={0.01};
 float specularmateyes[]={0.5};
 float eyesshininessmat=32;

int rgb = GL_TRUE;
int doubleBuffer = GL_TRUE;
int windType;

GLint windW, windH;

GLUquadricObj *myQuadricObj;

/* named parts of the iguana */

#define IGUANA_NONE               0
#define IGUANA_BODY               1
#define IGUANA_TAIL               2
#define IGUANA_LEFT_FRONT_LEG     3
#define IGUANA_RIGHT_FRONT_LEG    4
#define IGUANA_LEFT_HIND_LEG      5
#define IGUANA_RIGHT_HIND_LEG     6
#define IGUANA_NECK               7
#define IGUANA_RESET              8

int picked = IGUANA_NONE;

/* transformation parameters */
GLdouble translate_increment;
float Iguana_position[3] = {0.0, 0.0, 0.0};

float front_LLangle = 0.0;
float front_RLangle = 0.0;
float hind_LLangle = 0.0;
float hind_RLangle = 0.0;
float tail_angle = 0.0;
float neck_angle = 0.0;

float front_LLangle1 = 0.0;
float front_RLangle1 = 0.0;
float hind_LLangle1 = 0.0;
float hind_RLangle1 = 0.0;
float tail_angle1 = 0.0;
float neck_angle1 = 0.0;

/* Texture values */

#ifdef GL_VERSION_1_1
static GLuint texName;
#endif

#define TEXTURE_WIDTH  64
#define TEXTURE_HEIGHT 64

GLubyte Picture[TEXTURE_WIDTH][TEXTURE_HEIGHT][4];			/* Array of texels */

static void set_material(GLfloat *ambient, GLfloat *diffuse, GLfloat *specular, GLfloat shininess)
{
	glMaterialfv (GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, specular);
	glMaterialf (GL_FRONT, GL_SHININESS, shininess);
}

//The init function.

static void Init(void)
{
	/* Set background color */

    glClearColor(0.2, 0.8, 1.0, 0.0); /* blue sky */

	/* Enable depth buffer */

	glEnable(GL_DEPTH_TEST);

	/* Set polygon attributes */

	glPolygonMode (GL_FRONT, GL_FILL);
	//glEnable (GL_CULL_FACE);
	//glCullFace (GL_BACK);

	/* Set shading & lighting values*/

	glShadeModel (GL_SMOOTH);

	glEnable (GL_LIGHTING);
	glEnable (GL_LIGHT0);

   /* Enable texture mapping */
	glEnable(GL_TEXTURE_2D);

   /* Create quadric object for all of the puppet's parts */

    myQuadricObj = gluNewQuadric();
    gluQuadricDrawStyle(myQuadricObj, (GLenum)GLU_FILL);
    gluQuadricNormals(myQuadricObj, (GLenum)GLU_SMOOTH);
    gluQuadricTexture(myQuadricObj,GL_TRUE);
}

/* Generate a texture */

void GenerateTexture(void) {

	/* Generate the texture map */
	int i, j;

	for (j=0; j<TEXTURE_HEIGHT; j++) {
		for (i=0; i<TEXTURE_WIDTH; i++) {
         //Creating texture from the function.
			Picture[i][j][0] =  cos(cos(i+j+1)/sin(i+j+1))*255;
			Picture[i][j][1] =
			Picture[i][j][2] = 0;
			Picture[i][j][3] = 255;
		}
	}

	/* Define it as a texture map */

#ifdef GL_VERSION_1_1
   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);
#endif

	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0,
				  GL_RGBA, GL_UNSIGNED_BYTE, Picture);

}

/* Window size has changed:
   adjust viewport and perspective transformations */

static void Reshape(int width, int height)
{
	float aspect;

    windW = (GLint)width;
    windH = (GLint)height;
	aspect = (float)windW / (float)windH;
   translate_increment=0.1;

	/* Viewport fills the entire window */

    glViewport(0, 0, width, height);

	/* Use perspective projection */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (60.0, aspect, 1.0, 1000.0); /* fovy, aspect, near, far */

	/* Return to modelview mode */
    glMatrixMode(GL_MODELVIEW);
}

/* Set modeling and viewing transformations,
   then draw the letter polygons */

#define BUFSIZE 64

#define BODY_RADIUS 2.0
#define NECK_RADIUS 0.8
#define FACE_RADIUS 0.8
#define TOP_RADIUS    1.0
#define LEG_WIDTH     0.25
#define LEG_LENGTH    6.0	/* actually, a scale */
#define LEG_SHIFT     2.25	/* MIDDLE_RADIUS + 1/2 of LEG_LENGTH */
#define TAIL_WIDTH     0.25
#define TAIL_LENGTH    6.0	/* actually, a scale */

static void DrawIguana(void)
{ 

	/* Transformation for entire Iguana */

	glLoadIdentity();

	glTranslatef(0.0, 0.0, dist);		/* step back */
  	glRotatef(pitch, 1.0, 0.0, 0.0);	/* spin on X axis */
	glRotatef(yaw, 0.0, 1.0, 0.0);		/* spin on Y axis */

	/* Draw the body of the Iguana (The root of the hierarchy) */
   glScalef(2.5,1.0,1.0);
   set_material( ambiantmat, diffusemat, specularmat, shininessmat);
   glTranslatef(Iguana_position[0], Iguana_position[1], Iguana_position[2]);
	gluSphere (myQuadricObj, BODY_RADIUS, 50, 50);

   //Draw Tail.
   DrawTail(); 

   /* Draw the 4 legs */
   DrawLegs();

   //Draw the neck and face on it
   DrawNeck();

}

void DrawNeck()
{
      glPushMatrix();	// save Tx for body of Iguana

      set_material( ambiantmat, diffusemat, specularmat, shininessmat);

      glRotatef(-25,0.0,0.0,1.0);
      glTranslatef(-BODY_RADIUS,0.0,0.0);
      glRotatef(neck_angle,0.0,1.0,0.0);
      glRotatef(neck_angle1,0.0,0.0,1.0);
      gluSphere (myQuadricObj, NECK_RADIUS, 50, 50);

      //Draw the face
      DrawFace();
      
      glPopMatrix();	// restore Tx for body of Iguana
}

void DrawFace()
{
       glPushMatrix();	// save Tx for neck of Iguana         

       glRotatef(-10,0.0,0.0,1.0);
       glScalef(0.5,1.0,1.0);
       glTranslatef(-NECK_RADIUS-.5,0.0,0.0);
       gluSphere (myQuadricObj, FACE_RADIUS, 50, 50);

       //Draw the Eyes
       DrawEyes();

      glPopMatrix();	// restore Tx for neck of Iguana

}

void DrawEyes()
{
     //Left
     glPushMatrix();	// save Tx for face of Iguana

     set_material(ambiantmateyes,diffusemateyes,specularmateyes,eyesshininessmat);
     glScalef(0.8,1.0,1.0);
     glTranslatef(-FACE_RADIUS+0.3,0.32,0.5);
     glutSolidSphere (TOP_RADIUS/6.0, 10, 6);	// left eye

     glPopMatrix();	// restore Tx for face of Iguana

     //Right
     glPushMatrix();	// save Tx for face of Iguana

     set_material(ambiantmateyes,diffusemateyes,specularmateyes,eyesshininessmat);
     glScalef(0.8,1.0,1.0);
     glTranslatef(-FACE_RADIUS+0.3,0.32,-0.5);
     glutSolidSphere (TOP_RADIUS/6.0, 10, 6);	// right eye

     glPopMatrix();	// restore Tx for face of Iguana

}

void DrawTail()
{

	glPushMatrix();	// save Tx for body of Iguana

   set_material(ambiantmattail,diffusemattail,specularmattail,tailshininessmat);

   glRotatef(-5,0.0,0.0,1.0);
   glTranslatef(BODY_RADIUS-0.6,-0.6,2.0); 
   glRotatef(90,0.0,1.0,0.0);
   glRotatef(90,0.0,0.0,1.0);
	glTranslatef(0.0, -BODY_RADIUS, 0.0);
   glScalef(TAIL_LENGTH/2, 1.0, 1.0);
	glTranslatef(TAIL_WIDTH/2.0,0.0 , 0.0);

   glRotatef(-tail_angle,1.0,0.0,0.0);
   glRotatef(-tail_angle1,0.0,1.0,0.0);

   gluCylinder(myQuadricObj,0.2,0.0,2.5,40,40);

	glPopMatrix();	// restore Tx for body of Iguana

}

void DrawLegs()
{

   //Front left
   glPushMatrix();	// save Tx for body of Iguana

    set_material(ambiantmatlegs,diffusematlegs,specularmatlegs,legsshininessmat);

    glTranslatef(-0.8,-0.7,1.2);
    glRotatef(90,1.0,0.0,0.0);

    glRotatef(-front_LLangle,0.0,1.0,0.0);
    glRotatef(front_LLangle1,1.0,0.0,0.0);
    
    gluCylinder(myQuadricObj,0.1,0.025,2,40,40);

    glPopMatrix();	// restore Tx for body of Iguana

    //Front right
    glPushMatrix();	// save Tx for body of Iguana

    set_material(ambiantmatlegs,diffusematlegs,specularmatlegs,legsshininessmat);

    glTranslatef(-0.8,-0.7,-1.2);
    glRotatef(90,1.0,0.0,0.0);

    glRotatef(-front_RLangle,0.0,1.0,0.0);
    glRotatef(-front_RLangle1,1.0,0.0,0.0);

    gluCylinder(myQuadricObj,0.1,0.025,2,40,40);

    glPopMatrix();	// restore Tx for body of Iguana

    //Hind left
    glPushMatrix();	// save Tx for body of Iguana

    set_material(ambiantmatlegs,diffusematlegs,specularmatlegs,legsshininessmat);

    glTranslatef(0.8,-0.7,1.2);
    glRotatef(90,1.0,0.0,0.0);

    glRotatef(-hind_LLangle,0.0,1.0,0.0);
    glRotatef(hind_LLangle1,1.0,0.0,0.0);

    gluCylinder(myQuadricObj,0.1,0.025,2,40,40);

    glPopMatrix();	// restore Tx for body of Iguana

    //Hind right
    glPushMatrix();	// save Tx for body of Iguana

    set_material(ambiantmatlegs,diffusematlegs,specularmatlegs,legsshininessmat);

    glTranslatef(0.8,-0.7,-1.2);
    glRotatef(90,1.0,0.0,0.0);

    glRotatef(-hind_RLangle,0.0,1.0,0.0);
    glRotatef(-hind_RLangle1,1.0,0.0,0.0);

    gluCylinder(myQuadricObj,0.1,0.025,2,40,40);

    glPopMatrix();	// restore Tx for body of Iguana
    
}

static void Draw(void)
{
	/* clear the screen */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glEnable(GL_TEXTURE_2D);

   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
   
	/* draw the Iguana */

	DrawIguana();

	/* update the screen */

    glFlush();			/* force all changes to be applied to buffer */
	glutSwapBuffers();	/* display what you just drew */
}

/* Arrow keys change angle of rotation */

static void Key2(int key, int x, int y)
{

    switch (key) {
      case GLUT_KEY_LEFT:	/* decrease angle about Y axis */
		switch (picked) {
		case IGUANA_NONE:
			yaw -= 5.0;
			break;
		case IGUANA_BODY:
			Iguana_position[0] -= translate_increment;
			break;
		case IGUANA_LEFT_FRONT_LEG:
			front_LLangle += 5.0;
			break;
		case IGUANA_RIGHT_FRONT_LEG:
			front_RLangle += 5.0;
			break;
		case IGUANA_LEFT_HIND_LEG:
			hind_LLangle += 5.0;
			break;
		case IGUANA_RIGHT_HIND_LEG:
			hind_RLangle += 5.0;
			break;
      case IGUANA_TAIL:
			tail_angle += 5.0;
			break;
      case IGUANA_NECK:
			neck_angle += 5.0;
			break;
		}
	break;
      case GLUT_KEY_RIGHT:	/* increase angle about Y axis */
			switch (picked) {
		case IGUANA_NONE:
			yaw += 5.0;
			break;
		case IGUANA_BODY:
			Iguana_position[0] += translate_increment;
			break;
		case IGUANA_LEFT_FRONT_LEG:
			front_LLangle -= 5.0;
			break;
		case IGUANA_RIGHT_FRONT_LEG:
			front_RLangle -= 5.0;
			break;
		case IGUANA_LEFT_HIND_LEG:
			hind_LLangle -= 5.0;
			break;
		case IGUANA_RIGHT_HIND_LEG:
			hind_RLangle -= 5.0;
			break;
      case IGUANA_TAIL:
			tail_angle-= 5.0;
			break;
      case IGUANA_NECK:
			neck_angle -= 5.0;
			break;
		}
	break;
      case GLUT_KEY_UP:		/* decrease angle about Z axis */
			switch (picked) {
		case IGUANA_NONE:
			pitch -= 5.0;
			break;
		case IGUANA_BODY:
			Iguana_position[1] += translate_increment;
			break;
		case IGUANA_LEFT_FRONT_LEG:
			front_LLangle1 -= 5.0;
			break;
		case IGUANA_RIGHT_FRONT_LEG:
			front_RLangle1 -= 5.0;
			break;
		case IGUANA_LEFT_HIND_LEG:
			hind_LLangle1 -= 5.0;
			break;
		case IGUANA_RIGHT_HIND_LEG:
			hind_RLangle1 -= 5.0;
			break;
      case IGUANA_TAIL:
			tail_angle1 -= 5.0;
			break;
      case IGUANA_NECK:
			neck_angle1 -= 5.0;
			break;
		}
	break;
      case GLUT_KEY_DOWN:	/* increase angle about X axis */
		switch (picked) {
		case IGUANA_NONE:
			pitch += 5.0;
			break;
		case IGUANA_BODY:
			Iguana_position[1] -= translate_increment;
			break;
		case IGUANA_LEFT_FRONT_LEG:
			front_LLangle1 += 5.0;
			break;
		case IGUANA_RIGHT_FRONT_LEG:
			front_RLangle1 += 5.0;
			break;
		case IGUANA_LEFT_HIND_LEG:
			hind_LLangle1 += 5.0;
			break;
		case IGUANA_RIGHT_HIND_LEG:
			hind_RLangle1 += 5.0;
			break;
      case IGUANA_TAIL:
			tail_angle1 += 5.0;
			break;
      case IGUANA_NECK:
			neck_angle1 += 5.0;
			break;
		}
	break;
      default:
	return;
    }

    glutPostRedisplay();	/* force update of the display */
}

/* Handle other keys */

static void Key(unsigned char key, int x, int y)
{

    switch (key) {
      case 27:			/* ESC to quit */
	exit(1);
      case '+':
		  dist += 1.0;	/* move camera closer */
	break;
      case '-':
		  dist -= 1.0;	/* move camera back */
	break;
      default:
	return;
    }

    glutPostRedisplay();	/* force update of the display */
}

/* Create pop-up window using GLUT */

#define ROTATE_BODY 1

void PopUp (int value)
{
	if (value == IGUANA_RESET) {
		Iguana_position[0] = 0.0;
		Iguana_position[1] = 0.0;
		Iguana_position[2] = 0.0;

      front_LLangle = 0.0;
      front_RLangle = 0.0;
      hind_LLangle = 0.0;
      hind_RLangle = 0.0;
      tail_angle = 0.0;
      neck_angle = 0.0;

      front_LLangle1 = 0.0;
      front_RLangle1 = 0.0;
      hind_LLangle1 = 0.0;
      hind_RLangle1 = 0.0;
      tail_angle1 = 0.0;
      neck_angle1 = 0.0;

		yaw = 0.0;		/* rotate about Y axis */
		pitch = 0.0;	/* rotate about X axis */
		dist = -15.0;		/* distance from camera to object */

		glPolygonMode (GL_FRONT, GL_FILL);
		DrawIguana();

		glutPostRedisplay();
}
	else
		picked = value;
}

void initMenu(void)
{
	int menuid;

	/* create a menu and save the id */
	menuid = glutCreateMenu(PopUp);

	/* add menu entries */
	glutAddMenuEntry ("Rotate Body", IGUANA_NONE);
	glutAddMenuEntry ("Move Body", IGUANA_BODY);
	glutAddMenuEntry ("Move LEFT FRONT LEG", IGUANA_LEFT_FRONT_LEG);
	glutAddMenuEntry ("Move RIGHT FRONT LEG", IGUANA_RIGHT_FRONT_LEG);
   glutAddMenuEntry ("Move LEFT HIND LEG", IGUANA_LEFT_HIND_LEG);
	glutAddMenuEntry ("Move RIGHT HIND LEG", IGUANA_RIGHT_HIND_LEG);
   glutAddMenuEntry ("Move Tail", IGUANA_TAIL);
   glutAddMenuEntry ("Move Neck", IGUANA_NECK);
	glutAddMenuEntry ("Reset", IGUANA_RESET);

	/* attach menu to right button */
	glutAttachMenu (GLUT_RIGHT_BUTTON);
}

int main()
{
	/* Setup the window that logo will appear in */

    windW = 1220;
    windH = 900;
    glutInitWindowPosition(10, 10);
	 glutInitWindowSize( windW, windH);

    windType  = GLUT_DEPTH;
	 windType |= (rgb) ? GLUT_RGB : GLUT_INDEX;
    windType |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(( GLenum)windType);

    if (glutCreateWindow("Iguana") == GL_FALSE) {
		exit(1);
    }

    Init();
    GenerateTexture();
    initMenu();

    glutKeyboardFunc(Key);
    glutSpecialFunc(Key2);
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
