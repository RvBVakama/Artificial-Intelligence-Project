#pragma once
#include "IBehaviour.h"

class Entity;

class behaviourWander : public IBehaviour
{
public:
	behaviourWander(float fWeighting);
	~behaviourWander();

	Vector2 Calculate(Entity* pEntity, float fDeltaTime);

private:
	void SetAngle(Vector2 v2, float value, float number);

	float fWanderAngle;
};
