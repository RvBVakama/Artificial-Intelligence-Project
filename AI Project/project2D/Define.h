#pragma once

#define SCREENX 900
#define SCREENY 900
#define GRID_SIZE 30
#define NODE_SIZE 30
#define GRID_SPACING 0
#define ADJACENT_COST 10
#define DIAGONAL_COST 14
#define EDGE_THICKNESS 0.0f

//------------------------------------------------
// List of states that are used in the game
//------------------------------------------------
enum STATES
{
	E_STATEMOVEMENT,
	E_STATEIDLE
};

//------------------------------------------------
// Error Debug Codes
//------------------------------------------------
#define SUCCESS 0
#define OUT_OF_BOUNDS 1
#define INVALID_STATE 2
#define STATELIST_NEGATIVE_SIZE 3
#define STACK_NEGATIVE_SIZE 4
