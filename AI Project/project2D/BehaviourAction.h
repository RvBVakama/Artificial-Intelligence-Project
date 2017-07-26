#pragma once
#include "BehaviourNode.h"
#include <iostream>

class BehaviourAction : public BehaviourNode
{
public:
	BehaviourAction(char* text)
	{
		m_szText = text;
	}

	EBehaviourResult Execute()
	{
		std::cout << "Action Success" << std::endl;
		return EBEHAVIOUR_SUCCESS;
	}

	char* m_szText;
};