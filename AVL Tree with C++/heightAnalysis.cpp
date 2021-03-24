/**
* Title : Heaps and AVL Trees
* Author : Deniz Yüksel
* ID: 21600880
* Section : 1
* Assignment : 3
* Description : Implementation of the heightAnalysis function.
*/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "heightAnalysis.h"
#include "AVLTree.h"

using namespace std;

void heightAnalysis()
{

    const int SIZE = 80000;
    const int INTERVAL = 4000;
    AVLTree myAVLTreeRand;
    AVLTree myAVLAscend;
    AVLTree myAVLDescend;

    int rngArray[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        rngArray[i] = rand();
    }

    int ascendingArray[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        ascendingArray[i] = i;
    }

    int descendingArray[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        descendingArray[i] = SIZE - i;
    }


    cout << "Part b - Height analysis of AVL trees" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << left << setw(5) << "Array Size ";
    cout << right << setw(15) << "Random";
    cout << right << setw(15) << "Ascending";
    cout << right << setw(15) << "Descending" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        myAVLTreeRand.insert(rngArray[i]);
        myAVLAscend.insert(ascendingArray[i]);
        myAVLDescend.insert(descendingArray[i]);
        if ((i + 1) % INTERVAL == 0)
        {
            cout << left << setw(5) << i + 1;
            cout << right << setw(20) << myAVLTreeRand.getHeight();
            cout << right << setw(15) << myAVLAscend.getHeight();
            cout << right << setw(15) << myAVLDescend.getHeight() << endl;
        }
    }
    cout << endl << endl;
}



