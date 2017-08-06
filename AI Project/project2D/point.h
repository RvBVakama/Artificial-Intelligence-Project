//--------------------------------------------------------------------------------------
// Class for a Point
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"

//----------------------------------------------------------------------------------------------------
// Class for the point of a circle
//----------------------------------------------------------------------------------------------------
class Point
{

public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Point() {}

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~Point() {}

	//--------------------------------------------------------------------------------------
	// Sets the position of the point in which the circle will be calculated from.
	// Taking in an x and y value the funciton will set the points new location.
	//
	// Param:
	//		NewX: The x value that is passed in will become the new x value of the point.
	//		NewY: The y value that is passed in will become the new y value of the point.
	//--------------------------------------------------------------------------------------
	void SetPosition(int NewX, int NewY) 
	{
		x = NewX;
		y = NewY;
	}

	//--------------------------------------------------------------------------------------
	// Returns the points location.
	//
	// Return:
	//		Returns a Vector2 x and y coordinance of the point's location.
	//--------------------------------------------------------------------------------------
	Vector2 GetCenter()
	{
		return Vector2((float)x, (float)y);
	}

	int x, y;
};
