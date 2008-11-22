/* 
 * image.c
 *
 * read in a PPM or PGM image and display it, full size
 */

#include <Windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <malloc.h>

/* Global variables */

#define MAXLINE 80	/* maximum length of a line of text */

GLint windW, windH;	/* size of the window on the screen */

GLubyte *Picture;	/* Array of pixels */

int filetype;
enum {PGM, PPM};	/* possible file types */

/* Read in picture from a PPM or PGM file */

void readPPM (char *filename, GLubyte **pic) {

	FILE *fp;
	char line[MAXLINE];
	int i, j, size, rowsize;
	GLubyte *ptr;

/* Read in file type */

  fp = fopen(filename, "rb");
  fgets (line, MAXLINE, fp); /* 1st line: PPM or PGM */
  if (line[1] == '5')
	  filetype = PGM;
  else if (line[1] == '6')
	  filetype = PPM;
  else {
	  printf("Error: need PPM or PGM file as input!\n");
	  exit(1);
  }

/* Read in width and height, & allocate space */

  fgets (line, MAXLINE, fp); /* 2nd line: width height */
  sscanf(line, "%d %d", &windW, &windH);
  printf ("Width is %d, height is %d\n", windW, windH);

  if (filetype == PGM) {
	  size = windH * windW;		/* greymap: 1 byte per pixel */
	  rowsize = windW;
  }
  else /* filetype == PPM */ {
	  size = windH * windW * 3;	/* pixmap: 3 bytes per pixel */
	  rowsize = windW * 3;
  }
  *pic = (GLubyte *)malloc (size);

/* Read in maximum value (ignore) */
  fgets (line, MAXLINE, fp); /* 3rd line */

/* Read in the pixel array row-by-row: 1st row = top scanline */
  ptr = *pic + (windH-1) * rowsize;
  for (i = windH; i > 0; i--) {
	  j = fread((void *)ptr, 1, rowsize, fp);
	  ptr -= rowsize;
  }
  fclose(fp);
}


/* Initialization: create window */

void Init(void) {
	glutInitWindowPosition(0, 0); 
	glutInitWindowSize(windW, windH);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    if (glutCreateWindow("Image") == GL_FALSE) {
		exit(1);
    }
}


/* Draw the picture on the screen */

void Draw(void) {
	glRasterPos2i(0, 0);

	if (filetype == PGM)	/* greymap: use as illumination values */
		glDrawPixels(windW, windH, GL_LUMINANCE, GL_UNSIGNED_BYTE, Picture);

	else // filetype == PPM
		glDrawPixels(windW, windH, GL_RGB, GL_UNSIGNED_BYTE, Picture);
}

/* Resize the picture */

void Resize(GLint w, GLint h) {
//	windW = w;
//	windH = h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windW, 0, windH);
    glMatrixMode(GL_MODELVIEW);
}

static void Key(unsigned char key, int x, int y)
{
    switch (key) {
	case 27:
		exit(1);
    default:
		return;
    }
}


/* Main program */

void main(int argc, char **argv)
{
	char filename[MAXLINE];

	/* Read in the file (allocates space for Picture) */

	if (argc < 2) {
		printf ("Enter the name of a PPM or PGM file: ");
		scanf("%s", filename);
		readPPM ((char *)filename, &Picture);
	}
	else {
		readPPM (argv[1], &Picture);
	}

    glutInit(&argc, argv);
	Init();

    glutReshapeFunc(Resize);
    glutDisplayFunc(Draw);
	glutKeyboardFunc(Key);
    glutMainLoop();
}

