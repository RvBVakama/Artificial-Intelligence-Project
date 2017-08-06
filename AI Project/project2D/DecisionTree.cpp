#include "DecisionTree.h"
#include "DecisionWander.h"
#include "DecisionButtonPressed.h"
#include "DecisionArrive.h"
#include "DecisionSeek.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
DecisionTree::DecisionTree()
{
	m_pRoot = new DecisionButtonPressed();
	m_pRoot->m_pWanderDecision = new DecisionWander();
	m_pRoot->m_ArriveDecision = new DecisionArrive();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionTree::~DecisionTree()
{
	delete m_pRoot->m_ArriveDecision;
	delete m_pRoot->m_pWanderDecision;
	delete m_pRoot;
}
void DecisionTree::Update(Agent* pAgent, float fDeltaTime)
{
	m_pRoot->MakeDecision(pAgent, fDeltaTime);
}