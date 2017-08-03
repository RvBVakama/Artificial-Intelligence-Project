#pragma once
#include "BaseDecision.h"

class DecisionArrive : public BaseDecision
{
public:
	DecisionArrive();
	~DecisionArrive();

	void MakeDecision(Agent* pAgent, float fDeltaTime);
};
