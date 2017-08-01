#pragma once
#include "Composite.h"

class Sequence : public Composite
{
public:
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime)
	{
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			if (children[i]->Execute(pAgent, fDeltaTime) == EBEHAVIOUR_FAILURE)
			{
				return EBEHAVIOUR_FAILURE;
			}
		}

		return EBEHAVIOUR_SUCCESS;
	}
};
