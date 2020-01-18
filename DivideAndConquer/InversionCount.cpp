#include <iostream>
using namespace std;

int countMerge(int low,int mid,int high,int* array){
    int totalInversions = 0;
    int i=low,j=mid+1,k=low;
    int* barr = new int[high+1];
    while(i<=mid && j<=high)
        if(array[i]<=array[j])
            barr[k++] = array[i++];
        else{
            totalInversions += (mid+1-i);
            barr[k++] = array[j++];
        }
    if(i<=mid)
        while(i<=mid)
            barr[k++] = array[i++];
    else
        while(j<=high)
            barr[k++] = array[j++];
    for(int i=low;i<=high;i++)
        array[i] = barr[i];
    delete[] barr;
    return totalInversions;
}

int countInversions(int low,int high,int* array){
    int totalInversions = 0;
    if(low<high){
        int mid = (low+high)/2;
        totalInversions += countInversions(low,mid,array);
        totalInversions += countInversions(mid+1,high,array);
        totalInversions += countMerge(low,mid,high,array);
    }
    return totalInversions;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int elements;
        cin>>elements;
        int* array = new int[elements];
        for(int i=0;i<elements;i++)
            cin>>array[i];
        cout<<countInversions(0,elements-1,array)<<endl;
        delete[] array;
    }
}