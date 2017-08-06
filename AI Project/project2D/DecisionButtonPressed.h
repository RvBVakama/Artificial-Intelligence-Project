//--------------------------------------------------------------------------------------
// Class for DecisionButtonPressed
//--------------------------------------------------------------------------------------
#pragma once
#include "DecisionQuestion.h"

//--------------------------------------------------------------------------------------
// DecisionButtonPressed object
// Based on the keys pressed a decision will be made and 2 weighted behaviours will run.
//--------------------------------------------------------------------------------------
class DecisionButtonPressed : public DecisionQuestion
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	DecisionButtonPressed();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~DecisionButtonPressed();

	//--------------------------------------------------------------------------------------
	// If the player presses a button the decision changes, thus changing to the different
	// weighted behaviours.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Agent* pAgent, float fDeltaTime);
	
private:
	bool toggle;
};

