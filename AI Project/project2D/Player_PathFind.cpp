#include "Player_PathFind.h"
#include "AIStateMachine.h"
#include "statePathFind.h"
#include "Define.h"
#include "Renderer2D.h"
#include "GridNode.h"

Player_PathFind::Player_PathFind(int StartNode, int EndNode)
{
	nStartNode = StartNode;
	nEndNode = EndNode;

	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);

	m_pstatePathFind = new statePathFind();
	_ASSERT(m_pstatePathFind);

	// Registering all possible states
	m_pAIStateMachine->RegisterState(E_STATEPATHFIND, m_pstatePathFind);

	m_pAIStateMachine->PushState(E_STATEPATHFIND);
}

Player_PathFind::~Player_PathFind()
{
	delete m_pstatePathFind;
}

void Player_PathFind::Update(float deltaTime)
{
	m_pAIStateMachine->Update(this, deltaTime);
}

void Player_PathFind::Draw(Renderer2D * pRenderer2D)
{
	m_pAIStateMachine->Draw(pRenderer2D);

	//Draw Player
	pRenderer2D->setRenderColour(0x32CD32FF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 25, 25);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
