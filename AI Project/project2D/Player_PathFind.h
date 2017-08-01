#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>
#include "AStarNode.h"

using namespace aie;

class AIStateMachine;
class statePathFind;

class Player_PathFind : public Agent
{
public:
	Player_PathFind(int StartNode, int EndNode);
	~Player_PathFind();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);
	
private:
	vector<AStarNode*> m_path;

	AIStateMachine*		m_pAIStateMachine;
	statePathFind*		m_pstatePathFind;
};
