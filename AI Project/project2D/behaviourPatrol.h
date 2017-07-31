#pragma once
#include "IBehaviour.h"
#include "AStar.h"
#include "GridNode.h"
#include "Renderer2D.h"

using namespace aie;

class Player_PathFind;

class behaviourPatrol : public IBehaviour
{
public:
	behaviourPatrol();
	~behaviourPatrol();

	Vector2 Calculate(Agent* pAgent, float deltaTime);
	void OnDraw(Renderer2D* pRenderer2D);

private:
	AStar*				m_pAStar;
	vector<AStarNode*>	m_path;
	Player_PathFind*	m_pPlayer_PathFind;

	unsigned int m_nNextNode;
};
