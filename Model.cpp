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
	this->points = 0;
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
	int r = 0;	// Index to point in mesh
	double a;	// Angle around the y axis (radians)
	Point *p;	// Temporary storage
	this->points = (Point *)malloc(profile->getSize() * this->resolution * \
																 sizeof(Point));
	for(i = 0; i < profile->getSize(); i++)
	{
		p = profile->getPoint(i);
		cout << "Using point: (" << p->x << ", " << p->y << ")" << endl;
		for(a = 0; a < 2 * PI; a += 2 * PI / this->resolution)
		{
			this->points[r].x = p->x * cos(a);
			this->points[r].y = p->y;
			this->points[r].z = p->x * sin(a);
			cout << "(" << this->points[r].x << ", " << \
										 this->points[r].y << ", " << \
										 this->points[r].z << ")" << endl;
			r++;
		}
	}
	cout << "Created points." << endl;
	return;
}

void Model::createPolygons(int numProfile)
// Create all polygons in mesh
{
	int i, j;
	int p = 0;	// Index of polygon in mesh
	int h, v;		// Index offsets
	if(!this->mesh) this->mesh = (Polygon *)malloc((numProfile - 1) * \
														(this->resolution - 1) * sizeof(Polygon));
	else exit(1);
	for(j = 0; j < numProfile - 1; j++)
	{
		for(i = 0; i < this->resolution; i++)
		{
			h = i + 1;
			v = (j + 1) * this->resolution;
			this->mesh[p].addPoint(this->points + i);
			if(i == this->resolution - 1)
				this->mesh[p].addPoint(this->points + i + 1);
			else
				this->mesh[p].addPoint(this->points + (j * this->resolution));
			this->mesh[p].addPoint(this->points + v);
			if(i == this->resolution - 1)
				this->mesh[p].addPoint(this->points + h + v);
			else
				this->mesh[p].addPoint(this->points + h + v);
		}
	}
	return;
}

void Model::clear(void)
// Delete the contents of the model
{
	if(this->mesh) free(this->mesh);
	this->mesh = 0;
	if(this->points) free(this->points);
	this->points = 0;
	cout << "Cleared model." << endl;
	return;
}

void Model::createModel(Profile *profile)
// Create the model from the profile points. Resolution is number of points
// around the y axis. Use clear() before using this function.
{
	if((resolution < 3) || (profile == 0) || (mesh != 0)) return;
	this->createPoints(profile);
	this->createPolygons(profile->getSize());
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

