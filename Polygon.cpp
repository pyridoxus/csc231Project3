/*
 * Polygon.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: pyridoxus
 */

#include "Polygon.h"
#include <iostream>	// Only for debugging
using namespace std;

Polygon::Polygon()
{
	this->index = 0;
	this->color.x = 1.0;
	this->color.y = 1.0;
	this->color.z = 1.0;
	return;
}

Polygon::~Polygon()
{
	//	cout <<"Polygon Destructor called." << endl; // Debug
	return;
}

int Polygon::addPoint(Point p)		// Add a point to the polygon
{
	if(this->index < 4) this->points[this->index++] = p;
	else return -1;	// Polygon is completely defined already
	return 0;
}

void Polygon::draw(void)					// Draw the polygon into the OpenGL system
{
  glBegin( GL_POLYGON );
  for(int i = 0; i < 4; i++)
  {
  	glVertex3f( this->points[i].x,
  			this->points[i].y,
  			this->points[i].z);
  }
  glEnd();
	return;
}

void Polygon::setColor(Point *c)	// Use the point structure to hold RGB color
{
	return;
}
