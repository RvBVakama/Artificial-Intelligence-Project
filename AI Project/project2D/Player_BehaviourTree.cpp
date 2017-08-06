#include "Player_BehaviourTree.h"
#include "ActionControl.h"
#include "ActionSeekandAvoid.h"
#include "BehaviourButtonPressed.h"
#include "Selector.h"
#include "Sequence.h"
#include "BehaviourNode.h"

//--------------------------------------------------------------------------------------
// Default Constructor // Using Selector as root and then Sequence below that.
//--------------------------------------------------------------------------------------
Player_BehaviourTree::Player_BehaviourTree()
{

	m_v2Pos.x = 200.0f;
	m_v2Pos.y = 250.0f;

	m_pRoot = new Selector();

	BehaviourNode* pFirst = new Sequence();

	//LHS
	BehaviourNode* pFirstFirst = new BehaviourButtonPressed();
	BehaviourNode* pFirstSecond = new ActionControl();
	((Composite*)pFirst)->children.push_back(pFirstFirst);
	((Composite*)pFirst)->children.push_back(pFirstSecond);

	//RHS
	BehaviourNode* pSecond = new ActionSeekandAvoid();
	((Composite*)m_pRoot)->children.push_back(pFirst);
	((Composite*)m_pRoot)->children.push_back(pSecond);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player_BehaviourTree::~Player_BehaviourTree()
{
	delete m_pRoot;
}

//--------------------------------------------------------------------------------------
// Executing the root's update.
//
// Param:
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void Player_BehaviourTree::Update(float deltaTime)
{
	m_pRoot->Execute(this, deltaTime);
}

//--------------------------------------------------------------------------------------
// Drawing the player.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void Player_BehaviourTree::Draw(Renderer2D* pRenderer2D)
{
	// Draw Player
	pRenderer2D->setRenderColour(0x70996CFF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20, 0.785398163399f, -1);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
