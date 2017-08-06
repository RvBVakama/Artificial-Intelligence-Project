#include "behaviourPatrol.h"
#include "Grid.h"
#include "Agent.h"
#include "Player_PathFind.h"
#include "Define.h"

//----------------------------------------------------------------------------------------
// A heuritic that allows for AStar to plot a path on diagonals aswell as straights.
//----------------------------------------------------------------------------------------
int DiagonalHeurisitic(AStarNode* pNode, AStarNode* pEnd)
{
	//Diagonal Shortcut Method
	int difX = ((GridNode*)pNode)->m_nIndexX - ((GridNode*)pEnd)->m_nIndexX;
	int difY = ((GridNode*)pNode)->m_nIndexY - ((GridNode*)pEnd)->m_nIndexY;

	difX = abs(difX);
	difY = abs(difY);

	if (difX > difY)
		return (DIAGONAL_COST * difY) + ADJACENT_COST * (difX - difY);
	else
		return (DIAGONAL_COST * difX) + ADJACENT_COST * (difY - difX);
}

//----------------------------------------------------------------------------------------
// Default Constructor // Creates a grid, sets the heurisitic and sets the next node to 0.
//----------------------------------------------------------------------------------------
behaviourPatrol::behaviourPatrol()
{
	//Setup AStar
	m_pAStar = new AStar(GRID_SIZE * GRID_SIZE);

	m_pAStar->SetHeuristic(&DiagonalHeurisitic);

	m_nNextNode = 0;
}

//----------------------------------------------------------------------------------------
// Default Destructor // Deletes the instance of AStar.
//----------------------------------------------------------------------------------------
behaviourPatrol::~behaviourPatrol()
{
	delete m_pAStar;
}

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
Vector2 behaviourPatrol::Calculate(Agent* pAgent, float deltaTime)
{
	m_path.clear();

	Grid* pGrid = Grid::getInstance();

	m_pAStar->CalculatePath(pGrid->GetNode(pAgent->nStartNode), pGrid->GetNode(pAgent->nEndNode), &m_path);
	
	Vector2 dest = ((GridNode*)m_path[m_nNextNode])->m_v2Pos;
	Vector2 dist = dest - pAgent->GetPosition();
	float fDist = dist.Magnitude();

	if (fDist < 10)
	{
		++m_nNextNode;
	}
	
	if (m_nNextNode >= m_path.size())
	{
		m_nNextNode = 0;
	}

	Vector2 dir = dest - pAgent->GetPosition();
	dir.Normalise();

	return dir * 200.0f * deltaTime;
}

//--------------------------------------------------------------------------------------
// Draws the path that the AStar pathfinding calulated.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void behaviourPatrol::OnDraw(Renderer2D* pRenderer2D)
{
	// Draw Path
	for (size_t i = 0; i < m_path.size(); ++i)
	{
		GridNode* pNode = (GridNode*)m_path[i];

		pRenderer2D->setRenderColour(0x207068FF);
		pRenderer2D->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 0.9f, NODE_SIZE / 0.9f, 0, 99);
		pRenderer2D->setRenderColour(0xFFFFFFFF);
	}
}
