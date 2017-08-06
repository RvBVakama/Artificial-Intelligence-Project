#include "Player_Mouse.h"
#include "AIStateMachine.h"
#include "stateMovement.h"
#include "stateIdle.h"
#include "Define.h"
#include "Renderer2D.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor // Creating states and pushing the first one.
//--------------------------------------------------------------------------------------
Player_Mouse::Player_Mouse()
{
	m_v2Pos.x = 400.0f;
	m_v2Pos.y = 400.0f;

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

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player_Mouse::~Player_Mouse()
{
	delete m_pStateIdle;
	delete m_pstateMovement;
	delete m_pAIStateMachine;
}

//--------------------------------------------------------------------------------------
// If the player presses and holds a defined key the current state will chagne.
//
// Param:
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void Player_Mouse::Update(float deltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_S))
	{
		m_pAIStateMachine->PushState(E_STATEIDLE);
	}

	else
	{
		m_pAIStateMachine->PushState(E_STATEMOVEMENT);
	}

	m_pAIStateMachine->Update(this, deltaTime);
}

//--------------------------------------------------------------------------------------
// Drawing the current state.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void Player_Mouse::Draw(Renderer2D* pRenderer2D)
{
	m_pAIStateMachine->Draw(pRenderer2D);

	// Draw Player
	pRenderer2D->setRenderColour(0xFF0080FF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 20, 20 ,0, 0);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
