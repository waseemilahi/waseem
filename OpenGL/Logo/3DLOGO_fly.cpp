/*
 * wilahi_3DLOGO_fly.cpp
 *
 * draws the initials of my first, middle and last names that fly.
 */


#include <Windows.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Screen window parameters */
int windType;
GLint windW, windH;

/* camera parameters */

struct camera {
	float ex, ey, ez;	/* eye position */
	float ux, uy, uz;	/* u axis */
	float vx, vy, vz;	/* v axis */
	float nx, ny, nz;	/* n axis */
} myCamera;

GLdouble spin_angle = 0.0;
GLdouble spin_increment = 3;
GLboolean animate = FALSE;

 /* camera functions */

void init_camera (float ex, float ey, float ez, // eye or camera coordinates (origin of view)
		  float ux, float uy, float uz, // u axis (points to right of origin)
		  float vx, float vy, float vz, // v axis (points up from origin)
		  float nx, float ny, float nz) // n axis (points opposite of view direction)
{
	myCamera.ex = ex;
	myCamera.ey = ey;
	myCamera.ez = ez;
	myCamera.ux = ux;
	myCamera.uy = uy;
	myCamera.uz = uz;
	myCamera.vx = vx;
	myCamera.vy = vy;
	myCamera.vz = vz;
	myCamera.nx = nx;
	myCamera.ny = ny;
	myCamera.nz = nz;
}
void setModelViewMatrix(struct camera C) {
	float m[16];
	m[0] = C.ux; m[1] = C.vx; m[2]  = C.nx; m[3]  = 0; 
	m[4] = C.uy; m[5] = C.vy; m[6]  = C.ny; m[7]  = 0; 
	m[8] = C.uz; m[9] = C.vz; m[10] = C.nz; m[11] = 0;
	m[12] = -((C.ex * C.ux) + (C.ey * C.uy) + (C.ez * C.uz)); 
	m[13] = -((C.ex * C.vx) + (C.ey * C.vy) + (C.ez * C.vz)); 
	m[14] = -((C.ex * C.nx) + (C.ey * C.ny) + (C.ez * C.nz)); 
	m[15] = 1;
	glMatrixMode (GL_MODELVIEW);
	glLoadMatrixf (m);
}
void slide_camera (float dx, float dy, float dz) {
	myCamera.ex += (dx * myCamera.ux) + (dy * myCamera.vx) + (dz * myCamera.nx);
	myCamera.ey += (dx * myCamera.uy) + (dy * myCamera.vy) + (dz * myCamera.ny);
	myCamera.ez += (dx * myCamera.uz) + (dy * myCamera.vz) + (dz * myCamera.nz);
} 
void roll_camera (double angle)
{
      angle=0.0174532925*angle;

     myCamera.ux=myCamera.ux*cos(angle)-myCamera.vx*sin(angle);
     myCamera.uy=myCamera.uy*cos(angle)-myCamera.vy*sin(angle);
     myCamera.uz=myCamera.uz*cos(angle)-myCamera.vz*sin(angle);

     myCamera.vx=myCamera.vx*cos(angle)+myCamera.ux*sin(angle);
     myCamera.vy=myCamera.vy*cos(angle)+myCamera.uy*sin(angle);
     myCamera.vz=myCamera.vz*cos(angle)+myCamera.uz*sin(angle);

     glutPostRedisplay();
}
void pitch_camera (double angle)
{
    angle=0.0174532925*angle;

     myCamera.vx=myCamera.vx*cos(angle)-myCamera.nx*sin(angle);
     myCamera.vy=myCamera.vy*cos(angle)-myCamera.ny*sin(angle);
     myCamera.vz=myCamera.vz*cos(angle)-myCamera.nz*sin(angle);

     myCamera.nx=myCamera.nx*cos(angle)+myCamera.vx*sin(angle);
     myCamera.ny=myCamera.ny*cos(angle)+myCamera.vy*sin(angle);
     myCamera.nz=myCamera.nz*cos(angle)+myCamera.vz*sin(angle);

     glutPostRedisplay();

}
void yaw_camera (double angle)
{

      angle=0.0174532925*angle;

     myCamera.ux=myCamera.ux*cos(angle)+myCamera.nx*sin(angle);
     myCamera.uy=myCamera.uy*cos(angle)+myCamera.ny*sin(angle);
     myCamera.uz=myCamera.uz*cos(angle)+myCamera.nz*sin(angle);

     myCamera.nx=myCamera.nx*cos(angle)-myCamera.ux*sin(angle);
     myCamera.ny=myCamera.ny*cos(angle)-myCamera.uy*sin(angle);
     myCamera.nz=myCamera.nz*cos(angle)-myCamera.uz*sin(angle);

     glutPostRedisplay();

}

