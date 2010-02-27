#include <string>
#include <map>
#include <vector>
#include <cassert>

#include <boost/python.hpp>
#include <SFML/Window.hpp>

#include "bacon.hpp"

sf::Window * appWindow;
typedef std::vector< ITask * > task_list;
task_list tasks;

void StartEngine()
{
	// do all our core startup tasks
	// we should go to our initial appstate here.

	// todo: res from host? or from config?
	// debug-friendly :S
	appWindow = new sf::Window( 
		sf::VideoMode(800,600,32),
		"Bacon Game Engine" );
}

static bool running = false;
void Run()
{
	running = true;
	while (running)
	{
		assert( !"NOTI" );

		// tick each of our active tasks
		// note that we want the active appstate's tasks,
		// not a fixed list!
		task_list::iterator it;
		for( it = tasks.begin(); it != tasks.end(); it++ )
			(*it)->Tick();
			

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
