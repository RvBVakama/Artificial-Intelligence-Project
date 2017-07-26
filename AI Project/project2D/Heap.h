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
		//Add data to 
		m_Data.push_back(data);

		//Loop through and swap with parent if data is smaller.
		int current = m_Data.size() - 1;
		while (true)
		{

			if (current == 0)
				break;

			int parent = GetParentIndex(current);

			if (m_Data[current]->m_nFScore < m_Data[parent]->m_nFScore)
			{
				AStarNode* swap = m_Data[current];
				m_Data[current] = m_Data[parent];
				m_Data[parent] = swap;

				current = parent;
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

private:
	vector<AStarNode*> m_Data;
};