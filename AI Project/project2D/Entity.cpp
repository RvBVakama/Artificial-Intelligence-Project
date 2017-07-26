#include "Entity.h"
#include "Collider.h"

//--------------------------------------------------------------------------------------
// Default Constructor
// Sets default collision areas and sets some bools and pointer to safe initial values.
//--------------------------------------------------------------------------------------
Entity::Entity()
{
	//choosing the pixles to set the collision area
	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);
	//any object with this bool as true can kill players
	bCanKill = false;
	//setting m_Parent to null so that its not assigned garbage memory
	m_Parent = nullptr;
	//setting the default
	bWallHit = true;
	//setting the dead value
	bDead = false;
	//settings the default active value
	m_bActive = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
}

//--------------------------------------------------------------------------------------
// Checks if the object has a parent if so it updates its transform to match that of 
// its parent.
// Else it updates its own transform.
//--------------------------------------------------------------------------------------
void Entity::UpdateTransforms()
{
	//if the object has a parent do this
	if (m_Parent)
	{
		globalTransform = m_Parent->globalTransform * localTransform;
	}
	else
	{
		globalTransform = localTransform;
	}
}

//--------------------------------------------------------------------------------------
// Sets the parent to the passed in object.
//
// Param:
//		a: Sets the parent to the passed in object.
//--------------------------------------------------------------------------------------
void Entity::SetParent(Entity* a)
{
	m_Parent = a;
}

//--------------------------------------------------------------------------------------
// Pushes back the passed in object one spot back in the array to allow for adding for
// children.
//
// Param:
//		a: Pushes back the passed in object one spot in the array.
//--------------------------------------------------------------------------------------
void Entity::SetChild(Entity* a)
{
	//pushing back the child one spot in the array
	m_children.push_back(a);
}

void Entity::SetActive(bool a)
{
	m_bActive = a;
}

bool Entity::GetActive()
{
	return m_bActive;
}

//--------------------------------------------------------------------------------------
// Gets the position of the obejct.
//
// Return:
//		Returns the position of the object (its vector x and y values).
//--------------------------------------------------------------------------------------
Vector2 Entity::GetPosition()
{
	return Vector2(globalTransform.GetPos().x, globalTransform.GetPos().y);
}

//--------------------------------------------------------------------------------------
// Returns the adress of m_Collider to report back what object is colliding.
// 
// Return:
//		Returns m_Collider.
//--------------------------------------------------------------------------------------
Collider& Entity::GetCollider()
{
	return m_Collider;
}

