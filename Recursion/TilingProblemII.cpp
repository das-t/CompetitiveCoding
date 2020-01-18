#include <iostream>
using namespace std;

// Given a floor of size n x m. Find the number of ways to tile 
// the floor with tiles of size 1 x m . A tile can either be placed 
// horizontally or vertically.

long long int MODVALUE = 1000000007;
long long int countTileCombination(int remLength,int tileLength,long long int* memorize){
    if(remLength<0)
        return 0;
    else if(remLength==0)
        return 1;
    else if(memorize[remLength]!=0)
        return memorize[remLength];
    else
        memorize[remLength] = (countTileCombination(remLength-1,tileLength,memorize)+
            countTileCombination(remLength-tileLength,tileLength,memorize))%MODVALUE;
    return memorize[remLength];
}

int main(){
    int testCases;
    cin>>testCases;
    while(testCases-->0){
        int floorLength, tileLength;
        cin>>floorLength>>tileLength;
        long long int* memorize = new long long int[floorLength+1];
        for(int i=0;i<=floorLength;i++)
            memorize[i] = 0;
        cout<<countTileCombination(floorLength,tileLength,memorize)<<endl;
        delete[] memorize;
    }
}