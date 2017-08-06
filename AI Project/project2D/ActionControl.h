//--------------------------------------------------------------------------------------
// Class for the ActionControl
//--------------------------------------------------------------------------------------
#pragma once
#include "BehaviourNode.h"

//--------------------------------------------------------------------------------------
// ActionControl object
// Weights the keyboard and wander behaviours aginst eachother so they can 
// work together or one or the other.
//--------------------------------------------------------------------------------------
class ActionControl : public BehaviourNode
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Weighting between 2 behaviours.
	//--------------------------------------------------------------------------------------
	ActionControl();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~ActionControl();

	//--------------------------------------------------------------------------------------
	// Performing calculation on the beahaviours and their weighting and returns SUCCESS. 
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	// Return:
	//		Returns EBEHAVIOUR_SUCCESS if the function ran.
	//--------------------------------------------------------------------------------------
	EBehaviourResult Execute(Agent* pAgent, float fDeltaTime);
};
