
output: main.o AVLTree.o AVLTreeNode.o heightAnalysis.o
	g++ main.o AVLTree.o AVLTreeNode.o heightAnalysis.o -o hw3

main.o: main.cpp
	g++ -c main.cpp

PbBSTNode.o: AVLTreeNode.cpp AVLTreeNode.h
	g++ -c AVLTreeNode.cpp

PbBST.o: AVLTree.cpp AVLTree.h
	g++ -c AVLTree.cpp

analysis.o: heightAnalysis.cpp heightAnalysis.h
	g++ -c heightAnalysis.cpp

clean:
	rm *.o hw3
