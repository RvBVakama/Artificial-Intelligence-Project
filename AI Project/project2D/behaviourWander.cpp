#include "behaviourWander.h"
//#include "Input.h"
#include "Entity.h"
#include "Define.h"
#include <math.h>
#include "Agent.h"

//using namespace aie;

behaviourWander::behaviourWander(float fWeighting) : IBehaviour(fWeighting)
{
	fWanderAngle = 50.0f * 4;
}

behaviourWander::~behaviourWander()
{
}

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
	fWanderAngle += rand() % 10 * 4 - 4 * 4;

	// Calculate and return the wander force
	Vector2 v2WanderForce;
	v2WanderForce = v2CircleCentre + v2Displacement;

	return v2WanderForce;
}

Vector2 behaviourWander::SetAngle(Vector2 v2, float value)
{
	Vector2 v2Res;

	// HELP // matt I think has a different function for getting the
	// vector.length which included more than just magnitude
	float fLength = v2.Magnitude();
	v2Res.x = cosf(value) * fLength;
	v2Res.y = sinf(value) * fLength;

	return v2Res;
}
