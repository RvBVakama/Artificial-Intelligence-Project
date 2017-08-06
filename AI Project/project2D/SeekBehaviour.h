//--------------------------------------------------------------------------------------
// Class for the Seek Behaviour
//--------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"

class Agent;

//--------------------------------------------------------------------------------------
// SeekBehaviour object // Inherits from IBehaviour
// Seeks the mouse cursor and applies that force to an object.
//--------------------------------------------------------------------------------------
class SeekBehaviour : public IBehaviour
{
public:

	//--------------------------------------------------------------------------------------
	// Alternative Constructor
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object
	//--------------------------------------------------------------------------------------
	SeekBehaviour(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~SeekBehaviour();

	//--------------------------------------------------------------------------------------
	// Steers the player in the direction of the mouse.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns the force velocity to be applied to the player, as a Vector2.
	//--------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);
};
