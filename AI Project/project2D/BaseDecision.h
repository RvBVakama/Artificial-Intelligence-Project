#pragma once
#include <vector>

using namespace std;

class Agent;
class IBehaviour;

class BaseDecision
{
public:
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
