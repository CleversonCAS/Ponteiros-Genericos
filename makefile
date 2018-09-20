main:	main.o imp.o 
	g++	 main.o imp.o -Wall

main.o: main.cpp
	g++  -c main.cpp -std=c++11 -Wall

imp.o: imp.cpp 
	g++	-c imp.cpp -std=c++11 -Wall

fun.o: fun.h 
	g++ -c fun.h -std=c++11 -Wall

clean:
	rm *.o