#ifndef __EXTERN_SORT__
#define __EXTERN_SORT__
#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>



class ExternSort
{
public:
    ExternSort();
    ~ExternSort() = default;
    void randomNumbers();
    void createInitialRuns();

private:
    ExternSort(const ExternSort& oth);
    void merge();
private:
    int j;
    int tmp;
    int write_count;
    std::multiset<int> myFile;
    std::multiset<int>::iterator iter;
    std::ifstream fileIn;
    std::ofstream fileOut;
    std::string path;
};





#endif
