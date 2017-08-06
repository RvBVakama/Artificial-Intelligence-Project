#include "DecisionSeek.h"
#include "SeekBehaviour.h"
#include "Agent.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
DecisionSeek::DecisionSeek()
{
	m_pBehaviourSeek = new SeekBehaviour(1.0f);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionSeek::~DecisionSeek()
{
	delete m_pBehaviourSeek;
}

//--------------------------------------------------------------------------------------
// Calculating the force the player needs to move along the path set by AStar and then 
// updating the player's velocity to match.
//
// Param:
//		pAgent: A pointer to the agent so we can get and set the player's position 
//				and velocity.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void DecisionSeek::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Force = m_pBehaviourSeek->Calculate(pAgent, fDeltaTime);

	Vector2 v2Velocity = pAgent->GetVelocity();
	v2Velocity = v2Velocity + v2Force * 10.0f * fDeltaTime;

	if (v2Velocity.Magnitude() > 60.0f)
	{
		v2Velocity.Normalise();
		v2Velocity = v2Velocity * 60.0f;
	}

	pAgent->SetPosition(pAgent->GetPosition() + v2Velocity * fDeltaTime);
	pAgent->SetVelocity(v2Velocity);
}
