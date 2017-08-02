#pragma once
#include "BaseDecision.h"

class behaviourArrive;

class DecisionArrive : public BaseDecision
{
public:
	DecisionArrive();
	virtual ~DecisionArrive();

	void MakeDecision(Agent* pAgent, float fDeltaTime);
	
private:
	//behaviourArrive* m_pBehaviourArrive;
};

