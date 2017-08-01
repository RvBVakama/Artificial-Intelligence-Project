#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

struct GridNode;
class AStar;
class StateMachine;
class Agent;
class Player_Mouse;
class Player_PathFind;
class DecisionAgent;

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

private:
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Audio*			m_audio;
	StateMachine*		m_pStateMachine;
	Player_Mouse*		m_pPlayer_Mouse;
	Player_PathFind*	m_pPlayer_PathFindA;
	Player_PathFind*	m_pPlayer_PathFindB;
	DecisionAgent*		m_pDecisionAgent;
	
	float m_cameraX, m_cameraY;
};
