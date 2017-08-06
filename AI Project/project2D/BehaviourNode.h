//--------------------------------------------------------------------------------------
// Class for the EBehaviourResult
//--------------------------------------------------------------------------------------
#pragma once
#include <vector>

class Agent;
class IBehaviour;

using namespace std;

//--------------------------------------------------------------------------------------
// An enum list of the possible outcomes of the behaviour tree
//--------------------------------------------------------------------------------------
enum EBehaviourResult
{
	EBEHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

//--------------------------------------------------------------------------------------
// BehaviourNode object
// Based on conditions and selector or sequence methods the tree will 
// update the correct behaviour.
//--------------------------------------------------------------------------------------
class BehaviourNode
{
public:
	BehaviourNode() {};
	virtual ~BehaviourNode() {};
	virtual EBehaviourResult Execute(Agent* pAgent, float fDeltaTime) = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
