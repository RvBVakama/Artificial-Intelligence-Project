#pragma once
#include "DecisionQuestion.h"

class DecisionButtonPressed : public DecisionQuestion
{
public:
	DecisionButtonPressed();
	virtual ~DecisionButtonPressed();

	void MakeDecision(Entity* pEntity, float fDeltaTime);
};

