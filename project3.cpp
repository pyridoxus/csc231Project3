/**********************************************************************
Surface of Revolution
************************************************************************/

#include <iostream>
using namespace std;

#include <math.h>
#include <GL/glut.h>

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

void main( int argc, char *argv[] )
{
  // Initialize window system
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( (WIDTH*2)+(GAP*3), HEIGHT+(GAP*2) );
  main_w = glutCreateWindow( "Project 3" );
  glutDisplayFunc( drawMain );

  // Orthographic profile view
  ortho = glutCreateSubWindow( main_w, GAP, GAP, WIDTH, HEIGHT );

	// Construct two-dimensional orthographic projection here

	// Orthographic draw
	glutDisplayFunc( drawOrtho );

	// Orthographic mouse callback
  glutMouseFunc( plotPoints );

  // Perspective surface view
  persp = glutCreateSubWindow( main_w, GAP+WIDTH+GAP, GAP, WIDTH, HEIGHT );

	// Construct three-dimensional perspective projection here

	// Perspective draw
  glEnable( GL_DEPTH_TEST );
	glutDisplayFunc( drawPersp );

	// Perspective keyboard and menu callbacks
	glutKeyboardFunc( keyboard );
  glutCreateMenu( menu );
  glutAttachMenu( GLUT_RIGHT_BUTTON );

  // Main loop
  glutMainLoop();
}

// Main background display
void drawMain()
{
  glClearColor(.5,.5,.5,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glutSwapBuffers();
}

// Orthographic profile draw
void drawOrtho()
{
  glClearColor(0,0,0,1);
  glClear( GL_COLOR_BUFFER_BIT );

	// Draw here

	glutSwapBuffers();
}

// Orthographic mouse callback
void plotPoints( int button, int state, int x, int y )
{

}

// Perspective surface draw
void drawPersp()
{
  glClearColor( 0, 0, 0, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	// Draw here

	glutSwapBuffers();
}

// Perspective menu callback
void menu( int value )
{

}

// Perspective keyboard callback
void keyboard( unsigned char key, int x, int y )
{

}

