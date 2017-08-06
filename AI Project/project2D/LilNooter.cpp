#include "LilNooter.h"

//--------------------------------------------------------------------------------------
// Default Constructor // Setting a starting location.
//--------------------------------------------------------------------------------------
LilNooter::LilNooter()
{
	m_v2Pos.x = 855.0f;
	m_v2Pos.y = 450.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
LilNooter::~LilNooter()
{
}

//--------------------------------------------------------------------------------------
// Updating nothing.
// 
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void LilNooter::Update(float deltaTime)
{
}

//--------------------------------------------------------------------------------------
// Draws the lil nooter, he/she/they are lost baby penguins.
// 
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void LilNooter::Draw(Renderer2D * pRenderer2D)
{
	// Draw Player
	pRenderer2D->setRenderColour(0x5F115FFF);
	pRenderer2D->drawBox(m_v2Pos.x, m_v2Pos.y, 13, 13, 0, 0);
	pRenderer2D->setRenderColour(0xFFFFFFFF);
}
