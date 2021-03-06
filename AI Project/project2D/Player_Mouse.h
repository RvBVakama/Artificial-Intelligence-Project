//--------------------------------------------------------------------------------------
// Class for Player_Mouse
//--------------------------------------------------------------------------------------
#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>

using namespace aie;

class AIStateMachine;
class stateMovement;
class stateIdle;

//--------------------------------------------------------------------------------------
// Player_Mouse object
// The the player that handles seeking and fleeing from the mouse cursor
//--------------------------------------------------------------------------------------
class Player_Mouse : public Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Creating states and pushing the first one.
	//--------------------------------------------------------------------------------------
	Player_Mouse();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player_Mouse();

	//--------------------------------------------------------------------------------------
	// If the player presses and holds a defined key the current state will chagne.
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Drawing the current state.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* pRenderer2D);

private:
	AIStateMachine*		m_pAIStateMachine;
	stateMovement*		m_pstateMovement;
	stateIdle*			m_pStateIdle;
};
