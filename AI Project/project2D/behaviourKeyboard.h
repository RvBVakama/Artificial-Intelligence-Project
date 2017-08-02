#pragma once
#include "IBehaviour.h"

class behaviourKeyboard : public IBehaviour
{
public:
	behaviourKeyboard(float fWeighting);
	~behaviourKeyboard();

	Vector2 Calculate(Agent* pAgent, float fDeltaTime);
};
