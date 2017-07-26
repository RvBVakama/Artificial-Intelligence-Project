#include "SeekBehaviour.h"
#include "Input.h"
#include "Agent.h"

using namespace aie;

SeekBehaviour::SeekBehaviour(float fWeighting) : IBehaviour(fWeighting)
{
}

SeekBehaviour::~SeekBehaviour()
{
}

Vector2 SeekBehaviour::Calculate(Agent * pAgent, float fDeltaTime)
{
	int nMouseX;
	int nMouseY;
	Input::getInstance()->getMouseXY(&nMouseX, &nMouseY);
	Vector2 v2_mousePos(nMouseX, nMouseY);

	Vector2 v2Dir = v2_mousePos - pAgent->GetPosition();
	v2Dir.Normalise();

	return v2Dir * 100.0f * fDeltaTime;
}