/* FILL IN THIS FUNCTION TO INCREMENTALLY CHANGE POSITION / ORIENTATION / SIZE OF LOGO */
/* 
   Hint: change global rotation or position value(s) by a small amount,
   then use the value(s) as parameters in the Draw function
*/

void fly (void)
{
     spin_angle+=spin_increment;   

     glutPostRedisplay();	/* update of the display */
}

GLuint letterI; // display list speeds up rendering
GLuint letterW; // display list speeds up rendering
GLuint letterK; // display list speeds up rendering

/* draw the letter I in a display list called letterI */

void drawI (void)
{

	#define NPOINTS   8
	#define NPOLYGONS 6

	/* define all the points on the letter */

	GLdouble point[NPOINTS][3] = {
		{4.5, 0.0, 1.2},
		{5.5, 0.0, 1.2},
		{5.5, 6.0, 1.2},
		{4.5, 6.0, 1.2},
      {4.5, 0.0, 0.0},
		{5.5, 0.0, 0.0},
		{5.5, 6.0, 0.0},
		{4.5, 6.0, 0.0}};

	/* each polygonal face references 4 points */

	int polygon[NPOLYGONS][4] = {
		{0, 1, 2, 3}, /* front face */

		{4, 7, 6, 5}, /* back face */

		{0, 3, 7, 4}, /* side faces */

      {1, 5, 6, 2},

		{2, 6, 7, 3},

		{4, 5, 1, 0}};

	/* color array defines a different color for each face */

	GLdouble color[NPOLYGONS][3] = {
		{0.3, 0.5, 0.2}, /* front face */

		{0.3, 0.5, 0.2}, /* back face */

		{0.4, 0.4, 0.4}, /* side faces */

		{0.6, 0.6, 0.6},

		{0.8, 0.8, 0.8},

		{0.9, 0.9, 0.9}};

	int face, pt;

	/* Setup display list */
	letterI = glGenLists(1);
	glNewList (letterI, GL_COMPILE);

	/* Draw the letter */
	for (face = 0; face < NPOLYGONS; face++) {
		glColor3dv(color[face]);    /* set the color of the face */
		glBegin(GL_POLYGON);
		for (pt = 0; pt < 4; pt++)  /* draw all points on the face */
			glVertex3dv (point[polygon[face][pt]]);
		glEnd();
	}

	/* Finish the display list */
	glEndList();
}

/* draw the letter K in a display list called letterk */

