//--------------------------------------------------------------------------------------
// Class for the Vector4 object
//--------------------------------------------------------------------------------------
#pragma once

//--------------------------------------------------------------------------------------
// Including Vector3.h to allow for converting Vector3s to Vector4s
// and including math.h to use it's "sqrtf" (square root) function
//--------------------------------------------------------------------------------------
#include "Vector3.h"
#include "math.h"

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
// Vector4 object
// Contains functions that are commonly used in games for various reasons
// mainly to manipulate an object's position, rotation and scale
//--------------------------------------------------------------------------------------
class Vector4
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4();

	//--------------------------------------------------------------------------------------
	// Alternative Constructor to allow for simpler input of values into a 
	// Vector4's x, y, z and w axes by entering values in between the () smybols
	// 
	// Param:
	//		scopex: A float value that will be input into the x axis of the Vector4
	//		scopey: A float value that will be input into the y axis of the Vector4
	//		scopez: A float value that will be input into the z axis of the Vector4
	//		scopew: A float value that will be input into the w axis of the Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4(float scopex, float scopey, float scopez, float scopew);

	//--------------------------------------------------------------------------------------
	// Alternative Constructor to allow for the simple converstion from Vector3s to Vector4s
	// Takes a Vector3 and sets its x, y and z axes into the x, y and z axes in a Vector4s
	// setting w to 1
	// 
	// Param:
	//		rhs: Accesses the Vector3s x, y and z axes to allow for them to
	//			 be inputted into the x, y and z axes in the Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4(Vector3 & rhs);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATHLIB ~Vector4();

	//--------------------------------------------------------------------------------------
	// Creating the class's four dimensional Vector
	//--------------------------------------------------------------------------------------
	float x;
	float y;
	float z;
	float w;

	//--------------------------------------------------------------------------------------
	// Overloading the + operator to allow for Vector4s to be added together
	// 
	// Param:
	//		rhs: Accesses the passed in Vector4s x, y and z axes to allow
	//			 for them to be added to the Vector4's x, y and z axes
	// Return:
	//		Returns the final modified Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator+(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to allow for Vector4s to be taken away from eachother
	// 
	// Param:
	//		rhs: Accesses the passed in Vector4's x, y and z axes to allow
	//			 for them to be taken away from the Vector4's x, y and z axes
	// Return:
	//		Returns the final modified Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator-(Vector4 rhs);
	
	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector4s to be multiplied by Vector4s
	// The passed in Vector4s axes are on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted Vector4 axes to be
	//			 multipled with each axis of the Vector4
	// Return:
	//		Returns the final modified Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator*(Vector4 lhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to allow for Vector4s to be multiplied by floats
	// The float value is on the right hand side of the operator
	// 
	// Param:
	//		rhs: Allows for the inputted float value to be 
	//			 multipled with each axis of the Vector4
	// Return:
	//		Returns the final modified Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator*(float rhs);

	//--------------------------------------------------------------------------------------
	// Returns the memory address of x 
	// 
	// Return:
	//		Returns the memory address of x
	//--------------------------------------------------------------------------------------
	MATHLIB operator float*();

	//--------------------------------------------------------------------------------------
	// Overloading the array subscript operator [] to allow for checking what value is in
	// the x, y, z or w axis
	// 
	// Param:
	//		a: Takes a value from 0-3 to determine which axis to return the current value of 
	//		   x(0), y(1), z(2) or w(3), else it returns w
	//--------------------------------------------------------------------------------------
	MATHLIB float& operator[](int a);

	//--------------------------------------------------------------------------------------
	// Divides each axis of a Vector4 by a single passed in float value
	// 
	// Param:
	//		rhs: Replaces the passed in float to be divided by each axis in the array
	// Return:
	//		Returns the final modified Vector4 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 operator/(float rhs);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector4 axes to the Vector4's  axes to see 
	// if they are equal
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axes when they are
	//		determined to be of equal value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator==(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector4's axes to the Vector4 's axes to see 
	// if they are unequal
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axis when they are
	//		determined to be of unequal value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator!=(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector4's axes against a passed in Vector4 axes
	// to detemine if each axis is higher in value than the Vector4's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axes when they are
	//		determined to be of higher value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector4's axes against a passed in Vector4 axes
	// to detemine if each axis is lower in value than the Vector4's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axes when they are
	//		determined to be of lower value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector4's axes against a passed in Vector4 axes to
	// detemine if each axis is higher or equal to in value than the Vector4's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axes when they are
	//		determined to be of higher or equal value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator>=(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares each axis of the Vector4's axes against a passed in Vector4 axes to
	// detemine if each axis is lower or equal to in value than the Vector4's axes
	// 
	// Param:
	//		rhs: Value to compare against the Vector4 
	// Return:
	//		Returns true or false based on the passed in Vector4's axes when they are
	//		determined to be of lower or equal value compared to the current Vector4's axes
	//--------------------------------------------------------------------------------------
	MATHLIB bool operator<=(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Gets the magnitude of the Vector4 
	// 
	// Return:
	//		Returns the magnitude of the Vector4 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float Magnitude();

	//--------------------------------------------------------------------------------------
	// Gets the square magnitude of the Vector4 
	// 
	// Return:
	//		Returns the square magnitude of the Vector4 as a float
	//--------------------------------------------------------------------------------------
	MATHLIB float SqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises the Vector4, this scales the axes values to under '1.0' which makes
	// it easier in some cases to use
	//--------------------------------------------------------------------------------------
	MATHLIB void Normalise();
	
	//--------------------------------------------------------------------------------------
	// Normalises the Vector4, this scales the axes values to under '1' which makes
	// it easier in some cases to use
	// 
	// Return:
	//		Returns out the normalised Vector4 to another Vector4 to preserve 
	//		the state of the original Vector4 
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 NormaliseReturn();

	//--------------------------------------------------------------------------------------
	// Gets the distance between two Vector4s as a float which has been ran through the
	// magnitude function
	// 
	// Param:
	//		lhs: Passed in Vector4's axes
	// Return:
	//		Returns the final float value
	//--------------------------------------------------------------------------------------
	MATHLIB float Distance(Vector4 a);

	//--------------------------------------------------------------------------------------
	// Gets the dot product of 2 Vector4s
	// 
	// Param:
	//		rhs: Takes a Vector4 to dot product with the left hand instanced Vector4 object
	// Return:
	//		Returns a float which is the result of the dot product between the two Vector4s
	//--------------------------------------------------------------------------------------
	MATHLIB float Dot(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Gets the cross product of 2 Vector4s
	// 
	// Param:
	//		rhs: Takes a Vector4 to cross product with the Vector4 
	// Return:
	//		Returns Vector4 that is the result of the cross product between the two Vector4s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Cross(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector4s and returns the larger of each axis
	// 
	// Param:
	//		a: First Vector4 to compare
	//		b: Second Vector4 to compare
	// Return:
	//		Returns the larger of each axis as a new Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Max(Vector4 a, Vector4 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector4 with the Vector4 and assigns the new values to the 
	// Vector4 when they are determined to be the larger value of each axis
	// 
	// Param:
	//		a: Passed in Vector4 to compare against the Vector4 
	//--------------------------------------------------------------------------------------
	MATHLIB void Max(Vector4 a);

	//--------------------------------------------------------------------------------------
	// Compares two passed in Vector4s and returns the smaller of each axis
	// 
	// Param:
	//		a: First Vector4 to compare
	//		b: Second Vector4 to compare
	// Return:
	//		Returns the smaller of each axis as a new Vector4
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Min(Vector4 a, Vector4 b);

	//--------------------------------------------------------------------------------------
	// Compares a passed in Vector4 with the Vector4 and assigns the new values to the
	// Vector4 when they are determined to be the 
	// smaller value of each axis
	// 
	// Param:
	//		a: Passed in Vector4 to compare against the Vector4 
	//--------------------------------------------------------------------------------------
	MATHLIB void Min(Vector4 a);
	
	//--------------------------------------------------------------------------------------
	// Gets a lerped Vector4 from two passed in Vector4s and a time variable
	// 
	// Param: 
	//		a: First Vector4 to lerp from
	//		b: Second Vector4 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return
	// Return: 
	//		Returns a final lerped Vector4 from the passed in Vector4s and time values
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Lerp(Vector4 a, Vector4 b, float t);

	//--------------------------------------------------------------------------------------
	// Lerps between three Vector4s to create a bezier curve
	// 
	// Param: 
	//		a: First Vector4 to lerp from
	//		b: Second Vector4 to lerp to
	//		c: Third and final Vector4 to lerp to
	//		t: Lerp time to decide which point along the lerp line to return 
	// Return: 
	//		Returns the final lerped Vector4 of the passed in Vector4s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Bezier(Vector4 a, Vector4 b, Vector4 c, float t);

	//--------------------------------------------------------------------------------------
	// Creates a hermite curve by taking in four Vector4s, using two as points and the other
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
	//		Returns the final lerped Vector4 of the passed in Vector4s
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 HermiteCurve(Vector4 point0, Vector4 tangent0,
								 Vector4 point1, Vector4 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Allows the Vector4 to be swizzled to make a new Vector4 from the axes
	// values of the original Vector4 
	// 
	// Example:
	// Vector4 vec4a(1, 2, 3, 4);
	// Vector4 vec4b(0, 0, 0, 0);
	// vec4b = vec4a.wwxy();
	// This changes the original Vector4 (vec4b) to have: x=4, y=4, z=1 and w=2
	// 
	// Return:
	//		Returns swizzled Vector4 in the desired arrangement
	//--------------------------------------------------------------------------------------
	MATHLIB Vector4 Vector4::wwww();
	MATHLIB Vector4 Vector4::wwwx();
	MATHLIB Vector4 Vector4::wwwy();
	MATHLIB Vector4 Vector4::wwwz();
	MATHLIB Vector4 Vector4::wwxw();
	MATHLIB Vector4 Vector4::wwxx();
	MATHLIB Vector4 Vector4::wwxy();
	MATHLIB Vector4 Vector4::wwxz();
	MATHLIB Vector4 Vector4::wwyw();
	MATHLIB Vector4 Vector4::wwyx();
	MATHLIB Vector4 Vector4::wwyy();
	MATHLIB Vector4 Vector4::wwyz();
	MATHLIB Vector4 Vector4::wwzw();
	MATHLIB Vector4 Vector4::wwzx();
	MATHLIB Vector4 Vector4::wwzy();
	MATHLIB Vector4 Vector4::wwzz();
	MATHLIB Vector4 Vector4::wxww();
	MATHLIB Vector4 Vector4::wxwx();
	MATHLIB Vector4 Vector4::wxwy();
	MATHLIB Vector4 Vector4::wxwz();
	MATHLIB Vector4 Vector4::wxxw();
	MATHLIB Vector4 Vector4::wxxx();
	MATHLIB Vector4 Vector4::wxxy();
	MATHLIB Vector4 Vector4::wxxz();
	MATHLIB Vector4 Vector4::wxyw();
	MATHLIB Vector4 Vector4::wxyx();
	MATHLIB Vector4 Vector4::wxyy();
	MATHLIB Vector4 Vector4::wxyz();
	MATHLIB Vector4 Vector4::wxzw();
	MATHLIB Vector4 Vector4::wxzx();
	MATHLIB Vector4 Vector4::wxzy();
	MATHLIB Vector4 Vector4::wxzz();
	MATHLIB Vector4 Vector4::wyww();
	MATHLIB Vector4 Vector4::wywx();
	MATHLIB Vector4 Vector4::wywy();
	MATHLIB Vector4 Vector4::wywz();
	MATHLIB Vector4 Vector4::wyxw();
	MATHLIB Vector4 Vector4::wyxx();
	MATHLIB Vector4 Vector4::wyxy();
	MATHLIB Vector4 Vector4::wyxz();
	MATHLIB Vector4 Vector4::wyyw();
	MATHLIB Vector4 Vector4::wyyx();
	MATHLIB Vector4 Vector4::wyyy();
	MATHLIB Vector4 Vector4::wyyz();
	MATHLIB Vector4 Vector4::wyzw();
	MATHLIB Vector4 Vector4::wyzx();
	MATHLIB Vector4 Vector4::wyzy();
	MATHLIB Vector4 Vector4::wyzz();
	MATHLIB Vector4 Vector4::wzww();
	MATHLIB Vector4 Vector4::wzwx();
	MATHLIB Vector4 Vector4::wzwy();
	MATHLIB Vector4 Vector4::wzwz();
	MATHLIB Vector4 Vector4::wzxw();
	MATHLIB Vector4 Vector4::wzxx();
	MATHLIB Vector4 Vector4::wzxy();
	MATHLIB Vector4 Vector4::wzxz();
	MATHLIB Vector4 Vector4::wzyw();
	MATHLIB Vector4 Vector4::wzyx();
	MATHLIB Vector4 Vector4::wzyy();
	MATHLIB Vector4 Vector4::wzyz();
	MATHLIB Vector4 Vector4::wzzw();
	MATHLIB Vector4 Vector4::wzzx();
	MATHLIB Vector4 Vector4::wzzy();
	MATHLIB Vector4 Vector4::wzzz();
	MATHLIB Vector4 Vector4::xwww();
	MATHLIB Vector4 Vector4::xwwx();
	MATHLIB Vector4 Vector4::xwwy();
	MATHLIB Vector4 Vector4::xwwz();
	MATHLIB Vector4 Vector4::xwxw();
	MATHLIB Vector4 Vector4::xwxx();
	MATHLIB Vector4 Vector4::xwxy();
	MATHLIB Vector4 Vector4::xwxz();
	MATHLIB Vector4 Vector4::xwyw();
	MATHLIB Vector4 Vector4::xwyx();
	MATHLIB Vector4 Vector4::xwyy();
	MATHLIB Vector4 Vector4::xwyz();
	MATHLIB Vector4 Vector4::xwzw();
	MATHLIB Vector4 Vector4::xwzx();
	MATHLIB Vector4 Vector4::xwzy();
	MATHLIB Vector4 Vector4::xwzz();
	MATHLIB Vector4 Vector4::xxww();
	MATHLIB Vector4 Vector4::xxwx();
	MATHLIB Vector4 Vector4::xxwy();
	MATHLIB Vector4 Vector4::xxwz();
	MATHLIB Vector4 Vector4::xxxw();
	MATHLIB Vector4 Vector4::xxxx();
	MATHLIB Vector4 Vector4::xxxy();
	MATHLIB Vector4 Vector4::xxxz();
	MATHLIB Vector4 Vector4::xxyw();
	MATHLIB Vector4 Vector4::xxyx();
	MATHLIB Vector4 Vector4::xxyy();
	MATHLIB Vector4 Vector4::xxyz();
	MATHLIB Vector4 Vector4::xxzw();
	MATHLIB Vector4 Vector4::xxzx();
	MATHLIB Vector4 Vector4::xxzy();
	MATHLIB Vector4 Vector4::xxzz();
	MATHLIB Vector4 Vector4::xyww();
	MATHLIB Vector4 Vector4::xywx();
	MATHLIB Vector4 Vector4::xywy();
	MATHLIB Vector4 Vector4::xywz();
	MATHLIB Vector4 Vector4::xyxw();
	MATHLIB Vector4 Vector4::xyxx();
	MATHLIB Vector4 Vector4::xyxy();
	MATHLIB Vector4 Vector4::xyxz();
	MATHLIB Vector4 Vector4::xyyw();
	MATHLIB Vector4 Vector4::xyyx();
	MATHLIB Vector4 Vector4::xyyy();
	MATHLIB Vector4 Vector4::xyyz();
	MATHLIB Vector4 Vector4::xyzx();
	MATHLIB Vector4 Vector4::xyzy();
	MATHLIB Vector4 Vector4::xyzz();
	MATHLIB Vector4 Vector4::xzww();
	MATHLIB Vector4 Vector4::xzwx();
	MATHLIB Vector4 Vector4::xzwy();
	MATHLIB Vector4 Vector4::xzwz();
	MATHLIB Vector4 Vector4::xzxw();
	MATHLIB Vector4 Vector4::xzxx();
	MATHLIB Vector4 Vector4::xzxy();
	MATHLIB Vector4 Vector4::xzxz();
	MATHLIB Vector4 Vector4::xzyw();
	MATHLIB Vector4 Vector4::xzyx();
	MATHLIB Vector4 Vector4::xzyy();
	MATHLIB Vector4 Vector4::xzyz();
	MATHLIB Vector4 Vector4::xzzw();
	MATHLIB Vector4 Vector4::xzzx();
	MATHLIB Vector4 Vector4::xzzy();
	MATHLIB Vector4 Vector4::xzzz();
	MATHLIB Vector4 Vector4::ywww();
	MATHLIB Vector4 Vector4::ywwx();
	MATHLIB Vector4 Vector4::ywwy();
	MATHLIB Vector4 Vector4::ywwz();
	MATHLIB Vector4 Vector4::ywxw();
	MATHLIB Vector4 Vector4::ywxx();
	MATHLIB Vector4 Vector4::ywxy();
	MATHLIB Vector4 Vector4::ywxz();
	MATHLIB Vector4 Vector4::ywyw();
	MATHLIB Vector4 Vector4::ywyx();
	MATHLIB Vector4 Vector4::ywyy();
	MATHLIB Vector4 Vector4::ywyz();
	MATHLIB Vector4 Vector4::ywzw();
	MATHLIB Vector4 Vector4::ywzx();
	MATHLIB Vector4 Vector4::ywzy();
	MATHLIB Vector4 Vector4::ywzz();
	MATHLIB Vector4 Vector4::yxww();
	MATHLIB Vector4 Vector4::yxwx();
	MATHLIB Vector4 Vector4::yxwy();
	MATHLIB Vector4 Vector4::yxwz();
	MATHLIB Vector4 Vector4::yxxw();
	MATHLIB Vector4 Vector4::yxxx();
	MATHLIB Vector4 Vector4::yxxy();
	MATHLIB Vector4 Vector4::yxxz();
	MATHLIB Vector4 Vector4::yxyw();
	MATHLIB Vector4 Vector4::yxyx();
	MATHLIB Vector4 Vector4::yxyy();
	MATHLIB Vector4 Vector4::yxyz();
	MATHLIB Vector4 Vector4::yxzw();
	MATHLIB Vector4 Vector4::yxzx();
	MATHLIB Vector4 Vector4::yxzy();
	MATHLIB Vector4 Vector4::yxzz();
	MATHLIB Vector4 Vector4::yyww();
	MATHLIB Vector4 Vector4::yywx();
	MATHLIB Vector4 Vector4::yywy();
	MATHLIB Vector4 Vector4::yywz();
	MATHLIB Vector4 Vector4::yyxw();
	MATHLIB Vector4 Vector4::yyxx();
	MATHLIB Vector4 Vector4::yyxy();
	MATHLIB Vector4 Vector4::yyxz();
	MATHLIB Vector4 Vector4::yyyw();
	MATHLIB Vector4 Vector4::yyyx();
	MATHLIB Vector4 Vector4::yyyy();
	MATHLIB Vector4 Vector4::yyyz();
	MATHLIB Vector4 Vector4::yyzw();
	MATHLIB Vector4 Vector4::yyzx();
	MATHLIB Vector4 Vector4::yyzy();
	MATHLIB Vector4 Vector4::yyzz();
	MATHLIB Vector4 Vector4::yzww();
	MATHLIB Vector4 Vector4::yzwx();
	MATHLIB Vector4 Vector4::yzwy();
	MATHLIB Vector4 Vector4::yzwz();
	MATHLIB Vector4 Vector4::yzxw();
	MATHLIB Vector4 Vector4::yzxx();
	MATHLIB Vector4 Vector4::yzxy();
	MATHLIB Vector4 Vector4::yzxz();
	MATHLIB Vector4 Vector4::yzyw();
	MATHLIB Vector4 Vector4::yzyx();
	MATHLIB Vector4 Vector4::yzyy();
	MATHLIB Vector4 Vector4::yzyz();
	MATHLIB Vector4 Vector4::yzzw();
	MATHLIB Vector4 Vector4::yzzx();
	MATHLIB Vector4 Vector4::yzzy();
	MATHLIB Vector4 Vector4::yzzz();
	MATHLIB Vector4 Vector4::zwww();
	MATHLIB Vector4 Vector4::zwwx();
	MATHLIB Vector4 Vector4::zwwy();
	MATHLIB Vector4 Vector4::zwwz();
	MATHLIB Vector4 Vector4::zwxw();
	MATHLIB Vector4 Vector4::zwxx();
	MATHLIB Vector4 Vector4::zwxy();
	MATHLIB Vector4 Vector4::zwxz();
	MATHLIB Vector4 Vector4::zwyw();
	MATHLIB Vector4 Vector4::zwyx();
	MATHLIB Vector4 Vector4::zwyy();
	MATHLIB Vector4 Vector4::zwyz();
	MATHLIB Vector4 Vector4::zwzw();
	MATHLIB Vector4 Vector4::zwzx();
	MATHLIB Vector4 Vector4::zwzy();
	MATHLIB Vector4 Vector4::zwzz();
	MATHLIB Vector4 Vector4::zxww();
	MATHLIB Vector4 Vector4::zxwx();
	MATHLIB Vector4 Vector4::zxwy();
	MATHLIB Vector4 Vector4::zxwz();
	MATHLIB Vector4 Vector4::zxxw();
	MATHLIB Vector4 Vector4::zxxx();
	MATHLIB Vector4 Vector4::zxxy();
	MATHLIB Vector4 Vector4::zxxz();
	MATHLIB Vector4 Vector4::zxyw();
	MATHLIB Vector4 Vector4::zxyx();
	MATHLIB Vector4 Vector4::zxyy();
	MATHLIB Vector4 Vector4::zxyz();
	MATHLIB Vector4 Vector4::zxzw();
	MATHLIB Vector4 Vector4::zxzx();
	MATHLIB Vector4 Vector4::zxzy();
	MATHLIB Vector4 Vector4::zxzz();
	MATHLIB Vector4 Vector4::zyww();
	MATHLIB Vector4 Vector4::zywx();
	MATHLIB Vector4 Vector4::zywy();
	MATHLIB Vector4 Vector4::zywz();
	MATHLIB Vector4 Vector4::zyxw();
	MATHLIB Vector4 Vector4::zyxx();
	MATHLIB Vector4 Vector4::zyxy();
	MATHLIB Vector4 Vector4::zyxz();
	MATHLIB Vector4 Vector4::zyyw();
	MATHLIB Vector4 Vector4::zyyx();
	MATHLIB Vector4 Vector4::zyyy();
	MATHLIB Vector4 Vector4::zyyz();
	MATHLIB Vector4 Vector4::zyzw();
	MATHLIB Vector4 Vector4::zyzx();
	MATHLIB Vector4 Vector4::zyzy();
	MATHLIB Vector4 Vector4::zyzz();
	MATHLIB Vector4 Vector4::zzww();
	MATHLIB Vector4 Vector4::zzwx();
	MATHLIB Vector4 Vector4::zzwy();
	MATHLIB Vector4 Vector4::zzwz();
	MATHLIB Vector4 Vector4::zzxw();
	MATHLIB Vector4 Vector4::zzxx();
	MATHLIB Vector4 Vector4::zzxy();
	MATHLIB Vector4 Vector4::zzxz();
	MATHLIB Vector4 Vector4::zzyw();
	MATHLIB Vector4 Vector4::zzyx();
	MATHLIB Vector4 Vector4::zzyy();
	MATHLIB Vector4 Vector4::zzyz();
	MATHLIB Vector4 Vector4::zzzw();
	MATHLIB Vector4 Vector4::zzzx();
	MATHLIB Vector4 Vector4::zzzy();
	MATHLIB Vector4 Vector4::zzzz();
};

//--------------------------------------------------------------------------------------
// Overloading the * operator to allow for Vector4s to be multiplied by floats
// The float value is on the left hand side of the operator
// 
// Param:
//		rhs: Allows for the inputted float value to be 
//			 multipled with each axis of the Vector4
//		lhs: A float that is passed into the left hand side of the operand
// Return:
//		Returns the final modified Vector4
//--------------------------------------------------------------------------------------
MATHLIB Vector4 operator *(float lhs, Vector4 rhs);