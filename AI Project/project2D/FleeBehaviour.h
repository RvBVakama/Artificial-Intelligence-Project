#pragma once
#include "IBehaviour.h"

class Agent;

class FleeBehaviour : public IBehaviour
{
public:
	FleeBehaviour(float fWeighting);
	~FleeBehaviour();

	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

};
