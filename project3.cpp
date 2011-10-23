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
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluOrtho2D( 0.0, WIDTH, 0.0, HEIGHT );

	// Orthographic draw
	glutDisplayFunc( drawOrtho );

	// Orthographic mouse callback
  glutMouseFunc( plotPoints );

  // Perspective surface view
  persp = glutCreateSubWindow( main_w, GAP+WIDTH+GAP, GAP, WIDTH, HEIGHT );

	// Construct three-dimensional perspective projection here
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  gluPerspective( 0.0, WIDTH, 0.0, HEIGHT );

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
  cout << "Start profile draw" << endl;
	profile.draw();

	glutSwapBuffers();
}

// Orthographic mouse callback
void plotPoints( int button, int state, int x, int y )
{
	if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		profile.addPoint(x, HEIGHT - y);
		drawOrtho();									// Draw the profile
	}
	if((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
	{
		model.clear();								// Clear current model
		model.createModel(&profile);	// Create new one from profile
		drawPersp();									// Draw new model
	}
	return;
}

// Perspective surface draw
void drawPersp()
{
  glClearColor( 0, 0, 0, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  cout << "Start model draw" << endl;
	model.draw();

	glutSwapBuffers();
}

// Perspective menu callback
void menu( int value )
{

}

// Perspective keyboard callback
void keyboard( unsigned char key, int x, int y )
{
	switch(key)
	{
		case 'q':
			exit(0);
		break;
		case '+':
			model.incResolution();
		break;
		case '-':
			model.decResolution();
		break;
	}
}

void consoleMenu(void)
{
	cout << "+ - Increase resolution" << endl;
	cout << "- - Decrease resolution" << endl;
	cout << "q - exit" << endl;
	return;
}

