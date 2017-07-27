#pragma once
#include <vector>
#include <math.h>
#include "AStarNode.h"
using namespace std;

class Heap
{
public:
	void Push(AStarNode* data)
	{
		// Add data to the m_Data vector list which holds nodes usually
		m_Data.push_back(data);

		// Setting the last node as the current node
		int currentNode = m_Data.size() - 1;
		
		// Loop through and swap with parent if data is smaller.
		while (true)
		{
			if (currentNode == 0)
				break;

			// Sets the parent node
			int parentNode = GetParentIndex(currentNode);

			
			if (m_Data[currentNode]->m_nFScore < m_Data[parentNode]->m_nFScore)
			{
				AStarNode* swap = m_Data[currentNode];
				m_Data[currentNode] = m_Data[parentNode];
				m_Data[parentNode] = swap;

				currentNode = parentNode;
			}
			else
				break;
		}
	}

	AStarNode* Pop()
	{
		AStarNode* result = m_Data[0];

		//Replace first element with last element.
		int last = m_Data.size() - 1;
		m_Data[0] = m_Data[last];

		int current = 0;
		while (true)
		{
			//work out which child is smaller
			int child0 = GetChildIndex(current, 1);
			if (child0 > last)
				break;

			int child1 = GetChildIndex(current, 2);
			int smallerChild = child0;
			if (child1 <= last && m_Data[child1]->m_nFScore < m_Data[smallerChild]->m_nFScore)
				smallerChild = child1;

			//Check if smaller than present, if so swap.
			if (m_Data[smallerChild]->m_nFScore < m_Data[current]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[smallerChild];
				m_Data[smallerChild] = swap;

				current = smallerChild;
			}
			else
				break;
		}

		m_Data.pop_back();

		return result;
	}

	void Clear()
	{
		m_Data.clear();
	}

	int GetSize()
	{
		return (int)m_Data.size();
	}

	//---------------------------------------------
	// 
	// 
	//---------------------------------------------
	int GetParentIndex(int childIndex)
	{
		return (childIndex - 1)  / 2;
	}

	int GetChildIndex(int parentIndex, int whichIndex)
	{
		return (2 * parentIndex) + whichIndex;
	}

	bool Contains(AStarNode* pData)
	{
		for (size_t i = 0; i < m_Data.size(); ++i)
		{
			if (m_Data[i] == pData)
				return true;
		}
		return false;
	}
	
	/*int Contains(AStarNode* pData)
	{
		//runs for the amount of nodes there are
		for (size_t i = 0; i < m_Data.size(); ++i)
		{
			if (m_Data[i] == pData)
			{
				return i;
			}
			else
			{
				return -1;
			}
		}
	}*/

	//void Resort(int index)
	//{
	//	if (index == 0)
	//		return;

	//	int nNodeIndex = index;
	//	int nParent = GetParentIndex(index);
	//	
	//	//Check if node has a lower F value than parent, if so then swap.
	//	while (nParent >= 0 && m_Data[nNodeIndex]->m_nFScore < m_Data[nParent]->m_nFScore)
	//	{
	//		//Swap
	//		AStarNode* temp = m_Data[nParent];
	//		m_Data[nParent] = m_Data[nNodeIndex];
	//		m_Data[nNodeIndex] = temp;

	//		nNodeIndex = nParent;
	//		nParent = GetParentIndex(nNodeIndex);
	//	}
	//}

private:
	vector<AStarNode*> m_Data;
};