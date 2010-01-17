LIBS=boost_python sfml-graphics sfml-network sfml-system
CXXFLAGS=-Wall -Wextra -fPIC -shared -O2

bacon.so:
	g++ -o bacon.so $(CXXFLAGS) $(patsubst %,-l%,$(LIBS)) -Iinclude *.cpp