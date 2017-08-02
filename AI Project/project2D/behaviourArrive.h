#pragma once
#include "IBehaviour.h"

class LilNooter;

class behaviourArrive : public IBehaviour
{
public:
	behaviourArrive(float fWeighting);
	~behaviourArrive();

	Vector2 Calculate(Agent* pAgent, float fDeltaTime);

private:
	LilNooter*			m_pLilNooter;
};
