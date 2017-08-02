#include "LilNooter.h"

LilNooter::LilNooter()
{
	m_v2Pos.x = 855.0f;
	m_v2Pos.y = 450.0f;
}

LilNooter::~LilNooter()
{
}

void LilNooter::Update(float deltaTime)
{
}

void LilNooter::Draw(Renderer2D * pRenderer2D)
{
	// Draw Player
	pRenderer2D->setRenderColour(0x5F115FFF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 13, 13, 0, 0);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
