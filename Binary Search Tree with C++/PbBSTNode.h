#ifndef PBBSTNODE_H_INCLUDED
#define PBBSTNODE_H_INCLUDED
#include <iostream>
using namespace std;

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Header file for TreeNode class.
* Contains its functions and properties.
*/

class TreeNode {
private:
    TreeNode();
    TreeNode(const int &nodeItem, TreeNode *left = NULL, TreeNode *right = NULL);
    TreeNode(const TreeNode &node);

    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
    friend class PbBST;
};



#endif // PBBSTNODE_H_INCLUDED
