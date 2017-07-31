#include "DecisionAgent.h"
//Decision Implementation
#include "DecisionTree.h"

DecisionAgent::DecisionAgent()
{
	m_v2Pos.x = 400.0f;
	m_v2Pos.y = 400.0f;

	//Decision Implementation
	m_pDecisionTree = new DecisionTree();
	_ASSERT(m_pDecisionTree);
}

DecisionAgent::~DecisionAgent()
{
	//Decision Implementation
	delete m_pDecisionTree;
}

void DecisionAgent::Update(float deltaTime)
{
	//Decision Implementation
	m_pDecisionTree->Update(this, deltaTime);
}

void DecisionAgent::Draw(Renderer2D * pRenderer2D)
{
	//Draw Player
	pRenderer2D->setRenderColour(0x207068FF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
