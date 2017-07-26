#pragma once
#include "BaseDecision.h"

class DecisionPrint : public BaseDecision
{
public:
	DecisionPrint();
	~DecisionPrint();

	void MakeDecision(Entity* pEntity, float fDeltaTime);
private:
	float m_fTimer;
};

