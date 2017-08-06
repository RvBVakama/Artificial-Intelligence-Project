//--------------------------------------------------------------------------------------
// Class for the Grid
//--------------------------------------------------------------------------------------
#pragma once
#include <crtdbg.h>
#include "Renderer2D.h"

struct GridNode;

using namespace aie;

//--------------------------------------------------------------------------------------
// Grid object
// Creates an instance of a grid and sets up its side of AStar and then renders it.
//--------------------------------------------------------------------------------------
class Grid
{
public:

	static Grid* getInstance() { return m_grid; }

	static void create() { m_grid = new Grid(); _ASSERT(m_grid);}

	static void destroy() { delete m_grid; }

	//--------------------------------------------------------------------------------------
	// Draws the grid.
	//
	// Param:
	//		eType: The type of the weapon the player currently has equipped.
	//		level: The player's current level.
	//		bonus: Any bonus damage from buffs.
	// Return:
	//		Returns an int containing the total damage the player will do with next attack.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Returns a node specified by the passed in index.
	//
	// Param:
	//		index: The node to be returned out.
	// Return:
	//		Returns the node at the passed in index.
	//--------------------------------------------------------------------------------------
	GridNode* GetNode(int index);

private:
	Grid();
	~Grid();
	
	static Grid* m_grid;

	GridNode**			m_ppGrid;
	aie::Renderer2D*	m_2dRenderer;
};
