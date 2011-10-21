/*
 * Model.cpp
 *
 *  Created on: Oct 20, 2011
 *      Author: pyridoxus
 */

#include "Model.h"

Model::Model(Point *points, int resolution)
// Create model using profile in null terminated array of Point pointers.
// Resolution is the number of points around the 3D axis.
// The constructor does not set the drawing type or does the actual drawing.
// The constructor only creates the model.
{
	int i = 0;
	this->dType = GL_POINTS;
	this->index = 0;
	this->mesh = 0;
	if((resolution < 3) || (points == 0)) return;
	do
	{
	}	while(points[i++] != 0);
	return;
}

Model::~Model()
{
	return;
}
