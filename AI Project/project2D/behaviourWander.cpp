#include "behaviourWander.h"
//#include "Input.h"
#include "Entity.h"
#include "Define.h"

//using namespace aie;

behaviourWander::behaviourWander(float fWeighting) : IBehaviour(fWeighting)
{
	fWanderAngle = 25.0f;
}

behaviourWander::~behaviourWander()
{
}

Vector2 behaviourWander::Calculate(Entity* pEntity, float fDeltaTime)
{
	// Circle center calculation
	Vector2* v2CircleCentre = new Vector2;
	v2CircleCentre->Normalise();
	*v2CircleCentre = *v2CircleCentre * CIRCLE_DISTANCE;
	
	// Displacement force calculation
	Vector2* v2Displacement = new Vector2(0, -1);
	*v2Displacement = *v2Displacement * CIRCLE_RADIUS;

	// Random vector direction angles
	SetAngle(*v2Displacement, fWanderAngle, 1.0f);

	// Change wander angle every frame just a bit so it never 
	// has the same value as the last frame
	fWanderAngle += rand() % 51;

	// Calculate and return the wander force
	Vector2 v2WanderForce;
	v2WanderForce = *v2CircleCentre + *v2Displacement;

	return v2WanderForce;
}

void behaviourWander::SetAngle(Vector2 v2, float value, float number)
{
	float fLength = v2.Magnitude();
	v2.x = 
	//https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624
}
