#include <iostream>
using namespace std;
#include "PbBSTNode.h"

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Implementation of TreeNode class.
*/

TreeNode::TreeNode(){
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

TreeNode::TreeNode(const int &nodeItem, TreeNode *leftPtr, TreeNode *rightPtr) :item(nodeItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) {
    item = nodeItem;
    leftPtr = leftChildPtr;
    rightPtr = rightChildPtr;
}

TreeNode::TreeNode(const TreeNode &node){
    item = node.item;
    leftChildPtr = node.leftChildPtr;
    rightChildPtr = node.rightChildPtr;
}
