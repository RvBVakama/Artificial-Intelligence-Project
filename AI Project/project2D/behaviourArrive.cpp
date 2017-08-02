#include "behaviourArrive.h"
#include "LilNooter.h"
#include "Define.h"

behaviourArrive::behaviourArrive(float fWeighting) : IBehaviour(fWeighting)
{
	m_pLilNooter = new LilNooter();
	_ASSERT(m_pLilNooter);
}

behaviourArrive::~behaviourArrive()
{
	delete m_pLilNooter;
}

Vector2 behaviourArrive::Calculate(Agent * pAgent, float fDeltaTime)
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
