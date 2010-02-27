#include <string>
#include <boost/python.hpp>
#include "bacon.hpp"

BOOST_PYTHON_MODULE(bacon)
{
	using namespace boost::python;
	class_<Bacon>("bacon")
        .def("StartEngine", &Bacon::StartEngine)
        .def("Run", &Bacon::Run)
        .def("Shutdown", &Bacon::Shutdown)
        .def("RegisterPrototype", &Bacon::RegisterPrototype)
        .def("Spawn", &Bacon::Spawn)
        ;
};
