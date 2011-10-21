#ifndef PROJECT3_H_
#define PROJECT3_H_

#include <iostream>
using namespace std;

#include <math.h>
#include "Model.h"

// window constants
#define GAP				10
#define WIDTH			520
#define HEIGHT		390

// GLUT window ids
int main_w, ortho, persp;

// Callback functions
void drawMain();
void drawOrtho();
void drawPersp();
void plotPoints( int, int, int, int );
void keyboard( unsigned char, int, int );
void menu( int );
void consoleMenu(void);
#endif
