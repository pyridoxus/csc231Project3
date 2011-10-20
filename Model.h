#ifndef MODEL_H_
#define MODEL_H_

#include "Polygon.h"

class Model
{
	public:
		Model();
		virtual ~Model();
		void draw(void);						// Draw the mesh into the OpenGL system
		int addPolygon(Polygon *p);	// Add the polygon to the mesh
		void drawType(int d);				// Set the drawing type (wireframe, solid, etc)
	private:
		Polygon *mesh;		// Pointer to all polygons in the mesh
		int index;				// Index to next polygon (used in addPolygon)
		int dType;				// Drawing type (wireframe, solid, etc)
};

#endif
