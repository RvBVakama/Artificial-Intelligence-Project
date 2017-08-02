#pragma once
#include "IBehaviour.h"

class behaviourWander : public IBehaviour
{
public:
	behaviourWander(float fWeighting);
	~behaviourWander();

	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

private:
	Vector2 SetAngle(Vector2 v2, float value);

	float fWanderAngle;
};
