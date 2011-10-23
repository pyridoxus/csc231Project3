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
	this->numPolygons = 0;
	return;
}

Model::~Model()
{
	this->clear();
	return;
}

void Model::createPoints(Profile *profile)
// Create all 3D points
{
	int i;	// Index to point in profile
	int r = 0;	// Index to point in mesh
	double a;	// Angle around the y axis (radians)
	Point *p;	// Temporary storage
	if(!this->points)
		this->points = (Point *)malloc(profile->getSize() * this->resolution * \
																 sizeof(Point));
	else
	{
		cout << "Cannot create points" << endl;
		exit(1);
	}
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
	int i = 0;	// Index to point in 3D points
	int p;			// Index of polygon in mesh
	this->numPolygons = 0;
	if(!this->mesh) this->mesh = (Polygon **)malloc(numProfile * \
														this->resolution * sizeof(Polygon *));
	else
	{
		cout << "Cannot create polygons" << endl;
		exit(2);	// Mesh should have been freed and reset first.
	}
	cout << "Creating polygons..." << endl;
	cout << "Resolution = " << this->resolution << endl;
	cout << "Points in profile = " << numProfile << endl;

	for(p = 0; p < this->resolution * (numProfile - 1); p++)
	{
		i = p;	// Start the points in polygon with the current polygon index.
		this->mesh[p] = new Polygon;
		cout << "Polygon " << p << ": (" << this->points + i << ": ";
		this->printPoint(this->points + i);
//		cout << "Polygon " << p << ": (" << i;
		this->mesh[p]->addPoint(this->points + i);

		i += this->resolution;	// Point to the point on next row of profile.
		this->mesh[p]->addPoint(this->points + i);
		cout << ", " << this->points + i << ": ";
		this->printPoint(this->points + i);
//		cout << ", " << i;
		// Now index the next point on next row. Check if the point is as the
		// beginning of the row.
		i ++; // Index to point
		if((i % this->resolution) == 0) i -= this->resolution;	// Wrap around
		this->mesh[p]->addPoint(this->points + i);
		cout << ", " << this->points + i << ": ";
		this->printPoint(this->points + i);
//		cout << ", " << i;

		// Now index the last point which is on current row.
		i -= this->resolution;
		this->mesh[p]->addPoint(this->points + i);
		cout << ", " << this->points + i << ": ";
		this->printPoint(this->points + i);
		cout << ")" << endl;
//		cout << ", " << i << ")" << endl;
		this->numPolygons++;
	}
	return;
}

void Model::clear(void)
// Delete the contents of the model
{
	if(this->mesh)
	{
		for(int i = 0; i < this->numPolygons; i++)
			delete this->mesh[i];
		free(this->mesh);
	}
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
	if((resolution < 3) || (profile == 0) || (mesh != 0))
	{
		cout << "Cannot create model" << endl;
		return;
	}
	this->createPoints(profile);
	this->createPolygons(profile->getSize());
	cout << "Created model." << endl;
	return;
}

void Model::draw(void)
// Draw the mesh into the OpenGL system
{
//	cout << "Drawing..." << endl;
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for(int i = 0; i < this->numPolygons; i++)
	{
//		cout << "Drawing polygon " << i << endl;
		this->mesh[i]->draw();
	}
  glFlush();
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

void Model::printPoint(Point *p)
{
	cout << "(" << p->x << ", ";
	cout << p->y << ", ";
	cout << p->z << ")";
	return;
}
