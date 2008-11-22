/*
 * wilahi_3DLOGO_fly_illuminate.cpp
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

#define FLAT_L 1
#define SMOOTH_L 2

/* 
 * unitSize
 *
 * given an original normal (array of 3 values),
 * converts it to a unit size normal
 */

void unitSize (GLdouble normal[3])
{
	GLdouble length, x, y, z;
	x = normal[0];
	y = normal[1];
	z = normal[2];
	length = sqrt(x*x + y*y + z*z);

   if(length==0)length=1;

	normal[0] = x / length;
	normal[1] = y / length;
	normal[2] = z / length;
}

/*
 * getNormals
 *
 * given an array of points (3D coordinates) and an array of polygons (4 point indices),
 * writes out a unit normal for each face (face_normals)
 * and a unit normal for each point (point_normals)
 */

void getNormals (GLdouble points[][3], int nPoints, int polygons[][4], int nPolygons, 
				 GLdouble (*face_normals)[3], GLdouble (*point_normals)[3])
{
	int i, j, n, pindex;
	GLdouble v1x, v1y, v1z, v2x, v2y, v2z;
	GLdouble *ptr;
	GLdouble (*normPtr)[3];
	int (*polyPtr)[4];

	/* Point_normals are "average" of adjacent face normals */
	/* Initialize space prior to accumulating values */

	n = nPoints * 3; // # of elements in point_normals
	for (i = n, ptr =(double*) point_normals; i > 0; i--, ptr++) {
		*ptr = 0.0;
	}

	/* Calculate normals of faces based on 3 points */
	/* polyPtr points to the current polygon, normPtr points to its normal */

	for (i = nPolygons, polyPtr = polygons, normPtr = face_normals; 
	     i > 0; i--, polyPtr++, normPtr++) {

		/* Get coordinates of 2 vectors on the polygon */
		v1x = points[(*polyPtr)[1]][0] - points[(*polyPtr)[0]][0];
		v1y = points[(*polyPtr)[1]][1] - points[(*polyPtr)[0]][1];
		v1z = points[(*polyPtr)[1]][2] - points[(*polyPtr)[0]][2];
		v2x = points[(*polyPtr)[2]][0] - points[(*polyPtr)[0]][0];
		v2y = points[(*polyPtr)[2]][1] - points[(*polyPtr)[0]][1];
		v2z = points[(*polyPtr)[2]][2] - points[(*polyPtr)[0]][2];

		/* Use cross product to calculate normal to the polygon */
		(*normPtr)[0] = (v1y * v2z) - (v1z * v2y);
		(*normPtr)[1] = (v1z * v2x) - (v1x * v2z);
		(*normPtr)[2] = (v1x * v2y) - (v1y * v2x);

		/* Convert to a unit normal */
		unitSize(*normPtr);

		/* Add to the accumulator for all points on the polygon */
		for (j = 0; j < 4; j++) {
			pindex = (*polyPtr)[j]; // index of point that uses this polygon
			point_normals[pindex][0] += (*normPtr)[0];
			point_normals[pindex][1] += (*normPtr)[1];
			point_normals[pindex][2] += (*normPtr)[2];
		}
	}

	/* Point normals already accumulated; just make the sum unit-size */

	for (i = nPoints, normPtr = point_normals; i > 0; i--, normPtr++) {
		unitSize(*normPtr);
	}
}

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

/*
   change global rotation or position value(s) by a small amount,
   then use the value(s) as parameters in the Draw function
*/

void fly (void)
{
     spin_angle+=spin_increment;

     glutPostRedisplay();	/* update of the display */
}

GLuint letter; // display list speeds up rendering

