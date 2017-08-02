#include "DecisionArrive.h"
#include "behaviourArrive.h"
#include "Agent.h"

DecisionArrive::DecisionArrive()
{
	m_pBehaviourArrive = new behaviourArrive(1.0f);
}

DecisionArrive::~DecisionArrive()
{
	delete m_pBehaviourArrive;
}

void DecisionArrive::MakeDecision(Agent * pAgent, float fDeltaTime)
{
	Vector2 v2Force = m_pBehaviourArrive->Calculate(pAgent, fDeltaTime);

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
