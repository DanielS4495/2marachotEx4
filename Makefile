# #!make -f

# CXX=clang++
# CXXFLAGS=-std=c++17 -Werror -Wsign-conversion -pedantic -g
# VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99
# LDLIBS=-pthread

# # SOURCES = Tree.cpp Iterator.cpp  complex.cpp Demo.cpp 
# # HEADERS = TreeNode.hpp Tree.hpp Iterator.hpp  complex.hpp
# # OBJECTS = $(SOURCES:.cpp=.o)
# EXECUTABLES = Tree
# all: $(EXECUTABLES) 

# run: Tree
# 	./$^

# Tree.o: Tree.cpp Tree.hpp TreeNode.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# Iterator.o: Iterator.cpp Iterator.hpp TreeNode.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# complex.o: complex.cpp complex.hpp	
# 	$(CXX) $(CXXFLAGS) -c $< -o $@


# Demo.o: Demo.cpp Tree.hpp TreeNode.hpp Iterator.hpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# Tree: Tree.o Iterator.o complex.o Demo.o 
# 	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)
# 	./$@


# tidy:
# 	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# valgrind: Tree
# 	# valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
# 	# valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }
	


# %.o: %.cpp $(HEADERS)
# 	$(CXX) $(CXXFLAGS) --compile $< -o $@


# clean:
# 	rm -f *.o $(EXECUTABLES)
# /////////////////////////////////////////////////
# CXX = clang++
# CXXFLAGS = -std=c++17 -Werror -Wsign-conversion -pedantic -g

# all: Demo



# Demo: Demo.o TreeNode.hpp Tree.hpp
# 	$(CXX) $(CXXFLAGS) Demo.o TreeNode.hpp Tree.hpp -o Demo  $(LDFLAGS)

# Demo.o: Demo.cpp TreeNode.hpp Tree.hpp
# 	$(CXX) $(CXXFLAGS) -c Demo.cpp


# Iterator.o: Iterator.cpp Iterator.hpp
# 	$(CXX) $(CXXFLAGS) -c Iterator.cpp

# complex.o: complex.cpp
# 	$(CXX) $(CXXFLAGS) -c complex.cpp

# clean:
# 	rm -f *.o Demo

