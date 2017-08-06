//--------------------------------------------------------------------------------------
// Class for DecisionWander
//--------------------------------------------------------------------------------------
#pragma once
#include "BaseDecision.h"

class behaviourWander;

//--------------------------------------------------------------------------------------
// DecisionWander object
// The decision that is used to tell DecisionAgent when to run the 
// wander behaviour's code.
//--------------------------------------------------------------------------------------
class DecisionWander : public BaseDecision
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor // Weighting between behaviours.
	//--------------------------------------------------------------------------------------
	DecisionWander();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~DecisionWander();

	//--------------------------------------------------------------------------------------
	// Calculating the force the player needs to seek and wander.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get the players position and velocity.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	behaviourWander* m_pBehaviourWander;
};
