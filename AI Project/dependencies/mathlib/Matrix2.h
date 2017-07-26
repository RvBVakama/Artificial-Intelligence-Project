//--------------------------------------------------------------------------------------
// Class for the Matrix2 object
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// If function to determine if "MATHLIB" should build for dll or static library mode
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
// Matrix2 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Matrix2
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	// Any new Matrix2 is set to identity first
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix2();

	//--------------------------------------------------------------------------------------
	// Alternative constructor to allow for the user to input values into the Matrix2
	//
	// Param:
	//		a: The float inputted into the a will be assigned to the matrix slot [0][0]
	//		b: The float inputted into the b will be assigned to the matrix slot [0][1]
	//		c: The float inputted into the c will be assigned to the matrix slot [1][0]
	//		d: The float inputted into the d will be assigned to the matrix slot [1][1]
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix2(float a, float b, float c, float d);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Matrix2();

	//--------------------------------------------------------------------------------------
	// Creating the class's two dimensional Matrix
	//--------------------------------------------------------------------------------------
	float Matrix2x2[2][2];

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix2 to be multiplied with a passed in Vector2
	//
	// Param:
	//		rhs: The Vector2 to be multipled with the Matrix2
	// Return:
	//		Returns the multipled Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 operator *(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix2 to be multiplied with a passed in Matrix2
	//
	// Param:
	//		rhs: The first matrix to be multipled in the equation
	// Return:
	//		Returns the multipled Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix2 operator *(Matrix2 rhs);

	//--------------------------------------------------------------------------------------
	// Lets the user very easily assign a row of x and y from a Matrix2 values to a 
	// Vector2
	// 
	// Example:
	// Matrix2 m2(3, 0, 0, 2);
	// Vector2 vec2res14(0, 0);
	// vec2res14 = m2[1];
	// This will grab the 2nd row in the matrix and return a new Vector2 with the values 
	// x=0, y=7 and z=8
	// 
	// Param:
	//		a: Which row to take values from and assign to the returned Vector2
	// Return:
	//		Returns a Vector2 with the values in the passed in row number
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2& operator[](int a);

	//--------------------------------------------------------------------------------------
	// Returns the [0][0] slot of the Matrix2
	// 
	// Return:
	// Returns the [0][0] slot of the Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB operator float*();

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix2 by the 
	// passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix2 by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotate(float angle);

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix2
	// 
	// Return:
	//		Returns the determinant of the Matrix2 considering the passed in float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Determinant();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a Matrix2 
	// 
	// Everything was learned from the link linked below:
	// https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//--------------------------------------------------------------------------------------
	MATHLIB void Inverse();
	
	//--------------------------------------------------------------------------------------
	// Checks if the Matrix2 object is identity, this is useful to see if its been changed
	// 
	// Return:
	//		Returns true or false, true if the Matrix is an identity Matrix, else is false
	//--------------------------------------------------------------------------------------
	MATHLIB bool IsIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix2 by swappng the values down a diagonal from the top left of the 
	// Matrix2 to the bottom right
	// 
	// Return:
	//		Returns out the flipped Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix2 Transpose();

	//--------------------------------------------------------------------------------------
	// Sets the Matrix2 to the desired position
	//  
	// Param:
	//		x: The x float to set to the axis in the Matrix2
	//		y: The y float to set to the axis in the Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(float x, float y);

	//--------------------------------------------------------------------------------------
	// Sets the Matrix2 to the desired position
	//  
	// Param:
	//		lhs: Inputs the Vector2's axes into the Matrix3 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(Vector2 lhs);

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix2 to the desired size
	// 
	// Param:
	//		x: Float to scale the Matrix2 by
	//		y: Float to scale the Matrix2 by
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(float x, float y);

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix2 to the desired size
	//  
	// Param:
	//		lhs: Inputs the Vector2's axes into the Matrix2 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(Vector2 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the scale of the Matrix2
	// Return:
	//		Returns the scale of the Matrix2
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 GetScale();

};