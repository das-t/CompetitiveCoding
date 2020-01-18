#include <iostream>
using namespace std;

// Given a sorted but rotated array. You need to find the index 
// of the pivot element of the array where pivot is that element in 
// the array which is greater than its next element and divides 
// the array into two monotonically increasing halves.

// IMPORTANT CONCEPT: BINARY SEARCH

int getPivotElement(int* array,int elements){
    int low=0, high=elements-1;
    while(low<high){
        if(low==high-1 && array[low]>array[high])
            return low;
        else if(low==high-1)
            return -1;
        int mid = (low+high)/2;
        if(array[mid]>array[high])
            low = mid;
        else
            high = mid;
    }
    return low;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    cout<<getPivotElement(array,elements)<<endl;
    delete[] array;
}

