#include "DecisionWander.h"
#include "behaviourWander.h"
#include "Agent.h"

DecisionWander::DecisionWander()
{
	m_pBehaviourWander = new behaviourWander(1.0f);
}

DecisionWander::~DecisionWander()
{
	delete m_pBehaviourWander;
}

void DecisionWander::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Force = m_pBehaviourWander->Calculate(pAgent, fDeltaTime);

	Vector2 v2Velocity = pAgent->GetVelocity();
	v2Velocity = v2Velocity + v2Force * 10.0f * fDeltaTime;
	
	if (v2Velocity.Magnitude() > 60.0f)
	{
		v2Velocity.Normalise();
		v2Velocity = v2Velocity * 60.02;
	}

	pAgent->SetPosition(pAgent->GetPosition() + v2Velocity * fDeltaTime);
	pAgent->SetVelocity(v2Velocity);
}
