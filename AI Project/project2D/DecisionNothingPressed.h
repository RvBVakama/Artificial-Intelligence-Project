#pragma once
#include "BaseDecision.h"

class DecisionNothingPressed : public BaseDecision
{
public:
	DecisionNothingPressed();
	virtual ~DecisionNothingPressed();

	void MakeDecision(Entity* pEntity, float fDeltaTime);

};

