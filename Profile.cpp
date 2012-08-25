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
	return;
}

void Profile::draw(void)
// Draw the profile
{
	Point p;	// Temporary storage
  glColor3f(1.0, 1.0, 1.0 );
  glBegin( GL_LINE_STRIP );
  for(unsigned int i = 0; i < this->points.size(); i++)
  {
  	p = this->points[i];
		glVertex2f( p.x, p.y );
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

