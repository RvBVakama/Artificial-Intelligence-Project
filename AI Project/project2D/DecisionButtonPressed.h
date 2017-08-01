#pragma once
#include "DecisionQuestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:
	DecisionButtonPressed();
	virtual ~DecisionButtonPressed();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	bool toggle;
};

