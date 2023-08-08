CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp Homework.o
	$(CXX) $(CXXFLAGS) lab6.cpp Homework.o -o lab6

Homework.o: Homework.h Homework.cpp
	$(CXX) $(CXXFLAGS) -c Homework.cpp

run:
	./lab6

clean:
	rm *~
