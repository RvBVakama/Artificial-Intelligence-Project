//--------------------------------------------------------------------------------------
// Class for Player_PathFind
//--------------------------------------------------------------------------------------
#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>
#include "AStarNode.h"

using namespace aie;

class AIStateMachine;
class statePathFind;

//--------------------------------------------------------------------------------------
// Player_PathFind object
// The the player that handles pathfinding using AStar
//--------------------------------------------------------------------------------------
class Player_PathFind : public Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Creating states and pushing the first state.
	//--------------------------------------------------------------------------------------
	Player_PathFind(int StartNode, int EndNode);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player_PathFind();

	//--------------------------------------------------------------------------------------
	// Updating the current state.
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Drawing the current state.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* pRenderer2D);
	
private:
	vector<AStarNode*> m_path;

	AIStateMachine*		m_pAIStateMachine;
	statePathFind*		m_pstatePathFind;
};
