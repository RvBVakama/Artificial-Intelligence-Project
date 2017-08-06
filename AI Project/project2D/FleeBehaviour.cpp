#include "FleeBehaviour.h"
#include "Input.h"
#include "Agent.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Alternative Constructor 
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//--------------------------------------------------------------------------------------
FleeBehaviour::FleeBehaviour(float fWeighting) : IBehaviour(fWeighting)
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
FleeBehaviour::~FleeBehaviour()
{
}

//--------------------------------------------------------------------------------------
// Steers the player away from the mouse .
//
// Param:
//		pAgent: A pointer to the agent so we can get the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns the force velocity to be applied to the player, as a Vector2.
//--------------------------------------------------------------------------------------
Vector2 FleeBehaviour::Calculate(Agent * pAgent, float fDeltaTime)
{
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2FleePos((float)nMouseX, (float)nMouseY);

	Vector2 v2Dir = pAgent->GetPosition() - v2FleePos;
	v2Dir.Normalise();

	return v2Dir * 100.0f * fDeltaTime;
}
