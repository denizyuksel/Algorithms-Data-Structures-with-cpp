Additional libraries imported to the main.cpp:

#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Also, please don't forget to change the path of the movieDataset.txt file
while I'm scanning it in my pc, in line 53 of the main method:

std::ifstream file("D:\\Deniz Courses\\Cs-202\\homework\\hw4\\202_hw4\\movieDataset.txt");

This path will surely change in your machine.

I already assume you are aware that while reading textfiles, but
just in case...