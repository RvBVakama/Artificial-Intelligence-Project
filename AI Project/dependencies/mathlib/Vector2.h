//--------------------------------------------------------------------------------------
// Class for the Vector2 object
//--------------------------------------------------------------------------------------
#pragma once

//--------------------------------------------------------------------------------------
// if statement to determine if "MATHLIB" should build for dll or static library mode
//--------------------------------------------------------------------------------------
#ifdef STATIC_EXPORT
#define MATHLIB
#else
#ifdef DLL_EXPORT
#define MATHLIB __declspec(dllexport)
#else
#define MATHLIB __declspec(dllimport)
#endif
#endif

//--------------------------------------------------------------------------------------
// Vector2 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Vector2
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2();

	//--------------------------------------------------------------------------------------
	// Alternative Constructor to allow for simpler input of values into a 
	// Vector2's x, y, z and w axes by entering values in between the () smybols
	// 
	// Param:
	//		scopex: A float value that will be input into the x axis of the Vector2
	//		scopey: A float value that will be input into the y axis of the Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2(float scopex, float scopey);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Vector2();

	//--------------------------------------------------------------------------------------
	// Creating the class's two dimensional Vector
	//--------------------------------------------------------------------------------------
	float x;
	float y;

	//--------------------------------------------------------------------------------------
	// Overloading the + operator to allow for Vector2s to be added together
	// 
	// Param:
	//		rhs: Accesses the passed in Vector2s x and y axes to allow
	//			 for them to be added to the Vector2's x and y axes
	// Return:
	//		Returns the final modified Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator +(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to allow for Vector2s to be taken away from eachother
	// 
	// Param:
	//		rhs: Accesses the passed in Vector2's x and y axes to allow
	//			 for them to be taken away from the Vector2's x and y axes
	// Return:
	//		Returns the final modified Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator -(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector2s to be multiplied by Vector2s
	// The passed in Vector2s axes are on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted Vector2 axes to be
	//			 multipled with each axis of the Vector2
	// Return:
	//		Returns the final modified Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator*(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector2s to be multiplied by floats
	// The float value is on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted float value to be 
	//			 multipled with each axis of the Vector2
	// Return:
	//		Returns the final modified Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator *(float rhs);

	//--------------------------------------------------------------------------------------
	// Returns the memory address of x 
	// 
	// Return:
	//		Returns the memory address of x
	//--------------------------------------------------------------------------------------
	MATHLIB operator float*();

	//--------------------------------------------------------------------------------------
	// Overloading the array subscript operator [] to allow for checking what value is in
	// the x, y or z axis
	// 
	// Param:
	//		a: Takes a value from 0-3 to determine which axis to return the current value of 
	//		   x(0), y(1) or z(2), else it returns z
	//--------------------------------------------------------------------------------------
	MATHLIB float& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Divides each axis of a Vector2 by a single passed in float value
	// 
	// Param:
	//		rhs: Replaces the passed in float to be divided by each axis in the array
	// Return:
	//		Returns the final modified Vector2 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator/(float rhs);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector2 axes to the Vector2's  axes to see 
	// if they are equal
	// 
	// Param:
	//		rhs: Value to compare against the Vector2
	// Return:
	//		Returns true or false based on the passed in Vector2's axes when they are
	//		determined to be of equal value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator==(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector2's axes to the Vector2 's axes to see 
	// if they are unequal
	// 
	// Param:
	//		rhs: Value to compare against the Vector2 
	// Return:
	//		Returns true or false based on the passed in Vector2's axis when they are
	//		determined to be of unequal value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator!=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector2's axes against a passed in Vector2 axes
	// to detemine if each axis is higher in value than the Vector2's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector2 
	// Return:
	//		Returns true or false based on the passed in Vector2's axes when they are
	//		determined to be of higher value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector2's axes against a passed in Vector2 axes
	// to detemine if each axis is lower in value than the Vector2's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector2 
	// Return:
	//		Returns true or false based on the passed in Vector2's axes when they are
	//		determined to be of lower value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector2's axes against a passed in Vector2 axes to
	// detemine if each axis is higher or equal to in value than the Vector2's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector2 
	// Return:
	//		Returns true or false based on the passed in Vector2's axes when they are
	//		determined to be of higher or equal value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector2's axes against a passed in Vector2 axes to
	// detemine if each axis is lower or equal to in value than the Vector2's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector2 
	// Return:
	//		Returns true or false based on the passed in Vector2's axes when they are
	//		determined to be of lower or equal value compared to the current Vector2's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Gets the magnitude of the Vector2 
	// 
	// Return:
	//		Returns the magnitude of the Vector2 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float Magnitude();

	//--------------------------------------------------------------------------------------
	// Gets the square magnitude of the Vector2 
	// 
	// Return:
	//		Returns the square magnitude of the Vector2 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float SqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises the Vector2, this scales the axes values to under '1.0' which makes
	// it easier in some cases to use
	//--------------------------------------------------------------------------------------
	MATHLIB void Normalise();

	//--------------------------------------------------------------------------------------
	// Normalises the Vector2, this scales the axes values to under '1' which makes
	// it easier in some cases to use
	// 
	// Return:
	//		Returns out the normalised Vector2 to another Vector2 to preserve 
	//		the state of the original Vector2 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 NormaliseReturn();

	//--------------------------------------------------------------------------------------
	// Gets the distance between two Vector2s as a float which has been ran through the
	// magnitude function
	// 
	// Param:
	//		lhs: Passed in Vector2's axes
	// Return:
	//		Returns the final float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Distance(Vector2 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the dot product of 2 Vector2s
	// 
	// Param:
	//		rhs: Takes a Vector2 to dot product with the left hand instanced Vector2 object
	// Return:
	//		Returns a float which is the result of the dot product between the two Vector2s
	//--------------------------------------------------------------------------------------
	MATHLIB float Dot(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector2s and returns the larger of each axis
	// 
	// Param:
	//		a: First Vector2 to compare
	//		b: Second Vector2 to compare
	// Return:
	//		Returns the larger of each axis as a new Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 Max(Vector2 a, Vector2 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector2 with the Vector2 and assigns the new values to the 
	// Vector2 when they are determined to be the larger value of each axis
	// 
	// Param:
	//		a: Passed in Vector2 to compare against the Vector2 
	//--------------------------------------------------------------------------------------
	MATHLIB void Max(Vector2 a);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector2s and returns the smaller of each axis
	// 
	// Param:
	//		a: First Vector2 to compare
	//		b: Second Vector2 to compare
	// Return:
	//		Returns the smaller of each axis as a new Vector2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 Min(Vector2 a, Vector2 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector2 with the Vector2 and assigns the new values to the
	// Vector2 when they are determined to be the 
	// smaller value of each axis
	// 
	// Param:
	//		a: Passed in Vector2 to compare against the Vector2 
	//--------------------------------------------------------------------------------------
	MATHLIB void Min(Vector2 a);

	//--------------------------------------------------------------------------------------
	// Gets a lerped Vector2 from two passed in Vector2s and a time variable
	// 
	// Param: 
	//		a: First Vector2 to lerp from
	//		b: Second Vector2 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return
	// Return: 
	//		Returns a final lerped Vector2 from the passed in Vector2s and time values
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 Lerp(Vector2 a, Vector2 b, float t);

	//--------------------------------------------------------------------------------------
	// Lerps between three Vector2s to create a bezier curve
	// 
	// Param: 
	//		a: First Vector2 to lerp from
	//		b: Second Vector2 to lerp to
	//		c: Third and final Vector2 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return 
	// Return: 
	//		Returns the final lerped Vector2 of the passed in Vector2s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 Bezier(Vector2 a, Vector2 b, Vector2 c, float t);

	//--------------------------------------------------------------------------------------
	// Creates a hermite curve by taking in four Vector2s, using two as points and the other
	// two as tangents. It also considers a time float that tells it which point in the line 
	// to return, using a lower time value creates a smoother curve.
	// 
	// Param:
	//		point0: First point to lerp from
	//		tangent0: First tangent to offset the lerp from point0
	//		point1: Second point to lerp to
	//		tangent1: Second tangent to offset the lerp from point1
	//		t: Lerp time to decide which point along the lerp line to return
	// Return:
	//		Returns the final lerped Vector2 of the passed in Vector2s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 HermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Allows the Vector2 to be swizzled to make a new Vector2 from the axes
	// values of the original Vector2 
	// 
	// Example:
	// Vector2 vec2a(1, 2);
	// Vector2 vec2b(0, 0);
	// vec2b = vec2a.yy();
	// This changes the original Vector2 (vec2b) to have: x=2 and y=2
	// 
	// Return:
	//		Returns swizzled Vector2 in the desired arrangement
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 Vector2::xx();
	MATHLIB Vector2 Vector2::yx();
	MATHLIB Vector2 Vector2::yy();
};

//--------------------------------------------------------------------------------------
// Overloading the * operator to allow for Vector2s to be multiplied by floats
// The float value is on the left hand side of the operator
// 
// Param:
//		rhs: Allows for the inputted float value to be 
//			 multipled with each axis of the Vector2
//		lhs: A float that is passed into the left hand side of the operand
// Return:
//		Returns the final modified Vector2
//--------------------------------------------------------------------------------------
MATHLIB Vector2 operator*(float lhs, Vector2 rhs);