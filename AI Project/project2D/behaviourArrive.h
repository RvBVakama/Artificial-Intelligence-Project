//--------------------------------------------------------------------------------------
// Class for the lil nooter
//--------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"

class LilNooter;

//---------------------------------------------------------------------------------------
// behaviourArrive object // Inherits from IBehaviour
// Moves the player towards the target and slows based on distance from the obejct, the 
// closer the player to the target the slower the player moves until ultimately stopping.
//---------------------------------------------------------------------------------------
class behaviourArrive : public IBehaviour
{
public:

	//------------------------------------------------------------------------------------------------------
	// Alternative Constructor 
	// Creates an instance of LilNooter which is a baby penguin.
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object.
	//------------------------------------------------------------------------------------------------------
	behaviourArrive(float fWeighting);

	//------------------------------------------------------------------------------------------------------
	// Default Destructor // Deletes the LilNooter.
	//------------------------------------------------------------------------------------------------------
	~behaviourArrive();

	//------------------------------------------------------------------------------------------------------
	// Calculates the velocity needed to arrive at a target effectively.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position and velocity.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns v2Steering as a Vector2 which steers the player in the direction of the target.
	//------------------------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

private:
	LilNooter*			m_pLilNooter;
};
