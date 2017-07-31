#pragma once
#include "BaseDecision.h"

class DecisionIdle : public BaseDecision
{
public:
	DecisionIdle();
	virtual ~DecisionIdle();

	void MakeDecision(Agent* pAgent, float fDeltaTime);
};
