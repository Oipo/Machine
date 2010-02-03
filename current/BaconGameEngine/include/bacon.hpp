#ifndef _BACON_HPP_INCLUDED
#define _BACON_HPP_INCLUDED

void StartEngine();
void Run();
void Shutdown();
void RegisterPrototype( std::string const & type, 
			boost::python::object prototype );
boost::python::object Spawn( std::string const & type, int x, int y );

// Introduce `interface` as a synonym for `class`, to be used when defining 
// pure virtual bases.
#define interface class

interface ITask 
{ 
public:
	virtual ~ITask() = 0; 
	virtual void OnTick() = 0; 
};

/* well-known tasks */
ITask * CreateVideoTask();
ITask * CreateInputTask();

class Entity
{
	boost::python::object pythonObject;	// ref?
public:
	// etc etc
};

#endif