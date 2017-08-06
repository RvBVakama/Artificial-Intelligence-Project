#include "Application2D.h"
#include <iostream>
#include <time.h>
#include "Define.h"
#include "Heap.h"

// Memory leak checker
#define _CRTDBG_MAP_ALLOC _CrtDumpMemoryLeaks
#include <stdlib.h>  
#include <crtdbg.h>

#include "Heap.h"
#include "AStarNode.h"

//-------------------------------------------------------------------------------
// int main first tests the Linked list and then creates a new app and starts it.
// then deletes it after it the quit function is called.
//
// Return:
//		Returns 0 to tell windows that the application ran successfully.
//-------------------------------------------------------------------------------
int main() 
{
	// Memory leak checker
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// For better random values
	srand((int)time(NULL));
	
	// allocation
	auto app = new Application2D();
	_ASSERT(app);
	// initialise and loop
	app->run("AIE", SCREENX, SCREENY, false);

	// deallocation
	delete app;

	//system("pause");
	
	return 0;
}