//
//  FYSort.cpp
//  CPPTest
//
//  Created by fychen on 10/2/14.
//  Copyright (c) 2014 fychen. All rights reserved.
//

#include "FYSort.h"
#include <stack>

void FYSort::mySwap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

void FYSort::SelectSort(vector<int> &v) {
    for(int i=0;i<v.size();++i) {
        int minIdx=i;
        for(int j=i+1;j<v.size();++j) {
            if(v[j]<v[minIdx]) minIdx=j;
        }
        mySwap(v[minIdx], v[i]);
    }
}

void FYSort::InsertSort(vector<int> &v) {
    for(int i=0;i<v.size()-1;++i) {
        for(int j=i+1;j>0;--j) {
            if(v[j]<v[j-1]) mySwap(v[j], v[j-1]);
        }
    }
}

void FYSort::BubbleSort(vector<int> &v) {
    bool flag=true;
    while(flag) {
        flag=false;
        for(int i=1;i<v.size();++i) {
            if(v[i]<v[i-1]) {
                mySwap(v[i], v[i-1]);
                flag=true;
            }
        }
    }
}

void FYSort::QuickSortNonRecursive(vector<int> &v) {
    vector<int> vParam = {0, static_cast<int>(v.size()-1)};
    stack<vector<int> > st;
    st.push(vParam);
    
    while(!st.empty()) {
        auto curr=st.top();
        st.pop();
        if(curr[0]<curr[1]) {
            int idx=qsPartition(v, curr[0], curr[1]);
            st.push(vector<int> {curr[0], idx-1});
            st.push(vector<int> {idx+1, curr[1]});
        }
    }
}

void FYSort::QuickSort(vector<int> &v) {
    QuickSort(v, 0, static_cast<int>(v.size()-1));
}

int FYSort::qsPartition(vector<int> &v, int begin, int end) {
    int x=v[begin];
    while(begin<end) {
        while(begin<end && v[end]>=x) --end;
        if(begin<end) v[begin++]=v[end];
        while(begin<end && v[begin]<x) ++begin;
        if(begin<end) v[end--]=v[begin];
    }
    v[begin]=x;
    return begin;
}

void FYSort::QuickSort(vector<int> &v, int begin, int end) {
    if(begin<end) {
        int idx=qsPartition(v, begin, end);
        QuickSort(v, begin, idx-1);
        QuickSort(v, idx+1, end);
    }
}

void FYSort::MergeSort(vector<int> &v) {
    MergeSort(v, 0, static_cast<int>(v.size()-1));
}

void FYSort::MergeSort(vector<int> &v, int begin, int end){
    if(begin<end) {
        int mid=begin+(end-begin)/2;
        MergeSort(v, begin, mid);
        MergeSort(v, mid+1, end);
        Merge(v, begin, mid, end);
    }
}

void FYSort::Merge(vector<int> &v, int begin, int mid, int end) {
    vector<int> tmpV=v;
    int i=begin, j=mid+1, s=begin;
    while(i<=mid && j<=end) {
        if(tmpV[i]<tmpV[j]) {
            v[s++]=tmpV[i++];
        } else {
            v[s++]=tmpV[j++];
        }
    }
    while(i<=mid) v[s++]=tmpV[i++];
    while(j<=end) v[s++]=tmpV[j++];
}

void FYSort::MergeSortNonRecursive(vector<int> &v) {
    for(int s=1; s<v.size(); s+=s) {
        for(int l=0; l<v.size()-s; l+=(s+s)) {
            Merge(v, l, l+s-1, min(l+s+s-1, static_cast<int>(v.size()-1)));
        }
    }
}
