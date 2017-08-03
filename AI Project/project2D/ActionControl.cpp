#include "ActionControl.h"
#include "behaviourWander.h"
#include "behaviourKeyboard.h"
#include "Agent.h"

ActionControl::ActionControl()
{
	m_BehaviourList.push_back(new behaviourKeyboard(380.0f));
	m_BehaviourList.push_back(new behaviourWander(500.00f));
}

ActionControl::~ActionControl()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

EBehaviourResult ActionControl::Execute(Agent * pAgent, float fDeltaTime)
{
	Vector2 v2Velocity = pAgent->GetVelocity();

	Vector2 v2TotalForce;
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		Vector2 v2Force = m_BehaviourList[i]->Calculate(pAgent, fDeltaTime);
		v2TotalForce = v2TotalForce + v2Force * m_BehaviourList[i]->m_fWeighting;

		if (v2TotalForce.Magnitude() > 1000.0f)
		{
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 1000.0f;
			break;
		}
	}

	v2Velocity = v2Velocity + v2TotalForce * 10.0f * fDeltaTime;
	if (v2Velocity.Magnitude() > 60.0f)
	{
		v2Velocity.Normalise();
		v2Velocity = v2Velocity * 60.0f;
	}

	pAgent->SetPosition(pAgent->GetPosition() + v2Velocity * fDeltaTime);
	pAgent->SetVelocity(v2Velocity);

	return EBEHAVIOUR_SUCCESS;
}
