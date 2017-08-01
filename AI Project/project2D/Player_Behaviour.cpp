#include "Player_Behaviour.h"
#include "BehaviourAction.h"
#include "BehaviourQuestion.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

Player_Behaviour::Player_Behaviour()
{
	m_pRoot = new Selector();
	BehaviourNode* pFirst = new Sequence();

	//LHS
	BehaviourNode* pFirstFirst = new BehaviourQuestion();
	BehaviourNode* pFirstSecond = new BehaviourAction("Button Pressed");
	((Composite*)pFirst)->children.push_back(pFirstFirst);
	((Composite*)pFirst)->children.push_back(pFirstSecond);

	//RHS
	BehaviourNode* pSecond = new BehaviourAction("Button Not Pressed");

	((Composite*)pFirst)->children.push_back(pFirstFirst);
	((Composite*)pFirst)->children.push_back(pFirstSecond);
}

Player_Behaviour::~Player_Behaviour()
{
}

void Player_Behaviour::Update(float deltaTime)
{
	m_pRoot->Execute(this, deltaTime);
}

void Player_Behaviour::Draw(Renderer2D * pRenderer2D)
{
}
