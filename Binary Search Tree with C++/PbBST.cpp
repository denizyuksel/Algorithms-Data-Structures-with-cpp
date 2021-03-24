#include <iostream>
#include <math.h>
using namespace std;
#include "PbBST.h"
#include "PbBSTNode.h"

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Implementation of PbBST class.
*/

PbBST::PbBST()
{
    root = NULL;
}

PbBST::PbBST(TreeNode *node)
{
    root = node;
}

PbBST::~PbBST()
{
    destructTree(root);
}

bool PbBST::isEmpty()
{
    return ( root == NULL);
}

void PbBST::destructTree(TreeNode* node)
{
    if (node != NULL)
    {
        destructTree(node->leftChildPtr);
        destructTree(node->rightChildPtr);
        delete node;
        node = NULL;
    }
}

/*
    Queue stuff...
*/

PbBST::Queue::Queue(): backPtr(NULL), frontPtr(NULL)
{

}

PbBST::Queue::~Queue()
{

    while (!isEmpty())
        dequeue();
}

bool PbBST::Queue::isEmpty() const
{
    return backPtr == NULL;
}

bool PbBST::Queue::enqueue(TreeNode* newItem)
{

    QueueNode *newPtr = new QueueNode;

    newPtr->item = newItem;
    newPtr->next = NULL;


    if (isEmpty())
        frontPtr = newPtr;
    else
        backPtr->next = newPtr;

    backPtr = newPtr;

    return true;
}

bool PbBST::Queue::dequeue()
{

    if (isEmpty())
        return false;

    else
    {
        // queue is not empty; remove front
        QueueNode *tempPtr = frontPtr;

        if (frontPtr == backPtr)    // special case
        {
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;

        tempPtr->next = NULL;  // defensive strategy
        delete tempPtr;
        return true;
    }
}

bool PbBST::Queue::dequeue(TreeNode*& queueFront)
{

    if (isEmpty())
        return false;

    else
    {
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;
        dequeue();  // delete front

        return true;
    }

}

TreeNode* PbBST::Queue::getFront()
{
    return frontPtr->item;
}

void PbBST::insertKey( int key)
{
    insertRecursive( root, key);
}

void PbBST::insertRecursive(TreeNode *& treePtr, const int &key)
{
    // Position of insertion found; insert after leaf
    if (treePtr == NULL)
    {
        treePtr = new TreeNode(key, NULL, NULL);
        if (treePtr == NULL)
            cout << "Insert failed" << endl;
    }
    // Else search for the insertion position
    else if (key < treePtr->item)
        insertRecursive(treePtr->leftChildPtr, key);
    else
        insertRecursive(treePtr->rightChildPtr, key);
}


void PbBST::deleteKey( int key)
{
    deleteRecursive(root, key);
}

void PbBST::deleteRecursive(TreeNode * &treePtr, int key)
{
    if (treePtr == NULL) // Empty tree
        cout << "Delete failed" << endl;

    // Position of deletion found
    else if (key == treePtr->item)
        deleteNode(treePtr);

    // Else search for the deletion position
    else if (key < treePtr->item)
        deleteRecursive(treePtr->leftChildPtr, key);
    else
        deleteRecursive(treePtr->rightChildPtr, key);
}

void PbBST::deleteNode(TreeNode * &nodePtr)
{
    TreeNode *delPtr;
    int replacementItem;


    // (1)  Test for a leaf
    if ( (nodePtr->leftChildPtr == NULL) &&
            (nodePtr->rightChildPtr == NULL) )
    {
        delete nodePtr;
        nodePtr = NULL;
    }


    // (2)  Test for no left child
    else if (nodePtr->leftChildPtr == NULL)
    {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL;
        delete delPtr;
    }
// (3)  Test for no right child
    else if (nodePtr->rightChildPtr == NULL)
    {
        // ...
        // Left as an exercise
    }


    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else
    {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }

}

void PbBST::processLeftmost(TreeNode *&nodePtr, int & key)
{

    if (nodePtr->leftChildPtr == NULL)
    {
        key = nodePtr->item;
        TreeNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, key);
}

/*getHeight calls getHeightHelper because we have to have the getHeight method without
parameters -.-*/
int PbBST::getHeight()
{
    return getHeightHelper(root);
}

// helper method for finding the height of the BST
int PbBST::getHeightHelper(TreeNode *node)
{
    if (node == NULL)
        return 0;

    return 1 + max( getHeightHelper(node->leftChildPtr), getHeightHelper(node->rightChildPtr));
}

int PbBST::getNodeCount()
{
    return getNodeCountHelper( root);
}

int PbBST::getNodeCountHelper(TreeNode *node)
{
    if ( node == NULL)
        return 0;
    return 1 + getNodeCountHelper(node->leftChildPtr) + getNodeCountHelper(node->rightChildPtr);

}

int PbBST::findNodesRequired()
{
    int nodeCount = getNodeCount();
    int height = getHeight();
    int nodeCountWhenFullTree = pow( 2, height) - 1;
    return nodeCountWhenFullTree - nodeCount;
}

void PbBST::mirrorTree()
{
    mirrorTreeHelper(root);
}

void PbBST::mirrorTreeHelper(TreeNode* node)
{
    if( node == NULL)
        return;
    else
    {
        TreeNode* temp;

        //recurse to left subtree.
        mirrorTreeHelper( node->leftChildPtr);
        //recurse to right subtree.
        mirrorTreeHelper( node->rightChildPtr);

        //swap the pointers.
        temp = node->leftChildPtr;
        node->leftChildPtr = node->rightChildPtr;
        node->rightChildPtr = temp;

    }
}

int PbBST::findFullBTLevel()
{
    return findFullBTLevelHelper( root);
}

int PbBST::findFullBTLevelHelper(TreeNode* node)
{
    int nodeByLevel = 0;
    int nivel = 1;
    int reqNodeByLevel = pow(2, nivel);
    bool levelUp;
    Queue Q;
    TreeNode* temp = node;

    if( node == NULL)
        return 0;

    else if( node -> leftChildPtr == NULL && node->rightChildPtr == NULL)
        return 1;
    else
    {
        Q.enqueue(temp);
        while( !Q.isEmpty())
        {
            levelUp = false;
            temp = Q.getFront();
            Q.dequeue();

            if( temp->leftChildPtr == NULL || temp->rightChildPtr == NULL)
            {
                return nivel;
            }
            else
            {
                Q.enqueue(temp->leftChildPtr);
                Q.enqueue(temp->rightChildPtr);
                nodeByLevel = nodeByLevel + 2;
            }
            if( nodeByLevel >= 2 && nodeByLevel == reqNodeByLevel)
            {
                levelUp = true;
                nivel++;
            }
            if( levelUp)
            {
                reqNodeByLevel = pow(2, nivel);
                nodeByLevel = 0;
            }
        }
        return nivel;
    }
}

int PbBST::nodeCountInLevel(TreeNode* node, int level)
{
    int nodeCount = 0;
    if( level == 1)
        return 1;

    return nodeCount;
}

void PbBST::printTree()
{
    printTreeHelper( root);
}

void PbBST::printTreeHelper(TreeNode* node)
{
    if( node == NULL)
        return;

    printTreeHelper(node->leftChildPtr);
    cout << node->item << " ";
    printTreeHelper(node->rightChildPtr);
    // I tried so hard to do this method, but I could not manage.
    // it always gave stupid results, so I sacrifice 10 points
    // and made a inorder traversal print.
}

