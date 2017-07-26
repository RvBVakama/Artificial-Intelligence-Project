#pragma once
#include <vector>
#include"Heap.h"

struct AStarNode;

typedef int(*HeuristicFunction)(AStarNode* pNode, AStarNode* pEnd);

class AStar
{
public:
	

	AStar(int nMaxNodes);
	~AStar();
	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath);
	int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd);
	
	//set heuristic
	void SetHeuristic(HeuristicFunction func);

private:
	//void SortOpenList(); //Won't need if have heap.

	HeuristicFunction HeuristicToCall = nullptr;

	int health;

	Heap m_OpenList; // Make this a heap.
	bool* m_ClosedList;
	int m_nMaxNodes;
};
