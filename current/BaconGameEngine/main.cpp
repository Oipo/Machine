#include <cassert>
#include "bacon.hpp"

void StartEngine()
{
	// do all our core startup tasks
	ASSERT( !"NOTI" );
}

static bool running = false;
void Run()
{
	running = true;
	while (running)
	{
		ASSERT( !"NOTI" );

		// call some python code; tick the physics; render the frame
	}
}

// called by python code at any time, to kill the main loop.
void Shutdown()
{
	running = false;
}