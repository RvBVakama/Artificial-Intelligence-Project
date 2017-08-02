#include "behaviourKeyboard.h"
#include "Input.h"

behaviourKeyboard::behaviourKeyboard(float fWeighting)
{
}

behaviourKeyboard::~behaviourKeyboard()
{
}

Vector2 behaviourKeyboard::Calculate(Agent * pAgent, float fDeltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT));
	{}
	return Vector2();
}
