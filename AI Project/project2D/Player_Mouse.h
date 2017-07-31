#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>

using namespace aie;

class AIStateMachine;
class stateMovement;
class stateIdle;

class Player_Mouse : public Agent
{
public:
	Player_Mouse();
	~Player_Mouse();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);

private:
	AIStateMachine*		m_pAIStateMachine;
	stateMovement*		m_pstateMovement;
	stateIdle*			m_pStateIdle;
};
