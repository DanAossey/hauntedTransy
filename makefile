hauntedTransy : hauntedTransyDriver.o car.o people.o
	g++  hauntedTransyDriver.o car.o people.o -lpthread -lrt -o hauntedTransy 
hauntedTransyDriver.o : hauntedTransyDriver.cpp
	g++ -c hauntedTransyDriver.cpp
car.o : car.h car.cpp
	g++ -c car.cpp
people.o : people.h people.cpp
	g++ -c people.cpp
