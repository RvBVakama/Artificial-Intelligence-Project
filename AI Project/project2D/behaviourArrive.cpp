#include "behaviourArrive.h"
#include "LilNooter.h"
#include "Define.h"

//------------------------------------------------------------------------------------------------------
// Alternative Constructor 
// Creates an instance of LilNooter which is a baby penguin.
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//------------------------------------------------------------------------------------------------------
behaviourArrive::behaviourArrive(float fWeighting) : IBehaviour(fWeighting)
{
	m_pLilNooter = new LilNooter();
	_ASSERT(m_pLilNooter);
}

//------------------------------------------------------------------------------------------------------
// Default Destructor // Deletes the LilNooter.
//------------------------------------------------------------------------------------------------------
behaviourArrive::~behaviourArrive()
{
	delete m_pLilNooter;
}

//------------------------------------------------------------------------------------------------------
// Calculates the velocity needed to arrive at a target effectively.
//
// Param:
//		pAgent: A pointer to the agent so we can get the players position and velocity.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns v2Steering as a Vector2 which steers the player in the direction of the target.
//------------------------------------------------------------------------------------------------------
Vector2 behaviourArrive::Calculate(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Steering;

	Vector2 v2DesiredVel = m_pLilNooter->GetPosition() - pAgent->GetPosition();
	float fDist = v2DesiredVel.Magnitude();

	// Check to see if inside the circle or not to slow or not
	// Inside the slowing radius, slowing
	if (fDist < SLOWING_RADIUS)
		v2DesiredVel = v2DesiredVel.NormaliseReturn() * MAX_VELOCITY * (fDist / SLOWING_RADIUS);
	
	// Outside the circle, not slowing
	else
		v2DesiredVel = v2DesiredVel.NormaliseReturn() * MAX_VELOCITY;

	// Applying to the steering
	v2Steering = v2DesiredVel - pAgent->GetVelocity();
	return v2Steering;
}
