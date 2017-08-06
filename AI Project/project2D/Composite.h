//--------------------------------------------------------------------------------------
// Class for Composite
//--------------------------------------------------------------------------------------
#pragma once
#include "BehaviourNode.h"
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------
// Composite object
// Creates a list of children which are behaviour nodes.
//--------------------------------------------------------------------------------------
class Composite : public BehaviourNode
{
public:
	Composite() {};
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
