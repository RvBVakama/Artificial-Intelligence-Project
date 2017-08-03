#pragma once
#include "BehaviourNode.h"
#include "Input.h"

using namespace aie;

class BehaviourButtonPressed : public BehaviourNode
{
public:
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{
		if (Input::getInstance()->isKeyDown(INPUT_KEY_G))
			return EBEHAVIOUR_SUCCESS;
		else
			return EBEHAVIOUR_FAILURE;
	}
};
