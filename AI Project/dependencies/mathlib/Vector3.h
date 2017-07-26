//--------------------------------------------------------------------------------------
// Class for the Vector3 object
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
// Vector3 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Vector3
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3();

	//--------------------------------------------------------------------------------------
	// Alternative Constructor to allow for simpler input of values into a 
	// Vector3's x, y, z and w axes by entering values in between the () smybols
	// 
	// Param:
	//		scopex: A float value that will be input into the x axis of the Vector3
	//		scopey: A float value that will be input into the y axis of the Vector3
	//		scopez: A float value that will be input into the z axis of the Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3(float scopex, float scopey, float scopez);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Vector3();

	//--------------------------------------------------------------------------------------
	// Creating the class's three dimensional Vector
	//--------------------------------------------------------------------------------------
	float x;
	float y;
	float z;

	//--------------------------------------------------------------------------------------
	// Overloading the + operator to allow for Vector3s to be added together
	// 
	// Param:
	//		rhs: Accesses the passed in Vector3s x, y and z axes to allow
	//			 for them to be added to the Vector3's x, y and z axes
	// Return:
	//		Returns the final modified Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator+(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to allow for Vector3s to be taken away from eachother
	// 
	// Param:
	//		rhs: Accesses the passed in Vector3's x and y axes to allow
	//			 for them to be taken away from the Vector3's x, y and z axes
	// Return:
	//		Returns the final modified Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator-(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector3s to be multiplied by Vector3s
	// The passed in Vector3s axes are on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted Vector3 axes to be
	//			 multipled with each axis of the Vector3
	// Return:
	//		Returns the final modified Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator*(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector3s to be multiplied by floats
	// The float value is on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted float value to be 
	//			 multipled with each axis of the Vector3
	// Return:
	//		Returns the final modified Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator*(float rhs);

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
	MATHLIB float& operator[](int a);

	//--------------------------------------------------------------------------------------
	// Divides each axis of a Vector3 by a single passed in float value
	// 
	// Param:
	//		rhs: Replaces the passed in float to be divided by each axis in the array
	// Return:
	//		Returns the final modified Vector3 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator/(float rhs);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector3 axes to the Vector3's  axes to see 
	// if they are equal
	// 
	// Param:
	//		rhs: Value to compare against the Vector3
	// Return:
	//		Returns true or false based on the passed in Vector3's axes when they are
	//		determined to be of equal value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator==(Vector3 rhs);
	
	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector3's axes to the Vector3 's axes to see 
	// if they are unequal
	// 
	// Param:
	//		rhs: Value to compare against the Vector3 
	// Return:
	//		Returns true or false based on the passed in Vector3's axis when they are
	//		determined to be of unequal value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator!=(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector3's axes against a passed in Vector3 axes
	// to detemine if each axis is higher in value than the Vector3's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector3 
	// Return:
	//		Returns true or false based on the passed in Vector3's axes when they are
	//		determined to be of higher value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector3's axes against a passed in Vector3 axes
	// to detemine if each axis is lower in value than the Vector3's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector3 
	// Return:
	//		Returns true or false based on the passed in Vector3's axes when they are
	//		determined to be of lower value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector3's axes against a passed in Vector3 axes to
	// detemine if each axis is higher or equal to in value than the Vector3's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector3 
	// Return:
	//		Returns true or false based on the passed in Vector3's axes when they are
	//		determined to be of higher or equal value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>=(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector3's axes against a passed in Vector3 axes to
	// detemine if each axis is lower or equal to in value than the Vector3's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector3 
	// Return:
	//		Returns true or false based on the passed in Vector3's axes when they are
	//		determined to be of lower or equal value compared to the current Vector3's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<=(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Gets the magnitude of the Vector3 
	// 
	// Return:
	//		Returns the magnitude of the Vector3 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float Magnitude();

	//--------------------------------------------------------------------------------------
	// Gets the square magnitude of the Vector3 
	// 
	// Return:
	//		Returns the square magnitude of the Vector3 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float SqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises the Vector3, this scales the axes values to under '1.0' which makes
	// it easier in some cases to use
	//--------------------------------------------------------------------------------------
	MATHLIB void Normalise();

	//--------------------------------------------------------------------------------------
	// Normalises the Vector3, this scales the axes values to under '1' which makes
	// it easier in some cases to use
	// 
	// Return:
	//		Returns out the normalised Vector3 to another Vector3 to preserve 
	//		the state of the original Vector3 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 NormaliseReturn();

	//--------------------------------------------------------------------------------------
	// Gets the distance between two Vector3s as a float which has been ran through the
	// magnitude function
	// 
	// Param:
	//		lhs: Passed in Vector3's axes
	// Return:
	//		Returns the final float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Distance(Vector3 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the dot product of 2 Vector3s
	// 
	// Param:
	//		rhs: Takes a Vector3 to dot product with the left hand instanced Vector3 object
	// Return:
	//		Returns a float which is the result of the dot product between the two Vector3s
	//--------------------------------------------------------------------------------------
	MATHLIB float Dot(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Gets the cross product of 2 Vector3s
	// 
	// Param:
	//		rhs: Takes a Vector3 to cross product with the Vector3 
	// Return:
	//		Returns Vector3 that is the result of the cross product between the two Vector3s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Cross(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector3s and returns the larger of each axis
	// 
	// Param:
	//		a: First Vector3 to compare
	//		b: Second Vector3 to compare
	// Return:
	//		Returns the larger of each axis as a new Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Max(Vector3 a, Vector3 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector3 with the Vector3 and assigns the new values to the 
	// Vector3 when they are determined to be the larger value of each axis
	// 
	// Param:
	//		a: Passed in Vector3 to compare against the Vector3 
	//--------------------------------------------------------------------------------------
	MATHLIB void Max(Vector3 a);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector3s and returns the smaller of each axis
	// 
	// Param:
	//		a: First Vector3 to compare
	//		b: Second Vector3 to compare
	// Return:
	//		Returns the smaller of each axis as a new Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Min(Vector3 a, Vector3 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector3 with the Vector3 and assigns the new values to the
	// Vector3 when they are determined to be the 
	// smaller value of each axis
	// 
	// Param:
	//		a: Passed in Vector3 to compare against the Vector3 
	//--------------------------------------------------------------------------------------
	MATHLIB void Min(Vector3 a);

	//--------------------------------------------------------------------------------------
	// Gets a lerped Vector3 from two passed in Vector3s and a time variable
	// 
	// Param: 
	//		a: First Vector3 to lerp from
	//		b: Second Vector3 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return
	// Return: 
	//		Returns a final lerped Vector3 from the passed in Vector3s and time values
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Lerp(Vector3 a, Vector3 b, float t);

	//--------------------------------------------------------------------------------------
	// Lerps between three Vector3s to create a bezier curve
	// 
	// Param: 
	//		a: First Vector3 to lerp from
	//		b: Second Vector3 to lerp to
	//		c: Third and final Vector3 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return 
	// Return: 
	//		Returns the final lerped Vector3 of the passed in Vector3s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Bezier(Vector3 a, Vector3 b, Vector3 c, float t);

	//--------------------------------------------------------------------------------------
	// Creates a hermite curve by taking in four Vector3s, using two as points and the other
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
	//		Returns the final lerped Vector3 of the passed in Vector3s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 HermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Allows the Vector3 to be swizzled to make a new Vector3 from the axes
	// values of the original Vector3 
	// 
	// Example:
	// Vector3 vec3a(1, 2, 3);
	// Vector3 vec3b(0, 0, 0);
	// vec3b = vec3a.wxy();
	// This changes the original Vector3 (vec3b) to have: x=3, y=1 and z=2
	// 
	// Return:
	//		Returns swizzled Vector3 in the desired arrangement
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 Vector3::xxx();
	MATHLIB Vector3 Vector3::xxy();
	MATHLIB Vector3 Vector3::xxz();
	MATHLIB Vector3 Vector3::xyx();
	MATHLIB Vector3 Vector3::xyy();
	MATHLIB Vector3 Vector3::xzx();
	MATHLIB Vector3 Vector3::xzy();
	MATHLIB Vector3 Vector3::xzz();
	MATHLIB Vector3 Vector3::yxx();
	MATHLIB Vector3 Vector3::yxy();
	MATHLIB Vector3 Vector3::yxz();
	MATHLIB Vector3 Vector3::yyx();
	MATHLIB Vector3 Vector3::yyy();
	MATHLIB Vector3 Vector3::yyz();
	MATHLIB Vector3 Vector3::yzx();
	MATHLIB Vector3 Vector3::yzy();
	MATHLIB Vector3 Vector3::yzz();
	MATHLIB Vector3 Vector3::zxx();
	MATHLIB Vector3 Vector3::zxy();
	MATHLIB Vector3 Vector3::zxz();
	MATHLIB Vector3 Vector3::zyx();
	MATHLIB Vector3 Vector3::zyy();
	MATHLIB Vector3 Vector3::zyz();
	MATHLIB Vector3 Vector3::zzx();
	MATHLIB Vector3 Vector3::zzy();
	MATHLIB Vector3 Vector3::zzz();
};

//--------------------------------------------------------------------------------------
// Overloading the * operator to allow for Vector3s to be multiplied by floats
// The float value is on the left hand side of the operator
// 
// Param:
//		rhs: Allows for the inputted float value to be 
//			 multipled with each axis of the Vector3
//		lhs: A float that is passed into the left hand side of the operand
// Return:
//		Returns the final modified Vector3
//--------------------------------------------------------------------------------------
MATHLIB Vector3 operator*(float lhs, Vector3 rhs);