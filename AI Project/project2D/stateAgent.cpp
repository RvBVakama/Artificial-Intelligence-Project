#include "stateAgent.h"
#include "AIStateMachine.h"
#include "stateMovement.h"
#include "stateIdle.h"
#include "Define.h"
#include "Renderer2D.h"
#include "Renderer2D.h"
#include "GridNode.h"

stateAgent::stateAgent()
{
	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);

	m_pstateMovement = new stateMovement();
	_ASSERT(m_pstateMovement);

	m_pStateIdle = new stateIdle();
	_ASSERT(m_pStateIdle);

	// Registering all possible states
	m_pAIStateMachine->RegisterState(E_STATEMOVEMENT, m_pstateMovement);
	m_pAIStateMachine->RegisterState(E_STATEIDLE, m_pStateIdle);

	m_pAIStateMachine->PushState(E_STATEMOVEMENT);
}

stateAgent::~stateAgent()
{
	delete m_pAIStateMachine;
	delete m_pStateIdle;
	delete m_pstateMovement;
}

void stateAgent::Update(float deltaTime)
{
	m_pAIStateMachine->Update(this, deltaTime);
}

void stateAgent::Draw(Renderer2D* pRenderer2D)
{
	//Draw Path
	
	for (size_t i = 0; i < m_path.size(); ++i)
	{
		GridNode* pNode = (GridNode*)m_path[i];
	
		pRenderer2D->setRenderColour(0x00FF00FF);
		pRenderer2D->drawBox(pNode->m_v2Pos.x, pNode->m_v2Pos.y, NODE_SIZE / 0.9f, NODE_SIZE / 0.9f);
		pRenderer2D->setRenderColour(0xFFFFFFFF);
	}

	//Draw Player
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 30, 30);
}
