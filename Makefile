#!make -f

CXX=g++
CXXFLAGS=-std=c++14 -Werror -Wsign-conversion -pedantic -g
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
LDLIBS=-pthread

SOURCES = tree.cpp Iterator.cpp node.cpp complex.cpp main.cpp 
HEADERS = tree.hpp Iterator.hpp node.hpp complex.hpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLES = tree
all: $(EXECUTABLES) 

run: tree
	./$^



tree: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)
	./$@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: tree
	# valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	# valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
	


%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@


clean:
	rm -f *.o $(EXECUTABLES)
 