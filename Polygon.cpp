/*
 * Polygon.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: pyridoxus
 */

#include "Polygon.h"

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
	return 0;
}

void Polygon::draw(void)					// Draw the polygon into the OpenGL system
{
	return;
}

void Polygon::setColor(Point *c)	// Use the point structure to hold RGB color
{
	return;
}
