//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
void buildModel(void);
void plotPoints( int, int, int, int );
void keyboard( unsigned char, int, int );
void menu( int );
void consoleMenu(void);
#endif
