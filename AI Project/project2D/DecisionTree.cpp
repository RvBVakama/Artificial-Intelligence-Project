#include "DecisionTree.h"
#include "DecisionWander.h"
#include "DecisionButtonPressed.h"
//#include "DecisionPrint.h"
#include "DecisionIdle.h"
//#include "DecisionNothingPressed.h"

DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();
	//m_pRoot->m_pTrueDecision = new DecisionPrint();
	m_pRoot->m_pWanderDecision = new DecisionWander();
	//m_pRoot->m_pFalseDecision = new DecisionNothingPressed();
	m_pRoot->m_pIdleDecision = new DecisionIdle();
}

DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_pWanderDecision;
	//delete m_pRoot->m_pTrueDecision;
	delete m_pRoot->m_pIdleDecision;
	//delete m_pRoot->m_pFalseDecision;
	delete m_pRoot;
}

void DecisionTree::Update(Entity* pEntity, float fDeltaTime)
{
	m_pRoot->MakeDecision(pEntity, fDeltaTime);
}