//--------------------------------------------------------------------------------------
// Class for the statePathFind
//--------------------------------------------------------------------------------------
#pragma once
#include "AIBaseState.h"

class behaviourPatrol;

//--------------------------------------------------------------------------------------
// statePathFind object
// Base class definition of what all state classes should have.
//--------------------------------------------------------------------------------------
class statePathFind : public AIBaseState
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	statePathFind();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~statePathFind();

	//--------------------------------------------------------------------------------------
	// Optional function to run.
	//--------------------------------------------------------------------------------------
	void OnEnter();

	//--------------------------------------------------------------------------------------
	// Calculating the force the player needs to move along the path set by AStar and then 
	// updating the player's velocity to match.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void OnUpdate(Agent* pAgent, float fDeltaTime);

	//--------------------------------------------------------------------------------------
	// Draws the path that the AStar pathfinding calulated.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* renderer2d);

	//--------------------------------------------------------------------------------------
	// Optional function to run.
	//--------------------------------------------------------------------------------------
	void OnExit();

private:
	behaviourPatrol* m_behaviourPatrol;
};
