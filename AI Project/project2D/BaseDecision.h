#pragma once
#include <vector>

using namespace std;

class Agent;
class IBehaviour;

class BaseDecision
{
public:
	BaseDecision() {}
	virtual ~BaseDecision() {}
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
