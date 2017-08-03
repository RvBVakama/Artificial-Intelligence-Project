#pragma once
#include "BehaviourNode.h"

class ActionSeek : public BehaviourNode
{
public:
	ActionSeek();

	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{

		return EBEHAVIOUR_SUCCESS;
	}
};
