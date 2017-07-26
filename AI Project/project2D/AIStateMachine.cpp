#include "AIStateMachine.h"
#include <crtdbg.h>
#include "Define.h"

//---------------------------------------------------------------------------------------
// Default Constructor, sets the bool that controls rendering of lower states to false.
//---------------------------------------------------------------------------------------
AIStateMachine::AIStateMachine()
{
	bDrawLowerState = false;
}

//---------------------------------------------------------------------------------------
// Default Destructor / Clears the statelist thus releasing all the ram from the states.
//---------------------------------------------------------------------------------------
AIStateMachine::~AIStateMachine()
{
	//for (int i = 0; i < m_StateList.Size(); ++i)
	//{
	//	delete m_StateList[i];
	//}
	
	m_StateList.Clear();
}

//---------------------------------------------------------------------------------------
// Updates the statelist and the stack and updates the top state in the stack.
//
// Param:
//		deltaTime: Used to keep time, passed into the stack's top update funtion.
// Return:
//		Returns SUCCESS if the function ran correctly, asserts and returns
//		STATELIST_NEGATIVE_SIZE if the function failed to execute correctly.
//---------------------------------------------------------------------------------------
int AIStateMachine::Update(Agent* pAgent, float deltaTime)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return STATELIST_NEGATIVE_SIZE;

	m_CurrentState->OnUpdate(pAgent, deltaTime);

	return SUCCESS;
}

//---------------------------------------------------------------------------------------
// Draws the statelist and the stack and draws the top state in the stack.
//
// Param:
//		m_2dRenderer: Allows textures to render.
// Return:
//		Returns SUCCESS if the function ran correctly, asserts and returns
//		STATELIST_NEGATIVE_SIZE if the function failed to execute correctly.
//---------------------------------------------------------------------------------------
int AIStateMachine::Draw(Renderer2D * m_2dRenderer)
{
	_ASSERT(m_StateList.Size() >= 0);
	if (m_StateList.Size() < 0)
		return STATELIST_NEGATIVE_SIZE;

	m_CurrentState->OnDraw(m_2dRenderer);

	return SUCCESS;
}

//---------------------------------------------------------------------------------------
// Pushes the passed in state onto the top of the stack so that it becomes current state.
//
// Param:
//		nStateIndex: The state to be pushed onto the top of the stack.
// Return:
//		Returns SUCCESS if the function ran correctly, asserts and returns
//		INVALID_STATE if the function failed to execute correctly.
//---------------------------------------------------------------------------------------
int AIStateMachine::PushState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return INVALID_STATE;

	//if (m_CurrentState)
	//	m_CurrentState->OnExit();
	
	m_CurrentState = m_StateList[nStateIndex];

	m_CurrentState->OnEnter();

	return SUCCESS;
}

//---------------------------------------------------------------------------------------
// Pushes the passed in state onto the top of the stack so that it becomes current state.
//
// Param:
//		nStateIndex: The variable that is the state that you want to register to let 
//					 the state machine use it.
//		pState: The pointer to the state to be registered to be able to be used by 
//				state machine.
//---------------------------------------------------------------------------------------
void AIStateMachine::RegisterState(int nStateIndex, AIBaseState* pState)
{
	int nResult = m_StateList.Insert(nStateIndex, pState);
	_ASSERT(nResult == 0);
}

//---------------------------------------------------------------------------------------
// Pops of the top state on the stack allowing to traverse out of menu hierarchy.
//---------------------------------------------------------------------------------------
void AIStateMachine::PopState()
{
	m_CurrentState = nullptr;
}
