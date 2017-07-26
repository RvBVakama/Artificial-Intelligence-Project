//--------------------------------------------------------------------------------------
// Class for the Matrix4 object
//--------------------------------------------------------------------------------------
#pragma once

//--------------------------------------------------------------------------------------
// Including Vector4.h to be able to multiply with the Matrix4 object
// also allowing set rotation, set position and set scale functions
// Including Matrix3.h to use it's determinant function to help with the inverse
// of Matrix4s
//--------------------------------------------------------------------------------------
#include "Vector4.h"
#include "Matrix3.h"

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
// Matrix4 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Matrix4
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	// Any new Matrix4 is set to identity first
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix4();

	//--------------------------------------------------------------------------------------
	// Alternative constructor to allow for the user to input values into the Matrix4
	//
	// Param:
	//		a: The float inputted into the a will be assigned to the matrix slot [0][0]
	//		b: The float inputted into the b will be assigned to the matrix slot [0][1]
	//		c: The float inputted into the c will be assigned to the matrix slot [0][2]
	//		d: The float inputted into the d will be assigned to the matrix slot [0][3]
	//		e: The float inputted into the e will be assigned to the matrix slot [1][0]
	//		f: The float inputted into the f will be assigned to the matrix slot [1][1]
	//		g: The float inputted into the g will be assigned to the matrix slot [1][2]
	//		h: The float inputted into the h will be assigned to the matrix slot [1][3]
	//		i: The float inputted into the i will be assigned to the matrix slot [2][0]
	//		j: The float inputted into the j will be assigned to the matrix slot [2][1]
	//		k: The float inputted into the k will be assigned to the matrix slot [2][2]
	//		l: The float inputted into the l will be assigned to the matrix slot [2][3]
	//		m: The float inputted into the m will be assigned to the matrix slot [3][0]
	//		n: The float inputted into the n will be assigned to the matrix slot [3][1]
	//		o: The float inputted into the o will be assigned to the matrix slot [3][2]
	//		p: The float inputted into the p will be assigned to the matrix slot [3][3]
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Matrix4();

	//--------------------------------------------------------------------------------------
	// Creating the class's four dimensional Matrix
	//--------------------------------------------------------------------------------------
	float Matrix4x4[4][4];

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix4 to be multiplied with a passed in Vector4
	//
	// Param:
	//		rhs: The Vector4 to be multipled with the Matrix4
	// Return:
	//		Returns the multipled Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator*(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Allows for the Matrix4 to be multiplied with a passed in Matrix4
	//
	// Param:
	//		rhs: The first matrix to be multipled in the equation
	// Return:
	//		Returns the multipled Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix4 operator*(Matrix4 rhs);

	//--------------------------------------------------------------------------------------
	// Lets the user very easily assign a row of x, y, z and w from a Matrix4 values to a 
	// Vector4
	// 
	// Example:
	// Matrix4 m4(0, 3, 0, 0, 2, 7, 0, 1, 8, 1, 1, 0, 6, 0, 2, 1);
	// Vector4 vec4res14(0, 0, 0, 0);
	// vec4res14 = m4[2];
	// This will grab the 3rd row in the matrix and return a new Vector4 with the values 
	// x=8, y=1, z=1 and w=0
	// 
	// Param:
	//		a: Which row to take values from and assign to the returned Vector4
	// Return:
	//		Returns a Vector4 with the values in the passed in row number
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4& operator[](int a);

	//--------------------------------------------------------------------------------------
	// Returns the [0][0] slot of the Matrix4
	// 
	// Return:
	// Returns the [0][0] slot of the Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB operator float*();

	//--------------------------------------------------------------------------------------
	// Multiplies each slot in a Matrix4 with a passed in float scalar value
	//  
	// Param:
	//		scalar: Passed in float scalar value to multiple each slot of the Matrix4 with
	// Return:
	//		Returns the final modified Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix4 operator*(float scalar);

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix4 on
	// the x axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix4 x axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateX(float angle);

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix4 on
	// the y axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix4 y axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateY(float angle);

	//--------------------------------------------------------------------------------------
	// Takes an angle float and uses cosf, sinf and -sinf to rotate the Matrix4 on
	// the z axis by the passed in float angle value
	//  
	// Param:
	//		angle: The float amount to rotate the Matrix4 z axis by 
	//--------------------------------------------------------------------------------------
	MATHLIB void setRotateZ(float angle);

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix4
	// 
	// Return:
	//		Returns the determinant of the Matrix4 considering the passed in float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Determinant();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a Matrix4 by using floats are temporary storage for the
	// the slots in the Matrix4, using Matrix3s to create a "Matrix of Minors" by finding
	// determinant of each slot in the orignal Matrix4, 
	// then transposing (adjugated) the Matrix4, then calculating the original 
	// Matrix4's determinant and finally dividing the determinant by the value one and 
	// multiplying it the transposed Matrix4
	// 
	// Everything was learned from the link linked below:
	// https://www.mathsisfun.com/algebra/matrix-inverse-minors-cofactors-adjugate.html
	//--------------------------------------------------------------------------------------
	MATHLIB void Inverse();

	//--------------------------------------------------------------------------------------
	// Checks if the Matrix4 object is identity, this is useful to see if its been changed
	// 
	// Return:
	//		Returns true or false, true if the Matrix is an identity Matrix, else is false
	//--------------------------------------------------------------------------------------
	MATHLIB bool IsIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix4 by swappng the values down a diagonal from the top left of the 
	// Matrix4 to the bottom right
	// 
	// Return:
	//		Returns out the flipped Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Matrix4 Transpose();

	//--------------------------------------------------------------------------------------
	// Changes the Matrix4's rotation axes to the desired direction
	//  
	// Param:
	//		from: The Vector3 that is the current object's rotation
	//		target: The desired Vector3 rotation
	//		up: The current up direction Vector3
	//--------------------------------------------------------------------------------------
	MATHLIB void LookAt(Vector3 from, Vector3 target, Vector3 up);

	//--------------------------------------------------------------------------------------
	// Sets the Matrix4 to the desired position
	//  
	// Param:
	//		x: The x float to set to the axis in the Matrix4
	//		y: The y float to set to the axis in the Matrix4
	//		z: The z float to set to the axis in the Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Sets the Matrix4 to the desired position
	//  
	// Param:
	//		lhs: Inputs the Vector4's axes into the Matrix4 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(Vector4 lhs);
	
	//--------------------------------------------------------------------------------------
	// Sets the Matrix4 to the desired position
	//  
	// Param:
	//		lhs: Inputs the Vector3's axes into the Matrix4 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetPos(Vector3 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the position of the Matrix4
	//  Return:
	//		Returns the position of the Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 GetPos();

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix4 to the desired size
	// 
	// Param:
	//		x: Float to scale the Matrix4 by
	//		y: Float to scale the Matrix4 by
	//		z: Float to scale the Matrix4 by
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Sets the scale of the Matrix4 to the desired size
	//  
	// Param:
	//		lhs: Inputs the Vector4's axes into the Matrix4 slots
	//--------------------------------------------------------------------------------------
	MATHLIB void SetScale(Vector4 lhs);

	//--------------------------------------------------------------------------------------
	// Gets the scale of the Matrix4
	// Return:
	//		Returns the scale of the Matrix4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector3 GetScale();
};
