
output: main.o graph.o 
	g++ main.o graph.o -o hw4

main.o: main.cpp
	g++ -c main.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp
	
clean:
	rm *.o hw4
