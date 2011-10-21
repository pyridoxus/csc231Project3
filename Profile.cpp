/*
 * Profile.cpp
 *
 *  Created on: Oct 21, 2011
 *      Author: pyridoxus
 */

#include "Profile.h"

Profile::Profile()
{
}

Profile::~Profile()
{
}

void Profile::addPoint(int x, int y)
// Add point to the profile
{
	Point p;
	p.x = x;
	p.y = y;
	p.z = 0.0;
	this->points.push_back(p);
	cout << "Added point at " << x << y << endl;
	return;
}

void Profile::draw(void)
// Draw the profile
{
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

