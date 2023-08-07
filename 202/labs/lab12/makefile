CXX = g++
CXXFLAGS = -Wall -g

lab12: Kennel.o lab12.cpp
	$(CXX) $(CXXFLAGS) Kennel.o lab12.cpp -o lab12

Kennel.o: Kennel.h Kennel.cpp
	$(CXX) $(CXXFLAGS) -c Kennel.cpp

clean:
	rm *.o
	rm *~

run:
	./lab12
