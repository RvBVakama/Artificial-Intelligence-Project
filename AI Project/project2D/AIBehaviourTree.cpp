#include "AIBehaviourTree.h"
#include "BehaviourAction.h"
#include "BehaviourQuestion.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

AIBehaviourTree::AIBehaviourTree()
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

AIBehaviourTree::~AIBehaviourTree()
{
}

void AIBehaviourTree::Update(float deltaTime)
{
}
