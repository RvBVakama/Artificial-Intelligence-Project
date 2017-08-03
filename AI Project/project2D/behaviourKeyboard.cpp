#include "behaviourKeyboard.h"
#include "Input.h"
#include "Agent.h"

behaviourKeyboard::behaviourKeyboard(float fWeighting) : IBehaviour(fWeighting)
{
}

behaviourKeyboard::~behaviourKeyboard()
{
}

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
