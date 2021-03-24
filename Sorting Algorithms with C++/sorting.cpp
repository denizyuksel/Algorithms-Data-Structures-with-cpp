#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <iomanip>
#include "sorting.h"
using namespace std;

/*
* Title : Algorithm Efficiency and Sorting
* Author : Deniz Yüksel
* ID : 21600880
* Section : 1
* Assignment : 1
* Description : this is the sorting.cpp class in which
the sorting algorithms and the performanceAnalysis
function are implemented.
*/

Sorting::Sorting()
{
    int compCount = 0;
    int moveCount = 0;
}

const int MAX_SIZE = 100000;

void Sorting::printArray(DataType arr[], int n)
{
    for( int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

void Sorting::insertionSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    for (int unsorted = 1; unsorted < last + 1; ++unsorted)
    {
        int nextItem = arr[unsorted];
        moveCount++;
        int loc = unsorted;
        while( loc > 0)
        {
            if( arr[loc-1] > nextItem)
            {
                compCount++;
                arr[loc] = arr[loc-1];
                moveCount++;
                loc--;
            }
            else
            {
                compCount++;
                break;
            }
        }
        if( loc != unsorted)
        {
            arr[loc] = nextItem;
            moveCount++;
        }
    }
}

void Sorting::merge( int* arr, int first, int mid, int last, int &compCount, int &moveCount)
{
    int tempArray[25000];

    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    while( first1 <= last1 && first2 <= last2)
    {
        if (arr[first1] < arr[first2])
        {
            tempArray[index] = arr[first1];
            moveCount++;
            ++first1;
        }
        else
        {
            tempArray[index] = arr[first2];
            moveCount++;
            ++first2;
        }
        index++;
        compCount++;
    }

    // NO KEY COMPARISON BELOW HERE.
    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = arr[first1];
        moveCount++;
    }

    for (; first2 <= last2; ++first2, ++index)
    {
        tempArray[index] = arr[first2];
        moveCount++;
    }

    for (index = first; index <= last; ++index)
    {
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void Sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    if (first < last)
    {
        int mid = (first + last)/2;

        mergeSort(arr, first, mid, compCount, moveCount);

        mergeSort(arr, mid+1, last, compCount, moveCount);


        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void Sorting::quickSort( int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;

    if (first < last)
    {

        partition(arr, first, last, pivotIndex, compCount, moveCount);

        quickSort(arr, first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }
}


void Sorting::partition(int* arr, int first, int last,
                        int &pivotIndex, int &compCount, int &moveCount)
{

    int pivot = arr[last];
    moveCount++;
    int lastS1 = last;
    int firstUnknown = last - 1;


    for (  ; firstUnknown >= first; --firstUnknown)
    {
        if (arr[firstUnknown] > pivot)
        {
            compCount++;
            --lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount++;
        }
        else{
            compCount++;
        }
    }
    swap(arr[last], arr[lastS1]);
    moveCount++;
    pivotIndex = lastS1;
}

void Sorting::hybridSort(int *arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;

    if (first < last)
    {
        if( last - first + 1 > 10)
        {
            partition(arr, first, last, pivotIndex, compCount, moveCount);

            hybridSort(arr, first, pivotIndex-1, compCount, moveCount);
            hybridSort(arr, pivotIndex+1, last, compCount, moveCount);
        }
        else
        {
            insertionSort(arr, first, last, compCount, moveCount);
        }
    }
}


void Sorting::performanceAnalysis( int n)
{
    //FOR RNG!!!
    //1
    int* arr1 = new int[n];

    for( int i = 0; i < n; i++)
    {
        int random = rand() % n + 1;
        arr1[i] = random;
    }

    int* arr2 = new int[n];
    for( int i = 0; i < n; i++)
    {
        arr2[i] = arr1[i];
    }

    int* arr3 = new int[n];
    for( int i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }

    int* arr4 = new int[n];
    for( int i = 0; i < n; i++)
    {
        arr4[i] = arr1[i];
    }

    //FOR INCREASING NUMBERS!!!
    //5
    int* arr5 = new int[n];
    for( int i = 0; i < n; i++)
        arr5[i] = i;

    //6
    int* arr6 = new int[n];
    for( int i = 0; i < n; i++)
        arr6[i] = i;

    //7
    int* arr7 = new int[n];
    for( int i = 0; i < n; i++)
        arr7[i] = i;

    //8
    int* arr8 = new int[n];
    for( int i = 0; i < n; i++)
        arr8[i] = i;


    //FOR DECREASING NUMBERS!!!
    //9
    int* arr9 = new int[n];
    for( int i = n - 1; i >= 0; i--)
        arr9[n - 1 - i] = i;

    //10
    int* arr10 = new int[n];
    for( int i = n - 1; i >= 0; i--)
        arr10[n - 1 - i] = i;

    //11
    int* arr11 = new int[n];
    for( int i = n - 1; i >= 0; i--)
        arr11[n - 1 - i] = i;

    //12
    int* arr12 = new int[n];
    for( int i = n - 1; i >= 0; i--)
        arr12[n - 1 - i] = i;



    int compCount1 = 0;
    int moveCount1 = 0;
    clock_t t1;
    t1 = clock();
    insertionSort(arr1, 0, n - 1, compCount1, moveCount1);
    t1 = clock() - t1;

    int compCount2 = 0;
    int moveCount2 = 0;
    clock_t t2;
    t2 = clock();
    mergeSort(arr2, 0, n - 1, compCount2, moveCount2);
    t2 = clock() - t2;

    int compCount3 = 0;
    int moveCount3 = 0;
    clock_t t3;
    t3 = clock();
    quickSort(arr3, 0, n - 1, compCount3, moveCount3);
    t3 = clock() - t3;

    int compCount4 = 0;
    int moveCount4 = 0;
    clock_t t4;
    t4 = clock();
    hybridSort(arr4, 0, n - 1, compCount4, moveCount4);
    t4 = clock() - t4;



    int compCount5 = 0;
    int moveCount5 = 0;
    clock_t t5;
    t5 = clock();
    insertionSort(arr5, 0, n - 1, compCount5, moveCount5);
    t5 = clock() - t5;

    int compCount6 = 0;
    int moveCount6 = 0;
    clock_t t6;
    t6 = clock();
    mergeSort(arr6, 0, n - 1, compCount6, moveCount6);
    t6 = clock() - t6;

    int compCount7 = 0;
    int moveCount7 = 0;
    clock_t t7;
    t7 = clock();
    quickSort(arr7, 0, n - 1, compCount7, moveCount7);
    t7 = clock() - t7;

    int compCount8 = 0;
    int moveCount8 = 0;
    clock_t t8;
    t8 = clock();
    hybridSort(arr8, 0, n - 1, compCount8, moveCount8);
    t8 = clock() - t8;

    int compCount9 = 0;
    int moveCount9 = 0;
    clock_t t9;
    t9 = clock();
    insertionSort(arr9, 0, n - 1, compCount9, moveCount9);
    t9 = clock() - t9;

    int compCount10 = 0;
    int moveCount10 = 0;
    clock_t t10;
    t10 = clock();
    mergeSort(arr10, 0, n - 1, compCount10, moveCount10);
    t10 = clock() - t10;

    int compCount11 = 0;
    int moveCount11 = 0;
    clock_t t11;
    t11 = clock();
    quickSort(arr11, 0, n - 1, compCount11, moveCount11);
    t11 = clock() - t11;

    int compCount12 = 0;
    int moveCount12 = 0;
    clock_t t12;
    t12 = clock();
    hybridSort(arr12, 0, n - 1, compCount12, moveCount12);
    t12 = clock() - t12;

    cout << "Performance analysis for arrays of size " << n << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Random integers ";
    cout << right << setw(20) << "Elapsed time";
    cout << right << setw(20) << "compCount";
    cout << right << setw(20) << "moveCount" << endl;
    cout << left << setw(20) << "Insertion sort";
    cout << right << setw(20) << t1;
    cout << right << setw(20) << compCount1;
    cout << right << setw(20) << moveCount1 << endl;

    cout << left << setw(20) << "Merge sort ";
    cout << right << setw(20) << t2;
    cout << right << setw(20) << compCount2;
    cout << right << setw(20) << moveCount2 << endl;

    cout << left << setw(20) << "Quick sort ";
    cout << right << setw(20) << t3;
    cout << right << setw(20) << compCount3;
    cout << right << setw(20) << moveCount3 << endl;

    cout << left << setw(20) << "Hybrid sort ";
    cout << right << setw(20) << t4;
    cout << right << setw(20) << compCount4;
    cout << right << setw(20) << moveCount4 << endl;

    cout << "---------------------------------------------------------------------------------" << endl;

    cout << left << setw(20) << "Ascending integers ";
    cout << right << setw(20) << "Elapsed time";
    cout << right << setw(20) << "compCount";
    cout << right << setw(20) << "moveCount" << endl;
    cout << left << setw(20) << "Insertion sort";
    cout << right << setw(20) << t5;
    cout << right << setw(20) << compCount5;
    cout << right << setw(20) << moveCount5 << endl;

    cout << left << setw(20) << "Merge sort ";
    cout << right << setw(20) << t6;
    cout << right << setw(20) << compCount6;
    cout << right << setw(20) << moveCount6 << endl;

    cout << left << setw(20) << "Quick sort ";
    cout << right << setw(20) << t7;
    cout << right << setw(20) << compCount7;
    cout << right << setw(20) << moveCount7 << endl;

    cout << left << setw(20) << "Hybrid sort ";
    cout << right << setw(20) << t8;
    cout << right << setw(20) << compCount8;
    cout << right << setw(20) << moveCount8 << endl;
    cout << "---------------------------------------------------------------------------------" << endl;

    cout << left << setw(20) << "Descending integers ";
    cout << right << setw(20) << "Elapsed time";
    cout << right << setw(20) << "compCount";
    cout << right << setw(20) << "moveCount" << endl;
    cout << left << setw(20) << "Insertion sort";
    cout << right << setw(20) << t9;
    cout << right << setw(20) << compCount9;
    cout << right << setw(20) << moveCount9 << endl;

    cout << left << setw(20) << "Merge sort ";
    cout << right << setw(20) << t10;
    cout << right << setw(20) << compCount10;
    cout << right << setw(20) << moveCount10 << endl;

    cout << left << setw(20) << "Quick sort ";
    cout << right << setw(20) << t11;
    cout << right << setw(20) << compCount11;
    cout << right << setw(20) << moveCount11 << endl;

    cout << left << setw(20) << "Hybrid sort ";
    cout << right << setw(20) << t12;
    cout << right << setw(20) << compCount12;
    cout << right << setw(20) << moveCount12 << endl;


}
