CXX = g++
CXXFLAGS = -Wall
lab5: Animal.o lab5.cpp
	$(CXX) $(CXXFLAGS) Animal.o lab5.cpp -o lab5
Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp
