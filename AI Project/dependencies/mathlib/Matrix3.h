//--------------------------------------------------------------------------------------
// Class for the Matrix3 object
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include <math.h>

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
// Matrix3 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Matrix3
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	// Any new Matrix3 is set to identity first
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix3();

	//--------------------------------------------------------------------------------------
	// Alternative constructor to allow for the user to input values into the Matrix3
	//
	// Param:
	//		a: The float inputted into the a will be assigned to the matrix slot [0][0]
	//		b: The float inputted into the b will be assigned to the matrix slot [0][1]
	//		c: The float inputted into the c will be assigned to the matrix slot [0][2]
	//		d: The float inputted into the d will be assigned to the matrix slot [1][0]
	//		e: The float inputted into the e will be assigned to the matrix slot [1][1]
	//		f: The float inputted into the f will be assigned to the matrix slot [1][2]
	//		g: The float inputted into the g will be assigned to the matrix slot [2][0]
	//		h: The float inputted into the h will be assigned to the matrix slot [2][1]
	//		i: The float inputted into the i will be assigned to the matrix slot [2][2]
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Matrix3();

	//--------------------------------------------------------------------------------------
	// Creating the class's three dimensional Matrix
	//--------------------------------------------------------------------------------------
	float Matrix3x3[3][3];

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix3 to be multiplied with a passed in Vector4
	//
	// Param:
	//		rhs: The Vector4 to be multipled with the Matrix3
	// Return:
	//		Returns the multipled Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 operator*(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix3 to be multiplied with a passed in Matrix3
	//
	// Param:
	//		rhs: The first matrix to be multipled in the equation
	// Return:
	//		Returns the multipled Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix3 operator*(Matrix3 rhs);

	//--------------------------------------------------------------------------------------
	// Lets the user very easily assign a row of x, y and z from a Matrix3 values to a 
	// Vector3
	// 
	// Example:
	// Matrix3 m3(0, 3, 0, 0, 2, 7, 0, 1, 8);
	// Vector3 vec3res14(0, 0, 0);
	// vec3res14 = m3[2];
	// This will grab the 3rd row in the matrix and return a new Vector3 with the values 
	// x=0, y=7 and z=8
	// 
	// Param:
	//		a: Which row to take values from and assign to the returned Vector3
	// Return:
	//		Returns a Vector3 with the values in the passed in row number
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3& operator[](int a);

	//--------------------------------------------------------------------------------------
	// Returns the [0][0] slot of the Matrix3
	// 
	// Return:
	// Returns the [0][0] slot of the Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB operator float*();

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix3 on
	// the x axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix3 x axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateX(float angle);

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix3 on
	// the y axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix3 y axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateY(float angle);

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix3 on
	// the z axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix3 z axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateZ(float angle);

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix3
	// 
	// Return:
	//		Returns the determinant of the Matrix3 considering the passed in float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Determinant();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a Matrix3 by first creating a "matrix of minors"
	// then it transposes the Matrix3, it then finds the determinant of the original Matrix3
	// then multiples the Matrix3 by the value on divided by Matrix3's determinant result 
	// 
	// Everything was learned from the link linked below:
	// https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//--------------------------------------------------------------------------------------
	MATHLIB void Inverse();

	//--------------------------------------------------------------------------------------
	// Checks if the Matrix3 object is identity, this is useful to see if its been changed
	// 
	// Return:
	//		Returns true or false, true if the Matrix is an identity Matrix, else is false
	//--------------------------------------------------------------------------------------
	MATHLIB bool IsIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix3 by swappng the values down a diagonal from the top left of the 
	// Matrix3 to the bottom right
	// 
	// Return:
	//		Returns out the flipped Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix3 Transpose();

	//--------------------------------------------------------------------------------------
	// Sets the Matrix3 to the desired position
	//  
	// Param:
	//		x: The x float to set to the axis in the Matrix3
	//		y: The y float to set to the axis in the Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(float x, float y);

	//--------------------------------------------------------------------------------------
	// Sets the Matrix3 to the desired position
	//  
	// Param:
	//		lhs: Inputs the Vector4's axes into the Matrix3 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(Vector3 lhs);
	
	//--------------------------------------------------------------------------------------
	// Sets the Matrix3 to the desired position
	//  
	// Param:
	//		lhs: Inputs the Vector2's axes into the Matrix3 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(Vector2 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the position of the Matrix3
	//  Return:
	//		Returns the position of the Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 GetPos();

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix3 to the desired size
	// 
	// Param:
	//		x: Float to scale the Matrix3 by
	//		y: Float to scale the Matrix3 by
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(float x, float y);

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix3 to the desired size
	//  
	// Param:
	//		lhs: Inputs the Vector4's axes into the Matrix3 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(Vector3 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the scale of the Matrix3
	// Return:
	//		Returns the scale of the Matrix3
	//--------------------------------------------------------------------------------------
	MATHLIB Vector2 GetScale();
};

