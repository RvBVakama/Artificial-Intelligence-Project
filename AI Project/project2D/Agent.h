//---------------------------------------------------------------------------------------
// Class for the Agent
//---------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include <vector>

using namespace aie;

class Player_Mouse;
class Player_PathFind;

//---------------------------------------------------------------------------------------
// Agent object
// Base class definitions defines Vectors for position, velocity, acceleration and force.
//---------------------------------------------------------------------------------------
class Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Agent();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~Agent();

	//--------------------------------------------------------------------------------------
	// An update Method.
	//
	// Param:
	//		deltaTime: Time in seconds as a float so derived classes can keep time.
	//--------------------------------------------------------------------------------------
	virtual void Update(float deltaTime) = 0;

	//--------------------------------------------------------------------------------------
	// A draw method.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2d renderer so the derived classes can draw stuff
	//--------------------------------------------------------------------------------------
	virtual void Draw(Renderer2D* pRenderer2D) = 0;

	//--------------------------------------------------------------------------------------
	// Returns the players position.
	//
	// Return:
	//		Returns the players position.
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition() { return m_v2Pos; }

	//--------------------------------------------------------------------------------------
	// Returns the x position of the player.
	//
	// Return:
	//		Returns the x position of the player.
	//--------------------------------------------------------------------------------------
	float GetX() { return m_v2Pos.x; }

	//--------------------------------------------------------------------------------------
	// Returns the y position of the player.
	//
	// Return:
	//		Returns the y position of the player.
	//--------------------------------------------------------------------------------------
	float GetY() { return m_v2Pos.y; }

	//--------------------------------------------------------------------------------------
	// Sets the players positions to the passed in value.
	//
	// Param:
	//		v2Pos: The position vector to change the players location.
	//--------------------------------------------------------------------------------------
	void SetPosition(Vector2 v2Pos) { m_v2Pos = v2Pos; }

	//--------------------------------------------------------------------------------------
	// Returns the players current velocity.
	//
	// Return:
	//		Returns the players current velocity.
	//--------------------------------------------------------------------------------------
	Vector2 GetVelocity() { return m_v2Velocity; }

	//--------------------------------------------------------------------------------------
	// Sets the players velocity, seldomly used.
	//
	// Param:
	//		v2Vel: The velocity to be set.
	//--------------------------------------------------------------------------------------
	void SetVelocity(Vector2 v2Vel) { m_v2Velocity = v2Vel; }

	int nStartNode;
	int nEndNode;

protected:
	std::vector<IBehaviour *> m_behaviours;

	Vector2 m_v2Pos;
	Vector2 m_v2Velocity;
	Vector2 m_force;
	Vector2 m_acceleration;
	
	Renderer2D* m_pRenderer;
};
