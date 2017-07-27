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
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2FleePos(nMouseX, nMouseY);

	Vector2 v2Dir = pAgent->GetPosition() - v2FleePos;
	v2Dir.Normalise();

	return v2Dir * 100.0f * fDeltaTime;
}
