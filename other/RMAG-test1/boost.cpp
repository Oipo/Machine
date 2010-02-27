#include <boost/python.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>

#include "miniengine.hpp"

/* working example for python integration
int outputShit(int shit) {
	return shit;
}

BOOST_PYTHON_MODULE(miniengine) {
	using namespace boost::python;
	def("submit", outputShit);
}
*/

// dirty hack
Engine * g_engine;
sf::Mutex initDone;

//
// OH SHIT, we still lose. sf::Mutex is implemented as a CS on win32.
//	unfortunately, CSs on win32 can be recursively entered by the owning thead.
// lets just make it properly then
// ok, i need another primitive to give you signaling like this.

// main function of engine thread
void startEngine(void *UserData) {
	// sorry we need that pointer, it's SFML internal
	g_engine = new Engine();
	g_engine->init();

	// A. signal something
	initDone.Unlock();
	
	while(true) {
		// magic happens in method below
		//std::cout << "lol" << std::endl;
		g_engine->handleEvents();
	}
	g_engine->die();
}

// called from *game* thread
int initengine() {
	// this starts the thread, replaces int main()
	sf::Thread engineThread(&startEngine);
	initDone.Lock();	// note, no matching unlock here. it's done in engine thread.
	engineThread.Launch();
	for (int i = 5000; i > 0; --i) {
		std::cout << "main thread here" << std::endl;
	}

	// B. wait until that thing is signaled.
	sf::Lock lock( initDone );	// momentarily take the lock. waits until it's free

	return 0;
}

// called from *game* thread
void submitevent(int event) {
	g_engine->submitEvent(event);
}

BOOST_PYTHON_MODULE(miniengine) {
	using namespace boost::python;
	def("initengine", initengine);
	def("submitevent", submitevent);
}