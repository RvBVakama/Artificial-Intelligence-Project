#pragma once
#include "IBehaviour.h"
#include "AStar.h"
#include "GridNode.h"

class behaviourPatrol : public IBehaviour
{
public:
	behaviourPatrol();
	~behaviourPatrol();

	Vector2 Calculate(Agent* pAgent, float deltaTime);	

private:
	AStar*				m_pAStar;

	vector<AStarNode*> m_path;

	unsigned int m_nNextNode;
};
