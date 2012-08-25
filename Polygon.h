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
#ifndef POLYGON_H_
#define POLYGON_H_

#include "point.h"
#include "drawModes.h"

class Polygon
{
	public:
		Polygon();
		virtual ~Polygon();
		int addPoint(Point p);		// Add a point to the polygon
		void draw(int mode);					// Draw the polygon into the OpenGL system
		void setColor(Point *c);	// Use the point structure to hold RGB color
	private:
		Point points[4];
		int index;							// Index to next point (used with addPoint)
		Point color;						// Use x y z as r g b for color
};

#endif
