//-------------------------------------------------------------------------------------------------
// Class for the StateMachine
//-------------------------------------------------------------------------------------------------
#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
#include "Stack.h"

using namespace aie;

//-------------------------------------------------------------------------------------------------
// StateMachine object
// Handles pushing, updating, registering, poping and drawing states commonly used for menu systems
//-------------------------------------------------------------------------------------------------
class StateMachine
{
public:

	//---------------------------------------------------------------------------------------
	// Default Constructor, sets the bool that controls rendering of lower states to false.
	//---------------------------------------------------------------------------------------
	StateMachine();

	//---------------------------------------------------------------------------------------
	// Default Destructor // Clears the statelist thus releasing all the ram from the states.
	//---------------------------------------------------------------------------------------
	~StateMachine();

	//---------------------------------------------------------------------------------------
	// Updates the statelist and the stack and updates the top state in the stack.
	//
	// Param:
	//		deltaTime: Used to keep time, passed into the stack's top update funtion.
	// Return:
	//		Returns SUCCESS if the function ran correctly, asserts and returns
	//		STATELIST_NEGATIVE_SIZE if the function failed to execute correctly.
	//---------------------------------------------------------------------------------------
	int Update(float fDetaTime);

	//---------------------------------------------------------------------------------------
	// Draws the statelist and the stack and draws the top state in the stack.
	//
	// Param:
	//		m_2dRenderer: Allows textures to render.
	// Return:
	//		Returns SUCCESS if the function ran correctly, asserts and returns
	//		STATELIST_NEGATIVE_SIZE if the function failed to execute correctly.
	//---------------------------------------------------------------------------------------
	int Draw(Renderer2D* m_2dRenderer);

	//---------------------------------------------------------------------------------------
	// Draws the second top state in the statelist and the stack and draws the 
	// seconds top state in the stack.
	//
	// Param:
	//		m_2dRenderer: Allows textures to render.
	// Return:
	//		Returns SUCCESS if the function ran correctly, asserts and returns
	//		STATELIST_NEGATIVE_SIZE if the function failed to execute correctly.
	//---------------------------------------------------------------------------------------
	int Draw2ndFromTop(Renderer2D* m_2dRenderer);

	//---------------------------------------------------------------------------------------
	// Pushes the passed in state onto the top of the stack so that it becomes current state.
	//
	// Param:
	//		nStateIndex: The state to be pushed onto the top of the stack.
	// Return:
	//		Returns SUCCESS if the function ran correctly, asserts and returns
	//		INVALID_STATE if the function failed to execute correctly.
	//---------------------------------------------------------------------------------------
	int PushState(int nStateIndex);

	//---------------------------------------------------------------------------------------
	// Pushes the passed in state onto the top of the stack so that it becomes current state.
	//
	// Param:
	//		nStateIndex: The variable that is the state that you want to register to let 
	//					 the state machine use it.
	//		pState: The pointer to the state to be registered to be able to be used by 
	//				state machine.
	//---------------------------------------------------------------------------------------
	void RegisterState(int nStateIndex, BaseState* pState);
	
	//---------------------------------------------------------------------------------------
	// Pops of the top state on the stack allowing to traverse out of menu hierarchy.
	//---------------------------------------------------------------------------------------
	void PopState();

	bool bDrawLowerState;

private:
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_Stack;
};
