#pragma once

class Agent;

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
};
