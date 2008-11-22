// Arguments to SetColor
enum {
    COLOR_BLACK = 0,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE
};

// RGB values of colors for SetColor
static float RGBMap[9][3] = {
    {0, 0, 0},
    {1, 0, 0},
    {0, 1, 0},
    {1, 1, 0},
    {0, 0, 1},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
    {0.5, 0.5, 0.5}
};

#define CI_ANTI_ALIAS_GREEN 16
#define CI_ANTI_ALIAS_YELLOW 32
#define CI_ANTI_ALIAS_RED 48

// Set the current color
static void SetColor(int c)
{
    if (glutGet(GLUT_WINDOW_RGBA))
        glColor3fv(RGBMap[c]);
    else
        glIndexf(c);
}

// Set the color index map (indexed color only)
static void InitMap(int rgb)
{
    int i;

    if (rgb)
	return;

    for (i = 0; i < 9; i++)
	    glutSetColor(i, RGBMap[i][0], RGBMap[i][1], RGBMap[i][2]);

    for (i = 0; i < 16; i++) {
	    glutSetColor(i+CI_ANTI_ALIAS_RED, i/15.0, 0.0, 0.0);
	    glutSetColor(i+CI_ANTI_ALIAS_YELLOW, i/15.0, i/15.0, 0.0);
	    glutSetColor(i+CI_ANTI_ALIAS_GREEN, 0.0, i/15.0, 0.0);
    }
}
