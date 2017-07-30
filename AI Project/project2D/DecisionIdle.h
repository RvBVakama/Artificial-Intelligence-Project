#pragma once
#include "BaseDecision.h"

class DecisionIdle : public BaseDecision
{
public:
	DecisionIdle();
	virtual ~DecisionIdle();

	void MakeDecision(Entity* pEntity, float fDeltaTime);
};
