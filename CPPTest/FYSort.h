//
//  FYSort.h
//  CPPTest
//
//  Created by fychen on 10/2/14.
//  Copyright (c) 2014 fychen. All rights reserved.
//

#ifndef CPPTest_FYSort_h
#define CPPTest_FYSort_h

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class FYSort {
public:
    static void mySwap(int &a, int &b);
    static void SelectSort(vector<int> &v);
    static void InsertSort(vector<int> &v);
    static void MergeSort(vector<int> &v);
    static void QuickSort(vector<int> &v);
    static void QuickSortNonRecursive(vector<int> &v);
    static void MergeSortNonRecursive(vector<int> &v);
    static void BubbleSort(vector<int> &v);
    static void HeapSort(vector<int> &v);
    static void ShellSort(vector<int> &v);
private:
    static int qsPartition(vector<int> &v, int begin, int end);
    static void QuickSort(vector<int> &v, int begin, int end);
    static void MergeSort(vector<int> &v, int begin, int end);
    static void Merge(vector<int> &v, int begin, int mid, int end);
};

#endif
