#pragma once
#include "BehaviourNode.h"
#include "Input.h"

using namespace aie;

class BehaviourQuestion : public BehaviourNode
{
public:
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{
		if (Input::getInstance()->wasKeyPressed(INPUT_KEY_W))
			return EBEHAVIOUR_SUCCESS;
		else
			return EBEHAVIOUR_FAILURE;
	}
};
