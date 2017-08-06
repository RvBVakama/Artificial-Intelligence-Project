//--------------------------------------------------------------------------------------
// Class for the DecisionQuestion
//--------------------------------------------------------------------------------------
#pragma once
#include "BaseDecision.h"

//--------------------------------------------------------------------------------------
// DecisionQuestion object
// Base class that defines which functions all decision classes should have. 
//--------------------------------------------------------------------------------------
class DecisionQuestion : public BaseDecision
{
public:
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

	BaseDecision* m_pWanderDecision;
	BaseDecision* m_ArriveDecision;
	BaseDecision* m_SeekDecision;
};
