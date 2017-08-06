//--------------------------------------------------------------------------------------
// Class for the ActionSeekandAvoid
//--------------------------------------------------------------------------------------
#pragma once
#include "BehaviourNode.h"

//--------------------------------------------------------------------------------------
// ActionSeekandAvoid object
// Runs the seek and avoid behaviours weighted so they can work in unison.
//--------------------------------------------------------------------------------------
class ActionSeekandAvoid : public BehaviourNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Weighting between 2 behaviours
	//--------------------------------------------------------------------------------------
	ActionSeekandAvoid();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~ActionSeekandAvoid();

	//--------------------------------------------------------------------------------------
	// Based on the weighting this function makes the player seek and avoid collision zones.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime);
};
