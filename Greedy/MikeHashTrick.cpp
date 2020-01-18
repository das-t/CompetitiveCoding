#include <iostream>
#include <map>
#define ll long long int
using namespace std;

/* Mike loves hashing. He decides to create his own hashing technique, so he
 creates a Hash Function, given as :

int* hash_array(int A[], int n)
{
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

You are given an array A. You have to find the Mike's hashes for all the values that 
appears in this array.
*/

int main(){
    ll elements;
    cin>>elements;
    map<ll,ll> lastIndexOccur;
    for(ll i=0;i<elements;i++){
        ll value;
        cin>>value;
        lastIndexOccur[value] = i;
    }
    map<ll,ll> reverseLastIndexOccurMap;
    map<ll,ll>::iterator itr=lastIndexOccur.begin();
    for(;itr!=lastIndexOccur.end();itr++)
        reverseLastIndexOccurMap[itr->second] = itr->first;
    itr=reverseLastIndexOccurMap.begin();
    for(;itr!=reverseLastIndexOccurMap.end();itr++)
        cout<<itr->second<<endl;
}