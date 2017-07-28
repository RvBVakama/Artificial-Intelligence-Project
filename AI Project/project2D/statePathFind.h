#pragma once
#include "AIBaseState.h"

class behaviourPatrol;

class statePathFind : public AIBaseState
{
public:
	statePathFind();
	~statePathFind();

	void OnEnter();
	void OnUpdate(Agent* pAgent, float fDeltaTime);
	void OnDraw(Renderer2D* renderer2d);
	void OnExit();

private:
	behaviourPatrol* m_behaviourPatrol;
};
