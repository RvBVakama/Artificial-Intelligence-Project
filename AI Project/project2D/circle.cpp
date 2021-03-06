#include "circle.h"

using namespace std;

//-----------------------------------------------------------------------------------------
// Default Constructor
//-----------------------------------------------------------------------------------------
Circle::Circle()
{
}

//-----------------------------------------------------------------------------------------
// Default Destructor
//-----------------------------------------------------------------------------------------
Circle::~Circle()
{
}

//--------------------------------------------------------------------------------------
// Calculates the damage the player will do with an attack.
//
// Param:
//		radius: The type of the weapon the player currently has equipped.
//--------------------------------------------------------------------------------------
void Circle::SetRadius(int radius)
{
	Radius = radius;
}

//--------------------------------------------------------------------------------------
// Returns the radius of the circle.
//
// Return:
//		Returns the radius of the circle as an int.
//--------------------------------------------------------------------------------------
int Circle::GetRadius()
{
	return Radius;
}