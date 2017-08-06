//--------------------------------------------------------------------------------------
// Class for the BehaviourButtonPressed
//--------------------------------------------------------------------------------------
#pragma once
#include "BehaviourNode.h"
#include "Input.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// BehaviourButtonPressed object
// If a button is pressed SUCCESS is returned out and that tell the higher ups if this 
// function has ran.
//--------------------------------------------------------------------------------------
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
