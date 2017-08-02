#pragma once
#include "AIBaseState.h"

class stateMovement : public AIBaseState
{
public:
	stateMovement();
	~stateMovement();

	void OnEnter();
	void OnUpdate(Agent* pAgent, float fDeltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};
