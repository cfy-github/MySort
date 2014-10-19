//
//  main.cpp
//  CPPTest
//
//  Created by fychen on 9/23/14.
//  Copyright (c) 2014 fychen. All rights reserved.
//


#include <iostream>
#include <stdlib.h>
#include <bitset>
#include <vector>
#include <stack>
#include "FYSort.h"

using namespace std;

void printVector(vector<int> &v) {
    for(auto &e: v) cout<<e<<",";
    cout<<endl;
}
class Base {
    
};

class Dri: Base {
    
};

class TestPrint{
public:
    TestPrint() {}
    void MyPrint() {cout<<"Print"<<endl;}
    void MyPrint() const {cout<<"Const P"<<endl;}
    void MyPrint() volatile {cout<<"Vola"<<endl;}
    void MyPrint() const volatile {cout<<"Cons Vola"<<endl;}
};

void sFunc(Base& b) {cout<<"B&"<<endl;}
void sFunc(Base b) {cout<<"B"<<endl;}
void sFunc(Dri& d) {cout<<"D&"<<endl;}
void sFunc(Dri d) {cout<<"D"<<endl;}

int main(int argc, const char * argv[])
{

    // insert code here...
    //std::cout << "Hello, World!\n";
    //std::cout<<sizeof(char)<<std::endl;
    //bitset<18> x((1<<18)-1);
    //vector<int> v={3,5,-2,6,1,11,13};
    //FYSort::SelectSort(v);
    //FYSort::InsertSort(v);
    //FYSort::BubbleSort(v);
    //FYSort::QuickSort(v);
    //FYSort::QuickSortNonRecursive(v);
    
    //FYSort::MergeSort(v);
    
    //FYSort::MergeSortNonRecursive(v);
    
    //printVector(v);
    //Dri d;
    //sFunc(d);
    TestPrint p;
    p.MyPrint();
    const TestPrint cp;
    cp.MyPrint();
    
    volatile TestPrint vp;
    vp.MyPrint();
    
    const volatile TestPrint cvp;
    cvp.MyPrint();
    
    return 0;
}

