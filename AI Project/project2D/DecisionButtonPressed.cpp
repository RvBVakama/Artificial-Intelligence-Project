#include "DecisionButtonPressed.h"
#include "Input.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
DecisionButtonPressed::DecisionButtonPressed()
{
	toggle = true;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
DecisionButtonPressed::~DecisionButtonPressed()
{
}

//--------------------------------------------------------------------------------------
// If the player presses a button the decision changes, thus changing to the different
// weighted behaviours.
//
// Param:
//		pAgent: A pointer to the agent so we can get and set the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void DecisionButtonPressed::MakeDecision(Agent* pAgent, float fDeltaTime)
{
	if (Input::getInstance()->wasKeyPressed(INPUT_KEY_SPACE))
		toggle = !toggle;

	if (!toggle)
		m_pWanderDecision->MakeDecision(pAgent, fDeltaTime);

	if (toggle)
		m_ArriveDecision->MakeDecision(pAgent, fDeltaTime);
}
