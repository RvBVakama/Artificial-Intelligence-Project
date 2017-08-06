//--------------------------------------------------------------------------------------
// Class for the AIBaseState
//--------------------------------------------------------------------------------------
#pragma once
#include "Renderer2D.h"
#include <vector>

class Agent;
class IBehaviour;

using namespace aie;
using namespace std;

//--------------------------------------------------------------------------------------
// AIBaseState object
// Base class definition of what each AI state should contain
//--------------------------------------------------------------------------------------
class AIBaseState
{
public:

	//---------------------------------------------------------------
	// Default Constructor
	// This constructor is ran when any inherited class of base state
	// runs its constructor.
	//---------------------------------------------------------------
	AIBaseState();

	//---------------------------------------------------------------
	// Default Destructor
	// This destructor is ran when any inherited class of base state
	// runs its destructor.
	//---------------------------------------------------------------
	~AIBaseState();

	//---------------------------------------------------------------
	// Optional funcion
	//---------------------------------------------------------------
	virtual void OnEnter() = 0;

	//---------------------------------------------------------------
	// An update function.
	//
	// Param:
	//		fDeltaTime: DeltaTime keeps time in seconds.
	//---------------------------------------------------------------
	virtual void OnUpdate(Agent* pAgent, float fDeltaTime) = 0;

	//---------------------------------------------------------------
	// A Draw function. 
	//
	// Param:
	//		pRenderer2D: A pointer to the 2d renderer so the derived 
	//					 classes can draw stuff
	//---------------------------------------------------------------
	virtual void OnDraw(Renderer2D* renderer2d) = 0;

	//---------------------------------------------------------------
	// Optional funcion
	//---------------------------------------------------------------
	virtual void OnExit() = 0;

protected:
	vector<IBehaviour*> m_BehaviourList;
};
