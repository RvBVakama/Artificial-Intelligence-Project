#pragma once
#include "AIBaseState.h"

class StateMachine;

class stateIdle : public AIBaseState
{
public:
	stateIdle();
	~stateIdle();

	void OnEnter();
	void OnUpdate(Agent* pAgent, float fDeltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();
};

