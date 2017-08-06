//--------------------------------------------------------------------------------------
// Class for the GridNode
//--------------------------------------------------------------------------------------
#pragma once

#include "AStarNode.h"
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// GridNode object
// Each node that the AStar path can appear on, the grid is made of gridnodes, each are 
// valid areas that AStar can assign to the path for the player to move along.
//--------------------------------------------------------------------------------------
struct GridNode : public AStarNode
{
	GridNode(Vector2 pos, int nIndex, int nIndexX, int nIndexY) : AStarNode(nIndex)
	{
		m_v2Pos = pos;
		m_nIndexX = nIndexX;
		m_nIndexY = nIndexY;
	}

	int m_nIndexX;
	int m_nIndexY;

	Vector2 m_v2Pos;
};