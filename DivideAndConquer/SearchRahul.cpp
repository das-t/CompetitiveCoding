#include <iostream>
using namespace std;

// Rahul had a sorted array of numbers from which he had to find a given 
// number quickly. His friend by mistake rotated the array. Now Rahul 
// doesn't have time to sort the elements again. Help him to quickly find 
// the given number from the rotated array.

int getPivotIndex(int* array,int elements){
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

int binarySearch(int low,int high,int* array,int element){
    while(low<=high){
        int mid = (low+high)/2;
        if(array[mid]==element)
            return mid;
        else if(array[mid]<element)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    int searchElement;
    cin>>searchElement;
    int pivotIndex = getPivotIndex(array,elements);
    if(pivotIndex==-1)
        cout<<binarySearch(0,elements-1,array,searchElement)<<endl;
    else if(array[0]>searchElement)
        cout<<binarySearch(pivotIndex+1,elements-1,array,searchElement)<<endl;
    else
        cout<<binarySearch(0,pivotIndex,array,searchElement)<<endl;
    delete[] array;
}