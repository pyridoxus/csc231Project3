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
	for(int i = 0; i < 4; i++) this->points[i] = 0;
	return;
}

Polygon::~Polygon()
{
	return;
}

int Polygon::addPoint(Point *p)		// Add a point to the polygon
{
	if(this->index < 4)
	{
		this->points[this->index++] = p;
		cout << "Polygon adding point " << this->index << " as " << p << endl;
	}
	else return -1;	// Polygon is completely defined already
	return 0;
}

void Polygon::draw(void)					// Draw the polygon into the OpenGL system
{
  glBegin( GL_POLYGON );
  for(int i = 0; i < 4; i++)
  {
		cout << "Drawing: Point " << i << " at " << this->points[i] << endl;
  }
  for(int i = 0; i < 4; i++)
  {
  	glVertex3f( this->points[i]->x,
  			this->points[i]->y,
  			this->points[i]->z);
//		cout << "Drawing: Point " << i << " (" << this->points[i]->x << ", ";
//		cout << this->points[i]->y << ", ";
//		cout <<	this->points[i]->z << ")" << endl;
  }
  glEnd();
	return;
}

void Polygon::setColor(Point *c)	// Use the point structure to hold RGB color
{
	return;
}
