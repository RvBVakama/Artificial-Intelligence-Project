#include "obstacleAvoidanceBehaviour.h"
#include "Agent.h"
#include "Define.h"
#include <math.h>
#include "Obstacle.h"

//------------------------------------------------------------------------------------------------------
// Alternative Constructor 
// Creates an array of circles which are used as collision objects.
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//------------------------------------------------------------------------------------------------------
obstacleAvoidanceBehaviour::obstacleAvoidanceBehaviour(float fWeighting) : IBehaviour(fWeighting)
{
	m_ppCircle = new Circle*[OBSTACLE_COUNT];
	_ASSERT(m_ppCircle);

	for (int i = 0; i < OBSTACLE_COUNT; ++i)
	{
		int f = (i * 10);
		m_ppCircle[i] = new Circle();
		m_ppCircle[i]->x = (int)345.0f + f;
		m_ppCircle[i]->y = (int)680.0f + f;
		m_ppCircle[i]->SetRadius(OBSTACLE_RADIUS);
	}
}

//------------------------------------------------------------------------------------------------------
// Default Destructor // Deletes the array of circles.
//------------------------------------------------------------------------------------------------------
obstacleAvoidanceBehaviour::~obstacleAvoidanceBehaviour()
{
	for (int i = 0; i < OBSTACLE_COUNT; ++i)
	{
		delete m_ppCircle[i];
	}

	delete m_ppCircle;
}

//------------------------------------------------------------------------------------------------------
// Calculates the avoidance velocity needed to steer the player away from the circles.
//
// Param:
//		pAgent: A pointer to the agent so we can get the players position and velocity.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns v2Avoidance as a Vector2 which is the avoidance force needed to steer 
//		the player away from the circles.
//------------------------------------------------------------------------------------------------------
Vector2 obstacleAvoidanceBehaviour::Calculate(Agent* pAgent, float fDeltaTime)
{
	v2Ahead = pAgent->GetPosition() + pAgent->GetVelocity().NormaliseReturn() * MAX_SEE_AHEAD;
	v2Ahead2 = pAgent->GetPosition() + pAgent->GetVelocity().NormaliseReturn() * MAX_SEE_AHEAD * 0.5f;

	//this should find the circle in front of the player with the vector lines ant antenna thingys
	Circle* mostThreatening = findMostThreateningObstacle(pAgent);
	Vector2 v2Avoidance;

	if (mostThreatening)
	{
		v2Avoidance.x = v2Ahead.x - mostThreatening->x;
		v2Avoidance.y = v2Ahead.y - mostThreatening->y;
				   
		v2Avoidance.Normalise();
		v2Avoidance.x *= MAX_AVOID_FORCE;
		v2Avoidance.y *= MAX_AVOID_FORCE;
	}
	else
	{
		v2Avoidance.x = 0.0f;
		v2Avoidance.y = 0.0f;
	}

	return v2Avoidance;
}

//------------------------------------------------------------------------------------------------------
// Works out when the player's antennas are in any circle and returns true or false.
//
// Param:
//		v2Ahead: The longer antenna.
//		v2Ahead2: The half length antenna.
//		circle: A pointer to the circle object so we can get the center/ of the circle.
// Return:
//		Returns true or false, true if either antenna is in the circles radius, false if not.
//------------------------------------------------------------------------------------------------------
bool obstacleAvoidanceBehaviour::lineIntersectsCircle(Vector2 v2Ahead, Vector2 v2Ahead2, Circle* circle)
{
	float fDist = v2Ahead.Distance(circle->GetCenter());
	
	float fDist2 = v2Ahead2.Distance(circle->GetCenter());

	return fDist <= circle->GetRadius() || fDist2 <= circle->GetRadius();
}

//------------------------------------------------------------------------------------------------------
// Finds the closest circle and returns it. This is done so the player only check the closest circle and 
// does not waste resources always check all objects in the game / application.
//
// Param:
//		pAgent: A pointer to the agent so we can get the players position and velocity.
// Return:
//		Returns a pointer to the circle that is the closest to the player.
//------------------------------------------------------------------------------------------------------
Circle* obstacleAvoidanceBehaviour::findMostThreateningObstacle(Agent* pAgent)
{
	Circle* mostThreatening = nullptr;

	Vector2 v2Dist1;
	Vector2 v2Dist2;

	for (int i = 0; i < OBSTACLE_COUNT; i++)
	{
		Circle* obstacle = m_ppCircle[i];
		bool bCollision = lineIntersectsCircle(v2Ahead, v2Ahead2, obstacle);

		if (bCollision && (mostThreatening == nullptr || pAgent->GetPosition().Distance(obstacle->GetCenter()) < pAgent->GetPosition().Distance(mostThreatening->GetCenter())))
			mostThreatening = obstacle;
	}

	return mostThreatening;
}