#pragma once
#include <vector>

class Agent;
class IBehaviour;

using namespace std;

enum EBehaviourResult
{
	EBEHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

class BehaviourNode
{
public:
	virtual EBehaviourResult Execute(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
