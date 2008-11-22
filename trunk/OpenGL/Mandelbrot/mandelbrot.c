/* 
 * mandelbrot.c
 *
 * Mandelbrot set viewer
 */


#include <Windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <malloc.h>

/* Global variables: view of the set */

double Rleft, Ibottom;		/* lower-left corner of the view */
double Rwidth, Iheight;		/* portion of the set being viewed */

GLint windW, windH;	/* size of the window on the screen */
int MaxCount;			/* maximum pixel value in current picture */

GLubyte *Picture;			/* Array of pixels */
int PictureSize;

/* Initialization */

void Init(void) {
	/* Generate a window */
	windW = 1100;
	windH = 900;
	glutInitWindowPosition(0,0);


	glutInitWindowSize(windW, windH);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    if (glutCreateWindow("Mandelbrot") == GL_FALSE) {
		exit(1);
    }

	/* Allocate memory for the picture */
	PictureSize = windW * windH;
	Picture = (GLubyte *)malloc(3 * PictureSize); // for RGB array
	MaxCount = 0;

	printf("Initialized OK\n");
}

/* Set colors specified in HSV */


void SetColorHSV (GLfloat H, GLfloat S, GLfloat V, GLubyte *R, GLubyte *G, GLubyte *B)
{
	int i;
	GLfloat f, p, q, t;

	/* no saturation = grey */
	if (S == 0) { 
		glColor3d (V, V, V);
	}

	/* color has chromacity (hue) */
	else {
		if (H >= 360) H -= 360.0;

		H /= 60.0;
		i = (int)H;
		f = H - i;

		p = V * (1 - S);
		q = V * (1 - (S * f));

		t = V * (1 - (S * (1 - f)));

		switch (i) {
		case 0:
			*R = (GLubyte)(V*255);
			*G = (GLubyte)(t*255);
			*B = (GLubyte)(p*255);
			break;
		case 1:
			*R = (GLubyte)(q*255);
			*G = (GLubyte)(V*255);
			*B = (GLubyte)(p*255);
			break;
		case 2:
			*R = (GLubyte)(p*255);
			*G = (GLubyte)(V*255);
			*B = (GLubyte)(t*255);
			break;

		case 3:
			*R = (GLubyte)(p*255);
			*G = (GLubyte)(q*255);
			*B = (GLubyte)(V*255);
			break;
		case 4:
			*R = (GLubyte)(t*255);
			*G = (GLubyte)(p*255);
			*B = (GLubyte)(V*255);
			break;
		case 5:
			*R = (GLubyte)(V*255);
			*G = (GLubyte)(p*255);
			*B = (GLubyte)(q*255);
			break;
		}
	}
}


/* Return a color value for the given complex number CR + CIi */

GLubyte MandelbrotColor(double CR, double CI, int limit) {
	/* Return a value 0..limit */
	int count = 0;
	double az = 0.0;
	double bz = 0.0;
	double size = 0;	/* actually size squared */
	double anew, bnew;

	while ((count <= limit) && (size<4)) {
		anew = (az * az) - (bz * bz) + CR;
		bnew = 2 * az * bz + CI;
		az = anew;
		bz = bnew;
		size = (az * az) + (bz * bz);
		count++;

	}

	if (count > limit)
		count = 0;
	else if (count > MaxCount)
		MaxCount = count;

	return (GLubyte)count;
}

/* Given a lower-left corner (Rleft, Ibottom) 
   and the size of the visible region of the complex plane (Rwidth, Iheight),
   generate a picture of the Mandelbrot set */

void GeneratePicture(void) {
	int limit;				/* total number of colors to use in drawing Mandelbrot Set */
	double xSpace, ySpace;		/*space between samples in digital image */
        GLubyte* p=Picture;
        GLubyte color;
        double  x,y;
        int i,j;
 
	// Determine the increment between samples in the complex number plane
	xSpace = Rwidth / (double)windW;
	ySpace = Iheight / (double)windH;
	limit =800;

       
	 for(y=Ibottom,i=0;i<windH;i++,y+=ySpace)
       for(x=Rleft,j=0;j<windW;j++,x+=xSpace){
	  color=MandelbrotColor(x,y,limit);

     if(color==0){
       SetColorHSV(color,1.0,1.0,p,p,p);p+=3;
     }
     else{ SetColorHSV(color,1.0,1.0,p,p+1,p+2);p+=3;
     }

       }
}

/* Draw the picture on the screen */

void Draw(void) {

	 gluOrtho2D(0, windW+50, 0, windH);
	glRasterPos2i(0, 0);
	glDrawPixels(windW, windH, GL_RGB, GL_UNSIGNED_BYTE, Picture);
}

/* Resize the picture */

void Resize(GLint w, GLint h) {
	windW = w;
	windH = h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windW, 0, windH);
    glMatrixMode(GL_MODELVIEW);

}

/* Main program */

int main(int argc, char **argv)
{
	/* Initialize the window for drawing in, and the array for holding the Picture */
    glutInit(&argc, argv);
    glClearColor(0.0,0.0,0.0,0.0);

	Init();

	/* Generate a "picture" of the Mandelbrot set, using initial values for the corner and range */
	Rleft = -2.0;
	Ibottom = -1.25;
	Rwidth = 3.0;
   Iheight = 2.50;
	GeneratePicture();

	/* Set callback functions for the program */
    glutDisplayFunc(Draw);
    
    glutMainLoop();
  
    return 0;    

}
