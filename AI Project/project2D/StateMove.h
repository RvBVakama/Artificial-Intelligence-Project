#pragma once
#include "AIBaseState.h"

class Agent;

class StateMove : public AIBaseState
{
public:
	StateMove();
	~StateMove();

	void OnUpdate(Agent* pAgent, float fDeltaTime);
};
