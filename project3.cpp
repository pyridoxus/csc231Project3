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
  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
  glTranslatef( 0, 0, -(CAMERA + 1) * WIDTH);
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
//  gluOrtho2D( 0.0, WIDTH, 0.0, HEIGHT );
  gluPerspective(11.0, WIDTH / HEIGHT, 1.0, (CAMERA + 2) * WIDTH);

	// Perspective draw
  glEnable( GL_DEPTH_TEST );
	glutDisplayFunc( drawPersp );

	// Perspective keyboard and menu callbacks
	glutKeyboardFunc( keyboard );
  glutCreateMenu( menu );
	glutAddMenuEntry( "Increase resolution ('+' key)", 1 );
	glutAddMenuEntry( "Decrease resolution ('-' key)", 2 );
	glutAddMenuEntry( "Draw as points ('p' key)", 3 );
	glutAddMenuEntry( "Draw as wireframe ('w' key)", 4 );
	glutAddMenuEntry( "Draw as hidden surface wireframe ('h' key)", 5 );
	glutAddMenuEntry( "Draw as random color polygon ('m' key)", 6 );
	glutAddMenuEntry( "Exit ('q' key)", 7 );
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
  glutSetWindow( ortho );
  glutPostRedisplay();
  glClearColor(0,0,0,1);
  glClear( GL_COLOR_BUFFER_BIT );
	glPushMatrix();		// Save view matrix
	glScalef( 1.0, -1.0, 1.0 );
	glTranslatef( WIDTH / 2.0, -HEIGHT, 0.0 );

	profile.draw();

	glPopMatrix();		// Restore view matrix
	glutSwapBuffers();
}

// Orthographic mouse callback
void plotPoints( int button, int state, int x, int y )
{
	if((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		profile.addPoint(x - WIDTH / 2.0, y);
		drawOrtho();									// Draw the profile
	}
	if((button == GLUT_LEFT_BUTTON) && (state == GLUT_UP))
	{
		buildModel();
	}
	return;
}

// Perspective surface draw
void drawPersp()
{
  glutSetWindow( persp );
  glutPostRedisplay();
  glClearColor( 0, 0, 0, 1.0 );
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glPushMatrix();		// Save view matrix
	glScalef( 1.0, -1.0, 1.0 );
	glTranslatef( 0, -HEIGHT / 2.0, 0.0 );
	model.draw();

	glPopMatrix();		// Restore view matrix
	glutSwapBuffers();
}

// Perspective menu callback
void menu( int value )
{
	switch(value)
	{
		case 1:
			model.incResolution();
		break;
		case 2:
			model.decResolution();
		break;
		case 3:
			model.drawType(POINTS);
		break;
		case 4:
			model.drawType(WIREFRAME);
		break;
		case 5:
			model.drawType(HIDDENSURFACEWIRE);
		break;
		case 6:
			model.drawType(RANDOMCOLORPOLY);
		break;
		case 7:
			exit(0);
		break;
	}
	buildModel();
	return;
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
		case 'p':
			model.drawType(POINTS);
		break;
		case 'w':
			model.drawType(WIREFRAME);
		break;
		case 'h':
			model.drawType(HIDDENSURFACEWIRE);
		break;
		case 'm':
			model.drawType(RANDOMCOLORPOLY);
		break;
	}
	buildModel();
}

void consoleMenu(void)
{
	cout << "+ - Increase resolution" << endl;
	cout << "- - Decrease resolution" << endl;
	cout << "p - Draw as points" << endl;
	cout << "w - Draw as wireframe" << endl;
	cout << "h - Draw as hidden surface wireframe" << endl;
	cout << "m - Draw as random color polygon" << endl;
	cout << "q - exit" << endl;
	return;
}

void buildModel(void)
{
	model.clear();								// Clear current model
	model.createModel(&profile);	// Create new one from profile
//	drawPersp();									// Draw new model
	return;
}
