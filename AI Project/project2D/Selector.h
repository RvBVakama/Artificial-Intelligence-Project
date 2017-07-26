#pragma once
#include "Composite.h"

class Selector : public Composite
{
public:
	EBehaviourResult Execute()
	{
		BehaviourNode* child = pendingNode;
		unsigned int i = -1;

		if (!child)
			i = 0;

		for (; i < children.size(); ++i)
		{
			if (i >= 0)
			child = children[i];
		
			EBehaviourResult result = child->Execute();
			if (result == EBEHAVIOUR_SUCCESS)
				return EBEHAVIOUR_SUCCESS;

			if (result == EBEHAVIOUR_FAILURE)
				return EBEHAVIOUR_FAILURE;
		}

		for (unsigned int i = 0; i < children.size(); ++i)
		{
			if (children[i]->Execute() == EBEHAVIOUR_SUCCESS)
			{
				return EBEHAVIOUR_SUCCESS;
			}
		}

		return EBEHAVIOUR_FAILURE;
	}
};

