#pragma once
#include "IBehaviour.h"

class Agent;

//--------------------------------------------------------------------------------------
// FleeBehaviour object // Inherits from IBehaviour
// Flees from the mouse.
//--------------------------------------------------------------------------------------
class FleeBehaviour : public IBehaviour
{
public:

	//--------------------------------------------------------------------------------------
	// Alternative Constructor 
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object.
	//--------------------------------------------------------------------------------------
	FleeBehaviour(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~FleeBehaviour();

	//--------------------------------------------------------------------------------------
	// Steers the player away from the mouse .
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns the force velocity to be applied to the player, as a Vector2.
	//--------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);
};
