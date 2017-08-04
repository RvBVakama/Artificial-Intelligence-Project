#include "ActionSeek.h"
#include "SeekBehaviour.h"
#include "obstacleAvoidanceBehaviour.h"
#include "Agent.h"

ActionSeek::ActionSeek()
{
	m_BehaviourList.push_back(new SeekBehaviour(100.00f));
	m_BehaviourList.push_back(new obstacleAvoidanceBehaviour(1000.0f));
}

ActionSeek::~ActionSeek()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

EBehaviourResult ActionSeek::Execute(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Velocity = pAgent->GetVelocity();

	Vector2 v2TotalForce;
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		Vector2 v2Force = m_BehaviourList[i]->Calculate(pAgent, fDeltaTime);
		v2TotalForce = v2TotalForce + v2Force * m_BehaviourList[i]->m_fWeighting;

		if (v2TotalForce.Magnitude() > 500.0f)
		{
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 500.0f;
			break;
		}
	}

	v2Velocity = v2Velocity + v2TotalForce * 15.0f * fDeltaTime;
	if (v2Velocity.Magnitude() > 50.0f)
	{
		v2Velocity.Normalise();
		v2Velocity = v2Velocity * 50.0f;
	}

	pAgent->SetPosition(pAgent->GetPosition() + v2Velocity * fDeltaTime);
	pAgent->SetVelocity(v2Velocity);

	return EBEHAVIOUR_SUCCESS;
}