void drawK (void)
{

	#define NPOINTSK   22
	#define NPOLYGONSK 19

	/* define all the points on the letter */

	GLdouble point[NPOINTSK][3] = {
		{-1.0, 0.0, 1.0},
		{ 0.0, 0.0, 1.0},
		{ 0.0, 6.0, 1.0},
		{-1.0, 6.0, 1.0},
      {-1.0, 0.0, 0.0},
		{ 0.0, 0.0, 0.0},
		{ 0.0, 6.0, 0.0},
		{-1.0, 6.0, 0.0},
      { 0.5, 3.0, 1.0},
      {-0.35,3.5, 1.0},
      {2.0, 6.0, 1.0},
      {3.2, 6.0, 1.0},
      {3.2, 0.0, 1.0},
      {2.0, 0.0, 1.0},
      {-0.5,2.0, 1.0},
      {0.0, 3.0, 0.0},
      {-0.4,3.5, 0.0},
      {2.0, 5.9, 0.0},
      {3.0, 5.9, 0.0},
      {2.8, 0.0, 0.0},
      {2.0, 0.0, 0.0},
      {-0.5,2.5, 0.0}};

	/* each polygonal face references 4 points */

	int polygon[NPOLYGONSK][4] = {
		{0, 1, 2, 3}, /* front face */

      {11, 10, 9, 8},

      {8, 14, 13, 12},

      {8, 9, 14, 14},

		{4, 7, 6, 5}, /* back face */

      {16,17,18,15},

      {15,19,20,21},

      {16, 15, 21,21},

		{0, 3, 7, 4}, /* side faces */

      {1, 5, 6, 2},

		{21, 14, 2, 6},

      {6, 7, 3, 2},

		{4, 5, 1, 0},

      {18, 17, 10, 11},

      {12, 13, 20, 19},

      {10, 17, 16, 9},

      {11, 8, 15, 18},

      {19, 15, 8, 12},

      {13, 14, 21, 20}};

	/* color array defines a different color for each face */

	GLdouble color[NPOLYGONSK][3] = {
		{0.3, 0.5, 0.2}, /* front face */

      {0.3, 0.5, 0.2},

      {0.3, 0.5, 0.2},

      {0.3, 0.5, 0.2},

		{0.3, 0.5, 0.2}, /* back face */

      {0.3, 0.5, 0.2},

      {0.3, 0.5, 0.2},

      {0.3, 0.5, 0.2},

		{0.4, 0.6, 0.3}, /* side faces */

		{0.6, 0.6, 0.6},

		{0.8, 0.8, 0.8},

      {0.8, 0.8, 0.8},

		{0.9, 0.9, 0.9},

      {0.7, 0.8, 0.9},

      {0.6, 0.7, 0.8},

      {0.2, 0.4, 0.6},

      {0.4, 0.1, 0.7},

      {0.4, 0.4, 0.4},

      {0.5, 0.5, 0.5}};

	int face, pt;

	/* Setup display list */
	letterK = glGenLists(1);
	glNewList (letterK, GL_COMPILE);

	/* Draw the letter */
	for (face = 0; face < NPOLYGONSK; face++) {
		glColor3dv(color[face]);    /* set the color of the face */
		glBegin(GL_POLYGON);
		for (pt = 0; pt < 4; pt++)  /* draw all points on the face */
			glVertex3dv (point[polygon[face][pt]]);
		glEnd();
	}

	/* Finish the display list */
	glEndList();
}

/* draw the letter W in a display list called W */

