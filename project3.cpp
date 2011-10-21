/**********************************************************************
Surface of Revolution
************************************************************************/
#include "project3.h"

Profile profile;
Model model;

int main( int argc, char *argv[] )	// Return int in Linux
{
	// Show console menu
	consoleMenu();

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
  return 0;
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

void consoleMenu(void)
{
	cout << GL_POINT << endl;
}

