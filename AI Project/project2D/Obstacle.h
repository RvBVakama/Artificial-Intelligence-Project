//--------------------------------------------------------------------------------------
// Class for Obstacles
//--------------------------------------------------------------------------------------
#pragma once
#include "Agent.h"
#include "Renderer2D.h"

using namespace aie;

//--------------------------------------------------------------------------------------
// Obstacle object
// Draws a circle that renders atop each circle collision avoidance area thus 
// representing where the player can collide.
//--------------------------------------------------------------------------------------
class Obstacle : public Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	Obstacle();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Obstacle();

	//--------------------------------------------------------------------------------------
	// If the obstacle had a behaviour or moved or did aything dynamic it would be 
	// calculated here.
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draws the path that the AStar pathfinding calulated.
	//
	// Param:
	//		pRenderer2D: A pointer to the 2D rendering engine.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* pRenderer2D);
};
