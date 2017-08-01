#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;

DecisionButtonPressed::DecisionButtonPressed()
{
}

DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_SPACE))
	{
		m_pWanderDecision->MakeDecision(pAgent, fDeltaTime);
		//m_pTrueDecision->MakeDecision(pEntity, fDeltaTime);
	}

	else
	{
		m_pIdleDecision->MakeDecision(pAgent, fDeltaTime);
		//m_pFalseDecision->MakeDecision(pEntity, fDeltaTime);
	}
}
