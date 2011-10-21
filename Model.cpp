/*
 * Model.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: pyridoxus
 */

#include "Model.h"
#include "Profile.h"

Model::Model(void)
// Create model
{
	this->dType = GL_POINTS;
	this->mesh = 0;
	return;
}

Model::~Model()
{
	return;
}

int Model::createPoints(Point *points, int resolution)
// Create all 3D points and return the number of points in the profile array
{
	return 0;
}

void Model::createPolygons(void)
// Create all polygons in mesh
{
	return;
}

void Model::clear(void)
// Delete the contents of the model
{
	if(mesh) free(mesh);
	mesh = 0;
	return;
}

void Model::createModel(Profile *profile, int resolution)
// Create the model from the profile points. Resolution is number of points
// around the y axis. Use clear() before using this function.
{
	int i;
	Point *p;
	if((resolution < 3) || (profile == 0) || (mesh != 0)) return;
	for(i = 0; i < profile->getSize(); i++)
	{
		p = profile->getPoint(i);
	}
	return;
}
