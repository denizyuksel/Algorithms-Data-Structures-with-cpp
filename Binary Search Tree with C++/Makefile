
output: main.o PbBST.o PbBSTNode.o analysis.o
	g++ main.o PbBST.o PbBSTNode.o analysis.o -o hw2

main.o: main.cpp
	g++ -c main.cpp

PbBSTNode.o: PbBSTNode.cpp PbBSTNode.h
	g++ -c PbBSTNode.cpp

PbBST.o: PbBST.cpp PbBST.h
	g++ -c PbBST.cpp

analysis.o: analysis.cpp analysis.h
	g++ -c analysis.cpp

clean:
	rm *.o hw2
