#include "Grid.h"
#include "Define.h"
#include "GridNode.h"

Grid* Grid::m_grid = nullptr;

Grid::Grid()
{
	m_ppGrid = new GridNode*[GRID_SIZE * GRID_SIZE];

	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			// Calculate the index of the node from the x and y.
			int index = (y * GRID_SIZE) + x;

			// Calculate position of node in game world.
			Vector2 pos((float)x * NODE_SIZE, (float)y * NODE_SIZE);

			// Create the node.
			m_ppGrid[index] = new GridNode(pos, index, x, y);

			if (x % 3 == 0 && y != 15)
			{
				m_ppGrid[index]->m_bBlocked = true;
			}
		}
	}

	// Connect up adjacent nodes.
	for (int x = 0; x < GRID_SIZE; ++x)
	{
		for (int y = 0; y < GRID_SIZE; ++y)
		{
			int index = (y * GRID_SIZE) + x;

			GridNode* currentNode = m_ppGrid[index];

			// Adjacent nodes
			// ---------
			//	-  3  -
			//	0  C  2
			//	-  1  -
			// ---------
			for (int a = 0; a < 4; ++a)
			{
				// Work out which are the adjacent nodes
				int localX = x;
				int localY = y;

				if (a % 2 == 0) // Check if number is even
					localX += a - 1;
				else
					localY += a - 2;

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				//int i = ((y + (a - 2)) * GRID_SIZE) + (x + (a-1));
				GridNode* adjNode = m_ppGrid[localIndex];

				// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = ADJACENT_COST;

				currentNode->m_AdjacentList.push_back(pEdge);
			}

			// Diagonal nodes.
			for (int d = 0; d < 4; ++d)
			{
				// Work out which are the adjacent nodes
				int localX = x;
				int localY = y;

				if (d % 2 == 0)
				{
					localX += d - 1;
					localY += d - 1;
				}

				else
				{
					localX += d - 2;
					localY -= d - 2;
				}

				if (localX < 0 || localX >= GRID_SIZE)
					continue;

				if (localY < 0 || localY >= GRID_SIZE)
					continue;

				int localIndex = (localY * GRID_SIZE) + localX;
				//int i = ((y + (a - 2)) * GRID_SIZE) + (x + (a-1));
				GridNode* adjNode = m_ppGrid[localIndex];

				// Connect adjacency
				AStarEdge* pEdge = new AStarEdge();
				pEdge->m_pEndNode = adjNode;
				pEdge->m_nCost = DIAGONAL_COST;

				currentNode->m_AdjacentList.push_back(pEdge);
			}

		}
	}
}


Grid::~Grid()
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		delete m_ppGrid[i];
	}

	delete[] m_ppGrid;
}

void Grid::Draw(Renderer2D* m_2dRenderer)
{
	for (int i = 0; i < GRID_SIZE * GRID_SIZE; ++i)
	{
		if (m_ppGrid[i]->m_bBlocked)
			m_2dRenderer->setRenderColour(0x003366FF);
		else
			m_2dRenderer->setRenderColour(0xB2E076FF);

		float x = m_ppGrid[i]->m_v2Pos.x;
		float y = m_ppGrid[i]->m_v2Pos.y;
		m_2dRenderer->drawBox(x, y, NODE_SIZE - GRID_SPACING, NODE_SIZE - GRID_SPACING);

		//for (size_t a = 0; a < m_ppGrid[i]->m_AdjacentList.size(); ++a)
		//{

		//	GridNode* otherNode = ((GridNode*)m_ppGrid[i]->m_AdjacentList[a]->m_pEndNode);

		//	float otherX = otherNode->m_v2Pos.x;
		//	float otherY = otherNode->m_v2Pos.y;
		//	//m_2dRenderer->setRenderColour(0xFF0000FF);
		//	//m_2dRenderer->drawLine(x, y, otherX, otherY, EDGE_THICKNESS);
		//	//m_2dRenderer->setRenderColour(0xFFFFFFFF);
		//}

	}
}

GridNode * Grid::GetNode(int index)
{
	return m_ppGrid[index];
}
