#include "SeekBehaviourForBehaviourTree.h"
#include "SeekBehaviour.h"
#include "Agent.h"

SeekBehaviourForBehaviourTree::SeekBehaviourForBehaviourTree()
{
	m_pBehaviourSeek = new SeekBehaviour(1.0f);
}

SeekBehaviourForBehaviourTree::~SeekBehaviourForBehaviourTree()
{
	delete m_pBehaviourSeek;
}

void SeekBehaviourForBehaviourTree::MakeDecision(Agent * pAgent, float fDeltaTime)
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
