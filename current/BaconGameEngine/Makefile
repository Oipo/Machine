TARGET=lib/bacon.so
INCLUDE=include /usr/include/python2.6 /usr/include/ImageMagick
LIBS=boost_python boost_filesystem sfml-graphics sfml-window sfml-system python2.6 Magick++
CXXFLAGS=-Wall -Wextra -fPIC -shared -O2

LIBFLAGS := $(patsubst %,-l%,$(LIBS))
INCLUDEFLAGS := $(patsubst %,-I%,$(INCLUDE))

$(TARGET): src/*.cpp include/*.hpp
	g++ -o $@ $(CXXFLAGS) $(INCLUDEFLAGS) $(LIBFLAGS) src/*.cpp
