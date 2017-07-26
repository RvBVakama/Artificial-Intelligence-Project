#pragma once
#include "Vector2.h"
#include "IBehaviour.h"

class Agent;

class Seek : public IBehaviour
{
	Vector2* m_targetPos;

	virtual bool Update(Agent* agent, float deltaTime)
	{
		// TODO: apply seek force to agent
		return true;
	}
	
public:
	Seek();
	~Seek();
};

