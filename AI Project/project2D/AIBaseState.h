#pragma once
#include "Renderer2D.h"
#include <vector>

class Agent;
class IBehaviour;

using namespace aie;
using namespace std;


class AIBaseState
{
public:
	AIBaseState();
	~AIBaseState();

	virtual void OnEnter() = 0;
	virtual void OnUpdate(Agent* pAgent, float fDeltaTime) = 0;
	virtual void OnDraw(Renderer2D* renderer2d) = 0;
	virtual void OnExit() = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};