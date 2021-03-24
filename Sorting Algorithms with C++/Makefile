
hw1: main.o sorting.o
	g++ main.o sorting.o -o hw1

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

clean:
	rm *.o hw1
