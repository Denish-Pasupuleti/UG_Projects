CXX = g++
CXXFLAGS = -Wall

lab8: LinkedList.o lab8.cpp
	$(CXX) $(CXXFLAGS) LinkedList.o lab8.cpp -o lab8

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CXX) $(CXXFLAGS) -c LinkedList.cpp

run:
	./lab8

clean:
	rm *~
