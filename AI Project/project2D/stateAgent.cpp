#include "stateAgent.h"
#include "AIStateMachine.h"
#include "stateMovement.h"
#include "statePathFind.h"
#include "stateIdle.h"
#include "Define.h"
#include "Renderer2D.h"
#include "GridNode.h"

stateAgent::stateAgent()
{
//	m_v2Pos.x = 200.0f;
//	m_v2Pos.y = 200.0f;

	m_pAIStateMachine = new AIStateMachine();
	_ASSERT(m_pAIStateMachine);

	m_pstateMovement = new stateMovement();
	_ASSERT(m_pstateMovement);

	m_pstatePathFind = new statePathFind();
	_ASSERT(m_pstatePathFind);

	m_pStateIdle = new stateIdle();
	_ASSERT(m_pStateIdle);

	// Registering all possible states
	m_pAIStateMachine->RegisterState(E_STATEMOVEMENT, m_pstateMovement);
	m_pAIStateMachine->RegisterState(E_STATEPATHFIND, m_pstatePathFind);
	m_pAIStateMachine->RegisterState(E_STATEIDLE, m_pStateIdle);

	//m_pAIStateMachine->PushState(E_STATEMOVEMENT);
	m_pAIStateMachine->PushState(E_STATEPATHFIND);
}

stateAgent::~stateAgent()
{
	delete m_pStateIdle;
	delete m_pstatePathFind;
	delete m_pstateMovement;
	delete m_pAIStateMachine;
}

void stateAgent::Update(float deltaTime)
{
	m_pAIStateMachine->Update(this, deltaTime);
}

void stateAgent::Draw(Renderer2D* pRenderer2D)
{
	m_pAIStateMachine->Draw(pRenderer2D);

	//Draw Player
	pRenderer2D->setRenderColour(0xFF0080FF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
