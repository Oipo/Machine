#include <boost/python.hpp>

#include <string>
#include <map>
#include <cassert>

#include "bacon.hpp"

void StartEngine()
{
	// do all our core startup tasks
	assert( !"NOTI" );
}

static bool running = false;
void Run()
{
	running = true;
	while (running)
	{
		assert( !"NOTI" );

		// call some python code; tick the physics; render the frame
	}
}

// called by python code at any time, to kill the main loop.
void Shutdown()
{
	running = false;
}

typedef std::map<std::string, boost::python::object> typemap;
typemap prototypes;

void RegisterPrototype( std::string const & type, 
			boost::python::object prototype )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it == prototypes.end()) && "Already registered" );
	
	prototypes[ type ] = prototype;

	// if the prototype mentions art assets, we probably
	// want to smartly precache them now.
}

boost::python::object Spawn( std::string const & type, int x, int y )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it != prototypes.end()) && "Not registered!" );

	// clone the prototype
	// inject into the world
	// return the new entity
	return it->second; // TODO: Return something smart
}
