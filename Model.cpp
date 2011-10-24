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
	this->points.clear();
	this->mesh.clear();
	this->resolution = 9;
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
	int j;	// Iterate through the resolution depth
	double a;	// Angle around the y axis (radians)
	Point *p;	// Temporary storage
	Point *q; // Temporary storage
	for(i = 0; i < profile->getSize(); i++)
	{
		p = profile->getPoint(i);
		q = new Point;
		a = 0;
		for(j = 0; j < this->resolution; j++)
		{
			q->x = p->x * cos(a);
			q->y = p->y;
			q->z = p->x * sin(a);
			a += 2.0 * PI / this->resolution;
			cout << "(" << q->x << ", " << q->y << ", " << q->z << ")" << endl;

			this->points.push_back(*q);	// Vector will handle deleting objects
		}
	}
	return;
}

void Model::createPolygons(int numProfile)
// Create all polygons in mesh
{
	int i = 0;	// Index to point in 3D points
	int p;			// Index of polygon in mesh
	Polygon *poly;	// Temporary storage
	Point c;

	for(p = 0; p < this->resolution * (numProfile - 1); p++)
	{
		i = p;	// Start the points in polygon with the current polygon index.
		poly = new Polygon;
		cout << "Polygon " << p << ": (" << i;
		poly->addPoint(this->points[i]);

		i += this->resolution;	// Point to the point on next row of profile.
		poly->addPoint(this->points[i]);
		cout << ", " << i;

		// Now index the next point on next row. Check if the point is as the
		// beginning of the row.
		i ++; // Index to point
		if((i % this->resolution) == 0) i -= this->resolution;	// Wrap around
		poly->addPoint(this->points[i]);
		cout << ", " << i;

		// Now index the last point which is on current row.
		i -= this->resolution;
		poly->addPoint(this->points[i]);
		cout << ", " << i << ")" << endl;

		if(this->dType == RANDOMCOLORPOLY)
		{
			c.x = (rand() % 256) / 256.0;
			c.y = (rand() % 256) / 256.0;
			c.z = (rand() % 256) / 256.0;
			poly->setColor(&c);
		}
		else
		{
			c.x = 1.0;
			c.y = 1.0;
			c.z = 1.0;
			poly->setColor(&c);
		}
		cout << "Random color: (" << c.x << ", " << c.y << ", " << c.z << ")" << endl;
		this->mesh.push_back(*poly);	// Vector will handle deleting objects
	}
	return;
}

void Model::clear(void)
// Delete the contents of the model
{
	cout << "Clearing model...." << endl;
	this->mesh.clear();
	this->points.clear();
	cout << "Cleared model." << endl;
	return;
}

void Model::createModel(Profile *profile)
// Create the model from the profile points. Resolution is number of points
// around the y axis. Use clear() before using this function.
{
	if((resolution < 3) || (profile == 0) || (!this->mesh.empty()))
	{
		cout << "Cannot create model" << endl;
		return;
	}
	this->createPoints(profile);
	this->createPolygons(profile->getSize());
	return;
}

void Model::draw(void)
// Draw the mesh into the OpenGL system
{
	Point c, d;
	unsigned int i;
	for(i = 0; i < this->mesh.size(); i++)
		this->mesh[i].draw(this->dType);
	if(this->dType == HIDDENSURFACEWIRE)
	{
		// This section draws the offset polygons for the hidden surface wireframe.
		c.x = c.y = c.z = 0.0;
		d.x = d.y = d.z = 1.0;
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_POLYGON_OFFSET_FILL);
		glPolygonOffset(0.5, 0.5);
		for(i = 0; i < this->mesh.size(); i++)
		{
			this->mesh[i].setColor(&c);
			this->mesh[i].draw(HIDDENSURFACEWIRE);
			this->mesh[i].setColor(&d);
		}
		// Put everything back to do the wireframe for next loop.
		glDisable(GL_POLYGON_OFFSET_FILL);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
  glFlush();
	return;
}

void Model::drawType(int d)
// Set the drawing type (wireframe, solid, etc)
{
	this->dType = d;
	switch(d)
	{
		case POINTS:
		break;
		case WIREFRAME:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
		case HIDDENSURFACEWIRE:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
		case RANDOMCOLORPOLY:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;
	}
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
	if(this->resolution > 3) this->resolution--;
	return;
}

void Model::printPoint(Point *p)
{
	cout << "(" << p->x << ", ";
	cout << p->y << ", ";
	cout << p->z << ")";
	return;
}
