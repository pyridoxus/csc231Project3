#ifndef PROFILE_H_
#define PROFILE_H_

#include "point.h"
#include <vector>

class Profile
{
	public:
		Profile();
		virtual ~Profile();
		void addPoint(int x, int y);	// Add point to the profile
		void draw(void);							// Draw the profile
		int getSize(void);						// Return the size of the point array
		Point *getPoint(int p);				// Return the point at p in array
	private:
		std::vector<Point> points;		// Array of points.
};

#endif
