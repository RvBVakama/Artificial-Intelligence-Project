#include "BaseDecision.h"
#pragma once

class SeekBehaviour;

class SeekBehaviourForBehaviourTree : public BaseDecision
{
public:
	SeekBehaviourForBehaviourTree();
	virtual ~SeekBehaviourForBehaviourTree();

	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	SeekBehaviour* m_pBehaviourSeek;
};

