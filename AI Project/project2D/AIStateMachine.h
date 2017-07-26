#pragma once
#include "Renderer2D.h"
#include "DynamicArray.h"
#include "AIBaseState.h"
#include "Stack.h"

using namespace aie;

class AIStateMachine
{
public:
	AIStateMachine();
	~AIStateMachine();

	int Update(Agent* pAgent, float fDetaTime);
	int Draw(Renderer2D* m_2dRenderer);
	int PushState(int nStateIndex);
	void RegisterState(int nStateIndex, AIBaseState* pState);
	void PopState();
	bool bDrawLowerState;

private:
	DynamicArray<AIBaseState*> m_StateList;
	AIBaseState* m_CurrentState;
};
