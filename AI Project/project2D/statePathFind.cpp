#include "statePathFind.h"
#include "behaviourPatrol.h"
#include "Agent.h"

statePathFind::statePathFind()
{
	m_behaviourPatrol = new behaviourPatrol;
	_ASSERT(m_behaviourPatrol);
}

statePathFind::~statePathFind()
{
	delete m_behaviourPatrol;
}

void statePathFind::OnEnter()
{
}

void statePathFind::OnUpdate(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Force = m_behaviourPatrol->Calculate(pAgent, fDeltaTime);
	pAgent->SetPosition(pAgent->GetPosition() + v2Force);
}

void statePathFind::OnDraw(Renderer2D * renderer2d)
{
	m_behaviourPatrol->OnDraw(renderer2d);
}

void statePathFind::OnExit()
{
}