void createDisplayLists ()
{

	#define NPOINTS   62
	#define NPOLYGONS 54

	/* define all the points on the letter */

	GLdouble point[NPOINTS][3] = {
		{4.5, 0.0, 1.2},
		{5.5, 0.0, 1.2},
		{5.5, 6.0, 1.2},
		{4.5, 6.0, 1.2},
      {4.5, 0.0, 0.0},
		{5.5, 0.0, 0.0},
		{5.5, 6.0, 0.0},
		{4.5, 6.0, 0.0},
      //K
      {-1.0, 0.0, 1.2},
		{ 0.0, 0.0, 1.2},
		{ 0.0, 6.0, 1.2},
		{-1.0, 6.0, 1.2},
      {-1.0, 0.0, 0.0},
		{ 0.0, 0.0, 0.0},
		{ 0.0, 6.0, 0.0},
		{-1.0, 6.0, 0.0},
      { 0.5, 3.0, 1.2},
      {-0.35,3.5, 1.2},
      {2.0, 6.0, 1.2},
      {3.2, 6.0, 1.2},
      {3.2, 0.0, 1.2},
      {2.0, 0.0, 1.2},
      {-0.5,2.0, 1.2},
      {0.0, 3.0, 0.0},
      {-0.4,3.5, 0.0},
      {2.0, 5.9, 0.0},
      {3.0, 5.9, 0.0},
      {2.8, 0.0, 0.0},
      {2.0, 0.0, 0.0},
      {-0.5,2.5, 0.0},
       //W
      {-7.9, 6.0, 1.2},
		{-7.3, 0.0, 1.2},
		{-5.7, 0.0, 1.2},
		{-4.3, 0.0, 1.2},
      {-2.7, 0.0, 1.2},
		{-2.1, 6.0, 1.2},
		{-3.1, 6.0, 1.2},
		{-4.3, 6.0, 1.2},
      {-5.7, 6.0, 1.2},
	        {-6.9, 6.0, 1.2},
	        {-6.0,0.0, 1.2},
	        {-3.7,0.0, 1.2},
	        {-5.0,4.0, 1.2},
           {-5.0, 6.0, 1.2},
	        {-6.7, 0.0, 1.2},
	        {-3.0, 0.0, 1.2},
      {-7.9, 6.0, 0.0},
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

	int polygon[NPOLYGONS][4] = {
		{0, 1, 2, 3}, 

		{4, 7, 6, 5},

		{0, 3, 7, 4},

      {1, 5, 6, 2},

		{2, 6, 7, 3},

		{4, 5, 1, 0},
       //K
      {8, 9, 10, 11},

      {19, 18, 17, 16},

      {16, 22, 21, 20},

      {16, 17, 22, 22},

		{12, 15, 14, 13},

      {24,25,26,23},

      {23,27,28,29},

      {24, 23, 29,29},

		{8, 11, 15, 12},

      {9, 13, 14, 10},

		{29, 22, 10, 14},

      {14, 15, 11, 10},

		{12, 13, 9, 8},

      {26, 25, 18, 19},

      {20, 21, 28, 27},

      {18, 25, 24, 17},

      {19, 16, 23, 26},

      {27, 23, 16, 20},

      {21, 22, 29, 28},
       //W
		{39, 30, 31, 44},
		{39, 44, 40, 40},
		{43, 38, 42, 42},
		{38, 44, 32, 42},
		{37,43, 42, 33},
		{37, 33, 45, 41},
		{36,41, 45, 34},
		{35, 36, 34, 34},

		{46, 55, 56, 60}, 
		{46, 60, 47, 47},
		{60, 54, 59, 58},
		{60, 58, 48, 48},
		{59, 53, 61, 49},
		{59, 49, 58, 58},
		{61, 57, 52, 51},

	   {51, 50, 61, 61},

		{30, 46, 47, 31},

		{55, 39, 40, 56},

		{38, 54, 56, 40},

      {53, 37, 41, 57},

		{36, 52, 57, 41},

		{51, 35, 34, 50},

		{55, 46, 30, 39},

		{51, 52, 36, 35},

		{32, 31, 47, 48},

           {34, 33, 49, 50},

	        {58, 42, 32, 48},

	        {42, 58, 49, 33},

	        {53, 54, 38, 37}};

	int face, pt,pindex;

   GLdouble face_normals[NPOLYGONS][3];
   GLdouble point_normals[NPOINTS][3];

   getNormals(point, NPOINTS, polygon, NPOLYGONS, face_normals, point_normals);

   letter = glGenLists(1);

   /* Create a display list for flat shading */

   glNewList (FLAT_L, GL_COMPILE);

	for (face = 0; face < NPOLYGONS; face++) {
		glBegin(GL_POLYGON);
		glNormal3dv(face_normals[face]);
		for (pt = 0; pt < 4; pt++)  /* draw all points on the face */
			glVertex3dv (point[polygon[face][pt]]);
		glEnd();
	}
	glEndList();

   /* Create a display list for smooth shading */

	glNewList (SMOOTH_L, GL_COMPILE);
	for (face = 0; face < NPOLYGONS; face++) {
		glBegin(GL_POLYGON);
		for (pt = 0; pt < 4; pt++) { /* draw all points on the face */
			pindex = polygon[face][pt];
			glNormal3dv (point_normals[pindex]);
			glVertex3dv (point[pindex]);
		}
		glEnd();
	}
	glEndList();
}

/* Setup OpenGL state machine */

static void Init(void)
{

   float ambiantmat[]={0.23125};
   float diffusemat[]={0.2775};
   float specularmat[]={0.773911};
   float shininessmat=89.6;

   float ambiantlight[]={1};
   float diffuselight[]={1};
   float specularlight[]={1};
   float positionlight[4]={0.0,0.0,1.0,1.0};

	/* Set background color */

    glClearColor(0.0, 0.0, 0.0, 0.0);

  /* Enable depth buffer & lighting */

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

   glLightfv(GL_LIGHT0, GL_POSITION,positionlight );
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiantlight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuselight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularlight);

	glEnable(GL_LIGHT0);

   glMaterialfv(GL_FRONT, GL_AMBIENT, ambiantmat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffusemat);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularmat);
	glMaterialf(GL_FRONT, GL_SHININESS, shininessmat);


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
    	gluPerspective (70.0, aspect, 0.001, 200.0); /* fovy, aspect, near, far */

	/* Return to modelview mode */
    glMatrixMode(GL_MODELVIEW);
}

static void Key2(int key, int x, int y)
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
      case 's':
     case 'S':
            glShadeModel(GL_SMOOTH);
      break;                   //Press Z for flat shading.
      case 'z':
     case 'Z':
            glShadeModel(GL_FLAT);
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

        glCallList(letter);

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

    if (glutCreateWindow("Illuminated Flying Logo") == GL_FALSE) {
		exit(1);
    }

    Init();

    createDisplayLists();/*Create default display list letter */

   	/* Initially center camera on world system, & step back 8 */
	init_camera (28.0, 1.0, 55.0,  // camera position in world coordinates
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
