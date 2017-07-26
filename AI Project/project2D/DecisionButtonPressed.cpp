#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;

DecisionButtonPressed::DecisionButtonPressed()
{
}


DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::MakeDecision(Entity * pEntity, float fDeltaTime)
{
	if (Input::getInstance()->isKeyDown(INPUT_KEY_SPACE))
	{
		m_pTrueDecision->MakeDecision(pEntity, fDeltaTime);
	}
	else
	{
		m_pFalseDecision->MakeDecision(pEntity, fDeltaTime);
	}
}
