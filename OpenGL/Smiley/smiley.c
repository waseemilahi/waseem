/*
 * Smiley.c
 *
 * A first attempt at OpenGL programming
 *
 */


#include <windows.h> 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables representing state of the graphics window
int rgb, doubleBuffer; 
GLenum windType;
GLint windW, windH;

// Values & functions for setting colors
#include "tkmap.c"

// Used to draw circles
GLUquadricObj *face;

// Initialize variables that do not change
static void Init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // black background

/* Create quadric object for Smiley's face */

    face=gluNewQuadric();
    gluQuadricDrawStyle(face, GLU_FILL);
    gluQuadricNormals(face, GLU_FLAT);
}

//This is called when the window appears or changes shape
static void Reshape(int width, int height)
{
    windW = (GLint)width;
    windH = (GLint)height;

	// Draw in all of the screen window
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1); // Range of coordinates in the viewport
    glMatrixMode(GL_MODELVIEW);
}

// Draw the smiley face: called whenever the screen window changes
static void Draw(void)
{
    float one_eighth, one_sixteenth, one_third;

    one_eighth = 2.0/8.0;		// one eighth of the visible area
    one_sixteenth = 2.0/16.0;	// one sixteenth of the visible area
	one_third = 2.0/3.0;		// one third of the visible area

/* Clear the screen */
    glClear(GL_COLOR_BUFFER_BIT);

/* Draw a yellow face */
    SetColor(COLOR_BLUE);
    gluDisk(face, 0.0, one_third, 380, 1);

/* Draw black eyes */
    SetColor(COLOR_RED);
    glBegin(GL_POLYGON);        /* right eye */
	glVertex2f(one_eighth, one_eighth);
	glVertex2f(one_eighth,one_sixteenth/4);
	glVertex2f(one_sixteenth, one_sixteenth/4);
	glVertex2f(one_sixteenth, one_eighth);
    glEnd();
    glBegin(GL_POLYGON);        /* left eye */
	glVertex2f(-one_eighth, one_eighth);
	glVertex2f(-one_eighth,one_sixteenth/4);
	glVertex2f(-one_sixteenth, one_sixteenth/4);
	glVertex2f(-one_sixteenth, one_eighth);
    glEnd();

/* Draw the mouth */
    SetColor(COLOR_GREEN);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
	glVertex2f(-one_eighth-.05, -one_eighth+.02);
	glVertex2f(-one_eighth+.02,-one_eighth*1.05);
    glEnd();

    glBegin(GL_LINE_STRIP);
	glVertex2f(-one_eighth+.02, -one_eighth*1.05);
	glVertex2f(-one_eighth+.2,-one_eighth*1.2);
    glEnd();

      glBegin(GL_LINE_STRIP);
	glVertex2f(-one_eighth+.2, -one_eighth*1.2);
	glVertex2f(one_eighth-.2,-one_eighth*1.2);
    glEnd();

      glBegin(GL_LINE_STRIP);
	glVertex2f(one_eighth-.2, -one_eighth*1.2);
	glVertex2f(one_eighth-.02,-one_eighth*1.05);
    glEnd();

    glBegin(GL_LINE_STRIP);
	glVertex2f(one_eighth-.02, -one_eighth*1.05);
	glVertex2f(one_eighth+.05,-one_eighth+.02);
    glEnd();

    glFlush();

    if (doubleBuffer) {
	  glutSwapBuffers();
    }
}

static GLenum Args(int argc, char **argv)  // command line arguments
{
    GLint i;

    rgb = GL_TRUE;
    doubleBuffer = GL_FALSE;

    for (i = 1; i < argc; i++) {
	if (strcmp(argv[i], "-ci") == 0) {
	    rgb = GL_FALSE;
	} else if (strcmp(argv[i], "-rgb") == 0) {
	    rgb = GL_TRUE;
	} else if (strcmp(argv[i], "-sb") == 0) {
	    doubleBuffer = GL_FALSE;
	} else if (strcmp(argv[i], "-db") == 0) {
	    doubleBuffer = GL_TRUE;
	} else {
	    printf("%s (Bad option).\n", argv[i]);
	    return GL_FALSE;
	}
    }
    return GL_TRUE;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    if (Args(argc, argv) == GL_FALSE) {
		exit(1);
    }

    windW = 300;
    windH = 300;
    glutInitWindowPosition(0, 0);
	glutInitWindowSize( windW, windH);

    windType = (rgb) ? GLUT_RGB : GLUT_INDEX;
    windType |= (doubleBuffer) ? GLUT_DOUBLE : GLUT_SINGLE;
    glutInitDisplayMode(windType);

    if (glutCreateWindow("Smiley Face") == GL_FALSE) {
		exit(1);
    }

    InitMap(rgb);

    Init();

    glutReshapeFunc(Reshape);
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}





