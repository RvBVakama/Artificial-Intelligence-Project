#pragma once
#include "Agent.h"
#include "Renderer2D.h"

using namespace aie;

class LilNooter : public Agent
{
public:
	LilNooter();
	~LilNooter();

	void Update(float deltaTime);
	void Draw(Renderer2D* pRenderer2D);
};

