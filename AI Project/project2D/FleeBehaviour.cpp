#include "FleeBehaviour.h"
#include "Input.h"
#include "Agent.h"

using namespace aie;

FleeBehaviour::FleeBehaviour(float fWeighting) : IBehaviour(fWeighting)
{
}

FleeBehaviour::~FleeBehaviour()
{
}

Vector2 FleeBehaviour::Calculate(Agent * pAgent, float fDeltaTime)
{
	Vector2 v2FleePos(200.0f, 200.0f);

	Vector2 v2Dir = pAgent->GetPosition() - v2FleePos;
	v2Dir.Normalise();

	return v2Dir * 100.0f * fDeltaTime;
}
