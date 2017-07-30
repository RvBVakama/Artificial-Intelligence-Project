#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "StateMachine.h"
#include "ResourceManager.h"
#include "CollisionManager.h"
#include "Define.h"
#include "GridNode.h"
#include "AStarNode.h"
//Decision Implementation
#include "DecisionTree.h"
#include "Agent.h"
#include "Player_Mouse.h"
#include "Player_PathFind.h"
#include "stateMovement.h"
#include "Grid.h"
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------------
// Default Constructor
// ---------------------------------------------------------------------------------
Application2D::Application2D() {

}

// ---------------------------------------------------------------------------------
// Default Destructor
// ---------------------------------------------------------------------------------
Application2D::~Application2D() {

}
// ---------------------------------------------------------------------------------
// Creates the renderer, collision manager, my resource manager and my state
// manager then registers all possible states and pushes my spash screen state.
// 
// Return:
// 		Returns true.
// ---------------------------------------------------------------------------------
bool Application2D::startup()
{
	// Creating everything
	m_2dRenderer = new aie::Renderer2D();
	_ASSERT(m_2dRenderer);

	CollisionManager::Create();

	CollisionManager* pPtr = CollisionManager::GetInstance();

	ResourceManager<Texture>::Create();

	//Decision Implementation
	m_pDecisionTree = new DecisionTree;
	_ASSERT(m_pDecisionTree);

	m_pStateMachine = new StateMachine();
	_ASSERT(m_pStateMachine);

	m_pPlayer_Mouse = new Player_Mouse;
	_ASSERT(m_pPlayer_Mouse);

	m_pPlayer_PathFind = new Player_PathFind;
	_ASSERT(m_pPlayer_PathFind);

	//m_pGrid = new Grid;
	Grid::create();

	m_cameraX = -15;
	m_cameraY = -15;
	
	return true;
}

// ---------------------------------------------------------------------------------
// Deletes and destroys all managers, states etc... to prevent memory leaks.
// ---------------------------------------------------------------------------------
void Application2D::shutdown() {

	delete m_pPlayer_PathFind;
	delete m_pPlayer_Mouse;
	//Decision Implementation
	delete m_pDecisionTree;
	Grid::destroy();
	ResourceManager<Texture>::Destroy();
	CollisionManager::Destroy();
	delete m_2dRenderer;
}

// ---------------------------------------------------------------------------------
// Updates the state machine and checks if the user has clicked the end key and
// ends the game.
// 
// Param:
// 		deltaTime: delta time simply is seconds as a float value. It is passed into 
// the state machine's update function.
// ---------------------------------------------------------------------------------
void Application2D::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_END))
		quit();

	// Updating the players
	m_pPlayer_Mouse->Update(deltaTime);
	m_pPlayer_PathFind->Update(deltaTime);

	//Decision Implementation
	m_pDecisionTree->Update(nullptr, deltaTime);

}

// ---------------------------------------------------------------------------------
// Clears the screen then begins the 2d renderer then draws the state machine
// by passing in the 2d renderer, finally ending the 2d renderer.
// ---------------------------------------------------------------------------------
void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->begin();

	Grid::getInstance()->Draw(m_2dRenderer);

	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	// Drawing the players
	m_pPlayer_Mouse->Draw(m_2dRenderer);
	m_pPlayer_PathFind->Draw(m_2dRenderer);
	
	m_2dRenderer->end();
}