void drawW (void)
{

	#define NPOINTSW   32
	#define NPOLYGONS1 16
        #define NPOLYGONS2 13

	/* define all the points on the letter */

	GLdouble point[NPOINTSW][3] = {
		{-7.9, 6.0, 1.2},
		{-7.3, 0.0, 1.2},
		{-5.7, 0.0, 1.2},
		{-4.3, 0.0, 1.2},
      {-2.7, 0.0, 1.2},
		{-2.1, 6.0, 1.2},
		{-3.1, 6.0, 1.2},
		{-4.3, 6.0, 1.2},
      {-5.7, 6.0, 1.2},
	        {-6.9, 6.0, 1.0},
	        {-6.0,0.0, 1.0},
	        {-3.7,0.0, 1.0},
	        {-5.0,4.0, 1.0},
           {-5.0, 6.0, 1.0},
	        {-6.7, 0.0, 1.0},
	        {-3.0, 0.0, 1.0},
      {-7.9, 6.0, 0.0},/*reverse side starts here*/
		{-7.3, 0.0, 0.0},
		{-5.7, 0.0, 0.0},
		{-4.3, 0.0, 0.0},
      {-2.7, 0.0, 0.0},
		{-2.1, 6.0, 0.0},
		{-3.1,  6.0, 0.0},
		{-4.3, 6.0, 0.0},
      {-5.7, 6.0, 0.0},
	        {-6.9, 6.0, 0.0},
	        {-6.4,1.5, 0.0},
	        {-3.7,1.5, 0.0},
	        {-5.0, 3.0, 0.0},
           {-5.0, 6.0, 0.0},
	        {-6.7, 0.0, 0.0},
	        {-3.4, 0.0, 0.0}};

	/* each polygonal face references 4 points */

	int polygon1[NPOLYGONS1][4] = {
		{9, 0, 1, 14}, /* front faces */
		{9, 14, 14, 10},
		{13, 8, 12, 12},
		{8, 14, 2, 12},
		{7,13, 12, 3},
		{7, 3, 15, 11},
		{6,11, 15, 4},
		{5, 6, 4, 4},

		{16, 25, 26, 30}, /* back faces */
		{16, 30, 17, 17},
		{30, 24, 29, 28},
		{30, 28, 18, 18},
		{29, 23, 31, 19},
		{29, 19, 28, 28},
		{31, 27, 22, 21},
	        {21, 20, 31, 31}};

	/* color array defines a different color for each face */

	GLdouble color1[NPOLYGONS1][3] = {
		{0.3, 0.5, 0.2}, /* front faces */
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},

		{0.3, 0.5, 0.2}, /* back faces */
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
      {0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2},
		{0.3, 0.5, 0.2}};


	/*Side faces: where each polygon refrences to 4 points.*/

        int polygon2[NPOLYGONS2][4] = {
		{0, 16, 17, 1},

		{25, 9, 10, 26},

		{8, 24, 26, 10},

      {23, 7, 11, 27},

		{6, 22, 27, 11},

		{21, 5, 4, 20},

		{25, 16, 0, 9},

		{21, 22, 6, 5},

		{2, 1, 17, 18},

           {4, 3, 19, 20},

	        {28, 12, 2, 18},

	        {12, 28, 19, 3},

	        {23, 24, 8, 7}};

     /* color array defines a different color for each face */

	GLdouble color2[NPOLYGONS2][3] = {
		{0.3, 0.3, 0.3}, /* side faces */
		{0.3, 0.7, 0.7},
		{0.4, 0.4, 0.4},
		{0.4, 0.5, 0.7},
		{0.5, 0.5, 0.5},
		{0.5, 0.6, 0.7},
		{0.6, 0.5, 0.6},
		{0.6, 0.8, 0.9},
		{0.7, 0.7, 0.7},
		{0.7, 0.9, 1.0},
		{0.9, 0.6, 0.9},
		{0.8, 1.0, 0.3},
                {0.9, 0.9, 0.9}};

	int face, pt;

	/* Setup display list */
	letterW = glGenLists(1);
	glNewList (letterW, GL_COMPILE);

	/* Draw the letter */
	for (face = 0; face < NPOLYGONS1; face++) {
		glColor3dv(color1[face]);    /* set the color of the face */
		glBegin(GL_POLYGON);
		for (pt = 0; pt < 4; pt++)  /* draw all points on the face */
			glVertex3dv (point[polygon1[face][pt]]);
		glEnd();
	}

	for (face = 0; face < NPOLYGONS2; face++) {
		glColor3dv(color2[face]);    /* set the color of the face */
		glBegin(GL_POLYGON);
		for (pt = 0; pt < 4; pt++)  /* draw all points on the face */
			glVertex3dv (point[polygon2[face][pt]]);
		glEnd();
	}

	/* Finish the display list */
	glEndList();
}

/* Setup OpenGL state machine */

static void Init(void)
{
	/* Set background color */

    glClearColor(0.0, 0.0, 0.0, 0.0);

	/* Enable depth buffer */

	glEnable(GL_DEPTH_TEST);

	/* Enable back-face culling */
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

   /* Set polygon attributes */
	glPolygonMode (GL_FRONT, GL_FILL);

	/* Set shading & lighting values*/
	glShadeModel (GL_FLAT);
}


/* Window size has changed:
   adjust viewport and perspective transformations */

static void Reshape(int width, int height)
{
	float aspect;

    windW = (GLint)width;
    windH = (GLint)height;

	aspect = (float)windW / (float)windH;

	/* Viewport fills the entire window */

    glViewport(0, 0, width, height);

	/* Use orthographic projection to set visibility boundaries relative to viewing coordinates */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    	gluPerspective (70.0, aspect, 0.001, 110.0); /* fovy, aspect, near, far */

	/* Return to modelview mode */
    glMatrixMode(GL_MODELVIEW);
}

