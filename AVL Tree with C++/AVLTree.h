/**
* Title : Heaps and AVL Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 3
* Description : Header file for the AVLTree class.
*/

#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED
#include "AVLTreeNode.h"
#include <iostream>
using namespace std;

/**
* Title : AVL Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 3
* Description : Header file of AVLTree: Contains
* its public and private data members and functions.
*/

class AVLTree
{

public:

    AVLTree();
    AVLTree(TreeNode *node);
    ~AVLTree();

    bool isEmpty();
    void destructTree(TreeNode* node);
    void insert(int val);
    void deleteKey(int val);
    void deleteNode(TreeNode * &node);
    int getHeight();
    int getNodeCount();
    int getNodeCountHelper(TreeNode *nodePtr);
    int findNodesRequired();
    void mirrorTree();
    int findFullBTLevel();
    void printTree();


    int nodeCountInLevel(TreeNode* node, int level);

    class Queue
    {
    public:
        Queue();
        ~Queue();
        struct QueueNode
        {
            TreeNode     *item;
            QueueNode     *next;
        };
        // Queue operations:
        bool isEmpty() const;
        bool enqueue(TreeNode* newItem);
        bool dequeue();
        bool dequeue(TreeNode*& queueFront);
        TreeNode* getFront();
        QueueNode *backPtr;
        QueueNode *frontPtr;
    };

private:
    //Helper & private Functions
    TreeNode* insertAndBalance(TreeNode*& treePtr, const int &key);
    TreeNode* deleteAndBalance(TreeNode * &treePtr, int key);
    int getHeightHelper(TreeNode *node);
    void mirrorTreeHelper(TreeNode* node);
    int findFullBTLevelHelper(TreeNode* node);
    void printTreeHelper(TreeNode* node);
    TreeNode* rightRotate(TreeNode* node);
    TreeNode* leftRotate(TreeNode* node);
    int getBalanceFactor(TreeNode* node);
    void processLeftmost(TreeNode *&nodePtr, int & treeItem);
    void printTreeCute(TreeNode* node);

    TreeNode* root;
};

#endif // AVLTREE_H_INCLUDED
