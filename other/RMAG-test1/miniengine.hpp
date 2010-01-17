#include <vector>
#include <string>

class Engine {

public:
	Engine();
	~Engine();

	void init();
	void die();

	// calculates events
	void handleEvents();
	void submitEvent(int);

	int fac(int);

private:
	std::vector<int> m_eventList;
};