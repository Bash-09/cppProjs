main: main.o something.o
	g++ main.o something.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

something.o: something.cpp
	g++ -c something.cpp -o something.o

clean:
	rm *.o main