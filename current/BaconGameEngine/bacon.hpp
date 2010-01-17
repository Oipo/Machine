#ifndef _BACON_INCLUDED_HPP
#define _BACON_INCLUDED_HPP

void StartEngine();
void Run();
void Shutdown();

// Introduce `interface` as a synonym for `class`, to be used when defining 
// pure virtual bases.
#define interface class

interface ITask 
{ 
public:
	virtual ~ITask() = 0; 
	virtual void OnTick() = 0; 
};

class Entity
{
	boost::python::object pythonObject;	// ref?
public:
	// etc etc
};

#endif