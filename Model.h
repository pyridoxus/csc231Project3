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
#ifndef MODEL_H_
#define MODEL_H_

#include "Polygon.h"
#include "Profile.h"
#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

class Model
{
	public:
		Model(void);	// Create model using array of points
		virtual ~Model();
		void draw(void);						// Draw the mesh into the OpenGL system
		void drawType(int d);				// Set the drawing type (wireframe, solid, etc)
		void clear(void);						// Delete the contents of the model
		void createModel(Profile *profile);	// Create model
		void incResolution(void);		// Increase resolution by 1.
		void decResolution(void);		// Decrease resolution by 1.
	private:
		void createPoints(Profile *profile);	// Create all 3D points
		void createPolygons(int numProfile);	// Create all polygons in mesh
		void printPoint(Point *);							// Print point for debug
		vector<Point> points;		// All points in the mesh
		vector<Polygon> mesh;		// Pointers to all polygons in the mesh
		int dType;				// Drawing type (wireframe, solid, etc)
		int resolution;		// Number of points around the y axis
};

#endif
