#include <iostream>
#include "PbBST.h";
#include "PbBSTNode.h"
#include "analysis.h"
using namespace std;

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Driver file to test the project.
*/

int main(){

    PbBST tree;

    // insert in this order:7; 3; 6; 12; 13; 4; 1; 9; 15; 0; 11; 14; 2; 8; 14; 5
    tree.insertKey(7);
    tree.insertKey(3);
    tree.insertKey(6);
    tree.insertKey(12);
    tree.insertKey(13);
    tree.insertKey(4);
    tree.insertKey(1);
    tree.insertKey(9);
    tree.insertKey(15);
    tree.insertKey(0);
    tree.insertKey(11);
    tree.insertKey(14);
    tree.insertKey(2);
    tree.insertKey(8);
    tree.insertKey(14);
    tree.insertKey(5);

    cout << "Find Nodes Required Method: " << tree.findNodesRequired() << endl;
    tree.deleteKey(8);
    tree.deleteKey(7);
    cout << "findFullBTLevel Method: " << tree.findFullBTLevel() << endl;
    tree.mirrorTree();
    tree.printTree();
    cout << endl;

return 0;
}
