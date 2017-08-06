#include "behaviourKeyboard.h"
#include "Input.h"
#include "Agent.h"

//------------------------------------------------------------------------------------
// Alternate Constructor 
//
// Param:
//		fWeighting: Used to change the amount of force to apply to the velocity of the 
//					target object.
//------------------------------------------------------------------------------------
behaviourKeyboard::behaviourKeyboard(float fWeighting) : IBehaviour(fWeighting)
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
behaviourKeyboard::~behaviourKeyboard()
{
}

//--------------------------------------------------------------------------------------
// Based on the user's input the player will move in the direction corresponding  to the
// buttons pressed
//
// Param:
//		pAgent: A pointer to the agent because the base class says so.
//		fDeltaTime: DeltaTime keeps time in seconds.
// Return:
//		Returns v2Dir which is the velocity Vector2 that is applied ot the player.
//--------------------------------------------------------------------------------------
Vector2 behaviourKeyboard::Calculate(Agent* pAgent, float fDeltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	Vector2 v2Dir;
	
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		v2Dir.y = 1.0f;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		v2Dir.y = -1.0f;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		v2Dir.x = 1.0f;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		v2Dir.x = -1.0f;

	v2Dir.Normalise();

	return v2Dir * fDeltaTime * 150.0f;
}
