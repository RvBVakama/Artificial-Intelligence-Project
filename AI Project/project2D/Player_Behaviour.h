#pragma once
#include "Agent.h"

class BehaviourNode;

class Player_Behaviour : public Agent
{
public:
	Player_Behaviour();
	~Player_Behaviour();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);

private:
	BehaviourNode* m_pRoot;
};
