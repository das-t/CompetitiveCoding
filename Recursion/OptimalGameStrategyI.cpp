#include <iostream>
using namespace std;

// Piyush and Nimit are playing a coin game. They are given n coins with values x1, x2 …. xn 
// where 'n' is always even. They take alternate terms. In each turn, a player picks either the 
// first coin or the last coin from the row and removes it from the row. The value of coin is 
// received by that player. Determine the maximum value that piyush can win if he moves first. 
// Both the players play optimally.

int gameStrategy(int start,int end,int* array){
    if(start==end)
        return array[start];
    else if(start==end-1)
        return max(array[start],array[end]);
    else
        return max(array[start]+min(gameStrategy(start+2,end,array),gameStrategy(start+1,end-1,array)),
            array[end]+min(gameStrategy(start+1,end-1,array),gameStrategy(start,end-2,array)));
}

int main(){
    int elements;
    cin>>elements;
    int* array = new int[elements];
    for(int i=0;i<elements;i++)
        cin>>array[i];
    cout<<gameStrategy(0,elements-1,array)<<endl;
}