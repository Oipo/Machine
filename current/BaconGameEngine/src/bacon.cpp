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
static bool running = false;
typedef std::map<std::string, boost::python::object> typemap;
typemap prototypes;

Bacon::Bacon()
{

}

void Bacon::StartEngine()
{
	// do all our core startup tasks
	// we should go to our initial appstate here.

	// todo: res from host? or from config?
	// debug-friendly :S
	appWindow = new sf::Window(
		sf::VideoMode(800,600,32),
		"Bacon Game Engine" );
}

void Bacon::Run()
{
	running = true;
	while (running)
	{
		//assert( !"NOTI" ); //What is this tomfoolery? Seriously. What is this?

		sf::Event Event;
        while(appWindow->GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                Shutdown();
        }

		// tick each of our active tasks
		// note that we want the active appstate's tasks,
		// not a fixed list!
		task_list::iterator it;
		for( it = tasks.begin(); it != tasks.end(); it++ )
			(*it)->Tick();


		// call some python code; tick the physics; render the frame

		appWindow->Display();
	}
}

// called by python code at any time, to kill the main loop.
void Bacon::Shutdown()
{
	running = false;
}

void Bacon::RegisterPrototype(  std::string const & type,
			                    boost::python::object prototype )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it == prototypes.end()) /*&& "Already registered"*/ );

	prototypes[ type ] = prototype;

	// if the prototype mentions art assets, we probably
	// want to smartly precache them now.
}

boost::python::object Bacon::Spawn( std::string const & type, int x, int y )
{
	typemap::const_iterator it = prototypes.find(type);
	assert( (it != prototypes.end()) /*&& "Not registered!"*/ );

	// clone the prototype
	// inject into the world
	// return the new entity
	return it->second; // TODO: Return something smart
}
