//--------------------------------------------------------------------------------------
// Class for the DecisionSeek
//--------------------------------------------------------------------------------------
#pragma once
#include "BaseDecision.h"

class SeekBehaviour;

//--------------------------------------------------------------------------------------
// DecisionSeek object
// Based on the keys pressed the decision tree will update this decision or not.
//--------------------------------------------------------------------------------------
class DecisionSeek : public BaseDecision
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	DecisionSeek();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	virtual ~DecisionSeek();

	//--------------------------------------------------------------------------------------
	// Calculating the force the player needs to move along the path set by AStar and then 
	// updating the player's velocity to match.
	//
	// Param:
	//		pAgent: A pointer to the agent so we can get and set the player's position 
	//				and velocity.
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void MakeDecision(Agent* pAgent, float fDeltaTime);

private:
	SeekBehaviour* m_pBehaviourSeek;
};
