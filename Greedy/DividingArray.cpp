#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// You are given an array, A, of n elements. You have to remove exactly n/2
// elements from array A, and add it to another array B(initially empty). After
// these operations, you can rearrange the elements of both the arrays in any
// order. We define, difference between these two arrays as :
// ∑ i = 1 N / 2 a b s ( A i − B i )
// Find the maximum and minimum values of differences of these two arrays.

struct cmpr{
    bool operator()(ll left,ll right){
        return left<right;
    }
}compare;

ll getMinAbsDiff(ll* array,ll elements){
    ll totalDiff = 0;
    for(ll i=0;i<elements;i+=2)
        totalDiff += abs(array[i]-array[i+1]);
    return totalDiff;
}

ll getMaxAbsDiff(ll* array,ll elements){
    ll totalDiff = 0;
    for(ll i=0;i<elements/2;i++)
        totalDiff += abs(array[i]-array[elements-1-i]);
    return totalDiff;
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        ll elements;
        cin>>elements;
        ll* array = new ll[elements];
        for(ll i=0;i<elements;i++)
            cin>>array[i];
        sort(array,array+elements,compare);
        cout<<getMinAbsDiff(array,elements)<<" ";
        cout<<getMaxAbsDiff(array,elements)<<endl;
        delete[] array;
    }
}