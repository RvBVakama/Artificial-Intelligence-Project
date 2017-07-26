//--------------------------------------------------------------------------------------
// Class for the CollisionManager
//--------------------------------------------------------------------------------------
#pragma once

#include <vector>
#include "Entity.h"

//--------------------------------------------------------------------------------------
// CollisionManager object
// Handles collision and what should happen when it occurs.
//--------------------------------------------------------------------------------------
class CollisionManager
{
public:
	//--------------------------------------------------------------------------------------
	// Returns m_instance to allow the game to continue with collisions.
	// 
	// Return:
	//		Returns m_instance to allow the game to continue with collisions.
	//--------------------------------------------------------------------------------------
	static CollisionManager* GetInstance();

	//--------------------------------------------------------------------------------------
	// Checks if there is anything assigned m_instance and does not run code to add it to the CollisionManager.
	//--------------------------------------------------------------------------------------
	static void Create();

	//--------------------------------------------------------------------------------------
	// Deletes m_instance to clean up after the application is exited. 
	//--------------------------------------------------------------------------------------
	static void Destroy();

	//--------------------------------------------------------------------------------------
	// Prints "Collision Manager Initialised" to console to let the debugger know it started 
	//--------------------------------------------------------------------------------------
	void Print();

	//--------------------------------------------------------------------------------------
	// Makes room for new objects to be stored in the STL vector array by pushing back the current item.
	//
	// Param:
	//		pObject: Pushes back the passed in object once in the STL vector array to make room for more objects.
	//--------------------------------------------------------------------------------------
	void AddObject(Entity * pObject);

	//--------------------------------------------------------------------------------------
	// Removes objects from the array.
	// 
	// Param:
	//		pObject: Removes objects from the array by checking their location in the arrayand erasing them.
	//--------------------------------------------------------------------------------------
	void RemoveObject(Entity * pObject);

	//--------------------------------------------------------------------------------------
	// Handles collisions and what should happen.
	// 
	// Param:
	//		pObject: Passes in a object and checks for collision.
	//--------------------------------------------------------------------------------------
	Entity* TestCollision(Entity * pObject);

private:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	CollisionManager();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~CollisionManager();

	//instance of an object
	static CollisionManager* m_instance;

	//the STL vector array that stores all the objects that can collide
	std::vector<Entity*> m_CollisionList;
};

