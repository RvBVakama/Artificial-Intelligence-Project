//--------------------------------------------------------------------------------------
// Class for the BaseDecision
//--------------------------------------------------------------------------------------
#pragma once
#include <vector>

using namespace std;

class Agent;
class IBehaviour;

//--------------------------------------------------------------------------------------
// BaseDecision object
// Base class that defines the functions needed by decision classes.
//--------------------------------------------------------------------------------------
class BaseDecision
{
public:
	BaseDecision() {}
	virtual ~BaseDecision() {}
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
