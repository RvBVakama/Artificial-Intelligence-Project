//--------------------------------------------------------------------------------------
// Class for the patrol behaviour, which really isn't a behaviour but I called it this 
// to match the naming convention I was going for.
//--------------------------------------------------------------------------------------
#pragma once
#include "IBehaviour.h"
#include "AStar.h"
#include "GridNode.h"
#include "Renderer2D.h"

using namespace aie;

class Player_PathFind;

//--------------------------------------------------------------------------------------
// behaviourPatrol object // Inherits from IBehaviour
// Moves the player along the path that AStar finds.
//--------------------------------------------------------------------------------------
class behaviourPatrol : public IBehaviour
{
public:

	//----------------------------------------------------------------------------------------
	// Default Constructor // Creates a grid, sets the heurisitic and sets the next node to 0.
	//----------------------------------------------------------------------------------------
	behaviourPatrol();

	//----------------------------------------------------------------------------------------
	// Default Destructor // Deletes the instance of AStar.
	//----------------------------------------------------------------------------------------
	~behaviourPatrol();
	
	//--------------------------------------------------------------------------------------
	// Moves the player along the AStar path by setting the velocity of the player 
	// based on the path.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the 
	//				player's start node, end node and position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns the wander velocity force to be applied to the player, as a Vector2.
	//--------------------------------------------------------------------------------------
	Vector2 Calculate(Agent* pAgent, float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draws the path that the AStar pathfinding calulated.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* pRenderer2D);

private:
	AStar*				m_pAStar;
	vector<AStarNode*>	m_path;
	Player_PathFind*	m_pPlayer_PathFind;

	unsigned int m_nNextNode;
};
