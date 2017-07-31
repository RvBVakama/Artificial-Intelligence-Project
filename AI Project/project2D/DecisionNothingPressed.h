#pragma once
#include "BaseDecision.h"

class DecisionNothingPressed : public BaseDecision
{
public:
	DecisionNothingPressed();
	virtual ~DecisionNothingPressed();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

};

