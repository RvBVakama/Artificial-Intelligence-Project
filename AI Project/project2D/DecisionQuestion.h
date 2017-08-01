#pragma once
#include "BaseDecision.h"

class DecisionQuestion : public BaseDecision
{
public:
	virtual void MakeDecision(Agent* pAgent, float fDeltaTime) = 0;

	BaseDecision* m_pWanderDecision;
	//BaseDecision* m_pTrueDecision;
	BaseDecision* m_ArriveDecision;
	//BaseDecision* m_pFalseDecision;
	BaseDecision* m_SeekDecision;
};
