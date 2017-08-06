#include "statePathFind.h"
#include "behaviourPatrol.h"
#include "Agent.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
statePathFind::statePathFind()
{
	m_behaviourPatrol = new behaviourPatrol;
	_ASSERT(m_behaviourPatrol);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
statePathFind::~statePathFind()
{
	delete m_behaviourPatrol;
}

//--------------------------------------------------------------------------------------
// Optional function to run.
//--------------------------------------------------------------------------------------
void statePathFind::OnEnter()
{
}

//--------------------------------------------------------------------------------------
// Calculating the force the player needs to move along the path set by AStar and then 
// updating the player's velocity to match.
//
// Param:
//		pAgent: A pointer to the agent so we can get and set the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void statePathFind::OnUpdate(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Force = m_behaviourPatrol->Calculate(pAgent, fDeltaTime);
	pAgent->SetPosition(pAgent->GetPosition() + v2Force);
}

//--------------------------------------------------------------------------------------
// Draws the path that the AStar pathfinding calulated.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void statePathFind::OnDraw(Renderer2D * renderer2d)
{
	m_behaviourPatrol->OnDraw(renderer2d);
}

//--------------------------------------------------------------------------------------
// Optional function to run.
//--------------------------------------------------------------------------------------
void statePathFind::OnExit()
{
}
