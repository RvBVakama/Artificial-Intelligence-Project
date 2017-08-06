//--------------------------------------------------------------------------------------
// Class for IBehaviour
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"

class Agent;

//--------------------------------------------------------------------------------------
// IBehaviour object
// IBehaviour is a class that allows for weighting, this allows for behaviours to be
// set to a certain amount of effectiveness (scaling the velocity that is returned).
//--------------------------------------------------------------------------------------
class IBehaviour
{
public:
	IBehaviour();
	IBehaviour(float fWeighting);
	virtual ~IBehaviour();

	//Update Function
	virtual Vector2 Calculate(Agent* pAgent, float fDeltaTime) = 0;

	float m_fWeighting;
};
