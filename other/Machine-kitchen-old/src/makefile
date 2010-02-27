builddir = ../build
bindir = ../bin
datadir = ../data
program = $(bindir)/machine

cxx = g++
srcs = main.cpp game.cpp state.cpp menustate.cpp menuentry.cpp gamestate.cpp
objs = $(srcs:%.cpp=$(builddir)/%.o)
flgs = -Wall -DSFML_DYNAMIC
libs = -lsfml-graphics -lsfml-window -lsfml-system

all: setup $(program)

run: setup $(program)
	./$(program)

clean:
	rm -rf $(bindir)
	rm -rf $(builddir)

setup:
	mkdir -p $(builddir)
	mkdir -p $(bindir)
	cp -R $(datadir) $(bindir)

$(program): $(objs)
	$(cxx) -o $(program) $(objs) $(libs)

$(builddir)/main.o: main.cpp
	$(cxx) $(flgs) -c $< -o $@

$(builddir)/%.o: %.cpp %.hpp
	$(cxx) $(flgs) -c $< -o $(builddir)/$@
