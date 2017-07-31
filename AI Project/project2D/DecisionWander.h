#pragma once
#include "BaseDecision.h"

class behaviourWander;

class DecisionWander : public BaseDecision
{
public:
	DecisionWander();
	virtual ~DecisionWander();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	behaviourWander* m_pBehaviourWander;
};
