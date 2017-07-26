#pragma once
#include "Vector2.h"

class Agent;

class IBehaviour
{
public:
	IBehaviour();
	IBehaviour(float fWeighting);
	~IBehaviour();

	//Update Function
	virtual Vector2 Calculate(Agent* pAgent, float fDeltaTime) = 0;

	float m_fWeighting;
};
