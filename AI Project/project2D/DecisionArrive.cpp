#include "DecisionArrive.h"
#include "behaviourArrive.h"
#include "FleeBehaviour.h"
#include "Agent.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor // Weighting between 2 behaviours.
//--------------------------------------------------------------------------------------
DecisionArrive::DecisionArrive()
{
	m_BehaviourList.push_back(new behaviourArrive(0.50f));
	m_BehaviourList.push_back(new FleeBehaviour(0.50f));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionArrive::~DecisionArrive()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
	//help //cannot step out of function, creating memory leaks.
}

//--------------------------------------------------------------------------------------
// Changes the amount of weighting on each behaviour if keys are pressed. Then updates.
//
// Param:
//		pAgent: A pointer to the agent so we can get and set the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void DecisionArrive::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_F))
	{
		m_BehaviourList[0]->m_fWeighting += 0.01f;
		m_BehaviourList[1]->m_fWeighting -= 0.01f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_H))
	{
		m_BehaviourList[0]->m_fWeighting -= 0.01f;
		m_BehaviourList[1]->m_fWeighting += 0.01f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_F) && Input::getInstance()->isKeyDown(INPUT_KEY_H))
	{
		m_BehaviourList[0]->m_fWeighting = 0.50f;
		m_BehaviourList[1]->m_fWeighting = 0.50f;
	}

	Vector2 v2Velocity = pAgent->GetVelocity();

	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		Vector2 v2Force = m_BehaviourList[i]->Calculate(pAgent, fDeltaTime);
		v2Force = v2Force * m_BehaviourList[i]->m_fWeighting;

		v2Velocity = v2Velocity + v2Force * 10.0f * fDeltaTime;

		if (v2Velocity.Magnitude() > 100.0f)
		{
			v2Velocity.Normalise();
			v2Velocity = v2Velocity * 100.0f;
			break;
		}
	}
	pAgent->SetPosition(pAgent->GetPosition() + v2Velocity * fDeltaTime);
	pAgent->SetVelocity(v2Velocity);
}
