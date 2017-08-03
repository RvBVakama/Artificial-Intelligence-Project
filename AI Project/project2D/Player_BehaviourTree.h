#pragma once
#include "Agent.h"
#include "Composite.h"

class BehaviourNode;

class Player_BehaviourTree : public Agent
{
public:
	Player_BehaviourTree();
	~Player_BehaviourTree();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);

private:
	BehaviourNode* m_pRoot;
};
