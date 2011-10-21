#ifndef MODEL_H_
#define MODEL_H_

#include "Polygon.h"
#include "Profile.h"
#include <stdlib.h>

class Model
{
	public:
		Model(void);	// Create model using array of points
		virtual ~Model();
		void draw(void);						// Draw the mesh into the OpenGL system
		void drawType(int d);				// Set the drawing type (wireframe, solid, etc)
		void clear(void);						// Delete the contents of the model
		void createModel(Profile *profile, int resolution);	// Create model
	private:
		int createPoints(Point *points, int resolution);	// Create all 3D points
		void createPolygons(void);	// Create all polygons in mesh
		Polygon *mesh;		// Pointer to all polygons in the mesh
		int dType;				// Drawing type (wireframe, solid, etc)
};

#endif
