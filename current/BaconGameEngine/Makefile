TARGET=bacon.so
INCLUDE=include /usr/include/python2.6
LIBS=boost_python sfml-graphics sfml-network sfml-system python2.6 Magick++
CXXFLAGS=-Wall -Wextra -fPIC -shared -O2

LIBFLAGS := $(patsubst %,-l%,$(LIBS))
INCLUDEFLAGS := $(patsubst %,-I%,$(INCLUDE))

SOURCES := $(shell /bin/ls *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
DEPS := $(SOURCES:.cpp=.o.dep)

.SUFFIXES:
.PHONY: default clean

%.o.dep: %.cpp
	@echo DEP $<
	@g++ -MM -MF $@ $(CXXFLAGS) $< $(INCLUDEFLAGS)

-include $(DEPS)

%.o: %.cpp
	@echo g++ $<
	@g++ -o $@ $(CXXFLAGS) $< $(INCLUDEFLAGS)

$(TARGET): $(OBJECTS)
	@echo LINK $@
	@g++ -o bacon.so $(CXXFLAGS) $(OBJECTS) $(LIBFLAGS)

clean:
	rm *.o *.o.dep $(TARGET)

all: clean $(TARGET)