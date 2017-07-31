#pragma once
#include "DecisionQuestion.h"

class DecisionTree
{
public:
	DecisionTree();
	~DecisionTree();

	void Update(Agent* pAgent, float fDeltaTime);
	
private:
	DecisionQuestion* m_pRoot;
};
