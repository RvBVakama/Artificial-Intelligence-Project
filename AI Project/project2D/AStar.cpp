#include "AStar.h"
#include "GridNode.h"
#include "Define.h"

AStar::AStar(int nMaxNodes)
{
	m_nMaxNodes = nMaxNodes;
	m_ClosedList = new bool[nMaxNodes];
}

AStar::~AStar()
{
	delete[] m_ClosedList;
}

bool AStar::CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath)
{
	//Reset everything incase there was a previous path.
	//clear open list
	m_OpenList.Clear();
	
	//set all elements in closed list to false.
	memset(m_ClosedList, 0, sizeof(bool) * m_nMaxNodes);
	
	//set start node's G score to zero.
	pStart->m_nGScore = 0;
	
	//calculate start node's H score (for now set to zero).
	pStart->m_nHScore = CalcHeuristic(pStart, pEnd);
	
	//calculate start node's F score.
	pStart->m_nFScore = pStart->m_nGScore + pStart->m_nHScore;

	//set start node's m_pPrev to null.
	pStart->m_pPrev = nullptr;

	//Add start node to open list.
	m_OpenList.Push(pStart);
	

	//While there are still nodes in the open list
	while (m_OpenList.GetSize() > 0)
	{
		//Get the node from the open list with the lowest F Score, we'll call that currentNode.
		//Remove currentNode from the open list.
		AStarNode* pCurrentNode = m_OpenList.Pop();
	
		//Add currentNode to the closed list. (by setting the bool to true)
		m_ClosedList[pCurrentNode->m_nIndex] = true;
		
		//if currentNode is the end node, we are finished.
		if(pCurrentNode == pEnd)
		{
			//Build path (remember it is backwards so we need to fix that)
			AStarNode* pNode = pEnd;
			do {
				finishedPath->insert(finishedPath->begin(), pNode);
				pNode = pNode->m_pPrev;
			} while (pNode);

			//Return that we found a valid path.
			return true;
		}

		//Loop through all of currentNode's neighbours
		for (size_t i = 0; i < pCurrentNode->m_AdjacentList.size(); ++i)
		{
			AStarNode* pNeighbour = pCurrentNode->m_AdjacentList[i]->m_pEndNode;
			int nCost = pCurrentNode->m_AdjacentList[i]->m_nCost;

			//Skip Walls
			if (pNeighbour->m_bBlocked)
				continue;

			//Skip neighbours that are already in the closed list.
			if (m_ClosedList[pNeighbour->m_nIndex])
				continue;

			//if neighbour is already in open list...
			if (m_OpenList.Contains(pNeighbour))
			{
				//Check if this current path is better than old path (lower F Score).
				if (pCurrentNode->m_nFScore + nCost < pNeighbour->m_nFScore)
				{
					//Update G Score.
					pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

					//Update F Score.
					pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

					//Update Prev node pointer.
					pNeighbour->m_pPrev = pCurrentNode;
				
					//Sort Heap

				}
			}
				//else (neighbour not in open list)
			else
			{
				
				//Calculate G Score.
				pNeighbour->m_nGScore = pCurrentNode->m_nGScore + nCost;

				//Calculate H Score.
				pNeighbour->m_nHScore = CalcHeuristic(pNeighbour, pEnd);
				
				//Calculate F Score.
				pNeighbour->m_nFScore = pNeighbour->m_nGScore + pNeighbour->m_nHScore;

				//Set Prev node pointer.
				pNeighbour->m_pPrev = pCurrentNode;

				//Add neighbour to open list.
				m_OpenList.Push(pNeighbour);

			}

		}
	}

	//No path found if we got to here, so return false.
	return false;
}

void AStar::SetHeuristic(HeuristicFunction func)
{
	HeuristicToCall = func;
}

int AStar::CalcHeuristic(AStarNode* pNode, AStarNode* pEnd)
{
	return HeuristicToCall(pNode, pEnd);
}

//void AStar::SortOpenList()
//{
//	for (size_t i = 0; i < m_OpenList.size(); ++i)
//	{
//		for (size_t j = 0; j < m_OpenList.size() - 1; ++j)
//		{
//			if (m_OpenList[j]->m_nFScore > m_OpenList[j + 1]->m_nFScore)
//			{
//				AStarNode* swap = m_OpenList[j];
//				m_OpenList[j] = m_OpenList[j + 1];
//				m_OpenList[j + 1] = swap;
//			}
//		}
//	}
//}