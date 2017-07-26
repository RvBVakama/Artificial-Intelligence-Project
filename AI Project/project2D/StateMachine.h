#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "BaseState.h"
#include "Stack.h"

using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	int Update(float fDetaTime);
	int Draw(Renderer2D* m_2dRenderer);
	int Draw2ndFromTop(Renderer2D* m_2dRenderer);
	int PushState(int nStateIndex);
	void RegisterState(int nStateIndex, BaseState* pState);
	void PopState();
	bool bDrawLowerState;

private:
	DynamicArray<BaseState*> m_StateList;
	Stack<BaseState*> m_Stack;
};
