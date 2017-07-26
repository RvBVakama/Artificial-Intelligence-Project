#pragma once
#include "BehaviourNode.h"
#include "Input.h"

using namespace aie;

class BehaviourQuestion : public BehaviourNode
{
public:
	EBehaviourResult Execute()
	{
		if (Input::getInstance()->wasKeyPressed(INPUT_KEY_Q))
			return EBEHAVIOUR_SUCCESS;
		else
			return EBEHAVIOUR_FAILURE;
	}
};
