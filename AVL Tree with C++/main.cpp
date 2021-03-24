/**
* Title : Heaps and AVL Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 3
* Description : main function.
*/

#include <iostream>
#include "AVLTree.h"
#include "heightAnalysis.h"
using namespace std;

int main()
{
    AVLTree myTree;

/**
creates an AVLTree object, inserts the following elements into it: {5, 10, 15, 60, 8,
40, 2, 30, 17, 12, 74}, then deletes the following elements: {30, 10, 8, 74, 5}. Also
prints the tree exactly 2 times; after the nal insertion and after the nal deletion
*/

   myTree.insert(5);
   myTree.insert(10);
   myTree.insert(15);
   myTree.insert(60);
   myTree.insert(8);
   myTree.insert(40);
   myTree.insert(2);
   myTree.insert(30);
   myTree.insert(17);
   myTree.insert(12);
   myTree.insert(74);
   myTree.printTree();
	cout << "\n";
   myTree.deleteKey(30);
   myTree.deleteKey(10);
   myTree.deleteKey(8);
   myTree.deleteKey(74);
   myTree.deleteKey(5);
   myTree.printTree();
	cout << "\n";


    heightAnalysis();


    return 0;
}

