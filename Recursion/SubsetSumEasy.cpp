#include <iostream>
using namespace std;

// If the sum of any of the non-empty subsets of the set A is zero.

int countSumZero = 0;
void getSubsetSum(int index,int remSum,int* array){
    if(index<0 && remSum==0)
        countSumZero++;
    else if(index<0)
        return;
    else{
        getSubsetSum(index-1,remSum,array);
        getSubsetSum(index-1,remSum-array[index],array);
    }
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        countSumZero = 0;
        int elements;
        cin>>elements;
        int* array = new int[elements];
        for(int i=0;i<elements;i++)
            cin>>array[i];
        getSubsetSum(elements-1,0,array);
        if(countSumZero>1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}