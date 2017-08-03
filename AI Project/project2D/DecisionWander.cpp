#include "DecisionWander.h"
#include "behaviourWander.h"
#include "SeekBehaviour.h"
#include "Agent.h"
#include "Input.h"

DecisionWander::DecisionWander()
{
	m_BehaviourList.push_back(new behaviourWander(500.00f));
	m_BehaviourList.push_back(new SeekBehaviour(60.00f));
}

DecisionWander::~DecisionWander()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

void DecisionWander::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_U))
	{
		m_BehaviourList[0]->m_fWeighting += 0.01f * 500.0f;
		m_BehaviourList[1]->m_fWeighting -= 0.01f * 60.0f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_O))
	{
		if (m_BehaviourList[0]->m_fWeighting > 0.0f)
			m_BehaviourList[0]->m_fWeighting -= 0.01f * 500.0f;
		m_BehaviourList[1]->m_fWeighting += 0.01f * 60.0f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_U) && Input::getInstance()->isKeyDown(INPUT_KEY_O))
	{
		m_BehaviourList[0]->m_fWeighting = 500.00f;
		m_BehaviourList[1]->m_fWeighting = 60.00f;
	}

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
}
