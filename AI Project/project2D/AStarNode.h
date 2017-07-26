#pragma once

#include "LinkedList.h"
#include <vector>

using namespace std;

struct AStarNode;

struct AStarEdge
{
	AStarNode* m_pEndNode;
	int m_nCost;
};

struct AStarNode
{
	AStarNode(int nIndex)
	{
		m_pPrev = nullptr;
		m_nGScore = 0;
		m_nHScore = 0;
		m_nFScore = 0;
		m_nIndex = nIndex;
		m_bBlocked = false;
	}

	virtual ~AStarNode()
	{
		for (size_t i = 0; i < m_AdjacentList.size(); ++i)
		{
			delete m_AdjacentList[i];
		}
	}

	AStarNode* m_pPrev;
	int m_nGScore;
	int m_nHScore;
	int m_nFScore;

	int m_nIndex;
	bool m_bBlocked;

	vector<AStarEdge*>m_AdjacentList;
};