#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <time.h>
#include "analysis.h"
#include "PbBST.h"
using namespace std;

/**
* Title : Binary Search Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 2
* Description : Implementation of analysis global function.
*/

void analysis()
{

    PbBST tree;
    int size = 15000;

    int* arr = new int[size];

    for( int i = 0; i < size; i++)
    {
        int random = rand() % size + 1;
        arr[i] = random;
    }

    cout << "Part e - Time analysis of Binary Search Tree - part 1 " << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << left << setw(20) << "Tree Size ";
    cout << right << setw(20) << "Time Elapsed" << endl;
    cout << "-------------------------------------------------------" << endl;
    clock_t t1;
    t1 = clock();
    int printInterval = 1500;
    for( int i = 0; i < size; i++)
    {
        tree.insertKey(arr[i]);
        if( i == printInterval - 1)
        {
            t1 = clock() - t1;

            cout << left << setw(20) << printInterval;
            cout << right << setw(20) << t1;
            cout << "\n";

            printInterval = printInterval + 1500;
        }
    }

    random_shuffle(&arr[0], &arr[15000]);
    cout << "Part e - Time analysis of Binary Search tree - part 2 " << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << left << setw(20) << "Tree Size ";
    cout << right << setw(20) << "Time Elapsed" << endl;
    cout << "-------------------------------------------------------" << endl;
    clock_t t2;
    t2 = clock();
    int treeSize = tree.getNodeCount();
    printInterval = 15000;
    for( int i = treeSize - 1; i >= 0; i--)
    {
        tree.deleteKey(arr[i]);
        if( i == printInterval - 1500)
        {
            t2 = clock() - t2;
            cout << left << setw(20) << printInterval;
            cout << right << setw(20) << t2;
            cout << "\n";

            printInterval = printInterval - 1500;
        }
    }

}

