//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#ifndef PROFILE_H_
#define PROFILE_H_

#include "point.h"
#include <vector>
#include <iostream>	// Only for debugging
using namespace std;

class Profile
{
	public:
		Profile(void);
		virtual ~Profile(void);
		void addPoint(int x, int y);	// Add point to the profile
		void draw(void);							// Draw the profile
		int getSize(void);						// Return the size of the point array
		Point *getPoint(int p);				// Return the point at p in array
	private:
		vector<Point> points;					// Array of points.
};

#endif
