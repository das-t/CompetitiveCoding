#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// IMPORTANT CONCEPT: Divide & Conquer

// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
// The stalls are located along a straight line at positions x1,…,xN 
// (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive 
// towards each other once put into a stall. To prevent the cows from hurting 
// each other, FJ wants to assign the cows to the stalls, such that the minimum
// distance between any two of them is as large as possible. What is the 
//largest minimum distance?

bool checkPossible(ll*,ll,ll,ll);
ll binSearch(ll* array,ll elements,ll cows){
    ll maxValue = array[elements-1];
    ll low=0, high=maxValue;
    while(low<high){
        ll mid = (low+high)/2;
        if(low==high-1 && checkPossible(array,elements,cows,high))
            return high;
        else if(low==high-1)
            return low;
        else if(!checkPossible(array,elements,cows,high) && 
                        !checkPossible(array,elements,cows,mid))
            high = mid;
        else
            low = mid;
    }
    return low;
}

bool checkPossible(ll* array,ll elements,ll cows,ll minDiff){
    ll currPos = array[0];
    cows--;
    for(ll i=1;i<elements;i++){
        if(array[i]-currPos>=minDiff){
            cows--;
            currPos = array[i];
        }
        if(cows==0)
            return true;
    }
    return false;
}

int main(){
    ll elements,cows;
    cin>>elements>>cows;
    ll* array = new ll[elements];
    for(ll i=0;i<elements;i++)
        cin>>array[i];
    sort(array,array+elements);
    cout<<binSearch(array,elements,cows)<<endl;
}