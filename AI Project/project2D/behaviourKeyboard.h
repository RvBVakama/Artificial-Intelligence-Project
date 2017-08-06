#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// behaviourKeyboard object // Inherits from IBehaviour
// Moves the player left, right, up, down or in any diagonal based on defined keys.
//--------------------------------------------------------------------------------------
class behaviourKeyboard : public IBehaviour
{
public:

	//------------------------------------------------------------------------------------
	// Alternate Constructor 
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object.
	//------------------------------------------------------------------------------------
	behaviourKeyboard(float fWeighting);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~behaviourKeyboard();

	//--------------------------------------------------------------------------------------
	// Based on the user's input the player will move in the direction corresponding  to the
	// buttons pressed
	//
	// Param:
	//		pAgent: A pointer to the agent because the base class says so.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns v2Dir which is the velocity Vector2 that is applied ot the player.
	//--------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);
};
