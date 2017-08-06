//--------------------------------------------------------------------------------------
// Class for the DecisionArrive
//--------------------------------------------------------------------------------------
#pragma once
#include "BaseDecision.h"

//--------------------------------------------------------------------------------------
// DecisionArrive object
// Based on the keys pressed the decision tree will update this decision or not.
//--------------------------------------------------------------------------------------
class DecisionArrive : public BaseDecision
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Weighting between 2 behaviours.
	//--------------------------------------------------------------------------------------
	DecisionArrive();
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~DecisionArrive();

	//--------------------------------------------------------------------------------------
	// Changes the amount of weighting on each behaviour if keys are pressed. Then updates.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the players position.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Agent* pAgent, float fDeltaTime);
};
