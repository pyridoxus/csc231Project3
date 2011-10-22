#ifndef PROFILE_H_
#define PROFILE_H_

#include "point.h"
#include <vector>
#include <iostream>	// Only for debugging
using namespace std;

class Profile
{
	public:
		Profile(int windowH);
		virtual ~Profile();
		void addPoint(int x, int y);	// Add point to the profile
		void draw(void);							// Draw the profile
		int getSize(void);						// Return the size of the point array
		Point *getPoint(int p);				// Return the point at p in array
	private:
		vector<Point> points;					// Array of points.
		int windowH;									// Height of window
};

#endif
