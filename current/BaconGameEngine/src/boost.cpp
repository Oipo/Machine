#include <string>
#include <boost/python.hpp>
#include "bacon.hpp"

BOOST_PYTHON_MODULE(bacon)
{
	using namespace boost::python;
	def("StartEngine", StartEngine);
	def("Run", Run);
	def("Shutdown", Shutdown);
	def("RegisterPrototype", RegisterPrototype);
	def("Spawn", Spawn);
};