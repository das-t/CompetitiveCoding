#include <iostream>
#include <algorithm>
using namespace std;

// IMPORTANT: ACTIVITY SELECTION PROBLEM
// You are given n activities (from 0 to n-1) with their start and finish times.
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time.

struct cmpr{
    bool operator()(pair<int,int> left,pair<int,int> right){
        return left.second <= right.second;
    }
} compare;

int nonOverlappedActivity(pair<int,int>* array,int elements){
    if(elements<=1)
        return elements;
    sort(array,array+elements,compare);
    int activity = 1;
    int currentFinishTime = array[0].second;
    for(int i=1;i<elements;i++)
        if(currentFinishTime <= array[i].first){
            activity++;
            currentFinishTime = array[i].second;
        }
    return activity;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements;
        cin>>elements;
        pair<int,int>* array = new pair<int,int>[elements];
        for(int i=0;i<elements;i++)
            cin>>array[i].first>>array[i].second;
        cout<<nonOverlappedActivity(array,elements)<<endl;
        delete[] array; 
    }
}