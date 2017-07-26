#include "IBehaviour.h"

IBehaviour::IBehaviour()
{
}

IBehaviour::IBehaviour(float fWeighting)
{
	m_fWeighting = fWeighting;
}

IBehaviour::~IBehaviour()
{
}

Vector2 IBehaviour::Calculate(Agent * pAgent, float fDeltaTime)
{
	return Vector2();
}
