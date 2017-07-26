#include "CollisionManager.h"
#include "Collider.h"
#include <iostream>

//instance of an object
CollisionManager* CollisionManager::m_instance = nullptr;

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
CollisionManager::CollisionManager()
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
CollisionManager::~CollisionManager()
{
}

//--------------------------------------------------------------------------------------
// Returns m_instance to allow the game to continue with collisions.
// 
// Return:
//		Returns m_instance to allow the game to continue with collisions.
//--------------------------------------------------------------------------------------
CollisionManager* CollisionManager::GetInstance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// Checks if there is anything assigned m_instance and does not run code to add it to 
// the CollisionManager.
//--------------------------------------------------------------------------------------
void CollisionManager::Create()
{
	if (!m_instance)
		m_instance = new CollisionManager();
		_ASSERT(m_instance);
}

//--------------------------------------------------------------------------------------
// Deletes m_instance to clean up after the application is exited. 
//--------------------------------------------------------------------------------------
void CollisionManager::Destroy()
{
	delete m_instance;
}

//--------------------------------------------------------------------------------------
// Prints "Collision Manager Initialised" to console to let the debugger know it started 
//--------------------------------------------------------------------------------------
void CollisionManager::Print()
{
	std::cout << "Collision Manager Initialised" << std::endl;
}

//--------------------------------------------------------------------------------------
// Makes room for new objects to be stored in the STL vector array by pushing back the 
// current item.
//
// Param:
//		pObject: Pushes back the passed in object once in the STL vector array to make 
//				 room for more objects.
//--------------------------------------------------------------------------------------
void CollisionManager::AddObject(Entity* pObject)
{
	m_CollisionList.push_back(pObject);
}

//--------------------------------------------------------------------------------------
// Removes objects from the array.
// 
// Param:
//		pObject: Removes objects from the array by checking their location in the array
//				 and erasing them.
//--------------------------------------------------------------------------------------
void CollisionManager::RemoveObject(Entity* pObject)
{
	auto iter = std::find(m_CollisionList.begin(), m_CollisionList.end(), pObject);
	if (iter != m_CollisionList.end())
		m_CollisionList.erase(iter);
}

//--------------------------------------------------------------------------------------
// Handles collisions and what should happen.
// 
// Param:
//		pObject: Passes in a object and checks for collision.
//--------------------------------------------------------------------------------------
Entity* CollisionManager::TestCollision(Entity* pObject)
{
	//goes through the STL vector array and check collision for every obejct every frame
	for (int i = 0; i < (int)m_CollisionList.size(); i++)
	{
		if (pObject == m_CollisionList[i])
			continue;

		//Calculate AABB of our two objects
		Collider collider1 = pObject->GetCollider();
		collider1.m_TL = collider1.m_TL + pObject->GetPosition();
		collider1.m_BR = collider1.m_BR + pObject->GetPosition();

		Collider collider2 = m_CollisionList[i]->GetCollider();
		collider2.m_TL = collider2.m_TL + m_CollisionList[i]->GetPosition();
		collider2.m_BR = collider2.m_BR + m_CollisionList[i]->GetPosition();

		//Test if two AABBs are overlapping
		if (collider1.m_BR.x > collider2.m_TL.x &&
			collider1.m_BR.y > collider2.m_TL.y &&
			collider1.m_TL.x < collider2.m_BR.x &&
			collider1.m_TL.y < collider2.m_BR.y)
		{
			return m_CollisionList[i];
		}
	}

	return nullptr;
}

