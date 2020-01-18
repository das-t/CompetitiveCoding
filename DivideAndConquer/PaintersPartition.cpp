#include <iostream>
#define ll long long int
using namespace std;

// Given K painters to paint N boards where each painter takes 1 unit of 
//time to paint 1 unit of boards i.e. if the length of a particular board 
//is 5, it will take 5 units of time to paint the board. Compute the minimum
// amount of time to paint all the boards.
// Note that:
// Every painter can paint only contiguous segments of boards.A board can 
// only be painted by 1 painter at maximum.

ll getSumArray(ll*,ll);
bool checkPossible(ll,ll*,ll,ll);
ll getMaxValArray(ll*,ll);

ll modifiedBinSearch(ll* array,ll elements,ll painters){
    ll low=getMaxValArray(array,elements),high=getSumArray(array,elements);
    while(low<high){
        ll mid = (low+high)/2;
        if(low==high-1 && checkPossible(low,array,elements,painters))
            return low;
        else if(low==high-1)
            return high;
        else if(checkPossible(mid,array,elements,painters))
            high = mid;
        else
            low = mid;
    }
    return low;
}

bool checkPossible(ll time,ll* array,ll elements,ll painters){
    ll currTotalTime = 0;
    painters--;
    for(ll i=0;i<elements;i++){
        if(currTotalTime+array[i]<=time)
            currTotalTime += array[i];
        else if(painters==0)
            return false;
        else{
            painters--;
            currTotalTime = array[i];
        }
    }
    return true;
}

ll getMaxValArray(ll* array,ll elements){
    ll maxValue = array[0];
    for(ll i=1;i<elements;i++)
        maxValue = max(maxValue,array[i]);
    return maxValue;
}

ll getSumArray(ll* array,ll elements){
    ll totalSum = 0;
    for(ll i=0;i<elements;i++)
        totalSum += array[i];
    return totalSum;
}

int main(){
    ll painters,boards;
    cin>>painters>>boards;
    ll* array = new ll[boards];
    for(ll i=0;i<boards;i++)
        cin>>array[i];
    cout<<modifiedBinSearch(array,boards,painters)<<endl;
    delete[] array;
}