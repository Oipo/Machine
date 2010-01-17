#include "miniengine.hpp"
#include <SFML/System.hpp>
#include <cassert>
#include <iostream>
#include <string>

Engine::Engine() {}
Engine::~Engine() {}

void Engine::init() {
	for (int i = 5000; i > 0; --i) {
		std::cout << "engine thread here" << std::endl;
	}
}

void Engine::die() {
}

// function called for testing to simulate thread "work"
int Engine::fac(int n) {
	assert(n >= 0 && "Fac is only defined on the natural numbers!");
	int m = n;
	while(n > 2) { // optimized to the fullest; ah, noobs.
		m *= --n;
	}
	return m;
}

void Engine::handleEvents() {
	std::vector<int>::const_iterator it;
	for(it = m_eventList.begin(); it != m_eventList.end(); ++it) {
		std::cout << *it << " - " << fac(*it) << std::endl;
	}
	m_eventList.clear();
	//std::cout << "omg" << std::endl;
}

void Engine::submitEvent(int event) {
	m_eventList.push_back(event); // engine thread!
}