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

void Polygon::draw(int mode)			// Draw the polygon into the OpenGL system
{
  glColor3f(this->color.x, this->color.y, this->color.z);
	switch(mode)
	{
		case POINTS:
			glBegin( GL_POINTS );
		break;
		case WIREFRAME:
			glBegin( GL_POLYGON );
		break;
		case HIDDENSURFACEWIRE:
			glBegin( GL_POLYGON );
		break;
		case RANDOMCOLORPOLY:
			glBegin( GL_POLYGON );
		break;
	}
  for(int i = 0; i < 4; i++)
  	glVertex3f( this->points[i].x, this->points[i].y, this->points[i].z);
  glEnd();
	return;
}

void Polygon::setColor(Point *c)	// Use the point structure to hold RGB color
{
	this->color = *c;
	return;
}
