#ifndef PBBST_H_INCLUDED
#define PBBST_H_INCLUDED
#include "PbBSTNode.h"
#include <iostream>
using namespace std;

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Header file of PbBST: Contains
* its public and private data members and functions.
*/

class PbBST
{

public:

    PbBST();
    PbBST(TreeNode *node);
    ~PbBST();

    bool isEmpty();
    void destructTree(TreeNode* node);
    void insertKey(int key);
    void insertRecursive(TreeNode*& treePtr, const int &key);

    void deleteKey(int key);
    void deleteRecursive(TreeNode * &treePtr, int key);
    void deleteNode(TreeNode * &nodePtr);

    int getHeight();
    int getHeightHelper(TreeNode *node);

    int getNodeCount();
    int getNodeCountHelper(TreeNode *node);
    int findNodesRequired();

    void mirrorTree();
    void mirrorTreeHelper(TreeNode* node);

    int findFullBTLevel();
    int findFullBTLevelHelper(TreeNode* node);

    void printTree();
    void printTreeHelper(TreeNode* node);

    int nodeCountInLevel(TreeNode* node, int level);

    void processLeftmost(TreeNode *&nodePtr, int & treeItem);

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
    TreeNode* root;

};

#endif // PBBST_H_INCLUDED