static void Key2(int key,int x,int y)
{

    switch (key) {
      case GLUT_KEY_LEFT:	/* decrease angle about Y axis */
		  yaw_camera(-5.0);
	break;
      case GLUT_KEY_RIGHT:	/* increase angle about Y axis */
		  yaw_camera(5.0);
	break;
      case GLUT_KEY_UP:		/* decrease angle about X axis */
		  pitch_camera(-5.0);
	break;
      case GLUT_KEY_DOWN:	/* increase angle about X axis */
		  pitch_camera(5.0);
	break;
      default:
	return;
    }

    glutPostRedisplay();	/* force update of the display */
}

static void Key(unsigned char key, int x, int y)
{

    switch (key) {
      case 27:			/* ESC to quit */
	exit(1);
      case 'r':
	  case 'R':
		  slide_camera (1.0, 0.0, 0.0);	/* move camera right */
		break;
      case 'l':
	  case 'L':
		  slide_camera (-1.0, 0.0, 0.0);	/* move camera left */
		break;
      case 'u':
	  case 'U':
		  slide_camera (0.0, 1.0, 0.0);	/* move camera up */
		break;
      case 'd':
	  case 'D':
		  slide_camera (0.0, -1.0, 0.0);	/* move camera down */
		break;
      case 'b':
	  case 'B':
		  slide_camera (0.0, 0.0, 1.0);	/* move camera back */
		break;
      case 'f':
	  case 'F':
		  slide_camera (0.0, 0.0, -1.0);	/* move camera forward */
		break;
      case 'a':
	  case 'A':
		  if (animate)
			  glutIdleFunc(NULL);
		  else
			  glutIdleFunc(fly);
		  animate = !animate;	
		break;
      case '+':
		  spin_increment+=0.05;
		break;
      case '-':
        if(spin_increment>=0.05)
		     spin_increment-=0.05;
		break;
      case 'w':            /* decrease angle about Z axis */
     case 'W':
     		roll_camera(-5.0);
      break;
      case 'q':            /* increase angle about Z axis */
     case 'Q':
     		roll_camera(5.0);
      break;
      default:
	return;
    }

    glutPostRedisplay();	/* force update of the display */
}


/* Set modeling and viewing transformations,
   then draw the letter polygons */

static void Draw(void)
{
	 //int face, pt;

	/* clear the screen AND the depth buffer */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Set the viewing transformation(s) */

	glLoadIdentity();
	setModelViewMatrix (myCamera); /* Load transformation for camera view */

		/* Transform the letters to the correct position (using global values set by "fly") */

     glTranslated(20,0,-10);

      glRotated(spin_angle,0,1,0);

      glTranslated(-20,0,10);

      glTranslated(-10,0,0);

      glRotated(spin_angle,0,1,0);

      glTranslated(10,0,0);

     /* Draw the letters */

        glCallList(letterW);
        glCallList(letterK);
        glCallList(letterI);

    glFlush();		/* force all changes to be applied to buffer */
	glutSwapBuffers();	/* display what you just drew */
}


int main()
{
	/* Setup the window that logo will appear in */

    windW = 950;
    windH = 950;
    glutInitWindowPosition(0, 0);
	glutInitWindowSize( windW, windH);

	/* Window uses depth buffer, full color, and double buffering */
    windType  = GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE;
    glutInitDisplayMode((GLenum)windType);

    if (glutCreateWindow("Flying Logo") == GL_FALSE) {
		exit(1);
    }

    Init();

    drawW();/*Create display list letterW */
    drawK();/*Create display list letterK */
    drawI(); /* Create display list letterI */

   	/* Initially center camera on world system, & step back 8 */
	init_camera (26.0, 2.0, 55.0,  // camera position in world coordinates
				 1.0, 0.0, 0.0,  // u vector (points to the right)
				 0.0, 1.0, 0.0,  // v vector (points up) 
				 0.0, 0.0, 1.0); // n vector (points opposite to line-of-sight)

    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Key);
    glutSpecialFunc(Key2);
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
