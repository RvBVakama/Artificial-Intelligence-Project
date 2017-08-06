#include "IBehaviour.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
IBehaviour::IBehaviour()
{
}

//--------------------------------------------------------------------------------------
// Alternate Constructor
// 
// Param:
//		fWeighting: Weighting value to be used to afftect the returned velocity in the 
//					update funciton used.
//--------------------------------------------------------------------------------------
IBehaviour::IBehaviour(float fWeighting)
{
	m_fWeighting = fWeighting;
}

//--------------------------------------------------------------------------------------
// Default Destructor // 
//--------------------------------------------------------------------------------------
IBehaviour::~IBehaviour()
{
}

//--------------------------------------------------------------------------------------
// Does nothing, has to return Vector2 to prevent build errors
//
// Param:
//		pAgent: A pointer to the agent.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
Vector2 IBehaviour::Calculate(Agent * pAgent, float fDeltaTime)
{
	return Vector2();
}
