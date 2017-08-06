#include "SeekBehaviour.h"
#include "Input.h"
#include "Agent.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Alternate Constructor 
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//--------------------------------------------------------------------------------------
SeekBehaviour::SeekBehaviour(float fWeighting) : IBehaviour(fWeighting)
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
SeekBehaviour::~SeekBehaviour()
{
}

//--------------------------------------------------------------------------------------
// Steers the player in the direction of the mouse.
//
// Param:
//		pAgent: A pointer to the agent so we can get the players position.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns the force velocity to be applied to the player, as a Vector2.
//--------------------------------------------------------------------------------------
Vector2 SeekBehaviour::Calculate(Agent* pAgent, float fDeltaTime)
{
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2_mousePos((float)nMouseX, (float)nMouseY);

	Vector2 v2Dir = v2_mousePos - pAgent->GetPosition();
	v2Dir.Normalise();

	return v2Dir * 100.0f * fDeltaTime;
}
