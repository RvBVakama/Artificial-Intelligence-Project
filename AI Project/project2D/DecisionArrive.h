#pragma once
#include "BaseDecision.h"

class DecisionArrive : public BaseDecision
{
public:
	DecisionArrive();
	virtual ~DecisionArrive();

	void MakeDecision(Agent* pAgent, float fDeltaTime);
};
