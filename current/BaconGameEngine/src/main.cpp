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

// is boost::python::object safe to store by value in a map?
// we'll find out :)
typedef std::map<std::string, boost::python::object> typemap;
typemap prototypes;

void RegisterPrototype( std::string const & type, 
			boost::python::object prototype )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it == prototypes.end()) && "Already registered" );
	
	prototypes[ type ] = prototype;	// chrisf is an idiot.

	// if the prototype mentions art assets, we probably
	// want to smartly precache them now.
	// let me paste my magic resource allocator
}

// what are the semantics of boost::python::object ?
// does "copying" it copy the python object, or is it a smart ptr?
// oh god let me look up the headers
boost::python::object Spawn( std::string const & type, int x, int y )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it != prototypes.end()) && "Not registered!" );

	// clone the prototype
	// inject into the world
	// return the new entity
	return // *it ?
}