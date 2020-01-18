// IMPORTATNT: PIGEON-HOLE PRINCIPLE

#include <iostream>
using namespace std;

// First line contains one integer n. Second line contains n space separated 
// non-negative integers denoting the sequence A. Output YES if there exist 
// four distinct indices i1, i2, i3, i4 such that A[i1] xor A[i2] xor A[i3] 
// xor A[i4] = 0. Otherwise, output NO.

bool getCombination(int* array,int elements){
    bool success = false;
    for(int i=0;i<elements;i++)
        for(int j=i+1;j<elements;j++)
            for(int k=j+1;k<elements;k++)
                for(int l=k+1;l<elements;l++)
                    if((array[i]^array[j]^array[k]^array[l])==0)
                        return true;
    return false;
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    if(elements>=130)
        cout<<"YES"<<endl;
    else if(getCombination(array,elements))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}