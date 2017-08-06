#include "Obstacle.h"
#include "Define.h"

//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
Obstacle::Obstacle()
{
	m_v2Pos.x = 345.0f;
	m_v2Pos.y = 680.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Obstacle::~Obstacle()
{
}

//--------------------------------------------------------------------------------------
// If the obstacle had a behaviour or moved or did aything dynamic it would be 
// calculated here.
//
// Param:
//		fDeltaTime: DeltaTime keeps time in seconds.
//--------------------------------------------------------------------------------------
void Obstacle::Update(float deltaTime)
{
}

//--------------------------------------------------------------------------------------
// Draws the path that the AStar pathfinding calulated.
//
// Param:
//		pRenderer2D: A pointer to the 2D rendering engine.
//--------------------------------------------------------------------------------------
void Obstacle::Draw(Renderer2D * pRenderer2D)
{
	// Draws the Obstacle/s // OBSTACLE_COUNT how many to draw of the Obstacle/s
	// OBSTACLE_COUNT also used for the COUNT of actual collision circles in the 
	// obstacleAvoidanceBehaviour.cpp

	for (int i = 0; i < OBSTACLE_COUNT; ++i)
	{
		int f = (i * 10);
		pRenderer2D->setRenderColour(0x95C8FFFF);
		pRenderer2D->drawCircle(m_v2Pos.x + f, m_v2Pos.y + f, (OBSTACLE_RADIUS - 8), 0);
		pRenderer2D->setRenderColour(0xFFFFFFFF);
	}
}
