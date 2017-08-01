#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;

DecisionButtonPressed::DecisionButtonPressed()
{
	toggle = true;
}

DecisionButtonPressed::~DecisionButtonPressed()
{
}

void DecisionButtonPressed::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_SPACE))
	{
		if (!toggle)
			toggle = true;

		else if (toggle)
			toggle = false;
	}

	if (!toggle)
	{
		m_pWanderDecision->MakeDecision(pAgent, fDeltaTime);
	}

	if (toggle)
	{
		m_SeekDecision->MakeDecision(pAgent, fDeltaTime);
		m_ArriveDecision->MakeDecision(pAgent, fDeltaTime);
	}	
}
