/*
 * Profile.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: pyridoxus
 */

#include "Profile.h"

Profile::Profile(void)
{
	return;
}

Profile::~Profile()
{
	return;
}

void Profile::addPoint(int x, int y)
// Add point to the profile
{
	Point p;
	p.x = x;
	p.y = y;
	p.z = 0.0;
	this->points.push_back(p);
//	cout << "Added point at " << x << y << endl;
	return;
}

void Profile::draw(void)
// Draw the profile
{
	Point p;	// Temporary storage
  glColor3f(1.0, 1.0, 1.0 );
//  cout << "Profile Draw..." << endl;
  glBegin( GL_LINE_STRIP );
//  cout << "Profile begin line" << endl;
//  cout << "Profile size: " << this->points.size() << endl;
  for(unsigned int i = 0; i < this->points.size(); i++)
  {
  	p = this->points[i];
		glVertex2f( p.x, p.y );
//		cout << "Profile Draw: (" << p.x << ", " << p.y << ")" << endl;
  }
  glEnd();
  glFlush();
	return;
}

int Profile::getSize(void)
// Return the size of the point array
{
	return this->points.size();
}

Point *Profile::getPoint(int p)
// Return the point at p in array
{
	return &this->points.at(p);
}

