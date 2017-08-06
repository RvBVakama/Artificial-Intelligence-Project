//--------------------------------------------------------------------------------------
// Class for the wander behaviour
//--------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// behaviourWander object // Inherits from IBehaviour
// Wanders around aimlessly.
//--------------------------------------------------------------------------------------
class behaviourWander : public IBehaviour
{
public:

	//------------------------------------------------------------------------------------------------------
	// Alternative Constructor 
	// Sets a wander angle, this variable slightly changes the location of the seek vector on the circle
	// that the player is moving towards
	//
	// Param:
	//		fWeighting: Used to change the amount of force to apply to the velocity of the 
	//					target object.
	//------------------------------------------------------------------------------------------------------
	behaviourWander(float fWeighting);

	//------------------------------------------------------------------------------------------------------
	// Default Destructor
	//------------------------------------------------------------------------------------------------------
	~behaviourWander();

	//--------------------------------------------------------------------------------------
	// Steers the player in a random direction based on an imaginary circle
	// that is CIRCLE_DISTANCE pixels in front of the player.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns the wander velocity force to be applied to the player, as a Vector2.
	//--------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

private:
	//--------------------------------------------------------------------------------------
	// Sets the angle of the wander direction based on a passed in displacement Vector2
	// and a wander angle float value.
	//
	// Param:
	//		vDisplacement: A Vector2 displacement value that varies the direction of the 
	//					seek point.
	//		fWanderAngle: Wander angle to give some jitter variation.
	// Return:
	//		Returns the result of the cos and sin equations on the wander angle and
	//		length of the displacement.
	//--------------------------------------------------------------------------------------
	Vector2 SetAngle(Vector2 v2, float value);

	float fWanderAngle;
};
