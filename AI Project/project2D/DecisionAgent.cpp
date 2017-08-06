#include "DecisionAgent.h"
#include "DecisionTree.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
DecisionAgent::DecisionAgent()
{
	m_v2Pos.x = 400.0f;
	m_v2Pos.y = 400.0f;

	m_pDecisionTree = new DecisionTree();
	_ASSERT(m_pDecisionTree);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionAgent::~DecisionAgent()
{
	delete m_pDecisionTree;
}

//--------------------------------------------------------------------------------------
// Updating the decision tree
//
// Param:
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void DecisionAgent::Update(float deltaTime)
{
	m_pDecisionTree->Update(this, deltaTime);
}

//--------------------------------------------------------------------------------------
// Drawing the player
//
// Param:
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void DecisionAgent::Draw(Renderer2D * pRenderer2D)
{
	// Draw Player // Grandpa Penguin Noot 
	// Body
	pRenderer2D->setRenderColour(0x5F115FFF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
	// Feet
	pRenderer2D->setRenderColour(0x000000FF);
	pRenderer2D->drawBox(m_v2Pos.x - 10, m_v2Pos.y, 5, 5, 0, 1);
	pRenderer2D->drawBox(m_v2Pos.x + 10, m_v2Pos.y, 5, 5, 0, 1);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
