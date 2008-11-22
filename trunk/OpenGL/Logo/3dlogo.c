/*
 * wilahi_3dlogo.c
 *
 * draws the initials of my first and last name.
 */


#include <Windows.h>


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int windType;
GLint windW, windH;

/* camera parameters */

#define EYEX_INIT 2.0
#define EYEY_INIT 3.0
#define EYEZ_INIT 10.0

GLdouble eyeX = EYEX_INIT;
GLdouble eyeY = EYEY_INIT;
GLdouble eyeZ = EYEZ_INIT;
GLdouble centerX = 1.0;
GLdouble centerY = 1.5;
GLdouble centerZ = 0.5;

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
		{5.5, 3.0, 1.2},
		{4.5, 3.0, 1.2},
      {4.5, 0.0, 0.0},
		{5.5, 0.0, 0.0},
		{5.5, 3.0, 0.0},
		{4.5, 3.0, 0.0}};

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

		{0.2, 0.2, 0.2}, /* back face */

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
		{-1.0, 0.0, 1.2},
		{ 0.0, 0.0, 1.2},
		{ 0.0, 3.0, 1.2},
		{-1.0, 3.0, 1.2},
      {-1.0, 0.0, 0.0},
		{ 0.0, 0.0, 0.0},
		{ 0.0, 3.0, 0.0},
		{-1.0, 3.0, 0.0},
      { 0.5, 1.5, 1.2},
      {-0.35,1.75, 1.2},
      {2.0, 3.0, 1.2},
      {3.2, 3.0, 1.2},
      {3.2, 0.0, 1.2},
      {2.0, 0.0, 1.2},
      {-0.5,1.25, 1.2},
      {0.0, 1.5, 0.0},
      {-0.4,1.75, 0.0},
      {2.0, 2.95, 0.0},
      {3.0, 2.95, 0.0},
      {2.8, 0.0, 0.0},
      {2.0, 0.0, 0.0},
      {-0.5,1.25, 0.0}};

	/* each polygonal face references 4 points */

	int polygon[NPOLYGONSK][4] = {
		{0, 1, 2, 3}, /* front face */

      {11, 10, 9, 8},

      {8, 14, 13, 12},

      {8, 9, 14, 14},

		{7, 4, 5, 6}, /* back face */

      {16,17,18,15},

      {15,19,20,21},

      {16, 15, 21,21},

		{7, 4, 0, 3}, /* side faces */

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

		{0.2, 0.2, 0.2}, /* back face */

      {0.2, 0.2, 0.2},

      {0.2, 0.2, 0.2},

      {0.2, 0.2, 0.2},

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
		{-7.9, 3.0, 1.2},
		{-7.3, 0.0, 1.2},
		{-5.7, 0.0, 1.2},
		{-4.3, 0.0, 1.2},
      {-2.7, 0.0, 1.2},
		{-2.1, 3.0, 1.2},
		{-3.1, 3.0, 1.2},
		{-4.3, 3.0, 1.2},
      {-5.7, 3.0, 1.2},
	        {-6.9, 3.0, 1.2},
	        {-6.0,0.0, 1.2},
	        {-3.7,0.0, 1.2},
	        {-5.0,2.0, 1.2},
           {-5.0, 3.0, 1.2},
	        {-6.7, 0.0, 1.2},
	        {-3.0, 0.0, 1.2},
      {-7.9, 3.0, 0.0},/*reverse side starts here*/
		{-7.3, 0.0, 0.0},
		{-5.7, 0.0, 0.0},
		{-4.3, 0.0, 0.0},
      {-2.7, 0.0, 0.0},
		{-2.1, 3.0, 0.0},
		{-3.1, 3.0, 0.0},
		{-4.3, 3.0, 0.0},
      {-5.7, 3.0, 0.0},
	        {-6.9, 3.0, 0.0},
	        {-6.4,0.75, 0.0},
	        {-3.7,0.75, 0.0},
	        {-5.0, 1.5, 0.0},
           {-5.0, 3.0, 0.0},
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

		{0.2, 0.2, 0.2}, /* back faces */
		{0.2, 0.2, 0.2},
		{0.2, 0.2, 0.2},
		{0.2, 0.2, 0.2},
      {0.2, 0.2, 0.2},
		{0.2, 0.2, 0.2},
		{0.2, 0.2, 0.2},
		{0.2, 0.2, 0.2}};


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
}


/* Window size has changed:
   adjust viewport and perspective transformations */

static void Reshape(int width, int height)
{
	float aspect;

    windW = (GLint)width;
    windH = (GLint)height;

	aspect = (float)windW / (float)windH;
	aspect *= 15.0; /* widen the lense */

	/* Viewport fills the entire window */

    glViewport(0, 0, width, height);

	/* Use orthographic projection to set visibility boundaries relative to viewing coordinates */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-aspect-3, aspect, -8.0, 8.0, 0.0, 1000.0); /* left, right, bottom, top, near, far */

	/* Return to modelview mode */
    glMatrixMode(GL_MODELVIEW);
}

/* Set modeling and viewing transformations,
   then draw the letter polygons */

static void Draw(void)
{
	// int face, pt;

	/* clear the screen AND the depth buffer */

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* Set the viewing transformation(s) */

	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, 0.0, 1.0, 0.0);

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

    if (glutCreateWindow("Logo") == GL_FALSE) {
		exit(1);
    }

    Init();

    drawW();/*Create display list letterW */
    drawK();/*Create display list letterK */
    drawI(); /* Create display list letterI */

    glutReshapeFunc(Reshape);
    glutDisplayFunc(Draw);
    glutMainLoop();

    return 0;
}
