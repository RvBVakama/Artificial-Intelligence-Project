//--------------------------------------------------------------------------------------
// Class for the player
//--------------------------------------------------------------------------------------
#pragma once

#include "Collider.h"
#include "Matrix3.h"
#include <vector>

//--------------------------------------------------------------------------------------
// Entity object
// The base object that contains lots of functions/variables that most object in a game will use.
//--------------------------------------------------------------------------------------
class Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Entity();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Entity();

	//--------------------------------------------------------------------------------------
	// Checks if the object has a parent if so it updates its transform to match that of its parent.
	// Else it updates its own transform.
	//--------------------------------------------------------------------------------------
	void UpdateTransforms();

	//--------------------------------------------------------------------------------------
	// Sets the parent to the passed in object.
	//
	// Param:
	//		a: Sets the parent to the passed in object.
	//--------------------------------------------------------------------------------------
	void SetParent(Entity* a);

	//--------------------------------------------------------------------------------------
	// Pushes back the passed in object one spot back in the array to allow for adding for children.
	//
	// Param:
	//		a: Pushes back the passed in object one spot in the array.
	//--------------------------------------------------------------------------------------
	void SetChild(Entity* a);
	
	void SetActive(bool a);
	
	bool GetActive();

	//any object with this bool as true when its touched it kills what touches it.
	bool bCanKill;

	//checks if the player has died
	bool bDead;

	//Checks if the wall has been hit to flip the player texture
	bool bWallHit;

	//Active or not?
	bool m_bActive;

	//a timer
	double m_timer;

	//stage counter
	int nStage;

	//the parent object link
	Entity* m_Parent;

	//STL vector array for storing children
	std::vector<Entity*> m_children;

	//--------------------------------------------------------------------------------------
	// Gets the position of the obejct.
	//
	// Return:
	//		Returns the position of the object (its vector x and y values).
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// Returns the adress of m_Collider to report back what object is colliding.
	// 
	// Return:
	//		Returns m_Collider.
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//local 3 dimensional local transform
	Matrix3 localTransform;

	//local 3 dimensional global transform
	Matrix3 globalTransform;

	//the collision object
	Collider m_Collider;
};
