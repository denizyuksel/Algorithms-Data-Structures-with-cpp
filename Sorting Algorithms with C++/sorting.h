#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

/*
* Title : Algorithm Efficiency and Sorting
* Author : Deniz Yüksel
* ID : 21600880
* Section : 1
* Assignment : 1
* Description : this is the header file of sorting class.
*/

class Sorting
{
public:
    typedef int DataType;
    Sorting();
    void printArray(DataType theArray[], int n);
    int* getArrRef();
    void insertionSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void merge( int* arr, int first, int mid, int last, int &compCount, int &moveCount);
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void hybridSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void partition(int* arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    void performanceAnalysis(int size);


private:
};

#endif // SORTING_H_INCLUDED

