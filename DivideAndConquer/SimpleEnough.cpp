#include <iostream>
#define ll long long int
using namespace std;

// IMPORTANT : DIFICULLTY
// For a given number n, form a list and insert the following pattern into the list
// at the same position sequentially. {floor(n/2) , n%2 , floor(n/2) } Until every
// element in the list is either 1 or 0. Now, calculate number of 1s in from l to r 
// (1-indexed).

ll stringLength(ll);

ll simpleEnough(ll number,ll low,ll high,ll startIndex,ll endIndex){
    if(low>high || low>endIndex || high<startIndex)
        return 0;
    ll mid = (low+high)/2;
    ll count1s = 0;
    if(mid>=startIndex && mid<=endIndex && number%2==1)
        count1s++;
    count1s += simpleEnough(number/2,low,mid-1,startIndex,endIndex);
    count1s += simpleEnough(number/2,mid+1,high,startIndex,endIndex);
    return count1s;
}

ll stringLength(ll number){
    if(number<=1)
        return 1;
    else
        return 2*stringLength(number/2)+1;
}

int main(){
    long long int number,startIndex,endIndex;
    cin>>number>>startIndex>>endIndex;
    cout<<simpleEnough(number,0,stringLength(number)-1,startIndex-1,endIndex-1)<<endl;
}