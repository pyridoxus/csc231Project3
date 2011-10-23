#ifndef POLYGON_H_
#define POLYGON_H_

#include "point.h"

class Polygon
{
	public:
		Polygon();
		virtual ~Polygon();
		int addPoint(Point p);		// Add a point to the polygon
		void draw(void);					// Draw the polygon into the OpenGL system
		void setColor(Point *c);	// Use the point structure to hold RGB color
	private:
		Point points[4];
		int index;							// Index to next point (used with addPoint)
		Point color;						// Use x y z as r g b for color
};

#endif
