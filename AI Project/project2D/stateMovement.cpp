#include "stateMovement.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "Agent.h"

stateMovement::stateMovement()
{
	m_BehaviourList.push_back(new SeekBehaviour(1.0f));
	m_BehaviourList.push_back(new FleeBehaviour(0.0f));
}

stateMovement::~stateMovement()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

void stateMovement::OnEnter()
{
}

void stateMovement::OnUpdate(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2TotalForce;

	//updates states and combines with wighting
	//Vector2 v2Force = m_BehaviourList[0]->Calculate(pAgent, fDeltaTime);

	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		Vector2 currentForce = m_BehaviourList[i]->Calculate(pAgent, fDeltaTime);
		currentForce = currentForce * m_BehaviourList[i]->m_fWeighting;

		v2TotalForce = v2TotalForce + currentForce;
		//limit total forces
		float fMagnitude = v2TotalForce.Magnitude();
		if (fMagnitude > 10.0f)
		{
			v2TotalForce.Normalise();
			v2TotalForce = v2TotalForce * 10.0f;
			break;
		}

		pAgent->SetPosition(pAgent->GetPosition() + v2TotalForce);
	}
}

void stateMovement::OnDraw(Renderer2D * renderer2d)
{
}

void stateMovement::OnExit()
{
}
