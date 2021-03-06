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
#include "Agent.h"
// Other
#include "stateMovement.h"
#include "Grid.h"
#include <vector>
// Players
#include "Player_Mouse.h"
#include "Player_PathFind.h"
#include "DecisionAgent.h"
#include "LilNooter.h"
#include "Player_BehaviourTree.h"
#include "Obstacle.h"

using namespace std;

//---------------------------------------------------------------------------------
// Default Constructor
//---------------------------------------------------------------------------------
Application2D::Application2D() {

}

//---------------------------------------------------------------------------------
// Default Destructor
//---------------------------------------------------------------------------------
Application2D::~Application2D() {

}

//---------------------------------------------------------------------------------
// Creates the renderer, collision manager, my resource manager and my state
// manager then registers all possible states and pushes my spash screen state.
// 
// Return:
// 		Returns true.
//---------------------------------------------------------------------------------
bool Application2D::startup()
{
	// Creating everything
	m_2dRenderer = new aie::Renderer2D();
	_ASSERT(m_2dRenderer);

	CollisionManager::Create();

	CollisionManager* pPtr = CollisionManager::GetInstance();

	ResourceManager<Texture>::Create();

	m_pStateMachine = new StateMachine();
	_ASSERT(m_pStateMachine);

	// Players (Human Players)
	m_pPlayer_Mouse = new Player_Mouse();
	_ASSERT(m_pPlayer_Mouse);

	m_pPlayer_PathFindA = new Player_PathFind(871, 899);
	_ASSERT(m_pPlayer_PathFindA);

	m_pPlayer_PathFindB = new Player_PathFind(7, 352);
	_ASSERT(m_pPlayer_PathFindB);

	m_pDecisionAgent = new DecisionAgent();
	_ASSERT(m_pDecisionAgent);

	m_pPlayer_BehaviourTree = new Player_BehaviourTree();
	_ASSERT(m_pPlayer_BehaviourTree);

	// AIs (Computer Players)
	m_pLilNooter = new LilNooter();
	_ASSERT(m_pLilNooter);

	m_pObstacle = new Obstacle();
	_ASSERT(m_pObstacle);

	Grid::create();

	m_cameraX = -15;
	m_cameraY = -15;
	
	return true;
}

//---------------------------------------------------------------------------------
// Deletes and destroys all managers, states etc... to prevent memory leaks.
//---------------------------------------------------------------------------------
void Application2D::shutdown() {
	
	// Other
	Grid::destroy();
	// AIs
	delete m_pObstacle;
	delete m_pLilNooter;
	// Players
	delete m_pPlayer_BehaviourTree;
	delete m_pDecisionAgent;
	delete m_pPlayer_PathFindB;
	delete m_pPlayer_PathFindA;
	delete m_pPlayer_Mouse;
	// Other
	delete m_pStateMachine;
	ResourceManager<Texture>::Destroy();
	CollisionManager::Destroy();
	delete m_2dRenderer;
}

//---------------------------------------------------------------------------------
// Updates the state machine and checks if the user has clicked the end key and
// ends the game.
// 
// Param:
// 		deltaTime: delta time simply is seconds as a float value. It is passed into 
// the state machine's update function.
//---------------------------------------------------------------------------------
void Application2D::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_END))
		quit();

	// Updating the players
	m_pPlayer_Mouse->Update(deltaTime/SLOW_MOTION);
	m_pPlayer_PathFindA->Update(deltaTime/SLOW_MOTION);
	m_pPlayer_PathFindB->Update(deltaTime/SLOW_MOTION);
	m_pDecisionAgent->Update(deltaTime/SLOW_MOTION);
	m_pLilNooter->Update(deltaTime/SLOW_MOTION);
	m_pPlayer_BehaviourTree->Update(deltaTime/SLOW_MOTION);
	m_pObstacle->Update(deltaTime/SLOW_MOTION);
}

//---------------------------------------------------------------------------------
// Clears the screen then begins the 2d renderer then draws the state machine
// by passing in the 2d renderer, finally ending the 2d renderer.
//---------------------------------------------------------------------------------
void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	m_2dRenderer->begin();

	Grid::getInstance()->Draw(m_2dRenderer);

	aie::Input* input = aie::Input::getInstance();

	int fMouseX = input->getMouseX();
	int fMouseY = input->getMouseY();

	// Drawing the players (Human)
	m_pPlayer_Mouse->Draw(m_2dRenderer);
	m_pPlayer_PathFindA->Draw(m_2dRenderer);
	m_pPlayer_PathFindB->Draw(m_2dRenderer);
	m_pDecisionAgent->Draw(m_2dRenderer);
	m_pPlayer_BehaviourTree->Draw(m_2dRenderer);
	// Drawing the AIs (Computer)
	m_pLilNooter->Draw(m_2dRenderer);
	m_pObstacle->Draw(m_2dRenderer);

	m_2dRenderer->end();
}
