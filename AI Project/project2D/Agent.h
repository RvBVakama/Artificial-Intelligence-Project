#pragma once
#include "IBehaviour.h"
#include "Renderer2D.h"
#include "Vector2.h"
#include <vector>

using namespace aie;

class stateAgent;

class Agent
{
public:
	Agent();

	virtual ~Agent();

	virtual void Update(float deltaTime) = 0;
	virtual void Draw(Renderer2D* pRenderer2D) = 0;

	Vector2 GetPosition() { return m_v2Pos; }
	void SetPosition(Vector2 v2Pos) { m_v2Pos = v2Pos; }

protected:
	std::vector<IBehaviour *> m_behaviours;

	stateAgent* m_pStateAgent;

	Vector2 m_v2Pos;
	Vector2 m_v2Velocity;
	Vector2 m_force;
	Vector2 m_acceleration;
	
	Renderer2D* m_pRenderer;

	//texture maybs?
};
