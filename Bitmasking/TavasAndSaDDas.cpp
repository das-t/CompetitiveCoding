#include <iostream>
#define ll long long int
using namespace std;

// IMPORTANT | CODEFORCES: 535/B
// You are given a lucky number n. Lucky numbers are the positive integers
// whose decimal representations contain only the lucky digits 4 and 7. For
// example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not. If we sort
// all lucky numbers in increasing order, what's the 1-based index of n?

int main(){
    ll number;
    cin>>number;
    ll index=0, length=0;
    while(number>0){
        if(number%10==7)
            index += 1<<length;
        length++;
        number /= 10;
    }
    ll value = ((ll)1<<length)+index-1;
    cout<<value<<endl;
}