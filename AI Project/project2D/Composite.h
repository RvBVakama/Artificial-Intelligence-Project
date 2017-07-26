#pragma once
#include "BehaviourNode.h"
#include <vector>

using namespace std;

class Composite : public BehaviourNode
{
public:
	virtual ~Composite()
	{
		for (unsigned int i = 0; i < children.size(); ++i)
		{
			delete children[i];
		}
	}
	vector<BehaviourNode*> children;
	BehaviourNode* pendingNode = nullptr;
};

