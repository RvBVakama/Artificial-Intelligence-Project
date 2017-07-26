#pragma once

enum EBehaviourResult
{
	EBEHAVIOUR_FAILURE,
	EBEHAVIOUR_SUCCESS,
	EBEHAVIOUR_PENDING
};

class BehaviourNode
{
public:
	virtual EBehaviourResult Execute() = 0;
};

