#pragma once
#include "BehaviourNode.h"

class ActionControl : public BehaviourNode
{
public:
	ActionControl();
	virtual ~ActionControl();

	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime);
};
