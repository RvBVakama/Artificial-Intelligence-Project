#pragma once
#include "AIBaseState.h"

class statePatrol : public AIBaseState
{
public:
	statePatrol();
	~statePatrol();

	void OnEnter();
	void OnUpdate(Agent* pAgent, float fDeltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};
