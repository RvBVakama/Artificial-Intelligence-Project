//--------------------------------------------------------------------------------------
// Class for the obstacle avoidance behaviour
//--------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"
#include "circle.h"

class Agent;
class Obstacle;

//--------------------------------------------------------------------------------------
// Player object // Inherits from IBehaviour
// Stores data used by the player, handles rendering and input.
//--------------------------------------------------------------------------------------
class obstacleAvoidanceBehaviour : public IBehaviour
{
public:

	//------------------------------------------------------------------------------------------------------
	// Alternative Constructor 
	// Creates an array of circles which are used as collision objects.
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object.
	//------------------------------------------------------------------------------------------------------
	obstacleAvoidanceBehaviour(float fWeighting);

	//------------------------------------------------------------------------------------------------------
	// Default Destructor // Deletes the array of circles .
	//------------------------------------------------------------------------------------------------------
	~obstacleAvoidanceBehaviour();

	//------------------------------------------------------------------------------------------------------
	// Calculates the avoidance velocity needed to steer the player away from the circles.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position and velocity.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns v2Avoidance as a Vector2 which is the avoidance force needed to steer 
	//		the player away from the circles.
	//------------------------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

	//------------------------------------------------------------------------------------------------------
	// Works out when the player's antennas are in any circle and returns true or false.
	//
	// Param:
	//		v2Ahead: The longer antenna.
	//		v2Ahead2: The half length antenna.
	//		circle: A pointer to the circle object so we can get the center/ of the circle.
	// Return:
	//		Returns true or false, true if either antenna is in the circles radius, false if not.
	//------------------------------------------------------------------------------------------------------
	bool lineIntersectsCircle(Vector2 v2Ahead, Vector2 v2Ahead2, Circle* cirObstacle);

	//------------------------------------------------------------------------------------------------------
	// Finds the closest circle and returns it. This is done so the player only check the closest circle and 
	// does not waste resources always check all objects in the game / application.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position and velocity.
	// Return:
	//		Returns a pointer to the circle that is the closest to the player.
	//------------------------------------------------------------------------------------------------------
	Circle* findMostThreateningObstacle(Agent* pAgent);

private:
	Vector2					v2Ahead;
	Vector2					v2Ahead2;
	Circle**				m_ppCircle;
};
