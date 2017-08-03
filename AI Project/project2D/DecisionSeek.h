#pragma once
#include "BaseDecision.h"

class SeekBehaviour;

class DecisionSeek : public BaseDecision
{
public:
	DecisionSeek();
	virtual ~DecisionSeek();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	SeekBehaviour* m_pBehaviourSeek;
};
