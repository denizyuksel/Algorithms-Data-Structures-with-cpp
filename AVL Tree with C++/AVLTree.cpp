/**
* Title : Heaps and AVL Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 3
* Description : Implementation of the AVLTree.
*/


#include "AVLTree.h"
#include "AVLTreeNode.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::AVLTree(TreeNode *node)
{
    root = node;
}

AVLTree::~AVLTree()
{
    destructTree(root);
}

bool AVLTree::isEmpty()
{
    return ( root == NULL);
}

void AVLTree::destructTree(TreeNode* node)
{
    if (node != NULL)
    {
        destructTree(node->leftChildPtr);
        destructTree(node->rightChildPtr);
        delete node;
        node = NULL;
    }
}

void AVLTree::insert( int key)
{
    root = insertAndBalance( root, key);
}

TreeNode* AVLTree::insertAndBalance(TreeNode *& treePtr, const int &key)
{
    // Regular BST insertion.
    if (treePtr == NULL)
    {
        treePtr = new TreeNode(key, NULL, NULL);
        return treePtr;
    }

    if (key < treePtr->item)
        treePtr->leftChildPtr = insertAndBalance(treePtr->leftChildPtr, key);
    else if( key > treePtr->item)
        treePtr->rightChildPtr = insertAndBalance(treePtr->rightChildPtr, key);
    else
        return treePtr;

    // 2. Update height the node.
    treePtr->height = 1 + max(getHeightHelper(treePtr->leftChildPtr), getHeightHelper(treePtr->rightChildPtr));
    /* 3. Get the balance factor.
     If positive, left side is heavier.
     If negative, right side is heavier.
     If 0, perfectly balanced.
     There is no balance problem if balance factor is [+-] 1.
    */
    int balanceFactor = getBalanceFactor(treePtr);

    // 4. if the node is unbalanced, there are four cases:
    // Left subtree of left child (outside):

    if (balanceFactor > 1 && key < treePtr->leftChildPtr->item)
    {
        return rightRotate(treePtr);
    }
    // inside cases:
    // inside right:
    if (balanceFactor > 1 && key > treePtr->leftChildPtr->item)
    {
        treePtr->leftChildPtr =  leftRotate(treePtr->leftChildPtr);
        return rightRotate(treePtr);
    }

    // inside left:
    if (balanceFactor < -1 && key < treePtr->rightChildPtr->item)
    {
        treePtr->rightChildPtr = rightRotate(treePtr->rightChildPtr);
        return leftRotate(treePtr);
    }

    // Right subtree of right child (outside):
    if (balanceFactor < -1 && key > treePtr->rightChildPtr->item)
    {
        return leftRotate(treePtr);
    }
    /* return the (unchanged) node pointer */
    return treePtr;
}

void AVLTree::deleteKey( int key)
{
    deleteAndBalance(root, key);
}

TreeNode* AVLTree::deleteAndBalance(TreeNode * &treePtr, int key)
{
   if (treePtr == NULL) // Empty tree
        return treePtr;

    // Position of deletion found
    else if (key == treePtr->item)
        deleteNode(treePtr);

    // Else search for the deletion position
    else if (key < treePtr->item)
        deleteAndBalance(treePtr->leftChildPtr, key);
    else
        deleteAndBalance(treePtr->rightChildPtr, key);

    if (treePtr == NULL)
      return treePtr;
    //2. SAME PROCEDURE WITH ADDITION, UPDATE HEIGHT.
    treePtr->height = 1 + max(getHeightHelper(treePtr->leftChildPtr), getHeightHelper(treePtr->rightChildPtr));

    //3. Get balance factor.

    int balanceFactor = getBalanceFactor(treePtr);
    // 4. if the node is unbalanced, there are four cases:
    // Left subtree of left child (outside):
    if (balanceFactor > 1 && getBalanceFactor(treePtr->leftChildPtr) >= 0)
    {
        return rightRotate(treePtr);
    }
    // inside cases:
    if (balanceFactor > 1 && getBalanceFactor(treePtr->leftChildPtr) < 0)
    {
        treePtr->leftChildPtr =  leftRotate(treePtr->leftChildPtr);
        return rightRotate(treePtr);
    }

    if (balanceFactor < -1 && getBalanceFactor(treePtr->rightChildPtr) > 0)
    {
        treePtr->rightChildPtr = rightRotate(treePtr->rightChildPtr);
        return leftRotate(treePtr);
    }

    // Right subtree of right child (outside):
    if (balanceFactor < -1 && getBalanceFactor(treePtr->rightChildPtr) <= 0)
    {
        return leftRotate(treePtr);
    }
    /* return the (unchanged) node pointer */
    return treePtr;
}

