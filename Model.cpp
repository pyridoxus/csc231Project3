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
	this->resolution = 3;
	return;
}

Model::~Model()
{
	return;
}

void Model::createPoints(Profile *profile)
// Create all 3D points
{
	int i;	// Index to point in profile
	double a;	// Angle around the y axis (radians)
	Point *p;	// Temporary storage
	for(i = 0; i < profile->getSize(); i++)
	{
		p = profile->getPoint(i);
		cout << "Using point: (" << p->x << ", " << p->y << ")" << endl;
		for(a = 0; a < 2 * PI; a += 2 * PI / this->resolution)
		{
			cout << a << endl;
		}
	}
	cout << "Created points." << endl;
	return;
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
	cout << "Cleared model." << endl;
	return;
}

void Model::createModel(Profile *profile)
// Create the model from the profile points. Resolution is number of points
// around the y axis. Use clear() before using this function.
{
	if((resolution < 3) || (profile == 0) || (mesh != 0)) return;
	this->createPoints(profile);
	cout << "Created model." << endl;
	return;
}

void Model::draw(void)
// Draw the mesh into the OpenGL system
{
	cout << "Drawing..." << endl;
	return;
}

void Model::drawType(int d)
// Set the drawing type (wireframe, solid, etc)
{
	this->dType = d;
	return;
}

void Model::incResolution(void)
// Increase resolution by 1.
{
	this->resolution++;
	return;
}

void Model::decResolution(void)
// Decrease resolution by 1.
{
	this->resolution--;
	return;
}

