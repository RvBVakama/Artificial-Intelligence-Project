//--------------------------------------------------------------------------------------
// Class for the Application2D
//--------------------------------------------------------------------------------------
#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"

struct GridNode;
class AStar;
class StateMachine;
class Agent;
// Players
class Player_Mouse;
class Player_PathFind;
class DecisionAgent;
class Player_BehaviourTree;
// AIs
class LilNooter;
class Obstacle;

//--------------------------------------------------------------------------------------
// Application2D object
// Creates updates and draws all elements in the game/app.
//--------------------------------------------------------------------------------------
class Application2D : public aie::Application {
public:

	//---------------------------------------------------------------------------------
	// Default Constructor
	//---------------------------------------------------------------------------------
	Application2D();

	//---------------------------------------------------------------------------------
	// Default Destructor
	//---------------------------------------------------------------------------------
	virtual ~Application2D();

	//---------------------------------------------------------------------------------
	// Creates the renderer, collision manager, my resource manager and my state
	// manager then registers all possible states and pushes my spash screen state.
	// 
	// Return:
	// 		Returns true.
	//---------------------------------------------------------------------------------
	virtual bool startup();

	//---------------------------------------------------------------------------------
	// Deletes and destroys all managers, states etc... to prevent memory leaks.
	//---------------------------------------------------------------------------------
	virtual void shutdown();

	//---------------------------------------------------------------------------------
	// Updates the state machine and checks if the user has clicked the end key and
	// ends the game.
	// 
	// Param:
	// 		deltaTime: delta time simply is seconds as a float value. It is passed into 
	// the state machine's update function.
	//---------------------------------------------------------------------------------
	virtual void update(float deltaTime);

	//---------------------------------------------------------------------------------
	// Clears the screen then begins the 2d renderer then draws the state machine
	// by passing in the 2d renderer, finally ending the 2d renderer.
	//---------------------------------------------------------------------------------
	virtual void draw();

private:
	aie::Renderer2D*		m_2dRenderer;
	aie::Font*				m_font;
	aie::Audio*				m_audio;
	StateMachine*			m_pStateMachine;
	
	// Players
	Player_Mouse*			m_pPlayer_Mouse;
	Player_PathFind*		m_pPlayer_PathFindA;
	Player_PathFind*		m_pPlayer_PathFindB;
	DecisionAgent*			m_pDecisionAgent;
	LilNooter*				m_pLilNooter;
	Player_BehaviourTree*	m_pPlayer_BehaviourTree;
	Obstacle*				m_pObstacle;

	float m_cameraX, m_cameraY;
};
