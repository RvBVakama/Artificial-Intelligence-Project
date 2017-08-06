//----------------------------------------------------------------------------------------
// Class for the AStar
//----------------------------------------------------------------------------------------
#pragma once
#include <vector>
#include"Heap.h"

struct AStarNode;

// Function pointer that allows for easy input of new heuristics 
typedef int(*HeuristicFunction)(AStarNode* pNode, AStarNode* pEnd);

//----------------------------------------------------------------------------------------
// AStar object
// Calculates the path that the player will move along using the AStar pathfinding method.
//----------------------------------------------------------------------------------------
class AStar
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	AStar(int nMaxNodes);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~AStar();

	//--------------------------------------------------------------------------------------
	// Calculating the force the player needs to move along the path set by AStar and then 
	// updating the player's velocity to match.
	//
	// Param:
	//		pStart: A pointer to the first AStarNode in the path.
	//		pEnd: A pointer to the last AStarNode in the path.
	//		finishedPath: The STL vector array of nodes that make up the path.
	// Return:
	//		Returns a bool, false if no path is found, and true if it found a path.
	//--------------------------------------------------------------------------------------
	bool CalculatePath(AStarNode* pStart, AStarNode* pEnd, vector<AStarNode*>* finishedPath);

	//--------------------------------------------------------------------------------------
	// Funciton pointer to set the passed in heuristic to be the one that is used.
	//--------------------------------------------------------------------------------------
	void SetHeuristic(HeuristicFunction func);

	//--------------------------------------------------------------------------------------
	// Another part of the funciton pointer heuristic design.
	// 
	// Return:
	//		Returns an int to the first and end nodes.
	//--------------------------------------------------------------------------------------
	int CalcHeuristic(AStarNode* pNode, AStarNode* pEnd);
	

private:
	//void SortOpenList(); //Won't need if have heap.

	HeuristicFunction HeuristicToCall = nullptr;

	int health;

	Heap m_OpenList; // Make this a heap.
	bool* m_ClosedList;
	int m_nMaxNodes;
};
