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
