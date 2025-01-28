CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: test

clean: 
	rm -f *.o test

test: test.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test