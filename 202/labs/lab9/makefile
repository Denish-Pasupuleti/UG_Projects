CXX = g++
CXXFLAGS = -Wall

lab9: Dishwasher.o Appliance.o Stove.o lab9.cpp
	$(CXX) $(CXXFLAGS) Dishwasher.o Appliance.o Stove.o lab9.cpp -o lab9

Dishwasher.o: Appliance.o Dishwasher.h Dishwasher.cpp
	$(CXX) $(CXXFLAGS) -c Dishwasher.cpp

Stove.o: Appliance.o Stove.h Stove.cpp
	$(CXX) $(CXXFLAGS) -c Stove.cpp

Appliance.o: Appliance.h Appliance.cpp
	$(CXX) $(CXXFLAGS) -c Appliance.cpp

clean:
	rm *~

run:
	./lab9
