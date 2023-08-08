CXX = g++
CXXFLAGS = -Wall

lab10: Song.o lab10.cpp
	$(CXX) $(CXXFLAGS) Song.o lab10.cpp -o lab10

Song.o: Song.h Song.cpp
	$(CXX) $(CXXFLAGS) -c Song.cpp

clean:
	rm *~

run:
	./lab10
