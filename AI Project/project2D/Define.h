#pragma once

//------------------------------------------------
// App Values
//------------------------------------------------
#define SCREENX 900
#define SCREENY 900

//------------------------------------------------
// AStar Grid Values
//------------------------------------------------
#define GRID_SIZE 30
#define NODE_SIZE 30
#define GRID_SPACING 0
#define ADJACENT_COST 10
#define DIAGONAL_COST 14

//------------------------------------------------
// AStar Debuging
//------------------------------------------------
#define EDGE_THICKNESS 1.0f

//------------------------------------------------
// Wander Behaviour
//------------------------------------------------
#define CIRCLE_DISTANCE 120.0f
#define CIRCLE_RADIUS 80.0f

//------------------------------------------------
// List of some state/s that are used in the app
//------------------------------------------------
enum PLAYER_MOUSE_STATES
{
	E_STATEMOVEMENT,
	E_STATEIDLE
};

//------------------------------------------------
// List of some state/s that are used in the app
//------------------------------------------------
enum PLAYER_PATHFIND_STATES
{
	E_STATEPATHFIND,
};

//------------------------------------------------
// Error Debug Codes
//------------------------------------------------
#define SUCCESS 0
#define OUT_OF_BOUNDS 1
#define INVALID_STATE 2
#define STATELIST_NEGATIVE_SIZE 3
#define STACK_NEGATIVE_SIZE 4
