#include <iostream>
#include <algorithm>
using namespace std;

int getLeftIndex(int*,int);
int getIndexLarger(int*,int,int,int);
void printArray(int*,int);
void swap(int*,int,int);

// Print all unique lexicographic permutations of the array.

void generatePermutation(int* array,int length){
    while(true){
        int leftIndex = getLeftIndex(array,length);
        if(leftIndex == -1)
            return;
        int rightIndex = getIndexLarger(array, length, leftIndex+1, array[leftIndex]);
        swap(array,leftIndex,rightIndex);
        sort(array+leftIndex+1,array+length);
        printArray(array,length);
    }
}

int getLeftIndex(int* array,int length){
    int index = length-2;
    while(index>=0)
        if(array[index]<array[index+1])
            return index;
        else
            index--;
    return index;
}

int getIndexLarger(int* array,int elements,int index,int pivot){
    int minIndex = index;
    for(int i=index+1;i<elements;i++)
        if(array[i]>pivot && array[i]<array[minIndex])
            minIndex = i;
    return minIndex;
}

void printArray(int* array,int elements){
    for(int i=0;i<elements;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

void swap(int* array,int index1,int index2){
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    sort(array, array+elements, less<int>());
    printArray(array,elements);
    generatePermutation(array,elements);
}