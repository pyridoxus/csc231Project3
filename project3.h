#ifndef PROJECT3_H_
#define PROJECT3_H_

#include <iostream>
using namespace std;

#include "Model.h"
#include "drawModes.h"

// window constants
#define GAP				10.0
#define WIDTH			520.0
#define HEIGHT		390.0
#define CAMERA		3.0			// Camera z position = CAMERA * WIDTH

// GLUT window ids
int main_w, ortho, persp;

// Callback functions
void drawMain();
void drawOrtho();
void drawPersp();
void drawModel(void);
void plotPoints( int, int, int, int );
void keyboard( unsigned char, int, int );
void menu( int );
void consoleMenu(void);
#endif
