//--------------------------------------------------------------------------------------
// Class for the DecisionAgent
//--------------------------------------------------------------------------------------
#pragma once
#include "Agent.h"
#include "Renderer2D.h"
#include <vector>

using namespace aie;

class DecisionTree;

//--------------------------------------------------------------------------------------
// DecisionAgent object
// Sets a base spawn location, updates the decision tree and renders the player.
//--------------------------------------------------------------------------------------
class DecisionAgent : public Agent
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	DecisionAgent();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~DecisionAgent();

	//--------------------------------------------------------------------------------------
	// Updating the decision tree
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Drawing the player
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* pRenderer2D);

private:
	DecisionTree*		m_pDecisionTree;
};
