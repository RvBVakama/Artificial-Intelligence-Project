//--------------------------------------------------------------------------------------
// Class for Player_BehaviourTree
//--------------------------------------------------------------------------------------
#pragma once
#include "Agent.h"
#include "Composite.h"

class BehaviourNode;

//--------------------------------------------------------------------------------------
// Player_BehaviourTree object
// The the player that handles seeking and fleeing from the mouse cursor
//--------------------------------------------------------------------------------------
class Player_BehaviourTree : public Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Using Selector as root and then Sequence below that.
	//--------------------------------------------------------------------------------------
	Player_BehaviourTree();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player_BehaviourTree();

	//--------------------------------------------------------------------------------------
	// Executing the root's update.
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Drawing the player.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* pRenderer2D);

private:
	BehaviourNode* m_pRoot;
};
