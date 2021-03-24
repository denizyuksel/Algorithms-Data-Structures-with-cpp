#include <iostream>
#include "sorting.h"
using namespace std;

/*
* Title : Algorithm Efficiency and Sorting
* Author : Deniz Yüksel
* ID : 21600880
* Section : 1
* Assignment : 1
* Description : this is the main function where performanceAnalysis
is tested four times.
*/

int main(){

    Sorting test;
    test.performanceAnalysis(1000);
    test.performanceAnalysis(7000);
    test.performanceAnalysis(14000);
    test.performanceAnalysis(21000);


    return 0;
}

