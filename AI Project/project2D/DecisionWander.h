#pragma once
#include "BaseDecision.h"

class behaviourWander;

class DecisionWander : public BaseDecision
{
public:
	DecisionWander();
	virtual ~DecisionWander();

	void MakeDecision(Entity* pEntity, float fDeltaTime);

private:
	behaviourWander* m_pBehaviourWander;
};
