#pragma once
#include "Renderer2D.h"

using namespace aie;

class StateMachine;

class BaseState
{
public:

	//---------------------------------------------------------------
	// Default Constructor
	// This constructor is ran when any inherited class of base state
	// runs its constructor.
	//---------------------------------------------------------------
	BaseState();

	//---------------------------------------------------------------
	// Default Destructor
	// This destructor is ran when any inherited class of base state
	// runs its destructor.
	//---------------------------------------------------------------
	~BaseState();

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
	virtual void OnUpdate(float fDeltaTime) = 0;

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
};