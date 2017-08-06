//------------------------------------------------------------------------------------------------------
// Credit to the following resource, It helped a lot.
// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624
//------------------------------------------------------------------------------------------------------

#include "behaviourWander.h"
#include "Define.h"
#include "Agent.h"

//------------------------------------------------------------------------------------------------------
// Alternative Constructor 
// Sets a wander angle, this variable slightly changes the location of the seek vector on the circle
// that the player is moving towards
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//------------------------------------------------------------------------------------------------------
behaviourWander::behaviourWander(float fWeighting) : IBehaviour(fWeighting)
{
	fWanderAngle = 25.0f;
}

//------------------------------------------------------------------------------------------------------
// Default Destructor
//------------------------------------------------------------------------------------------------------
behaviourWander::~behaviourWander()
{
}

//--------------------------------------------------------------------------------------
// Steers the player in a random direction based on an imaginary circle
// that is CIRCLE_DISTANCE pixels in front of the player.
//
// Param:
//		pAgent: A pointer to the agent so we can get the players velocity.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns the wander velocity force to be applied to the player, as a Vector2.
//--------------------------------------------------------------------------------------
Vector2 behaviourWander::Calculate(Agent* pAgent, float fDeltaTime)
{
	// Circle center calculation
	Vector2 v2CircleCentre = pAgent->GetVelocity();
	v2CircleCentre.Normalise();
	v2CircleCentre = v2CircleCentre * CIRCLE_DISTANCE;
	
	// Displacement force calculation
	Vector2 v2Displacement(0, -1);
	v2Displacement = v2Displacement * CIRCLE_RADIUS;

	// Random vector direction angles
	v2Displacement = SetAngle(v2Displacement, fWanderAngle);

	// Change wander angle every frame just a bit so it never 
	// has the same value as the last frame
	fWanderAngle += rand() % 4 * 2 - 2 * 2;

	// Calculate and return the wander force
	Vector2 v2WanderForce;
	v2WanderForce = v2CircleCentre + v2Displacement;

	return v2WanderForce;
}

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
Vector2 behaviourWander::SetAngle(Vector2 vDisplacement, float fWanderAngle)
{
	Vector2 v2Res;
	
	float fLength = vDisplacement.Magnitude();
	v2Res.x = cosf(fWanderAngle) * fLength;
	v2Res.y = sinf(fWanderAngle) * fLength;

	return v2Res;
}
