timer: main.o functions.o
	g++ main.o functions.o -o timer 

main.o: main.cpp
	g++ -c main.cpp 

functions.o: functions.cpp functions.hpp
	g++ -c functions.cpp 

clean:
	rm *.o timer