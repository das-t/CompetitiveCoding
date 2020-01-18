#include <iostream>
#define ll long long int
using namespace std;

ll maxSumSubArray(ll* array,ll elements){
    ll currSumSoFar=0,maxSumSoFar=-99999999999;
    for(ll i=0;i<elements;i++){
        currSumSoFar += array[i];
        if(currSumSoFar>maxSumSoFar)
            maxSumSoFar = currSumSoFar;
        if(currSumSoFar<0)
            currSumSoFar = 0;
    }
    return maxSumSoFar;
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
        cout<<maxSumSubArray(array,elements)<<endl;
        delete[] array;
    }
}