void AVLTree::deleteNode(TreeNode * &nodePtr)
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
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else
    {
        processLeftmost(nodePtr->rightChildPtr, replacementItem);
        nodePtr->item = replacementItem;
    }

}

void AVLTree::processLeftmost(TreeNode *&nodePtr, int & key)
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
int AVLTree::getHeight()
{
    return getHeightHelper(root);
}

// helper method for finding the height of the BST
int AVLTree::getHeightHelper(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int left = getHeightHelper(node->leftChildPtr);
    int right = getHeightHelper(node->rightChildPtr);

    return 1 + max(left, right);
}

int AVLTree::getNodeCount()
{
    return getNodeCountHelper( root);
}

int AVLTree::getNodeCountHelper(TreeNode *node)
{
    if ( node == NULL)
        return 0;
    return 1 + getNodeCountHelper(node->leftChildPtr) + getNodeCountHelper(node->rightChildPtr);

}

int AVLTree::findNodesRequired()
{
    int nodeCount = getNodeCount();
    int height = getHeight();
    int nodeCountWhenFullTree = pow( 2, height) - 1;
    return nodeCountWhenFullTree - nodeCount;
}

void AVLTree::mirrorTree()
{
    mirrorTreeHelper(root);
}

void AVLTree::mirrorTreeHelper(TreeNode* node)
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

int AVLTree::findFullBTLevel()
{
    return findFullBTLevelHelper( root);
}

int AVLTree::findFullBTLevelHelper(TreeNode* node)
{
    int nodeByLevel = 0;
    int nivel = 1;
    int reqNodeByLevel = pow(2, nivel);
    bool levelUp;
    Queue Q;
    TreeNode* temp = node;

    if( node == NULL)
        return 0;

    else if( node->leftChildPtr == NULL && node->rightChildPtr == NULL)
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

int AVLTree::nodeCountInLevel(TreeNode* node, int level)
{
    int nodeCount = 0;
    if( level == 1)
        return 1;

    return nodeCount;
}

void AVLTree::printTree()
{
    printTreeHelper(root);
}

void AVLTree::printTreeHelper(TreeNode* node)
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

void AVLTree::printTreeCute(TreeNode* node)
{

}

TreeNode* AVLTree::rightRotate(TreeNode* node)
{
    TreeNode *k1 = node->leftChildPtr;
    TreeNode *k2 = k1->rightChildPtr;

    // Perform rotation
    k1->rightChildPtr = node;
    node->leftChildPtr = k2;

    // Update heights
    node->height= max(getHeightHelper(node->leftChildPtr), getHeightHelper(node->rightChildPtr))+1;
    k1->height = max(getHeightHelper(k1->leftChildPtr), getHeightHelper(k1->rightChildPtr))+1;

    // Return new root
    return k1;

}

TreeNode* AVLTree::leftRotate(TreeNode* node)
{
    TreeNode *k1 = node->rightChildPtr;
    TreeNode *k2 = k1->leftChildPtr;

    // Perform rotation
    k1->leftChildPtr = node;
    node->rightChildPtr = k2;

    //  Update heights
    node->height = max(getHeightHelper(node->leftChildPtr), getHeightHelper(node->rightChildPtr))+1;
    k1->height = max(getHeightHelper(k1->leftChildPtr), getHeightHelper(k1->rightChildPtr))+1;

    // Return new root
    return k1;
}

int AVLTree::getBalanceFactor(TreeNode* node)
{
    if (node == NULL)
        return 0;
    return getHeightHelper(node->leftChildPtr) - getHeightHelper(node->rightChildPtr);
}

/*
--------------------------------QUEUE STUFF STARTS--------------------------------
*/

AVLTree::Queue::Queue(): backPtr(NULL), frontPtr(NULL)
{

}

AVLTree::Queue::~Queue()
{

    while (!isEmpty())
        dequeue();
}

bool AVLTree::Queue::isEmpty() const
{
    return backPtr == NULL;
}

bool AVLTree::Queue::enqueue(TreeNode* newItem)
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

bool AVLTree::Queue::dequeue()
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

bool AVLTree::Queue::dequeue(TreeNode*& queueFront)
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

TreeNode* AVLTree::Queue::getFront()
{
    return frontPtr->item;
}

//-------------------------------------- QUEUE STUFF FINISHED --------------------------------------
