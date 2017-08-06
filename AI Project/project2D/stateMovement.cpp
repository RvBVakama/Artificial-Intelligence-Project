#include "stateMovement.h"
#include "SeekBehaviour.h"
#include "FleeBehaviour.h"
#include "Agent.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor // Weighting 2 behaviours
//--------------------------------------------------------------------------------------
stateMovement::stateMovement()
{	
	m_BehaviourList.push_back(new SeekBehaviour(0.50f));
	m_BehaviourList.push_back(new FleeBehaviour(0.50f));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
stateMovement::~stateMovement()
{
	for (unsigned int i = 0; i < m_BehaviourList.size(); ++i)
	{
		delete m_BehaviourList[i];
	}
}

//--------------------------------------------------------------------------------------
// Optional function to run.
//--------------------------------------------------------------------------------------
void stateMovement::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Calculating the force the player needs to move towards or away from the mouse cursor
// using weighting.
//
// Param:
//		pAgent: A pointer to the agent so we can get and set the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void stateMovement::OnUpdate(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_Q))
	{
		m_BehaviourList[0]->m_fWeighting += 0.01f;
		m_BehaviourList[1]->m_fWeighting -= 0.01f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_E))
	{
		m_BehaviourList[0]->m_fWeighting -= 0.01f;
		m_BehaviourList[1]->m_fWeighting += 0.01f;
	}

	if (Input::getInstance()->isKeyDown(INPUT_KEY_Q) && Input::getInstance()->isKeyDown(INPUT_KEY_E))
	{
		m_BehaviourList[0]->m_fWeighting = 0.50f;
		m_BehaviourList[1]->m_fWeighting = 0.50f;
	}

	Vector2 v2TotalForce;

	//updates states and combines with weighting
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

	}
	pAgent->SetPosition(pAgent->GetPosition() + v2TotalForce);
}

//--------------------------------------------------------------------------------------
// Currently, nothing draws in this class.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void stateMovement::OnDraw(Renderer2D * renderer2d)
{
}

//--------------------------------------------------------------------------------------
// Optional function to run.
//--------------------------------------------------------------------------------------
void stateMovement::OnExit()
{
}
