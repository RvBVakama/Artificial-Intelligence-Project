#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>

using namespace aie;

class AIStateMachine;
class stateMovement;
class stateIdle;
//Decision Implementation
class DecisionTree;

class DecisionAgent : public Agent
{
public:
	DecisionAgent();
	~DecisionAgent();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);

private:
	//Decision Implementation
	DecisionTree*		m_pDecisionTree;
};
