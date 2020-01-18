#include <iostream>
using namespace std;

// Given n friends, each one can remain single or can be paired 
// up with some other friend. Each friend can be paired only once. 
// Find out the total number of ways

long long int friendPairing(int friends){
    if(friends==0 || friends==1)
        return 1;
    else
        return friendPairing(friends-1)+(friends-1)*friendPairing(friends-2);
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int friends;
        cin>>friends;
        cout<<friendPairing(friends)<<endl;
    }
}