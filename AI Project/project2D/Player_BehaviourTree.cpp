#include "Player_BehaviourTree.h"
#include "BehaviourAction.h"
#include "BehaviourQuestion.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

Player_BehaviourTree::Player_BehaviourTree()
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

Player_BehaviourTree::~Player_BehaviourTree()
{
	delete m_pRoot;
}

void Player_BehaviourTree::Update(float deltaTime)
{
	m_pRoot->Execute(this, deltaTime);
}

void Player_BehaviourTree::Draw(Renderer2D * pRenderer2D)
{
	// Draw Player
	pRenderer2D->setRenderColour(0x70996CFF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
