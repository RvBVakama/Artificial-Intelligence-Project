#include "DecisionWander.h"
#include "behaviourWander.h"

DecisionWander::DecisionWander()
{
}

DecisionWander::~DecisionWander()
{
}

void DecisionWander::MakeDecision(Entity* pEntity, float fDeltaTime)
{
	m_pBehaviourWander->Calculate(pEntity, fDeltaTime);
}
