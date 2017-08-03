#pragma once
#include "BehaviourNode.h"

class ActionSeek : public BehaviourNode
{
public:
	ActionSeek();
	virtual ~ActionSeek();

	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime);
};
