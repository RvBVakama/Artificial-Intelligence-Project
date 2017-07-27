#include "stateMovement.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "behaviourPatrol.h"
#include "Agent.h"

stateMovement::stateMovement()
{	
	//m_BehaviourList.push_back(new SeekBehaviour(0.0f));
	//m_BehaviourList.push_back(new FleeBehaviour(0.0f));
	//m_BehaviourList.push_back(new behaviourPatrol);
	m_behaviourPatrol = new behaviourPatrol;
	_ASSERT(m_behaviourPatrol);
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
//	Vector2 v2TotalForce;
//
//	//updates states and combines with weighting
//	Vector2 v2Force = m_BehaviourList[0]->Calculate(pAgent, fDeltaTime);
//
//	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
//	{
//		Vector2 currentForce = m_BehaviourList[i]->Calculate(pAgent, fDeltaTime);
//		currentForce = currentForce * m_BehaviourList[i]->m_fWeighting;
//		v2TotalForce = v2TotalForce + currentForce;
//
//		//limit total forces
//		float fMagnitude = v2TotalForce.Magnitude();
//		if (fMagnitude > 10.0f)
//		{
//			v2TotalForce.Normalise();
//			v2TotalForce = v2TotalForce * 10.0f;
//			break;
//		}
//
//		pAgent->SetPosition(pAgent->GetPosition() + v2TotalForce);
//	}

	m_behaviourPatrol->Calculate(pAgent, fDeltaTime);
}

void stateMovement::OnDraw(Renderer2D * renderer2d)
{
	m_behaviourPatrol->OnDraw(renderer2d);
}

void stateMovement::OnExit()
{
}
