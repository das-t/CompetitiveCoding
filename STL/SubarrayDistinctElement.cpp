#include <iostream>
#include <set>
#define ll long long int
#define MOD 1000000007
using namespace std;

// IMPORTANT: Given an array, the task is to calculate the sum of
// lengths of contiguous subarrays having all elements distinct

int main(){
    set<ll> occurSet;
    int elements;
    cin>>elements;
    ll* array = new ll[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    ll totalOccur=0,j=0;
    for(int i=0;i<elements;i++){
        while(j<elements && occurSet.find(array[j])==occurSet.end())
            occurSet.insert(array[j++]);
        totalOccur += ((j-i)*(j-i+1))/2;
        occurSet.erase(array[i]);
    }
    cout<<totalOccur<<endl;
    occurSet.clear();
}